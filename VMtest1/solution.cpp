#include "solution.h"
#include "ui_solution.h"
#include <QCheckBox>
#include <QFileDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QSqlError>
#include <QFile>
#include <QFileInfo>
#pragma execution_character_set("UTF-8")
solution::solution(QWidget *parent) :
    QDialog(parent),
    pVmSol(nullptr),
    ui(new Ui::solution)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath()+"\\book.db");  // 数据库路径
    if (!db.open()) {
        qDebug() << "Error: Unable to connect to the database." << db.lastError().text();
        return;
    }
    loadDataFromDatabase();
    inittable();
}

solution::~solution()
{
    if (db.isOpen()) {
        db.close();
    }
    delete ui;
}
void solution::inittable()
{
    int fixedColumnIndex = 0; // 需要设置为固定宽度的列的索引
    int fixedWidth = 100; // 固定列宽度的值

    // 设置固定宽度的列
    ui->tableWidget->setColumnWidth(fixedColumnIndex, fixedWidth);

    // 获取表头对象
    QHeaderView *header = ui->tableWidget->horizontalHeader();

    // 对所有列设置为均匀分布
    for (int i = 0; i < ui->tableWidget->columnCount(); ++i) {
        if (i != fixedColumnIndex) {
            header->setSectionResizeMode(i, QHeaderView::Stretch);
        } else {
            header->setSectionResizeMode(i, QHeaderView::Fixed);
        }
    }
}

void solution::on_btn_add_clicked()
{
    setsol  s1(this); // 传递当前窗口作为父窗口
    s1.exec();

    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);

    QLineEdit *nameEdit = new QLineEdit();
    QLineEdit *pathEdit = new QLineEdit();
    QPushButton *setbtn = new QPushButton("编辑");
    QPushButton *loadbtn = new QPushButton("加载方案");
    QPushButton *delbtn = new QPushButton("删除");
    QPushButton *copybtn = new QPushButton("复制");

    connect(&s1, &setsol::dataName, [nameEdit](const QString &data) {
        nameEdit->setText(data);
    });
    connect(&s1, &setsol::dataPath, [pathEdit](const QString &data) {
        pathEdit->setText(data);
    });

    ui->tableWidget->setCellWidget(rowCount, 0, nameEdit);
    ui->tableWidget->setCellWidget(rowCount, 1, pathEdit);
    ui->tableWidget->setCellWidget(rowCount, 2, setbtn);
    ui->tableWidget->setCellWidget(rowCount, 3, loadbtn);
    ui->tableWidget->setCellWidget(rowCount, 4, delbtn);
    ui->tableWidget->setCellWidget(rowCount, 5, copybtn);
    // 连接删除按钮的点击信号
    connect(delbtn, &QPushButton::clicked, [this, rowCount]() {
        ui->tableWidget->removeRow(rowCount);
    });
    // 加载方案按钮
    connect(loadbtn,&QPushButton::clicked,[this,pathEdit](){
        QString path = pathEdit->text();
        // 发射信号，传递方案路径
        emit solutionPathSelected(path);
    });
    // 复制按钮
    connect(copybtn, &QPushButton::clicked, [this, rowCount]() {
        copyFile(rowCount);

        on_btn_save_clicked();
    });
    //编辑按钮
    connect(setbtn,&QPushButton::clicked,[this,nameEdit,pathEdit](){
        setsol  s1(this);
        s1.setName(nameEdit->text());
        s1.setPath(pathEdit->text());
        connect(&s1, &setsol::dataName, [nameEdit](const QString &data) {
            nameEdit->setText(data);
        });
        connect(&s1, &setsol::dataPath, [pathEdit](const QString &data) {
            pathEdit->setText(data);
        });
        s1.exec();
    });

}

