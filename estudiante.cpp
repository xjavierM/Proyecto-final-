#include "estudiante.h"

Estudiante::Estudiante(QObject *parent) : QObject(parent)
{

}

Estudiante::Estudiante(QString nombre)
{
    m_nombre = nombre;

}

QString Estudiante::getnombre() const
{
    return m_nombre;
}

