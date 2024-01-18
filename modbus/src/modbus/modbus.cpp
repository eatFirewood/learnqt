#include "modbus.h"
#include "./ui_modbus.h"
#include <QSerialPort>
#include <QModbusDataUnit>

modbus::modbus(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::modbus)
{
    ui->setupUi(this);

}

modbus::~modbus()
{
    delete ui;
}

void modbus::btrd_clicked(){
    rtuClient->setConnectionParameter(QModbusDevice::SerialPortNameParameter, "COM3");
    rtuClient->setConnectionParameter(QModbusDevice::SerialParityParameter, QSerialPort::EvenParity);
    rtuClient->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,QSerialPort::Baud115200);
    rtuClient->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data8);
    rtuClient->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::OneStop);

    QModbusDataUnit unit(QModbusDataUnit::HoldingRegisters, ui->addrEditor->text().toInt(),1);
    QModbusReply* reply = rtuClient->sendReadRequest(unit, 1);
    if(reply && !reply->isFinished()){
        connect(reply, &QModbusReply::finished, this,&modbus::replyFinished);
    }
}

void modbus::btwt_clicked(){

}

void modbus::replyFinished(){
    QModbusReply* reply = qobject_cast<QModbusReply *>(sender());
    if(reply){
        QModbusDataUnit unit = reply->result();
        reply->deleteLater();

        ui->contentEditor->setText(QString::number(unit.value(0)));
    }
}
