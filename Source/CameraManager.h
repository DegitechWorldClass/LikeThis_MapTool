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
	
	Rect    reScreen; // ����ȭ�� ���� Rect
	Rect	reReal; // ����ȭ�� ���� Rect

	Matrix matView;

	Matrix matProj;

	void Update();
	void SetTransform();
};
#define CAMERA (*CameraManager::Instance())

