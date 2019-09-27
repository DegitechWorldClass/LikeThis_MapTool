#pragma once
#include "singleton.h"
class PhysicsManager :
	public singleton< PhysicsManager>
{
public:
	PhysicsManager();
	~PhysicsManager();

	bool GetPixelCollision(Sprite * _pTexture, Rect _Box, D3DXCOLOR _Color = D3DXCOLOR(1.f, 1.f, 1.f, 1.f));

	bool GetPixelCollision(Sprite * _pTexture, Vector2 _Pos, D3DXCOLOR _Color = D3DXCOLOR(1.f, 1.f, 1.f, 1.f));

	bool CheckCollision(const Rect& _reRect, const Vector2& _vPos);

	bool CheckCollision(const Vector2& _vPos, const Rect& _reRect);

	bool CheckCollision(const Rect& _reRect01, const Rect& _reRect02);

	bool CheckCollision(const Rect& _reRect01, float _fRot01, const Rect& _reRect02, float _fRot02);
};

#define PHYSICS (*PhysicsManager::Instance())