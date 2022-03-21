#pragma once
#include "Shape.h"
class TriangleS :public Shape
{

	DECLARE_SERIAL(TriangleS)
public:
	TriangleS() {};
	TriangleS(CPoint istart, CPoint iend);
	void Draw(CDC* dc) const;
};

