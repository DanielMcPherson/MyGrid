#include "ColorGrid.h"
#include "ColorBox.h"

ColorGrid::ColorGrid(int size, QWidget *parent)
    : QWidget{parent}
{    
    m_layout = new QGridLayout();
    setLayout(m_layout);
    m_layout->setSpacing(2);
    resize(size);
}

void ColorGrid::resize(int size)
{
    m_size = size;
    // ToDo: Retain boxes that fit in new grid size

    // Remove old boxes from layout
    QLayoutItem* item;
    while ((item = m_layout->takeAt(0)) != nullptr) {

        delete item->widget();
        delete item;
    }

    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            ColorBox *box = new ColorBox();
            m_layout->addWidget(box, i, j);
            // Use statusTip to hold max the minimum grid size that can contain
            // this box
            int minGridSize = i > j ? i + 1 : j + 1;
            box->setToolTip(QString::number(minGridSize));
            box->setStatusTip(QString::number(minGridSize));
        }
    }
}

int ColorGrid::size()
{
    return m_size;
}
