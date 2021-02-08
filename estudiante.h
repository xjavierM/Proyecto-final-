#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <QObject>

class Estudiante : public QObject
{
    Q_OBJECT
public:
    explicit Estudiante(QObject *parent = nullptr);
    Estudiante(QString getnombre);



    QString getnombre() const;


signals:

private:
    QString m_nombre;


};

#endif // ESTUDIANTE_H
