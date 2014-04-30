#include "abstractstylednumberrenderer.h"

AbstractStyledNumberRenderer::AbstractStyledNumberRenderer(int _num)
    : m_num(_num),
      m_img(NULL)
{}

AbstractStyledNumberRenderer::~AbstractStyledNumberRenderer()
{
    delete m_img;
}

QImage* AbstractStyledNumberRenderer::image() const
{
    return m_img;
}
