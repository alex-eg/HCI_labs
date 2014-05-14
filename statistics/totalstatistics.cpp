#include "totalstatistics.h"
#include "../stylednums/stylednumberrenderer.h"

TotalStatistics::TotalStatistics()
    : Statistics()
{
    m_description << "Угаданно" << "Неугаданно";
    m_statistics.resize(2);
}

void TotalStatistics::addUserStats(const QList<StyledNumberRenderer *> &_showedData, const QList<int> &_userCheckedData)
{
    foreach (StyledNumberRenderer* renderer, _showedData)
    {
        int generatedNum = renderer->num();

        if(_userCheckedData.contains(generatedNum))
            m_statistics[0]++;
        else
            m_statistics[1]++;
    }
}

StatTypes TotalStatistics::type() const
{
    return Total;
}
