#pragma once
#include<iostream>
#include <string>
#include"Color.h"
#include"Position.h"

class Figure {
  public:
    Figure();
    virtual ~Figure();
    
    void setCurrentPosition(Position currentPosition);
    void setColor(Color color);
    void setTypeFigure(std::string typeFigure);

    Position getCurrentPosition() const;
    Color getColor() const;
    std::string getTypeFigure() const ;

    void print();
    virtual bool isValidMove(Position newPosition, Figure* figure) = 0;
    
  private:
    std::string typeFigure;
    Color color;
    Position currentPosition;
};
