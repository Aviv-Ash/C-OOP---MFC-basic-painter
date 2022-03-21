#pragma once
#include "Line.h"
class RectangleS: public Line
{
	DECLARE_SERIAL(RectangleS)
public:
	RectangleS() {};
	RectangleS(CPoint istart, CPoint iend);
	void Draw(CDC* dc) const;

};

