#include "nota.h"

Nota::Nota(QObject *parent) : QObject(parent)
{

}

Nota::Nota(double nota1, double nota2, double total, double promedio, Estudiante estudiante)
{
     m_nota1 = nota1;
     m_nota2 = nota2;
     m_total = total;
     m_promedio = promedio;
     //m_estudiante;
}

double Nota::nota1() const
{
    return m_nota1;
}

double Nota::nota2() const
{
    return m_nota2;
}

double Nota::gettotal() const
{
    return m_total;
}

double Nota::getpromedio() const
{
    return m_promedio;
}

Estudiante Nota::getEstudiante(){

    //return  m_estudiante;
}
