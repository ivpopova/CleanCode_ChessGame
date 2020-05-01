#include "Square.h"
#include "Figure.h"

Square::Square() {
}

Square::~Square() {
}

Figure* Square::getFigure() const {
    return figure;
}


void Square::setFigure(Figure* figure) {
    this->figure = figure;
}


void Square::clearFigure() {
    this->figure = nullptr;
}

void Square::print() {
    figure->print();
}
