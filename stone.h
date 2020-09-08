#ifndef STONE_H
#define STONE_H
#include <QString>

class Stone
{
public:
    Stone();

    int row;//行
    int col;//列
    int id;//记号
    bool dead;//是否被吃
    bool color;//颜色true为红,false为黑
    enum TYPE{JIANG,CHE,PAO,MA,BING,SHI,XIANG};
    TYPE type;//类型

    void init(int i)
    {
        struct
        {
            int row1,col1;
            Stone::TYPE type1;
        }pos[16]={
        {0,0,Stone::CHE},
        {0,1,Stone::MA},
        {0,2,Stone::XIANG},
        {0,3,Stone::SHI},
        {0,4,Stone::JIANG},
        {0,5,Stone::SHI},
        {0,6,Stone::XIANG},
        {0,7,Stone::MA},
        {0,8,Stone::CHE},
        {2,1,Stone::PAO},
        {2,7,Stone::PAO},
        {3,0,Stone::BING},
        {3,2,Stone::BING},
        {3,4,Stone::BING},
        {3,6,Stone::BING},
        {3,8,Stone::BING},
        };
        id=i;
        dead=false;
        color=i<16;
        if(id<16)
        {
            row=pos[i].row1;
            col=pos[i].col1;
            type=pos[i].type1;
        }
        else
        {
            row=9-pos[i-16].row1;
            col=8-pos[i-16].col1;
            type=pos[i-16].type1;
        }
    }

    QString getText()
    {
        if(color==true)
        {
            switch(this->type)
            {
            case JIANG:
            return "帅";
            case CHE:
            return "车";
            case PAO:
            return "炮";
            case MA:
            return "马";
            case BING:
            return "兵";
            case SHI:
            return "仕";
            case XIANG:
            return "相";
            }
        }
        else
        {
            switch(this->type)
            {
            case JIANG:
            return "将";
            case CHE:
            return "车";
            case PAO:
            return "炮";
            case MA:
            return "马";
            case BING:
            return "卒";
            case SHI:
            return "士";
            case XIANG:
            return "象";
            }
        }
    }
};

#endif // STONE_H
