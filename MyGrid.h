#ifndef MYGRID_H
#define MYGRID_H

#include <QMainWindow>
#include <QLabel>
#include <QLayout>

class MyGrid : public QMainWindow
{
    Q_OBJECT

public:
    MyGrid(QWidget *parent = nullptr);
    ~MyGrid();

private slots:
    void sliderValueChanged(int value);


private:
    void resizeGrid();

private:
    int m_gridSize = 3;
    QGridLayout *m_boxLayout;
    QLabel *m_gridSizeLabel;
};
#endif // MYGRID_H
