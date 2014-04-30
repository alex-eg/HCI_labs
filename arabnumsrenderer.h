#ifndef ARABNUMSRENDERER_H
#define ARABNUMSRENDERER_H

#include "abstractstylednumberrenderer.h"

class ArabNumsRenderer : public AbstractStyledNumberRenderer
{
public:
    ArabNumsRenderer(int _number);
    void render(const QStyleOption& _option);
};

#endif // ARABNUMSRENDERER_H
