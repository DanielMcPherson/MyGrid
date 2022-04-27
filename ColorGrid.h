#ifndef COLORGRID_H
#define COLORGRID_H

#include "ColorBox.h"

#include <QWidget>
#include <QLayout>
#include <QMap>

class ColorGrid : public QWidget
{
    Q_OBJECT
public:
    explicit ColorGrid(int size = 3, QWidget *parent = nullptr);
    void resize(int size);
    int size();

signals:

private:
    // Current grid size
    int m_size = 0;
    // Grid layout
    QGridLayout *m_layout;
    // Cached color boxes to be assigned to grid layout
    QMap<QString, ColorBox *> m_colorBoxes;
};

#endif // COLORGRID_H
