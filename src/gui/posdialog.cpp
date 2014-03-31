#include "posdialog.h"
#include "ui_posdialog.h"

PosDialog::PosDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PosDialog)
{
    ui->setupUi(this);
}

PosDialog::~PosDialog()
{
    delete ui;
}


void PosDialog::accept() {
    _pos.x = ui->x->value();
    _pos.y = ui->y->value();
   _pos.z = ui->z->value();
    _pos.beta = ui->rx->value()*3.14/180;
    _pos.alpha = ui->ry->value()*3.14/180;
    _pos.gamma = ui->rz->value()*3.14/180;
    QDialog::accept();

}
