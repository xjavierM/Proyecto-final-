#include "drawingn.h"
#include "ui_drawingn.h"
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <nota.h>

DrawingN::DrawingN(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawingN)
{
    ui->setupUi(this);
}

DrawingN::DrawingN(QList<Nota*> nota):

    m_nota(nota),
    ui(new Ui::DrawingN)
{
    m_nota=nota;
    ui->setupUi(this);
    lienzo=QPixmap(ui->outDraw->size());
    lienzo.fill(Qt::white);
    ui->outDraw->setPixmap(lienzo);
    drawingN();
}

DrawingN::~DrawingN()
{
    delete ui;
}


void DrawingN::drawingN()
{
    QPainter painter(&lienzo);
    QPen penc(Qt::black);
    penc.setColor(Qt::black);
    painter.setPen(penc);

    //linea de mitad
    painter.drawLine(550,100,17,100);
    //linea de arriba
    painter.drawLine(15,300,15,10);

    //linea de la abajo(x)
    painter.drawLine(15,15,550,14);

    //cordenadas del plano
    painter.drawText(11,10,"Y");
    painter.drawText(600,15,"X");
    int aux=30;
   for(int i=0; i<m_nota.length();i++){
       if(m_nota.at(i)->gettotal()>=70){
           painter.setBrush(Qt::green);
           painter.drawRect(30+i*50,aux,10,m_nota.at(i)->gettotal()*10);
           QPen pen(Qt::black);
           pen.setColor(Qt::black);
           painter.setPen(pen);
           painter.drawText(30+i*50,27,m_nota.at(i)->getEstudiante().getnombre());
           ui->outDraw->setPixmap(lienzo);
       } else if (m_nota.at(i)->gettotal()<70){
           painter.setBrush(Qt::red);
           painter.drawRect(30+i*50,aux,10,m_nota.at(i)->gettotal());
           QPen pen(Qt::black);
           pen.setColor(Qt::black);
           painter.setPen(pen);
           painter.drawText(30+i*50,27,m_nota.at(i)->getEstudiante().getnombre());

           ui->outDraw->setPixmap(lienzo);
       }
       }
}

void DrawingN::on_cmdOk_clicked()
{
    this->close();

}
