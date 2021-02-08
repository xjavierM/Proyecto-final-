#ifndef NUEVOE_H
#define NUEVOE_H

#include <QDialog>

namespace Ui {
class NuevoE;
}

class NuevoE : public QDialog
{
    Q_OBJECT
     Q_PROPERTY(QString nombre READ nombre)
public:
    explicit NuevoE(QWidget *parent = nullptr);
    ~NuevoE();

     NuevoE(QString nombre);
     QString nombre() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NuevoE *ui;

    QString m_nombre;
};

#endif // NUEVOE_H
