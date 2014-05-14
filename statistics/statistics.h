#ifndef STATISTICS_H
#define STATISTICS_H

#include <QString>
#include <QVector>
#include "statisticsapi.h"

class StyledNumberRenderer;

class Statistics
{
public:
    Statistics(StatTypes _type);
    virtual ~Statistics();

    virtual const QVector<int> *statistics() const;
    virtual const QVector<QString> *description() const;

    virtual void addUserStats(const QList<StyledNumberRenderer*> &_showedData, const QList<int> &_userCheckedData);
    virtual StatTypes type() const;

protected:
    Statistics() : m_pimpl(NULL) {}
private:
    Statistics* statsFactory(StatTypes _type) const;

protected:
    QVector<int> m_statistics;
    QVector<QString> m_description;

    Statistics* m_pimpl;
};

#endif // STATISTICS_H
