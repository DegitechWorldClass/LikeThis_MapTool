#include "DXUT.h"
#include "Sprite.h"


Sprite::Sprite()
{
	this->vAnchorPoint = Vector2(0.5f, 0.5f);
	this->reNormalizedRect = Rect(0.f, 0.f, 1.f, 1.f);
}


Sprite::~Sprite()
{
	SAFE_RELEASE(lpTexture);
}
