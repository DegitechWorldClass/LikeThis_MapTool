#pragma once
#include "singleton.h"
class Sprite;
class RenderManager :
	public singleton<RenderManager>
{
public:
	RenderManager();
	~RenderManager();
private:
	map <string, Sprite*> mapSprite;
	map<string, LPD3DXFONT> mapFont; 
	
	LPD3DXSPRITE	lpSprite = NULL;
	LPD3DXFONT		lpFont = NULL;
	LPD3DXLINE		lpLine = NULL;
public:
	Sprite * FindSprite(const string& _Key);

	void Begin(bool isInterface);
	void End();
	void ReBegin(bool isInterface);
	//void AddFont(string _Key, string _Font);
	void PrintText(wstring _Str, Vector2 _Pos, int _Size, float _Degree, bool _Center, D3DCOLOR _Color);
	void RenderLine(Vector2 _Start, Vector2 _End, float _Width, D3DCOLOR _Color, float _Rot = 0.f, Vector2 _Center = Vector2(0, 0));
	void RenderSprite(Sprite * _pSprite, Vector2 _vPos, Vector2 _vScale = Vector2(1.f,1.f), float _fDegree = 0.f, Color _Color = D3DCOLOR_ARGB(255,255,255,255));

	HRESULT LoadSprite(const string& _Key, const string& _Path);
public:
	void OnLostDevice();
	void OnResetDevice();

};

#define RENDER (*RenderManager::Instance())
#define IMAGE (*RenderManager::Instance()).FindSprite

