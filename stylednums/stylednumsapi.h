#ifndef STYLEDNUMSAPI_H
#define STYLEDNUMSAPI_H

#include <QFont>
#include <QVector>
#include <QColor>

enum Style {ArabNums, RomeNums, Words, SymbolicNum, StylesCount};

inline QString randomColor()
{
    static QVector<QString> colors;
    if(colors.isEmpty())
    {
        foreach(QString s, QColor::colorNames())
            colors << s;
    }

    int randomNum = qrand() % colors.size();
    return colors[randomNum];
}


static QFont defaultStringsFont("Times New Roman", 20);

inline void inc(Style& _style)
{
    unsigned int tmp = static_cast<unsigned int>(_style);
    _style = static_cast<Style>(++tmp);
}


#endif // STYLEDNUMSAPI_H
