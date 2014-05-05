#include "stylednums/stylednumberrenderer.h"

StyledNumberRenderer::StyledNumberRenderer(int _num)
    : m_num(_num),
      m_img(NULL)
{}

StyledNumberRenderer::~StyledNumberRenderer()
{
    delete m_img;
}

QImage* StyledNumberRenderer::image() const
{
    return m_img;
}
