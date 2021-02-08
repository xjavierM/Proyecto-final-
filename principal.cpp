#include "principal.h"
#include "ui_principal.h"

#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QPainter>
#include <QPen>
#include <QPaintEvent>
#include <QDebug>

#include <QMessageBox>
#include "drawingn.h"
#include <drawingn.h>
#include "nuevoe.h"


Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    inicializarWidgets();
    datosI();


}

Principal::~Principal()
{
    delete ui;
}


void Principal::cargarDatos(){

    QString archivo = QFileDialog::getOpenFileName(this, "Abrir archivo",
                                                   "C:","(*.csv)");
    QFile file(archivo);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;

    }

    //PARA LEER LA PRIMERA LINEA
    bool primeraLinea = true;
    // if(file.open(QFile::ReadOnly)){
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString linea = in.readLine();
        if(primeraLinea){
            primeraLinea = false;
            continue;
        }

        //SEPARAR LOS DATOS POR ';'
        QStringList datos = linea.split(";");
        QString nombre  = datos[1];
        qDebug() << datos[1];


        //PARA CARGAR EN QTABLEWIDGET LISTA DE ESTUDIANTES
        int posicion = ui->outLista->rowCount();
        ui->outLista->insertRow(posicion);
        ui->outLista->setItem(posicion,0, new QTableWidgetItem(datos[1]));

}
    }

void Principal::inicializaTable()
{
    //Colocar cabecera
    QStringList cabecera = { "Nombre y Apellido"};

    ui->outDatos->setColumnCount(1);
    ui->outDatos->setHorizontalHeaderLabels(cabecera);
    ui->outDatos->setColumnWidth(0,254);
}

void Principal::datosI()
{

}
void Principal::inicializarWidgets(){



    //Colocar cabecera
    QStringList cabecera = { "Nombre y Apellido", "Nota 1", "Nota 2", "Total (/100)"};
    ui->outDatos->setColumnCount(4);
    ui->outDatos->setHorizontalHeaderLabels(cabecera);
    ui->outDatos->setColumnWidth(0,200);


    //Colocar cabecera para la lista
    QStringList cabeceralista = { "Nombre y Apellido"};
    ui->outLista->setColumnCount(1);
    ui->outLista->setHorizontalHeaderLabels(cabeceralista);
    ui->outLista->setColumnWidth(0,254);

}

void Principal::obtenerDatos(){
    QString nombre = ui->inNombre->text();
    double nota1 = ui->inNota1->text().toDouble();
    double nota2 =ui->inNota2->text().toDouble();
    double total = nota1 + nota2;

    ui->outPromedio->setText(QString::number(total));
    int posicion = ui->outDatos->rowCount();
    ui->outDatos->insertRow(posicion);

    ui->outDatos->setItem(posicion,0,new QTableWidgetItem(nombre));
    ui->outDatos->setItem(posicion,1,new QTableWidgetItem(QString::number(nota1)));
    ui->outDatos->setItem(posicion,2,new QTableWidgetItem(QString::number(nota2)));
    ui->outDatos->setItem(posicion,3, new QTableWidgetItem(QString::number(total)));
}

void Principal::guardarTabla()
{


    /*QString fileName = QFileDialog::getSaveFileName(this,
                          "Guardar datos", QDir::home().absolutePath(), "Archivo csv (*.csv)");
       QFile file(fileName);

       if (file.open(QFile::WriteOnly | QFile::Truncate)) {
           QTextStream data(&file);
           QStringList strList;
           for (int i = 0; i< ui->outDatos->columnCount(); i++){
               strList <<
                          "\" "+
                          ui->outDatos->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString() +
                          "\" ";
           }
           for (int j=0 ;j<ui->outDatos->rowCount(); j++) {
               strList.clear();
               for (int c = 0; c< ui->outDatos->columnCount(); c++) {
                   QTableWidgetItem* item = ui->outDatos->item(j,c);
                   if(!item || item->text().isEmpty()){
                       ui->outDatos->setItem(j, c, new QTableWidgetItem("0"));
                   }
                   strList << "\" "+ui->outDatos->item(j,c)->text()+ "\n"" ";
               }
               data << strList.join(";") + "\n";
           }

            statusBar()->showMessage(tr("Archivo guardado exitosamente."), 3000);
            file.close();
           }*/

    QString archivo = QFileDialog::getSaveFileName(this,
                                                   "Guardar datos", QDir::home().absolutePath(), "Archivo csv (*.csv)");
    QFile file(archivo);
    if(file.open(QFile::WriteOnly | QFile::Truncate)){
        QTextStream data(&file);
        QStringList strList;
        //Para obtener la cabecera en archivo .csv
        QTableWidget * table = ui->outDatos;
        for(int ca = 0; ca < ui->outDatos->columnCount(); ++ca){
            strList <<
                       "\" "+
                       table->horizontalHeaderItem(ca)->data(Qt::DisplayRole).toString()+
                       "\" ";
        }
        for( int i = 0; i < ui->outDatos->rowCount(); i++){
            strList.clear();
            for (int j = 0; j < ui->outDatos->columnCount(); j++) {
                strList << "\" "+ui->outDatos->item(i,j)->text() +"\" ";
            }
            data <<strList.join(";")+"\n";
        }
        statusBar()->showMessage(tr("Archivo guardado exitosamente."), 3000);
        file.close();
    }
}



void Principal::on_cmdAgregar_clicked()
{
    obtenerDatos();


}

void Principal::on_pushButton_clicked()
{

}

void Principal::on_pushButton_3_clicked()
{
    guardarTabla();
}

void Principal::on_outGrafica_clicked()
{
   openWindow(m_nota);
}

void Principal::openWindow(QList<Nota*> nota)
{
    DrawingN *window = new DrawingN(nota);
    window->show();
}

void Principal::on_cmdOpen_clicked()

{

    cargarDatos();
}

void Principal::on_cmdAdd_clicked()
{

   int res, fila;
   QString nombre;

   NuevoE nuevo(this);
   res= nuevo.exec();

   if(res==QDialog::Rejected)
       return;


           nombre =nuevo.nombre();


           ui->outLista->insertRow(ui->outLista->rowCount());
           //La ultima fila
           fila = ui->outLista->rowCount() -1 ;

           ui->outLista->setItem(fila, NOMBRE, new QTableWidgetItem(nombre));


}

void Principal::on_cmdSaveLista_clicked()
{
    guardarTabla();
}
