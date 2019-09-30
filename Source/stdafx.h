#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <random>
#include <algorithm>
#include <string>
#include <thread>



using Vector2 = D3DXVECTOR2;
using Vector3 = D3DXVECTOR3;
using Matrix = D3DXMATRIX;
using Color = D3DCOLOR;

#define g_Device DXUTGetD3D9Device()

const float WINSIZEX = 1600;
const float WINSIZEY = 900;
#define DeltaTime DXUTGetElapsedTime()
#define FixedDeltaTime 0.02f

const Vector2 ScreenCenter = Vector2(WINSIZEX/2.f, WINSIZEY/2.f);
const Vector2 Zero = Vector2(0, 0);
const Vector2 Left = Vector2(-1, 0);
const Vector2 Right = Vector2(1, 0);
const Vector2 Top = Vector2(0, -1);
const Vector2 Bottom = Vector2(0, 1);
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif
using namespace std;
#include "Rect.h"
#include "Sprite.h"

#include "Button.h"

#include "RenderManager.h"
#include "CameraManager.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "MathManager.h"

