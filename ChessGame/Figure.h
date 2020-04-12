#pragma once
#include<iostream>
#include <string>

enum  Color { Black, White };

struct Position
{
public:
    int x;
    int y;
    Position(int x=-1, int y=-1): x(x), y(y) {}
};

class Figure
{
protected:
    std::string type;
    Color color;
    Position position;

public:
    Figure();
    

    void print();
    void setPosition(Position position);

    Position getPosition() const;
    Color getColor() const;
    std::string getType() const ;

    virtual bool isValidMove(Position moveToPosition, Figure* figure) = 0;
    virtual ~Figure();
};
