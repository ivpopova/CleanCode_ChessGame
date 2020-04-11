#pragma once
#include<iostream>
#include <string>

enum  Color
{
    Black,
    White
};

struct Position
{
public:
    int xpos;
    int ypos;
    Position(int x=-1, int y=-1): xpos(x), ypos(y) {}
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
    virtual bool validateMove(Position moveToPosition, Figure* piece) = 0;
    virtual ~Figure();
};
