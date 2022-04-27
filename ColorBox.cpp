#include "ColorBox.h"
#include <QPainter>
#include <QDebug>

ColorBox::ColorBox(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(50, 50);
}

void ColorBox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor color = m_toggled ? Qt::blue : Qt::red;
    painter.fillRect(rect(), color);
}

void ColorBox::mousePressEvent(QMouseEvent *event)
{
    m_toggled = !m_toggled;
    repaint();
}
