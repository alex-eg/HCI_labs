#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDebug>
#include <QMap>
#include <QString>
#include "stylednums/stylednumsapi.h"

class Statistics
{
public:
    Statistics();

    class UserStats;
    void addUserStats(const QString& _user, const UserStats& _stats);
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

    class UserStats // should apply Pimp pattern
    {
    public:
        UserStats()
            : m_stat(new Stat[StylesCount]) {}
        UserStats(const UserStats& _stat)
            : m_stat(new Stat[StylesCount])
        {
            operator =(_stat);
        }

        UserStats& operator =(const UserStats& _stat)
        {
            // should find qt memcpy analog
            for(int i = 0; i < StylesCount; i++)
                m_stat[i] = _stat.m_stat[i];

            return *this;
        }

        Stat& operator [] (Style _n) const
        {
            qDebug() << Q_FUNC_INFO;
            Q_ASSERT(_n < StylesCount);
            return m_stat[_n];
        }

        void setStat(Style _style, Stat _successCount)
        {
            Q_ASSERT(_style < StylesCount);
            m_stat[_style] = _successCount;
        }

        void merge(const UserStats& _stats)
        {
            for(Style i = Invalid; i < StylesCount; inc(i))
            {
                m_stat[i].success += _stats[i].success;
                m_stat[i].unsuccess += _stats[i].unsuccess;
            }
        }

        ~UserStats()
        {
            delete[] m_stat;
        }
    private:
        Stat* m_stat;
    };
    //  -------------------------------------------

    QMap <QString, UserStats> m_statistics;
};

#endif // STATISTICS_H
