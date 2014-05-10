#ifndef LABAPI_H
#define LABAPI_H

#include <QFont>

enum Style {Invalid, ArabNums, RomeNums, Words, SymbolicNum, StylesCount};

static QFont defaultStringsFont("Times New Roman", 20);

inline void inc(Style& _style)
{
    unsigned int tmp = static_cast<unsigned int>(_style);
    _style = static_cast<Style>(++tmp);
}


#endif // LABAPI_H
