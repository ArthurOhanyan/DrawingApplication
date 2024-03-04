#include "draw.h"
#include <QVBoxLayout>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QMessageBox>
#include <QString>
#include <qwidget.h>


Draw::Draw(QWidget* parent) : QWidget(parent)
{
    setMinimumSize(600,600);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout -> setAlignment(Qt::AlignTop);
    m_shapeBox = new QComboBox();
    m_shapeBox ->addItems({"Select", "Line", "Rectangle"});
    mainLayout -> addWidget(m_shapeBox);

}

void Draw::mousePressEvent(QMouseEvent* event)
{
    m_start_point = event -> pos();
}

void Draw::mouseReleaseEvent(QMouseEvent* e)
{
    m_end_point = e -> pos();
    update();
}

void Draw::paintEvent(QPaintEvent* e)
{

     QPainter painter(this);
     drawShape(&painter);

}

void Draw::drawShape(QPainter* qp)
{
    if (m_shapeBox->currentText() == "Line" && !m_start_point.isNull() && !m_end_point.isNull()) {
        qp->setPen(Qt::green);
        qp->drawLine(m_start_point, m_end_point);

    } else if (m_shapeBox->currentText() == "Rectangle" && !m_start_point.isNull() && !m_end_point.isNull()) {
        qp->setPen(Qt::yellow);
        qp->drawRect(QRect(m_start_point, m_end_point));
    }

}
