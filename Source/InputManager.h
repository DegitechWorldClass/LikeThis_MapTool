#pragma once
#include "singleton.h"
class InputManager :
	public singleton< InputManager>
{
public:
	InputManager();
	~InputManager();

public:
	void Update();
	bool KeyUp(int _KeyCode);
	bool KeyDown(int _KeyCode);
	bool KeyPress(int _KeyCode);

	Vector2 GetMousePos() { return vMousePos; }
private:
	Vector2 vMousePos;
	bool CurInput[256];
	bool LastInput[256];
};
#define INPUT (*InputManager::Instance())
