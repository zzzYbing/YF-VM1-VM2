#ifndef DLG_DISPLAY_H
#define DLG_DISPLAY_H

#include <QDialog>

namespace Ui {
class Dlg_Display;
}

class Dlg_Display : public QDialog
{
    Q_OBJECT

public:
    explicit Dlg_Display(QWidget *parent = nullptr);
    ~Dlg_Display();

private:
    Ui::Dlg_Display *ui;
};

#endif // DLG_DISPLAY_H
