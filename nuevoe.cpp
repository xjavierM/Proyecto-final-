#include "nuevoe.h"
#include "ui_nuevoe.h"

NuevoE::NuevoE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NuevoE)
{
    ui->setupUi(this);
}

NuevoE::NuevoE(QString nombre){
    m_nombre = nombre;
}
NuevoE::~NuevoE()
{
    delete ui;
}


void NuevoE::on_buttonBox_accepted()
{
   accept();
}

void NuevoE::on_buttonBox_rejected()
{
   reject();
}
QString NuevoE::nombre() const
{
    return ui->inNombre->text();
}
