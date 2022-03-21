#pragma once
#include "Shape.h"
class Line: public Shape
{
	DECLARE_SERIAL(Line)
public:
	Line() {};
	Line(CPoint istart, CPoint iend);
};

