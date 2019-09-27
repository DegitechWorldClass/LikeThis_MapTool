#include "DXUT.h"
#include "MathManager.h"


MathManager::MathManager()
{
}


MathManager::~MathManager()
{
}

double MathManager::absDotVector(Vector2 a, Vector2 b)
{
	return abs(a.x * b.x + a.y * b.y);
}

double MathManager::DegToRad(double deg)
{
	return deg / 180 * 3.141592;
}

double MathManager::RadToDeg(double rad)
{
	return rad * 180 / 3.141592;

}

Vector2 MathManager::GetDistanceVector(Rect a, Rect b)
{
	Vector2 ret;
	ret.x = (a.Left + (a.Right - a.Left) / 2) - (b.Left + (b.Right - b.Left) / 2);
	ret.y = (a.Top + (a.Bottom - a.Top) / 2) - (b.Top + (b.Bottom - b.Top) / 2);
	return ret;
}

Vector2 MathManager::GetHeightVector(Rect a, float _fRot)
{
	Vector2 ret;
	ret.x = (a.Bottom - a.Top) * cos(DegToRad(_fRot - 90)) / 2;
	ret.y = (a.Bottom - a.Top) * sin(DegToRad(_fRot - 90)) / 2;
	return ret;
}

Vector2 MathManager::GetWidthVector(Rect a, float _fRot)
{
	Vector2 ret;
	ret.x = (a.Right - a.Left) * cos(DegToRad(_fRot)) / 2;
	ret.y = (a.Right - a.Left) * sin(DegToRad(_fRot)) / 2;
	return ret;
}

Vector2 MathManager::GetUnitVector(Vector2 a)
{
	Vector2 ret;
	double size;
	size = sqrtf(pow(a.x, 2) + pow(a.y, 2));
	ret.x = a.x / size;
	ret.y = a.y / size;
	return ret;
}

Vector2 MathManager::RotateVector(Vector2 _vCenter, Vector2 _vPoint, float _fDegree)
{
	float rad = DegToRad(_fDegree);
	float rx = (_vPoint.x - _vCenter.x)*cosf(rad) - (_vPoint.y - _vCenter.y)*sinf(rad) + _vCenter.x;
	float ry = (_vPoint.x - _vCenter.x)*sinf(rad) + (_vPoint.y - _vCenter.y)*cosf(rad) + _vCenter.y;
	return { rx , ry };
}

INT MathManager::GetRandomNum(INT _Min, INT _Max)
{
	//시드 설정
	random_device RndDevice;
	mt19937_64 rnd(RndDevice());

	//분포 설정
	uniform_int_distribution<int> range(_Min, _Max);

	//값 추출
	return range(rnd);
}

FLOAT MathManager::GetRandomNum(FLOAT _Min, FLOAT _Max)
{
	INT min = (INT)(_Min * 1000);
	INT max = (INT)(_Max * 1000);
	//시드 설정
	random_device RndDevice;
	mt19937_64 rnd(RndDevice());

	//분포 설정
	uniform_int_distribution<int> range(min, max);

	//값 추출
	return (FLOAT)(range(rnd) / 1000.f);
}

FLOAT MathManager::GetLength(Vector2 v1, Vector2 v2)
{
	float y = fabsf(v2.y - v1.y);
	float x = fabsf(v2.x - v1.x);

	return x + y;
}
