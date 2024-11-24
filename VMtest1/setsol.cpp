#include "setsol.h"
#include "ui_setsol.h"
#include<QFileDialog>

setsol::setsol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setsol)
{
    ui->setupUi(this);
}

setsol::~setsol()
{
    emit dataName(ui->name->text());
    emit dataPath(ui->path->text());
    delete ui;
}

void setsol::on_pushButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择文件"), "", tr("Sol Files (*.sol)"));
    if (!filePath.isEmpty()) {
        ui->path->setText(filePath);
    }
}
void setsol::setPath(const QString &path)
{
    ui->path->setText(path);
}
// 设置方案名称
void setsol::setName(const QString &name)
{
    ui->name->setText(name);
}
