#include "JiJ_P6.h"
#include <iostream>

using namespace std;

Shape::Shape()
{
	name = "";
}
Shape::Shape(string name)
{
	this->name = name;
}
string Shape::getName()
{
	return this->name;
}
void Shape::setName(string newName)
{
	this->name = newName;
}


Circle::Circle() : Shape("Circle"), radius(0)
{
}
Circle::Circle(int theRadius) : Shape("Circle"),radius(theRadius)
{ 
}
void Circle::setRadius(int newRadius)
{
    this->radius = newRadius;
}
double Circle::getRadius()
{ 
    return radius;
}  
double Circle::getArea()
{        
	return 3.14159 * radius * radius;
}  


Rectangle::Rectangle() : Shape("Rectangle"), height(0), width(0) //default constructor that sets shape name to "Rectangle"
{
}
Rectangle::~Rectangle()  //destructor
{
}
Rectangle::Rectangle(int a, int b) : Shape("Rectangle"), height(a), width(b)    //parameterized constructor that sets shape name to "Rectangle"
{
}
int Rectangle::getWidth()  //return width of rectangle
{
	return width;
}
int Rectangle::getHeight() //return height of rectangle
{
	return height;
}
void Rectangle::setHeight(int newHeight)  //change height of rectangle
{
	height = newHeight;
}
void Rectangle::setWidth(int newWidth) //change width of rectangle
{
	width = newWidth;
}
double Rectangle::getArea()  //return area of rectangle
{
	return height * width;
}

