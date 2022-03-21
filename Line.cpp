#include "stdafx.h"
#include "pch.h"
#include "Line.h"

IMPLEMENT_SERIAL(Line, CObject, 1)

Line::Line(CPoint istart, CPoint iend)
	:Shape(istart, iend)
{
}
