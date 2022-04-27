#include "ColorGrid.h"
#include "ColorBox.h"

#include <QDebug>

ColorGrid::ColorGrid(int size, QWidget *parent)
    : QWidget{parent}
{    
    m_layout = new QGridLayout();
    setLayout(m_layout);
    m_layout->setSpacing(2);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    resize(size);
}

// Resize the grid of color boxes
// Note: ColorBox widgets are not destroyed when resizing the grid.
// The m_colorBoxes map retains pointers to ColorBox widgets previously allocated
// for each grid location. This allows us to maintain existing color states when
// the grid is resized.
// An alternative would be to maintain a map of color states for each grid
// position (using a QMap<QString, bool>). We could then delete ColorBoxes
// when resizing, and set the desired state when creating new ColorBoxes.
void ColorGrid::resize(int size)
{
    m_size = size;

    // Remove all boxes from layout
    QLayoutItem* item;
    while ((item = m_layout->takeAt(0)) != nullptr) {
        // Remove item from layout, but don't delete it
        item->widget()->setVisible(false);
    }

    for (int i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size; j++) {
            QString position = QString("%1,%2").arg(i + 1).arg(j+1);
            ColorBox *box = nullptr;
            // Either create a new box for this grid position, or restore the existing
            // box that was already allocated for this position
            if (m_colorBoxes.contains(position)) {
//                qDebug() << "Reusing existing color box for position " << position;
                box = m_colorBoxes[position];
                box->setVisible(true);
            } else {
//                qDebug() << "Creating new color box for position " << position;
                box = new ColorBox();
                m_colorBoxes[position] = box;
                // Use statusTip to hold grid coordinates for debugging purposes
                box->setStatusTip(position);
            }
            m_layout->addWidget(box, i, j);
        }
    }
}

int ColorGrid::size()
{
    return m_size;
}
