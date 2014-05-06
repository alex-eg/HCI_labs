#ifndef STATISTICS_H
#define STATISTICS_H

#include <QMap>
#include <QString>
#include "stylednums/stylednumsapi.h"

class Statistics
{
public:
    Statistics();

private:
    struct stat
    {
        stat() : success(0), unsuccess(0)   {}

        int success, unsuccess;
    };


//    QMap<QString, stat[]

  //  QVector<QString> m_statistics[StylesCount];

};

#endif // STATISTICS_H
