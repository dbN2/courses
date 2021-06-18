#ifndef JIJ_P6_H
#define JIJ_P6_H

#include <iostream>
using namespace std;

class Shape
{
	public:
		Shape();
		Shape(string name);
		string getName();
		void setName(string newName);
		virtual double getArea() = 0;
	private:
		string name;
};
	
	
class Circle : public Shape
{
	public:
		Circle();
		Circle(int theRadius);
		void setRadius(int newRadius);
		double getRadius();
		virtual double getArea();
	private:
		int radius;
};

class Rectangle : public Shape
{
	private:
		int width;
		int height;
	public:
		Rectangle();
		~Rectangle();
		Rectangle(int a, int b);
		int getWidth();
		int getHeight();
		void setHeight(int newHeight);
		void setWidth(int newWidth);
		virtual double getArea();
};
		
#endif
