#ifndef ABSTRACTSTYLEDNUMBERRENDERER_H
#define ABSTRACTSTYLEDNUMBERRENDERER_H

#include <QString>
#include <QImage>
#include <QStyleOption>
#include "stylednumsapi.h"

class StyledNumberRenderer
{
public:
    StyledNumberRenderer(int _num);
    virtual ~StyledNumberRenderer();

    virtual Style type() const = 0;
    virtual void render(const QStyleOption& _option) = 0;

    QImage* image() const;

protected:
    void renderWithText(const QStyleOption& _option, const QString& _text);

protected:
    int m_num;
    QImage* m_img;
};

#endif // ABSTRACTSTYLEDNUMBERRENDERER_H
