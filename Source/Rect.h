#pragma once
class Rect
{
public:
	FLOAT Left;
	FLOAT Top;
	FLOAT Right;
	FLOAT Bottom;
public:
	Rect();
	~Rect();
	Rect(FLOAT _fLeft, FLOAT _fTop, FLOAT _fRight, FLOAT _fBottom);
	Rect(Vector2 _vPos, FLOAT _fWidth, FLOAT _fHeight);
	Rect(RECT _reRect);
	Rect(Vector2 _vVertex[4]);


	void operator *=(float _fScala)
	{
		this->Bottom *= _fScala;
		this->Left *= _fScala;
		this->Top *= _fScala;
		this->Right *= _fScala;
	}
	Rect operator *(float _fScala)
	{
		Rect re = *this;
		re.Bottom *= _fScala;
		re.Left *= _fScala;
		re.Top *= _fScala;
		re.Right *= _fScala;
		return re;
	}
	operator RECT() const
	{
		return
		{
			(LONG)Left,
			(LONG)Top,
			(LONG)Right,
			(LONG)Bottom
		};
	}
	float	GetWidth() { return fabsf(Right - Left); }
	float	GetHeight() { return fabsf(Bottom - Top); }
	Vector2 GetLT() { return Vector2(Left, Top); }
	Vector2 GetRT() { return Vector2(Right, Top); }
	Vector2 GetLB() { return Vector2(Left, Bottom); }
	Vector2 GetRB() { return Vector2(Right, Bottom); }
	Vector2 GetCenter() { return Vector2(Left + (Right - Left) / 2, Top + (Bottom - Top) / 2); }
};

