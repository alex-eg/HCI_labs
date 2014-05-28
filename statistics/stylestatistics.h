#ifndef STYLESTATISTICS_H
#define STYLESTATISTICS_H

#include "statistics.h"

class StyleStatistics : public Statistics
{
public:
    StyleStatistics(StatTypes _type);
    void addUserStats(const QList<StyledNumberRenderer*>& _showedData, const QList<int>& _userCheckedData);
    StatTypes type() const;

private:
    StatTypes m_type;
};

#endif // STYLESTATISTICS_H
