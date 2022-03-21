#include "stdafx.h"
#include "pch.h"
#include "TriangleS.h"

IMPLEMENT_SERIAL(TriangleS, CObject, 1)

TriangleS::TriangleS(CPoint istart, CPoint iend)
	:Shape(istart, iend)
{
}

void TriangleS::Draw(CDC* dc) const
{
	CPoint TPoints[3];
	TPoints[0].SetPoint(mStart.x, mEnd.y);
	TPoints[1].SetPoint(mEnd.x, mEnd.y);
	TPoints[2].SetPoint((mStart.x + mEnd.x) / 2, mStart.y);

	dc->Polygon(TPoints, 3);
}
