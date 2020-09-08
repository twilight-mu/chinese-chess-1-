#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include "stone.h"
#include <QPainter>

class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = nullptr);

    Stone s[32];

    int r;//棋子半径

    QPoint center(int row,int col);//获取棋盘行列对应坐标
    QPoint center(int id);//获取某一棋子的中心坐标
    void drawStone(QPainter &painter,int id);//绘画棋子
    void paintEvent(QPaintEvent *);


signals:

public slots:
};

#endif // BOARD_H
