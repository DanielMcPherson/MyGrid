#include "MyGrid.h"
#include "ColorBox.h"
#include <QLayout>
#include <QSlider>

MyGrid::MyGrid(QWidget *parent)
    : QMainWindow(parent)
{
    auto mainLayout = new QVBoxLayout();

    // Grid of color boxes
    auto boxLayout = new QGridLayout();
    boxLayout->setSpacing(1);
    const int size = 3;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ColorBox *box = new ColorBox();
            boxLayout->addWidget(box, i, j);
        }
    }
    mainLayout->addLayout(boxLayout);

    // Slider to control grid size
    auto slider = new QSlider(Qt::Horizontal);
    mainLayout->addWidget(slider);

    // Set window to main layout created above
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MyGrid::~MyGrid()
{
}

