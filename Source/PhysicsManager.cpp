#include "DXUT.h"
#include "PhysicsManager.h"


PhysicsManager::PhysicsManager()
{
}


PhysicsManager::~PhysicsManager()
{
}

bool PhysicsManager::GetPixelCollision(Sprite * _pTexture, Rect _Box, D3DXCOLOR _Color)
{
	D3DLOCKED_RECT LockRect;

	_pTexture->lpTexture->LockRect(0, &LockRect, 0, D3DLOCK_DISCARD);

	DWORD* pColor = (DWORD*)LockRect.pBits; // 잠금후 픽셀 값 받아오기

	for (int i = _Box.Top; i < _Box.Bottom; i++)
	{
		for (int j = _Box.Left; j < _Box.Right; i++)
		{
			D3DXCOLOR col = pColor[_pTexture->d3dInfo.Width * i + j];

			if (col == _Color)
			{
				_pTexture->lpTexture->UnlockRect(0); //  잠금 해제
				return true;
			}
		}
	}
	_pTexture->lpTexture->UnlockRect(0); //  잠금 해제
	return false;
}

bool PhysicsManager::GetPixelCollision(Sprite * _pTexture, Vector2 _Pos, D3DXCOLOR _Color)
{
	D3DLOCKED_RECT LockRect;

	_pTexture->lpTexture->LockRect(0, &LockRect, 0, D3DLOCK_DISCARD);

	DWORD* pColor = (DWORD*)LockRect.pBits; // 잠금후 픽셀 값 받아오기

	D3DXCOLOR col = pColor[_pTexture->d3dInfo.Width * (INT)_Pos.y + (INT)_Pos.x];

	bool Collision = false;
	if (col == _Color)
		Collision = true;

	_pTexture->lpTexture->UnlockRect(0); //  잠금 해제
	return Collision;
}

bool PhysicsManager::CheckCollision(const Rect & _reRect, const Vector2 & _vPos)
{
	return (_reRect.Left < _vPos.x &&
		_reRect.Top < _vPos.y &&
		_reRect.Right > _vPos.x &&
		_reRect.Bottom > _vPos.y);
}

bool PhysicsManager::CheckCollision(const Vector2 & _vPos, const Rect & _reRect)
{
	return CheckCollision(_reRect, _vPos);
}

bool PhysicsManager::CheckCollision(const Rect & _reRect01, const Rect & _reRect02)
{
	return (_reRect01.Left < _reRect02.Right &&
		_reRect01.Top <  _reRect02.Bottom &&
		_reRect01.Right > _reRect02.Left &&
		_reRect01.Bottom > _reRect02.Bottom);
}

bool PhysicsManager::CheckCollision(const Rect & _reRect01, float _fRot01, const Rect & _reRect02, float _fRot02)
{
	Vector2 dist = MATH.GetDistanceVector(_reRect01, _reRect02);
	Vector2 vec[4] = { MATH.GetHeightVector(_reRect01,_fRot01),  MATH.GetHeightVector(_reRect02,_fRot02),  MATH.GetWidthVector(_reRect01,_fRot01),  MATH.GetWidthVector(_reRect02,_fRot02) };

	Vector2 unit;
	for (int i = 0; i < 4; i++) {
		double sum = 0;
		unit = MATH.GetUnitVector(vec[i]);
		for (int j = 0; j < 4; j++) {
			sum += MATH.absDotVector(vec[j], unit);
		}
		if (MATH.absDotVector(dist, unit) > sum) {
			return false;
		}
	}
	return true;
}
