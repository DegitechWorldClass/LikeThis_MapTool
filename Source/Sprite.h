#pragma once
class Sprite
{
	friend class RenderManager;
	friend class PhysicsManager;
public:
	Sprite();
	~Sprite();

private:
	LPDIRECT3DTEXTURE9 lpTexture = nullptr;
	D3DXIMAGE_INFO d3dInfo;
	

public:
	float fWidth;
	float fHeight;
	Vector2 vAnchorPoint;
	Rect reNormalizedRect;

};

