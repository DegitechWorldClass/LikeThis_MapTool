#include "DXUT.h"
#include "RenderManager.h"


RenderManager::RenderManager()
{
	if (!lpSprite)
		D3DXCreateSprite(g_Device, &lpSprite);

	if (!lpFont)
		D3DXCreateFontW(g_Device, 40, 0, 0, 1,
			FALSE, HANGUL_CHARSET, 0, 0, 0, L"¸¼Àº °íµñ Bold", &lpFont);

	if (!lpLine)
		D3DXCreateLine(g_Device, &lpLine);
}


RenderManager::~RenderManager()
{
	for (auto iter : mapSprite)
	{
		SAFE_DELETE(iter.second);
	}
	mapSprite.clear();
	SAFE_RELEASE(lpSprite);
	SAFE_RELEASE(lpFont);
	SAFE_RELEASE(lpLine);

}

Sprite * RenderManager::FindSprite(const string & _Key)
{
	auto find = mapSprite.find(_Key);

	if (find != mapSprite.end())
	{
		return find->second;
	}

	return nullptr;
}

void RenderManager::Begin(bool isInterface)
{
	if (TRUE == isInterface)
	{
		lpSprite->Begin(D3DXSPRITE_ALPHABLEND);
	}
	else lpSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}

void RenderManager::End()
{
	lpSprite->End();
}

void RenderManager::ReBegin(bool isInterface)
{
	End();
	Begin(isInterface);
}

void RenderManager::PrintText(wstring _Str, Vector2 _Pos, int _Size, float _Degree, bool _Center, D3DCOLOR _Color)
{
	D3DXMATRIX matWorld, matTrans, matRot;
	D3DXMatrixRotationZ(&matRot, D3DXToRadian(_Degree));

	if (!_Center)
		D3DXMatrixTranslation(&matTrans, _Pos.x, _Pos.y, 0);
	else
		D3DXMatrixTranslation(&matTrans, _Pos.x - _Size * (_Str.size() * 0.25), _Pos.y - _Size / 2.f, 0);

	matWorld = matRot * matTrans;
	lpSprite->SetTransform(&matWorld);
	lpFont->DrawTextW(lpSprite, _Str.c_str(), _Str.size(), NULL, DT_CENTER | DT_NOCLIP, _Color);

}

void RenderManager::RenderLine(Vector2 _Start, Vector2 _End, float _Width, D3DCOLOR _Color, float _Rot, Vector2 _Center)
{
 	Vector3 vPos[2] = { {_End.x - _Center.x ,_End.y - _Center.y,1.f},{_Start.x - _Center.x,_Start.y - _Center.y,1.f} };
	Matrix matWorld, matScale, matRotation, matTransformation;
	D3DXMatrixScaling(&matScale, 1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotation, D3DXToRadian(_Rot));
	D3DXMatrixTranslation(&matTransformation, (-(WINSIZEX / 2.f) + _Center.x), (-(WINSIZEY / 2.F) + _Center.y), 0.f);
	matWorld = matScale * matRotation * matTransformation;
	lpLine->SetWidth(_Width);
	lpLine->SetAntialias(true);
	lpLine->DrawTransform(vPos, 2, &(matWorld * CAMERA. matProj), _Color);
	//lpLine->End();

}

void RenderManager::RenderSprite(Sprite * _pSprite, Vector2 _vPos, Vector2 _vScale, float _fDegree, Color _Color)
{
	Vector3 vCenter = Vector3(
		_pSprite->fWidth * _pSprite->vAnchorPoint.x ,
		_pSprite->fHeight * _pSprite->vAnchorPoint.y,
		0.f);

	Matrix matWorld, matScale, matRotation, matTransformation;

	D3DXMatrixScaling(&matScale, _vScale.x, _vScale.y, 1.f);

	D3DXMatrixRotationZ(&matRotation, MATH.DegToRad(_fDegree));

	D3DXMatrixTranslation(&matTransformation, _vPos.x, _vPos.y, 0.f);

	matWorld =  matRotation * matScale * matTransformation;

	lpSprite->SetTransform(&matWorld);
	 
	Rect RenderRect(_pSprite->fWidth * _pSprite->reNormalizedRect.Left,
		_pSprite->fHeight * _pSprite->reNormalizedRect.Top,
		_pSprite->fWidth * _pSprite->reNormalizedRect.Right,
		_pSprite->fHeight * _pSprite->reNormalizedRect.Bottom);
	
	lpSprite->Draw (_pSprite->lpTexture, &(RECT)RenderRect, &vCenter, nullptr, _Color);
}

HRESULT RenderManager::LoadSprite(const string & _Key, const string & _Path)
{
	Sprite * pSprite = new Sprite();
	if (S_OK == D3DXCreateTextureFromFileExA(
		g_Device,
		_Path.c_str(),
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		0,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0,
		&pSprite->d3dInfo,
		nullptr,
		&pSprite->lpTexture
	))
	{
		mapSprite.insert(make_pair(_Key, pSprite));
		pSprite->fHeight = pSprite->d3dInfo.Height;
		pSprite->fWidth = pSprite->d3dInfo.Width;

		return S_OK;
	}
	SAFE_DELETE(pSprite);
	return E_FAIL;
}

void RenderManager::OnLostDevice()
{
	lpLine->OnLostDevice();
	lpFont->OnLostDevice();
	lpSprite->OnLostDevice();
}

void RenderManager::OnResetDevice()
{
	lpLine->OnResetDevice();
	lpFont->OnResetDevice();
	lpSprite->OnResetDevice();
}
