#ifndef MODBUS_H
#define MODBUS_H

#include <QModbusRtuSerialClient>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui {
class modbus;
}
QT_END_NAMESPACE

class modbus : public QMainWindow
{
    Q_OBJECT

public:
    modbus(QWidget *parent = nullptr);
    ~modbus();
public slots:
    void btrd_clicked();
    void btwt_clicked();
    void replyFinished();
private:
    Ui::modbus *ui;
    QModbusRtuSerialClient* rtuClient;
};
#endif // MODBUS_H
