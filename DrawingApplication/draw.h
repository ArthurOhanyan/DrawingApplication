#ifndef DRAW_H
#define DRAW_H

#include "qwidget.h"
#include <QComboBox>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>

class Draw : public QWidget
{
    Q_OBJECT

public:
    Draw(QWidget*);

private slots:



protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void drawShape(QPainter* qp);
private:

    QComboBox* m_shapeBox;
    QPoint m_start_point;
    QPoint m_end_point;

};

#endif // DRAW_H
