#ifndef NOTA_H
#define NOTA_H

#include <QObject>
#include "estudiante.h"

class Nota : public QObject
{
    Q_OBJECT
public:
    explicit Nota(QObject *parent = nullptr);
    Nota(double nota1, double nota2, double gettotal, double getpromedio, Estudiante estudiante);


    double nota1() const;
    double nota2() const;
    double gettotal() const;
    double getpromedio() const;
    Estudiante getEstudiante();

signals:
private:
    double m_nota1;
    double m_nota2;
    double m_total;
    double m_promedio;
    Estudiante m_estudiante;
};

#endif // NOTA_H
