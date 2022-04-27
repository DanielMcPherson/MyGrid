#include "ColorBox.h"
#include <QPainter>

ColorBox::ColorBox(QWidget *parent)
    : QWidget{parent}
{

}

void ColorBox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(rect(), Qt::red);
}
