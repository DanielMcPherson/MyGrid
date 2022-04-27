#include "MyGrid.h"

#include <QLayout>
#include <QSlider>
#include <QLabel>
#include <QMenuBar>
#include <QMessageBox>
#include <QDebug>

MyGrid::MyGrid(QWidget *parent)
    : QMainWindow(parent)
{
    auto mainLayout = new QVBoxLayout();

    // Grid of color boxes
    m_grid = new ColorGrid();
    mainLayout->addWidget(m_grid);

    // Slider controls
    auto sliderLayout = new QVBoxLayout;
    sliderLayout->setAlignment(Qt::AlignBottom);
    auto sliderLabel = new QLabel(tr("Grid Size"));
    auto font = sliderLabel->font();
    font.setBold(true);
    sliderLabel->setFont(font);
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
    m_gridSizeLabel = new QLabel(QString::number(m_grid->size()));
    sliderHBoxLayout->addWidget(m_gridSizeLabel);
    sliderHBoxLayout->addStretch();
    sliderLayout->addLayout(sliderHBoxLayout);
    mainLayout->addLayout(sliderLayout);

    // Create About menu
    auto aboutMenu = menuBar()->addMenu(tr("About"));
    auto aboutAction = new QAction("About MyGrid");
    connect(aboutAction, &QAction::triggered, this, &MyGrid::showAboutDialog);
    aboutMenu->addAction(aboutAction);

    // Set window to main layout created above
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    resize(400, 400);
}

MyGrid::~MyGrid()
{
}

void MyGrid::sliderValueChanged(int value)
{
    m_grid->resize(value);
    m_gridSizeLabel->setText(QString::number(m_grid->size()));
}

void MyGrid::showAboutDialog()
{
    QString str =
            "MyGrid\n\n"
            "Example Qt C++ program\n"
            "  Daniel McPherson\n"
            "  27 April 2022\n\n"
            "https://github.com/DanielMcPherson/MyGrid";

    QMessageBox msg;
    msg.setText(str);
    msg.exec();
}
