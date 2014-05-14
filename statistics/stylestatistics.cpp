#include "stylestatistics.h"
#include "../stylednums/stylednumberrenderer.h"
#include "../stylednums/stylednumsapi.h"

StyleStatistics::StyleStatistics(StatTypes _type)
    : m_type(_type)
{
    m_description << stylesNames();
    m_statistics.resize(stylesNames().count());
}

void StyleStatistics::addUserStats(const QList<StyledNumberRenderer *>& _showedData, const QList<int>& _userCheckedData)
{
    foreach (StyledNumberRenderer* renderer, _showedData)
    {
        int generatedNum = renderer->num();
        Style generatedStyle = renderer->type();

        bool needInc = _userCheckedData.contains(generatedNum);
        needInc ^= !(m_type == StyleSuccess);

        if(needInc)
            m_statistics[generatedStyle]++;
    }
}

StatTypes StyleStatistics::type() const
{
    return m_type;
}
