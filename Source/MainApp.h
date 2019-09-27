#pragma once
class MainApp
{
public:
	MainApp();
	~MainApp();

public:
	void Init();
	void Update();
	void Render();
	void Release();

	void OnLostDevice();
	void OnResetDevice();
	float i = 1280;
	map <string , Button *> mapButton;


};

