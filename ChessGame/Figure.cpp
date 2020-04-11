#include "Figure.h"

Figure::Figure()
{
    type = " ";
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
    std::cout << type;

}

void Figure::setPosition(Position position)
{
    this->position = position;
}


Position Figure::getPosition() const
{
    return position;
}


Color Figure::getColor() const
{
    return this->color;
}

std::string Figure::getType() const
{
    return type;
}

Figure::~Figure()
{
}