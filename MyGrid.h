#ifndef MYGRID_H
#define MYGRID_H

#include "ColorGrid.h"

#include <QMainWindow>
#include <QLabel>

class MyGrid : public QMainWindow
{
    Q_OBJECT

public:
    MyGrid(QWidget *parent = nullptr);
    ~MyGrid();

private slots:
    void sliderValueChanged(int value);
    void showAboutDialog();

private:
    ColorGrid *m_grid;
    QLabel *m_gridSizeLabel;
};
#endif // MYGRID_H
