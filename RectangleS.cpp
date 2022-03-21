#include "stdafx.h"
#include "pch.h"
#include "RectangleS.h"

IMPLEMENT_SERIAL(RectangleS, CObject, 1)
RectangleS::RectangleS(CPoint istart, CPoint iend)
	:Line(istart,iend)
{
}

void RectangleS::Draw(CDC* dc) const
{
	CPoint start = getStart();
	CPoint end = getEnd();
	dc->Rectangle(start.x, start.y, end.x, end.y);
}
