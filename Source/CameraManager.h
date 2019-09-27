#pragma once
#include "singleton.h"
class CameraManager :
	public singleton< CameraManager>
{
public:
	CameraManager();
	~CameraManager();

public:
	Vector2 vPos;
	Vector2 vSize;
	Matrix matView;
	Matrix matProj;

	void Update();
	void SetTransform();
};
#define CAMERA (*CameraManager::Instance())

