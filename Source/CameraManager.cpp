#include "DXUT.h"
#include "CameraManager.h"


CameraManager::CameraManager()
{
	vSize = Vector2(WINSIZEX, WINSIZEY);
	vPos = ScreenCenter;
	D3DXMatrixOrthoLH(&matProj, vSize.x, -vSize.y, 0, 1);
	matView = Matrix(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-vPos.x, -vPos.y, 0, 1);
	g_Device->SetTransform(D3DTS_PROJECTION, &matProj);
	g_Device->SetTransform(D3DTS_VIEW, &matView);
}


CameraManager::~CameraManager()
{

}

void CameraManager::Update()
{
	Rect(230, 0, 1330, 600);
	D3DXMatrixOrthoLH(&matProj, vSize.x, -vSize.y, 0, 1);
	matView = Matrix(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-vPos.x, -vPos.y, 0, 1);
}

void CameraManager::SetTransform()
{
	g_Device->SetTransform(D3DTS_PROJECTION, &matProj);
	g_Device->SetTransform(D3DTS_VIEW, &matView);
}