void solution::loadDataFromDatabase()
{
    QSqlQuery query("SELECT name, path FROM sol");
    if (query.exec())
    {
        while (query.next()){
            QString name = query.value(0).toString();
            QString path = query.value(1).toString();

            int rowCount = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(rowCount);

            QLineEdit *nameEdit = new QLineEdit();
            QLineEdit *pathEdit = new QLineEdit();
            QPushButton *setbtn = new QPushButton("编辑");
            QPushButton *loadbtn = new QPushButton("加载方案");
            QPushButton *delbtn = new QPushButton("删除");
            QPushButton *copybtn = new QPushButton("复制");
            nameEdit->setText(name);
            pathEdit->setText(path);
            ui->tableWidget->setCellWidget(rowCount, 0, nameEdit);
            ui->tableWidget->setCellWidget(rowCount, 1, pathEdit);
            ui->tableWidget->setCellWidget(rowCount, 2, setbtn);
            ui->tableWidget->setCellWidget(rowCount, 3, loadbtn);
            ui->tableWidget->setCellWidget(rowCount, 4, delbtn);
            ui->tableWidget->setCellWidget(rowCount, 5, copybtn);
            // 连接删除按钮的点击信号
            connect(delbtn, &QPushButton::clicked, [this, rowCount]() {
                ui->tableWidget->removeRow(rowCount);
            });
            // 加载方案按钮
            connect(loadbtn,&QPushButton::clicked,[this,pathEdit](){
                QString path = pathEdit->text();
                // 发射信号，传递方案路径
                emit solutionPathSelected(path);
                // 发射信号，传递方案路径
                if (pVmSol == nullptr) {
                    qDebug() << "Failed to load solution from path:" << path;
                }
            });
            // 复制按钮
            connect(copybtn, &QPushButton::clicked, [this, rowCount]() {
                copyFile(rowCount);
                on_btn_save_clicked();
            });
            //编辑按钮
            connect(setbtn,&QPushButton::clicked,[this,nameEdit,pathEdit](){
                setsol  s1(this);
                s1.setName(nameEdit->text());
                s1.setPath(pathEdit->text());
                connect(&s1, &setsol::dataName, [nameEdit](const QString &data) {
                    nameEdit->setText(data);
                });
                connect(&s1, &setsol::dataPath, [pathEdit](const QString &data) {
                    pathEdit->setText(data);
                });
                s1.exec();
            });
        }
    }
    else
    {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    }
}
void solution::on_btn_save_clicked()
{
    QSqlQuery query(db);

    // 开始事务
    query.exec("BEGIN TRANSACTION");

    // 清空表数据
    query.exec("DELETE FROM sol");

    // 遍历所有行
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        QLineEdit* nameEdit = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(i, 0));
        QLineEdit* pathEdit = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(i, 1));

        if (nameEdit && pathEdit) {
            QString name = nameEdit->text();
            QString path = pathEdit->text();

            query.prepare("INSERT INTO sol (name, path) VALUES (:name, :path)");
            query.bindValue(":name", name);
            query.bindValue(":path", path);

            if (!query.exec()) {
                qDebug() << "Failed to insert data:" << query.lastError().text();
            }
        }
    }

    // 提交事务
    query.exec("COMMIT");
}

void solution::copyFile(int row)
{
    QLineEdit* pathEdit = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(row, 1));
    QLineEdit* nameEdit = qobject_cast<QLineEdit*>(ui->tableWidget->cellWidget(row, 0));
    if (pathEdit) {
        QString originalPath = pathEdit->text();
        QString newname = nameEdit->text();
        QFileInfo fileInfo(originalPath);
        QString originalFileName = fileInfo.fileName();
        QString originalDir = fileInfo.absolutePath();
        QString newFileName = QString("%1_1.%2").arg(fileInfo.baseName()).arg(fileInfo.suffix());
        QString newFilePath = originalDir + "/" + newFileName;

        if (QFile::copy(originalPath, newFilePath)) {
            qDebug() << "File copied to:" << newFilePath;
            addRowToTable(newname+"_1", newFilePath);
        } else {
            qDebug() << "Failed to copy file:" << originalPath;
        }
    }
}

void solution::addRowToTable(const QString &name, const QString &path)
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);

    QLineEdit *nameEdit = new QLineEdit();
    QLineEdit *pathEdit = new QLineEdit();
    QPushButton *setbtn = new QPushButton("编辑");
    QPushButton *loadbtn = new QPushButton("加载方案");
    QPushButton *delbtn = new QPushButton("删除");
    QPushButton *copybtn = new QPushButton("复制");

    nameEdit->setText(name);
    pathEdit->setText(path);

    ui->tableWidget->setCellWidget(rowCount, 0, nameEdit);
    ui->tableWidget->setCellWidget(rowCount, 1, pathEdit);
    ui->tableWidget->setCellWidget(rowCount, 2, setbtn);
    ui->tableWidget->setCellWidget(rowCount, 3, loadbtn);
    ui->tableWidget->setCellWidget(rowCount, 4, delbtn);
    ui->tableWidget->setCellWidget(rowCount, 5, copybtn);

    // 连接按钮的点击信号
    connect(delbtn, &QPushButton::clicked, [this, rowCount]() {
        ui->tableWidget->removeRow(rowCount);
    });
    connect(loadbtn,&QPushButton::clicked,[this,pathEdit](){
        QString path = pathEdit->text();
        // 发射信号，传递方案路径
        emit solutionPathSelected(path);
    });
    connect(copybtn, &QPushButton::clicked, [this, rowCount]() {
        copyFile(rowCount);
    });
    connect(setbtn,&QPushButton::clicked,[this,nameEdit,pathEdit](){
        setsol s1(this);
        s1.setName(nameEdit->text());
        s1.setPath(pathEdit->text());
        connect(&s1, &setsol::dataName, [nameEdit](const QString &data) {
            nameEdit->setText(data);
        });
        connect(&s1, &setsol::dataPath, [pathEdit](const QString &data) {
            pathEdit->setText(data);
        });
        s1.exec();
    });
}
