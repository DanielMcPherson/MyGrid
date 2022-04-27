#ifndef MYGRID_H
#define MYGRID_H

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

private:
    int m_gridSize = 3;
    QLabel *m_gridSizeLabel;
};
#endif // MYGRID_H
