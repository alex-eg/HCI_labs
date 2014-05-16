#ifndef NUMBERSTATISTICS_H
#define NUMBERSTATISTICS_H

#include "statistics.h"

class NumberStatistics : public Statistics
{
public:
    NumberStatistics(StatTypes _type);

    void addUserStats(const QList<StyledNumberRenderer*>& _showedData, const QList<int>& _userCheckedData) Q_DECL_OVERRIDE ;
    StatTypes type() const;

private:
    StatTypes m_type;
};

#endif // NUMBERSTATISTICS_H
