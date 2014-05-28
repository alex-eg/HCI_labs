#ifndef ARABNUMSRENDERER_H
#define ARABNUMSRENDERER_H

#include "stylednumberrenderer.h"

class ArabNumsRenderer : public StyledNumberRenderer
{
public:
    ArabNumsRenderer(int _number);
    Style type() const;

    void render(const QStyleOption &_option, const QFont &_font);
    void render(const QStyleOption& _option);
};

#endif // ARABNUMSRENDERER_H
