#pragma once
#include<iostream>
#include <string>
#include"Color.h"
#include"Position.h"

class Figure {
  public:
    Figure();
    
    void print();
    void setPosition(Position currentPosition);
    void setColor(Color color);
    void setTypeFigure(std::string typeFigure);

    Position getCurrentPosition() const;
    Color getColor() const;
    std::string getTypeFigure() const ;

    virtual bool isValidMove(Position newPosition, Figure* figure) = 0;
    virtual ~Figure();

  private:
    std::string typeFigure;
    Color color;
    Position currentPosition;

};
