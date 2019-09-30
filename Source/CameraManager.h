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
	
	Rect    reScreen; // 렌더화면 기준 Rect
	Rect	reReal; // 실제화면 기준 Rect

	Matrix matView;

	Matrix matProj;

	void Update();
	void SetTransform();
};
#define CAMERA (*CameraManager::Instance())

