#include "DXUT.h"
#include "InputManager.h"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::Update()
{
	memcpy(LastInput, CurInput, sizeof(CurInput));

	for (int i = 0; i < 256; i++)
	{
		if (GetAsyncKeyState(i))
		{
			CurInput[i] = true;
		}
		else CurInput[i] = false;
	}

	POINT ptMouse;
	GetCursorPos(&ptMouse);
	ScreenToClient(DXUTGetHWND(), &ptMouse);

	 vMousePos = Vector2(ptMouse.x, ptMouse.y);
}

bool InputManager::KeyUp(int _KeyCode)
{
	return !CurInput[_KeyCode] && LastInput[_KeyCode];
}

bool InputManager::KeyDown(int _KeyCode)
{
	return CurInput[_KeyCode] && !LastInput[_KeyCode];
}

bool InputManager::KeyPress(int _KeyCode)
{
	return CurInput[_KeyCode] && LastInput[_KeyCode];
}

