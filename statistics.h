#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDebug>
#include <QMap>
#include <QString>
#include "stylednums/stylednumsapi.h"

class Statistics
{
public:
    struct Stat;

    Statistics(const int _maxLength = StylesCount);
    const QVector<Stat> *statistics();

    void addUserStats(const QVector<Stat>& _stats);
    QVector<Statistics::Stat> defaultUserStats();

    void info() const;
//  -------------------------------------------
    struct Stat
    {
        Stat() : success(0), unsuccess(0)   {}

        friend const Stat& operator++(Stat &_s)
        {
            ++_s.success;
            return _s;
        }

        friend const Stat& operator--(Stat &_s)
        {
            ++_s.unsuccess;
            return _s;
        }
        int success, unsuccess;
    };

//  -------------------------------------------

    const int m_maxLength;
    QVector<Stat> m_statistics;
};

#endif // STATISTICS_H
