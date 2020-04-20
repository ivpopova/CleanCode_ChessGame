#include "Figure.h"

Figure::Figure()
{
    typeFigure = " ";
}

void Figure::print()
{
    if (color == Color::Black)
    {
        std::cout << "b";
    }
    else
    {
        std::cout << "w";
    }
    std::cout << typeFigure;

}

void Figure::setPosition(Position position)
{
    this->position = position;
}

void Figure::setColor(Color color)
{
    this->color = color;
}

void Figure::setTypeFigure(std::string typeFigure)
{
    this->typeFigure = typeFigure;
}


Position Figure::getCurrentPosition() const
{
    return position;
}


Color Figure::getColor() const
{
    return this->color;
}

std::string Figure::getTypeFigure() const
{
    return typeFigure;
}

Figure::~Figure()
{
}