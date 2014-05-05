#ifndef ROMENUMSRENDERER_H
#define ROMENUMSRENDERER_H

#include "stylednumberrenderer.h"

class RomeNumsRenderer : public StyledNumberRenderer
{
public:
    RomeNumsRenderer(int _num);
    Style type() const;
    void render(const QStyleOption& _option);
};

#endif // ROMENUMSRENDERER_H
