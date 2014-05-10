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

    Statistics();

    void addUserStats(const QString& _user, const QVector<Stat>& _stats);
    inline static QVector<Statistics::Stat> defaultUserStats();

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

    QMap <QString, QVector<Stat> > m_statistics;
};

#endif // STATISTICS_H
