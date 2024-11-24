#include "dlg_display.h"
#include "ui_dlg_display.h"

Dlg_Display::Dlg_Display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dlg_Display)
{
    ui->setupUi(this);
}

Dlg_Display::~Dlg_Display()
{
    delete ui;
}
