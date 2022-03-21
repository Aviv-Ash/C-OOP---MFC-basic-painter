#include "stdafx.h"
#include "pch.h"
#include "Shape.h"

IMPLEMENT_SERIAL(Shape, CObject, 1)
void Shape::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())//storing
	{
		//ADD STORING/LOADING TO CLOLRS TOO!!
		ar << mStart;
		ar << mEnd;
	}
	else // Loading
	{
		ar >> mStart;
		ar >> mEnd;
	}
}

void Shape::Draw(CDC* dc) const
{
	dc->MoveTo(mStart.x, mStart.y);
	dc->LineTo(mEnd.x, mEnd.y);
}

bool Shape::isInside(const CPoint& ipoint) const
{
	return (mStart.x <= ipoint.x && ipoint.x <= mEnd.x || mStart.x >= ipoint.x && ipoint.x >= mEnd.x) &&
		(mStart.y <= ipoint.y && ipoint.y <= mEnd.y || mStart.y >= ipoint.y && ipoint.y >= mEnd.y);
}

void Shape::Shift(int dx, int dy)
{
	mStart = mStart + CPoint(dx, dy);
	mEnd = mEnd + CPoint(dx, dy);
}
