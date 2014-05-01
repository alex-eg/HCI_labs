#ifndef ABSTRACTSTYLEDNUMBERRENDERER_H
#define ABSTRACTSTYLEDNUMBERRENDERER_H

#include <QImage>
#include <QStyleOption>

class AbstractStyledNumberRenderer
{
public:
    AbstractStyledNumberRenderer(int _num);
    virtual ~AbstractStyledNumberRenderer();

    virtual void render(const QStyleOption& _option) = 0;
    QImage* image() const;

protected:
    int m_num;
    QImage* m_img;
};

#endif // ABSTRACTSTYLEDNUMBERRENDERER_H
