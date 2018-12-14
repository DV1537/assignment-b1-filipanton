#ifndef FIGURE_H
#define FIGURE_H
#include "Shape.h"

struct boundingBoxCorners
{
    float xTopLeft;
    float yTopLeft;
    float xBottomRight;
    float yBottomRight;

};

class Figure
{
private:
    int counter;
    Shape **Shapes = new Shape*[5];
public:
    Figure() : counter(0){}
    void addShape(Shape *s);
    boundingBoxCorners getBoundingBox();
    Shape** getShapes()
    {
        return Shapes;
    }

};


#endif