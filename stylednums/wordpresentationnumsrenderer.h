#ifndef WORDPRESENTATIONNUMSRENDERER_H
#define WORDPRESENTATIONNUMSRENDERER_H

#include "stylednumberrenderer.h"

class WordPresentationNumsRenderer : public StyledNumberRenderer
{
public:
    WordPresentationNumsRenderer(int _num);

    Style type() const;
    void render(const QStyleOption& _option);

};

#endif // WORDPRESENTATIONNUMSRENDERER_H
