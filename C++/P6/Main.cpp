#include "JiJ_P6.h"
#include "JiJ_P6.cpp"
#include <iostream>
using namespace std;

int main()
{
	Circle c(2);
	Rectangle rec(3,4);
	
	cout << rec.getName() << " has width " << rec.getWidth() << " has height " << rec.getHeight()<< " and area "<< rec.getArea() <<endl;
	
	rec.setWidth(5);
	rec.setHeight(5);
	rec.setName("Square");
	
	cout << rec.getName() << " has width " << rec.getWidth() << " has height " << rec.getHeight()<< " and area "<< rec.getArea() <<endl;
	
	cout << c.getName() << " has radius " <<c.getRadius() << " and has area " << c.getArea() << endl;
	
	c.setRadius(5);
	
	cout << c.getName() << " has radius " <<c.getRadius() << " and has area " << c.getArea() << endl;

	
}
