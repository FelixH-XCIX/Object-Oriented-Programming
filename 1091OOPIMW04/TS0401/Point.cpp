#include "Point.h"

void Point::Set(int verticalx, int horizontaly)
{
	vertical = verticalx;
	horizontal = horizontaly;
}

void Point::Move(int x, int y)
{
	horizontal += y;
	vertical += x;
}
void Point::Rotate()
{
	int temp = vertical;
	vertical = horizontal;
	horizontal = (-1) * temp;
}
