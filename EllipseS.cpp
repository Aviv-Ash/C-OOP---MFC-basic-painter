#include "stdafx.h"
#include "pch.h"
#include "EllipseS.h"

IMPLEMENT_SERIAL(EllipseS,CObject,1)
EllipseS::EllipseS(CPoint istart, CPoint iend)
	:Line(istart,iend)
{
}

void EllipseS::Draw(CDC* dc) const
{
	CPoint start = getStart();
	CPoint end = getEnd();
	dc->Ellipse(start.x, start.y, end.x, end.y);
}
