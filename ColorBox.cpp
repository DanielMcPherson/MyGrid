#include "ColorBox.h"
#include <QPainter>
#include <QDebug>

ColorBox::ColorBox(QWidget *parent)
    : QWidget{parent}
{
    setMinimumSize(50, 50);
}

ColorBox::~ColorBox()
{
    // Print grid position when destroyed, to help ensure that all ColorBoxes are
    // being cleaned up when the program exits
//    qDebug() << Q_FUNC_INFO << statusTip();
}

// Fill box with current color
void ColorBox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor color = m_toggled ? Qt::blue : Qt::red;
    painter.fillRect(rect(), color);
}

// Toggle box color when box is clicked
void ColorBox::mousePressEvent(QMouseEvent *event)
{
    m_toggled = !m_toggled;
    repaint();
}
