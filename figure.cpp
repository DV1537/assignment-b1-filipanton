#include "figure.h"

void Figure::addShape(Shape *s)
{
    if(counter < 5)
    {
        Shapes[counter] = s;
    }
    else
    {
        Shape **temp = new Shape*[counter+2];
        for(int i=0; i < counter; i++)
        {
            temp[i] = Shapes[i]; 
        }

        delete[] Shapes;
        Shapes = new Shape*[counter + 1];

        for(int i=0; i < counter; i++)
        {
            Shapes[i] = temp[i]; 
        }
        
        Shapes[counter] = s;
    }

    counter++;
}

boundingBoxCorners Figure::getBoundingBox()
{
    float biggestX = Shapes[0]->getXCord()[0], biggestY = Shapes[0]->getYCord()[0], smallestX = Shapes[0]->getXCord()[0], smallestY = Shapes[0]->getXCord()[0];
    for(int x = 0; x < counter; x++)
    {
        for(int i = 0; i < Shapes[x]->getArraySize(); i++)
        {
            if(Shapes[x]->getXCord()[i] > biggestX)
            {
                biggestX = Shapes[x]->getXCord()[i];
            }
            if(Shapes[x]->getYCord()[i] > biggestY)
            {
                biggestY = Shapes[x]->getYCord()[i];
            }
            if(Shapes[x]->getXCord()[i] < smallestX)
            {
                smallestX = Shapes[x]->getXCord()[i];
            }
            if(Shapes[x]->getYCord()[i] < smallestY)
            {
                smallestY = Shapes[x]->getYCord()[i];
            }
        }
    }
    boundingBoxCorners object;
    object.xTopLeft = smallestX;
    object.yTopLeft = biggestY;
    object.xBottomRight = biggestX;
    object.yBottomRight = smallestY;
    return object;
}
