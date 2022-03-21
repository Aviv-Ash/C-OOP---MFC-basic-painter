#pragma once
#include "Line.h"
class EllipseS: public Line
{
	DECLARE_SERIAL(EllipseS)
public:
	EllipseS() {};
	EllipseS(CPoint istart, CPoint iend);
	void Draw(CDC* dc) const;
};

