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
    auto boxLayout = new QGridLayout();
    boxLayout->setSpacing(1);
    for (int i = 0; i < m_gridSize; i++) {
        for (int j = 0; j < m_gridSize; j++) {
            ColorBox *box = new ColorBox();
            boxLayout->addWidget(box, i, j);
        }
    }
    mainLayout->addLayout(boxLayout);

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
}

