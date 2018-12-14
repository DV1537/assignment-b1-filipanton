#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "shape.h"
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "polygon.h"
#include "figure.h"

struct OuputCords
{
    float *x;
    float *y;
    int arraySize;
    OuputCords(float *x, float *y, int arraySize)
    {
        this->x = x;
        this->y = y;
        this->arraySize = arraySize;
    }
};

Polygon operator+(Shape &shape, Shape &anotherShape)
    {
        float *ShapeX1 = shape.getXCord();
        float *ShapeY1 = shape.getYCord();
        int arraySize1 = shape.getArraySize();

        float *ShapeX2 = anotherShape.getXCord();
        float *ShapeY2 = anotherShape.getYCord();
        int arraySize2 = anotherShape.getArraySize();
      

        float *newShapeX = new float[arraySize1+arraySize2]{0.0};
        float *newShapeY = new float[arraySize1+arraySize2]{0.0};

        for(int i = 0; i < arraySize1; i++)
        {
            newShapeX[i] = ShapeX1[i];
            newShapeY[i] = ShapeY1[i];
        }
        for(int i = arraySize1; i < arraySize1+arraySize2; i++)
        {
            newShapeX[i] = ShapeX2[i-arraySize1];
            newShapeY[i] = ShapeY2[i-arraySize1];

        }
        int newArraySize = arraySize1+arraySize2;
        Polygon newPolygon(newShapeX, newShapeY, newArraySize);
        
        
        return newPolygon;
    }

std::ostream& operator<<(std::ostream& out, OuputCords object)
{
    for(int i = 0; i < object.arraySize ; i++)
    {
        std::cout << "(" << object.x[i] << "," << object.y[i] << ")\n";
    }

    return out;

}


void xArray(int &xArraySize, float input, int counterX, float *&arrX)
{
    if(counterX == xArraySize)
    {
        arrX[xArraySize -1] = input;
    }
    else
    {
        float *tempArray = new float[xArraySize+1]{0.0};
        for(int i = 0; i < xArraySize; i++)
        {
            tempArray[i] = arrX[i];
        }
        delete[] arrX;
        xArraySize++;
        arrX = new float[xArraySize];
        for(int x = 0; x < xArraySize; x++)
        {
            arrX[x] = tempArray[x];
        }
        arrX[xArraySize-1] = input;

    }
   
    
}


int main()
{
    float input = 0;
    std::string inputString1 = "";
    std::string inputString2 = "";
    int counter = 0;
    int counter2 = 0;
    int counterX = 0;
    int counterY = 0;
    int counterX2 = 0;
    int counterY2 = 0;
    float *arrX = new float[1]{0.0};
    float *arrY = new float[1]{0.0};
    float *arrX2 = new float[1]{0.0};
    float *arrY2 = new float[1]{0.0};
    int xArraySize = 1;
    int yArraySize = 1;
    int xArraySize2 = 1;
    int yArraySize2 = 1;
    std::ifstream myReadFile;
    myReadFile.open("cords");
    getline(myReadFile, inputString1);
    
        std::stringstream stream (inputString1);
        
        while(stream >> input)
        {
            
            
            counter++;

            if(counter % 2 == 0)
            {
                counterY++;
                xArray(yArraySize, input, counterY, arrY);
            }
            else
            {
                counterX++;
                xArray(xArraySize, input, counterX, arrX);
            }

        }
        getline(myReadFile, inputString2);

        std::stringstream stream2 (inputString2);
        
        while(stream2 >> input)
        {
                        
            counter2++;

            if(counter2 % 2 == 0)
            {
                counterY2++;
                xArray(yArraySize2, input, counterY2, arrY2);
            }
            else
            {
                counterX2++;
                xArray(xArraySize2, input, counterX2, arrX2);
            }

        }
    myReadFile.close();
    Polygon object(arrX, arrY, xArraySize);
    Shape *s = &object;
    Polygon object2(arrX2, arrY2, xArraySize2);
    Shape *s2 = &object2;
    Figure fig;
    fig.addShape(s);
    fig.addShape(s2);
    boundingBoxCorners Corners = fig.getBoundingBox();
    std::cout << "Top left: (" << Corners.xTopLeft << ", " << Corners.yTopLeft << ")\n";
    std::cout << "Bottom right: (" << Corners.xBottomRight << ", " << Corners.yBottomRight << ")\n";
        
    getchar();
    return 0;
}