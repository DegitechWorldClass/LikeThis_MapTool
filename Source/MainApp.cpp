#include "DXUT.h"
#include "MainApp.h"


MainApp::MainApp()
{
}


MainApp::~MainApp()
{
}

void MainApp::Init()
{
	RENDER.LoadSprite("OBJECTKINDLIST_ENEMY", "./resource/ObjectKindList/Enemy.png");
	RENDER.LoadSprite("UI_LOADFILE", "./resource/UI/LoadFile.png");
	RENDER.LoadSprite("UI_SAVEFILE", "./resource/UI/SaveFile.png");
	RENDER.LoadSprite("UI_OBJECTKINDLIST", "./resource/UI/ObjectKindList.png");
	RENDER.LoadSprite("UI_OBJECTLIST", "./resource/UI/ObjectList.png");
	RENDER.LoadSprite("UI_INSPECTOR", "./resource/UI/Inspector.png");

	

	Button * UI_SaveFile = new Button();
	UI_SaveFile->Init(IMAGE("UI_SAVEFILE"), Vector2(115, 750), ButtonType::Coloring, [this]() {OnSaveButtonClick(); });
	mapButton.insert(make_pair("SAVEFILE", UI_SaveFile));


	Button * UI_LoadFile = new Button();
	UI_LoadFile->Init(IMAGE("UI_LOADFILE"), Vector2(1465, 750), ButtonType::Coloring, [this]() {OnLoadButtonClick(); });
	mapButton.insert(make_pair("LOADFILE", UI_LoadFile));

}

void MainApp::Update()
{
	INPUT.Update();
	CAMERA.Update();
	
	for (auto iter : mapButton)
	{
		iter.second->Update();
	}
}

void MainApp::Render()
{
	CAMERA.SetTransform();

	RENDER.RenderLine({ 0,0 }, { i,0 }, 50, D3DCOLOR_ARGB(255, 100, 100,100));
	RENDER.Begin(true);
	RENDER.PrintText(L"FDGDFGD¤»fdksgfgfinsdifnspi", { 0,0 }, 50, 0,false,D3DCOLOR_ARGB(255,155,255,255));
	RENDER.End();

	RENDER.Begin(false);
	for (auto iter : mapButton)
	{
		iter.second->Render();
	}
	RENDER.RenderSprite(IMAGE("UI_OBJECTLIST"), Vector2(115 , 300));
	RENDER.RenderSprite(IMAGE("UI_INSPECTOR"), Vector2(1465 , 300));
	RENDER.RenderSprite(IMAGE("UI_OBJECTKINDLIST"), Vector2(780, 750));
	RENDER.End();

}

void MainApp::Release()
{
	RENDER.ReleaseInstance();
	CAMERA.ReleaseInstance();
	INPUT.ReleaseInstance();
	PHYSICS.ReleaseInstance();
	MATH.ReleaseInstance();

	for (auto iter : mapButton)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	mapButton.clear();
}

void MainApp::OnLostDevice()
{
	RENDER.OnLostDevice();
}

void MainApp::OnResetDevice()
{
	RENDER.OnResetDevice();
}

void MainApp::OnLoadButtonClick()
{
	OPENFILENAME OFN;
	TCHAR lpstrFile[MAX_PATH] = L"";
	memset(&OFN, 0, sizeof(OPENFILENAME));
	OFN.lStructSize = sizeof(OPENFILENAME);
	OFN.hwndOwner = DXUTGetHWND();
	OFN.lpstrFilter = L"Map Data File\0*.txt;\0";
	OFN.lpstrFile = lpstrFile;
	OFN.nMaxFile = 256;
	if (GetOpenFileName(&OFN) != 0) {

	}
}

void MainApp::OnSaveButtonClick()
{
	char szFile[260] = "";

	OPENFILENAMEA ofn;

	ZeroMemory(&ofn, sizeof(OPENFILENAMEA));

	ofn.lStructSize = sizeof(OPENFILENAMEA);

	ofn.hwndOwner = NULL;

	ofn.lpstrFile = szFile;

	ofn.nMaxFile = sizeof(szFile);

	ofn.lpstrFilter = "Avi Files(*.avi)\0*.avi\0All Files (*.*)\0*.*\0";

	ofn.nFilterIndex = 1;

	ofn.lpstrFileTitle = NULL;

	ofn.nMaxFileTitle = 0;

	ofn.lpstrInitialDir = NULL;

	ofn.Flags = OFN_OVERWRITEPROMPT;

	if (::GetSaveFileNameA(&ofn) == false) return;

}
