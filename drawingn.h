#ifndef DRAWINGN_H
#define DRAWINGN_H

#include <QWidget>
#include "nota.h"

namespace Ui {
class DrawingN;
}

class DrawingN : public QWidget
{
    Q_OBJECT

public:
    explicit DrawingN(QWidget *parent = nullptr);
    ~DrawingN();

    DrawingN(QList<Nota*> nota);

    QList<Nota*> getNotas();

    void drawingN();

private slots:
    void on_cmdOk_clicked();

private:
    Ui::DrawingN *ui;
    QPixmap lienzo;
    QList<Nota*> m_nota;
};

#endif // DRAWINGN_H
