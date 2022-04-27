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
    void mousePressEvent(QMouseEvent *event);

private:
    bool m_toggled = false;
};

#endif // COLORBOX_H
