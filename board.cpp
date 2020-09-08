#include "board.h"
#include "zhujiemian.h"
#include <QPainter>
#include <QWidget>
Board::Board(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("中国象棋");
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background,QColor(218,165,32));
    this->setPalette(palette);
    for(int i=0;i<32;i++)
    {
        s[i].init(i);//棋子初始化
    }
}

void Board::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int d=40;
    r=d/2;
    for(int i=1;i<=10;i++)//横线
    {
        painter.drawLine(QPoint(d,i*d),QPoint(9*d,i*d));
    }
    painter.setFont(QFont("楷体",20,30));
    painter.drawText(QPoint(d,d*6-7), "   楚河     汉界   ");
    for(int i=1;i<=9;i++)//竖线
    {
        if(i==1||i==9)
        painter.drawLine(QPoint(i*d,d),QPoint(i*d,10*d));
        else
        {
        painter.drawLine(QPoint(i*d,d),QPoint(i*d,5*d));
        painter.drawLine(QPoint(i*d,6*d),QPoint(i*d,10*d));
        }
    }
    painter.drawLine(QPoint(4*d,1*d),QPoint(6*d,3*d));
    painter.drawLine(QPoint(6*d,1*d),QPoint(4*d,3*d));
    painter.drawLine(QPoint(4*d,8*d),QPoint(6*d,10*d));
    painter.drawLine(QPoint(6*d,8*d),QPoint(4*d,10*d));

    //棋子绘制
    for(int i=0;i<32;i++)
    {
        drawStone(painter,i);
    }
}

QPoint Board::center(int row, int col)
{
    QPoint ret;
    ret.rx()=(col+1)*r*2;
    ret.ry()=(row+1)*r*2;
    return ret;
}

QPoint Board::center(int id)
{
    return center(s[id].row,s[id].col);
}

void Board::drawStone(QPainter& painter,int id)
{
    QPoint c= center(id);
    QRect rect=QRect(c.x()-r,c.y()-r,r*2,r*2);
    painter.setBrush(QBrush(QColor(205,133,63)));
    painter.setPen(Qt::black);
    painter.drawEllipse(center(id),r,r);
    if(s[id].color==1)
        painter.setPen(Qt::red);
    painter.setFont(QFont("楷体",r,700));
    painter.drawText(rect,s[id].getText(),QTextOption(Qt::AlignCenter));

}
