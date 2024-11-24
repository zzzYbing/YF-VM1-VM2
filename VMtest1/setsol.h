#ifndef SETSOL_H
#define SETSOL_H

#include <QDialog>

namespace Ui {
class setsol;
}

class setsol : public QDialog
{
    Q_OBJECT

public:
    explicit setsol(QWidget *parent = nullptr);
    ~setsol();
    void setPath(const QString &path);
    void setName(const QString &name);
signals:
    void dataName(const QString &data);
    void dataPath(const QString &data);
private slots:
    void on_pushButton_clicked();

private:
    Ui::setsol *ui;
};

#endif // SETSOL_H
