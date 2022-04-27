#ifndef COLORBOX_H
#define COLORBOX_H

#include <QWidget>

class ColorBox : public QWidget
{
    Q_OBJECT
public:
    explicit ColorBox(QWidget *parent = nullptr);

signals:

protected:
    void paintEvent(QPaintEvent *);

};

#endif // COLORBOX_H
