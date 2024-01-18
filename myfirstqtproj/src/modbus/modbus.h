#ifndef MODBUS_H
#define MODBUS_H

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
private slots:
    void dothis();
    void dothat();
private:
    Ui::modbus *ui;
    int countnum = 0;
};
#endif // MODBUS_H
