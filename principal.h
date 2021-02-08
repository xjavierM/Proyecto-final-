#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "estudiante.h"
#include "nota.h"
#include "nuevoe.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

    void openWindow(QList<Nota*> m_nota);

private slots:

    void on_cmdAgregar_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_outGrafica_clicked();

    void on_cmdOpen_clicked();

    void on_cmdAdd_clicked();

    void on_cmdSaveLista_clicked();

private:
    Ui::Principal *ui;

    QList<Estudiante*> m_estudiante;
    QList<Nota*> m_nota;

    QList<NuevoE*> m_nuevo;
    void inicializarWidgets();
    void obtenerDatos();
    void guardarTabla();
    void cargarDatos();
    void inicializaTable();
    void datosI();

    enum Columna{
        NOMBRE
    };

};
#endif // PRINCIPAL_H
