#include "dlg_vision.h"

#include "ui_dlg_vision.h"

Dlg_Vision::Dlg_Vision(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Vision)

{
    ui->setupUi(this);
    ui->axWidget->dynamicCall("GetObjectPointer()");
}

Dlg_Vision::~Dlg_Vision()
{
    delete ui;
}
