#include "stdafx.h"
#pragma once
class Shape:public CObject{
	DECLARE_SERIAL(Shape)
	CPoint mStart;
	CPoint mEnd;
public:
	Shape() {};
	Shape(CPoint istart, CPoint iend) :
		mStart(istart), mEnd(iend)
	{
	}
	void Serialize(CArchive& ar);
	virtual void Draw(CDC* dc) const;
	CPoint getStart() const { return mStart; };
	CPoint getEnd() const { return mEnd; };

	virtual void Redefine(CPoint istart, CPoint iend) { mStart = istart;mEnd =iend ; }
	virtual bool isInside(const CPoint& ipoint) const;
	virtual void Shift(int dx, int dy);

};

