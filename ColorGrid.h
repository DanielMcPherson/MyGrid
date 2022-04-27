#ifndef COLORGRID_H
#define COLORGRID_H

#include <QWidget>
#include <QLayout>

class ColorGrid : public QWidget
{
    Q_OBJECT
public:
    explicit ColorGrid(int size = 3, QWidget *parent = nullptr);
    void resize(int size);
    int size();

signals:

private:
    int m_size = 0;
    QGridLayout *m_layout;
};

#endif // COLORGRID_H
