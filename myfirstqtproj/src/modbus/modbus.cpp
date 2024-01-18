#include "modbus.h"
#include "./ui_modbus.h"

#include <QSerialPort>
#include <stdio.h>

modbus::modbus(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::modbus)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, &QAbstractButton::clicked,this, &modbus::dothis);
    QObject::connect(ui->pushButton_2, &QAbstractButton::clicked,this, &modbus::dothat);
}

modbus::~modbus()
{
    delete ui;
}
void modbus::dothis(){
    char text[20];
    countnum += 1;
    sprintf(text, "counter:%d", countnum);
    ui->label->setText(text);
}

void modbus::dothat(){
    char text[20];
    countnum = 0;
    sprintf(text, "counter:%d", countnum);
    ui->label->setText(text);
}
