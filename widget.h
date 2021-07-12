#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_send_clicked();
    void dealMessage();

    void on_buttonBindOwnPortn_clicked();

    void on_lineEditOwnPort_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;


};
#endif // WIDGET_H
