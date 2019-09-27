#include "DXUT.h"
#include "Rect.h"


Rect::Rect()
{
}


Rect::~Rect()
{
}

Rect::Rect(FLOAT _fLeft, FLOAT _fTop, FLOAT _fRight, FLOAT _fBottom)
	: Left(_fLeft), Top(_fTop), Right(_fRight), Bottom(_fBottom)
{
}

Rect::Rect(Vector2 _vPos, FLOAT _fWidth, FLOAT _fHeight)
	: Left(_vPos.x), Top(_vPos.y), Right(_vPos.x + _fWidth), Bottom(_vPos.y + _fHeight)
{
}

Rect::Rect(RECT _reRect)
	: Rect((FLOAT)_reRect.left,
	(FLOAT)_reRect.top,
		(FLOAT)_reRect.right,
		(FLOAT)_reRect.bottom) {
}

Rect::Rect(Vector2 _vVertex[4])
{
	Left = _vVertex[0].x;
	Top = _vVertex[0].y;
	Right = _vVertex[2].x;
	Bottom = _vVertex[2].y;
}
