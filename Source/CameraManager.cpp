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

	this->reReal = Rect(
		vPos.x - (WINSIZEX / 2.f),
		vPos.y - (WINSIZEY / 2.f),
		vPos.x + (WINSIZEX / 2.f),
		vPos.y + (WINSIZEY / 2.f));

	this->reScreen = Rect(
		reReal.Left + 230,
		reReal.Top,
		reReal.Right - 270,
		reReal.Bottom - 300);
}


CameraManager::~CameraManager()
{

}

void CameraManager::Update()
{
	this->reReal = Rect(
		vPos.x - (WINSIZEX / 2.f),
		vPos.y - (WINSIZEY / 2.f),
		vPos.x + (WINSIZEX / 2.f),
		vPos.y + (WINSIZEY / 2.f));

	this->reScreen = Rect(
		reReal.Left + 230,
		reReal.Top,
		reReal.Right - 270,
		reReal.Bottom - 300);

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
