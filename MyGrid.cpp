#include "MyGrid.h"
#include "ColorBox.h"
#include <QLayout>
#include <QSlider>
#include <QLabel>
#include <QDebug>

MyGrid::MyGrid(QWidget *parent)
    : QMainWindow(parent)
{
    auto mainLayout = new QVBoxLayout();

    // Grid of color boxes
    m_boxLayout = new QGridLayout();
    m_boxLayout->setSpacing(1);
    mainLayout->addLayout(m_boxLayout);
    resizeGrid();

    // ToDo: Layout is giving an equal amount of vertical space to grid layout and
    // slider controls. Make grid layout expand to maximum available space.

    // Slider controls
    auto sliderLayout = new QVBoxLayout;
    sliderLayout->setAlignment(Qt::AlignBottom);
    auto sliderLabel = new QLabel(tr("Grid Size"));
    sliderLayout->addWidget(sliderLabel);
    auto sliderHBoxLayout = new QHBoxLayout;
    // Slider to control grid size
    auto slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(2);
    slider->setMaximum(5);
    slider->setValue(3);
    connect(slider, &QSlider::valueChanged, this, &MyGrid::sliderValueChanged);
    sliderHBoxLayout->addWidget(slider);
    // Label to display current grid size
    m_gridSizeLabel = new QLabel(QString::number(m_gridSize));
    sliderHBoxLayout->addWidget(m_gridSizeLabel);
    sliderLayout->addLayout(sliderHBoxLayout);
    mainLayout->addLayout(sliderLayout);

    // Set window to main layout created above
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

MyGrid::~MyGrid()
{
}

void MyGrid::sliderValueChanged(int value)
{
    m_gridSize = value;
    m_gridSizeLabel->setText(QString::number(m_gridSize));
    resizeGrid();
}

void MyGrid::resizeGrid()
{
    // ToDo: Retain boxes that fit in new grid size

    // Remove old boxes from layout
    QLayoutItem* item;
    while ((item = m_boxLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    for (int i = 0; i < m_gridSize; i++) {
        for (int j = 0; j < m_gridSize; j++) {
            ColorBox *box = new ColorBox();
            m_boxLayout->addWidget(box, i, j);
        }
    }
}

