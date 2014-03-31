#ifndef POSDIALOG_H
#define POSDIALOG_H

#include <QDialog>
#include "../common/position_data.hpp"

namespace Ui {
class PosDialog;
}

class PosDialog : public QDialog
{
    Q_OBJECT


public:
        PositionData _pos;
    explicit PosDialog(QWidget *parent = 0);
    ~PosDialog();
public slots:
    virtual void accept();

private:
    Ui::PosDialog *ui;
};

#endif // POSDIALOG_H
