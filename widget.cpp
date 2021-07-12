#include "widget.h"
#include "ui_widget.h"
#include <QUdpSocket>
#include <QDebug>

#define BUFFER_SIZE 1024



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    udpSocket = NULL;

}

void Widget::on_buttonBindOwnPortn_clicked()
{
    quint64 port = ui->lineEditOwnPort->text().toInt();
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(port);
    QString str = QString("<h3>The port is bound successfully!</h3>");
    ui->textEditRead->setText(str);
    setWindowTitle(QString("Port:%1").arg(port));

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(dealMessage));


}
void Widget::dealMessage()
{
    while (udpSocket ->hasPendingDatagrams())
        {
            QByteArray data;
            data.resize(udpSocket->pendingDatagramSize());
            udpSocket->readDatagram(data.data(),data.size());
            ui->textEditRead->clear();
            ui->textEditRead->setText(QString(data));

       }
}
void Widget::on_send_clicked()
{
    if(udpSocket == NULL){
        return;
    }//Cannot send data before binding the port
    QString peer_ip = ui->lineEditIP->text();
    qint64 peer_port = ui->lineEditPeerPort->text().toInt();

    QString str = ui->textEditWrite->toPlainText();
    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(peer_ip),peer_port);
}
Widget::~Widget()
{
    delete ui;
}









