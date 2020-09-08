#ifndef ZHUJIEMIAN_H
#define ZHUJIEMIAN_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // ZHUJIEMIAN_H
