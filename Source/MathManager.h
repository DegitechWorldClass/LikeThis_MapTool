#pragma once
#include "singleton.h"
class MathManager :
	public singleton< MathManager>
{
public:
	MathManager();
	~MathManager();

public :
	const float PI = 3.141592f;


	double absDotVector(Vector2 a, Vector2 b);
	__inline double DegToRad(double deg);
	__inline double RadToDeg(double rad);
	Vector2 GetDistanceVector(Rect a, Rect b);
	Vector2 GetHeightVector(Rect a, float _fRot);
	Vector2 GetWidthVector(Rect a, float _fRot);
	Vector2 GetUnitVector(Vector2 a);
	Vector2 RotateVector(Vector2 _vCenter,
		Vector2 _vPoint,
		float _fDegree);
	INT GetRandomNum(INT _Min, INT _Max);
	FLOAT GetRandomNum(FLOAT _Min, FLOAT _Max);
	FLOAT GetLength(Vector2 v1, Vector2 v2);

	template <typename T>
	void Lerp(T* target, const T& start, const T& end, float speed)
	{
		*target = start + (end - start) * speed;
	}

};

#define MATH (*MathManager::Instance())