#include "DXUT.h"
#include "Button.h"


Button::Button()
{
}


Button::~Button()
{
}

void Button::Init(Sprite * _pSprite, Vector2 _vPos, ButtonType _Type, function<void()> _OnClickFunc)
{

	this->vScale = Vector2(1.f, 1.f);
	this->vPos = _vPos;
	this->pSprite = _pSprite;
	this->Status = ButtonStatus::BS_IDLE;
	this->reRect = Rect(
		_vPos.x - _pSprite->fWidth/2.f, _vPos.y - _pSprite->fHeight / 2.f,  
		_vPos.x + _pSprite->fWidth / 2.f, _vPos.y + _pSprite->fHeight / 2.f);

	this->Type = _Type;
	this->RenderColor = D3DXCOLOR(1.f, 1.f, 1.f, 1.f);
	this->OnClick = _OnClickFunc;
}

void Button::Update()
{
	Vector2 MousePos = INPUT.GetMousePos();


	if (PHYSICS.CheckCollision(MousePos, reRect))
	{
		this->Status = ButtonStatus::BS_ONCURSOR;

		if (INPUT.KeyDown(VK_LBUTTON))
		{
			OnClick();
		}
	}
	else this->Status = ButtonStatus::BS_IDLE;

	if (Type == ButtonType::Scaling)
	{
		if (this->Status == ButtonStatus::BS_ONCURSOR)
		{
			MATH.Lerp(&this->vScale, this->vScale, Vector2(1.1f, 1.1f), FixedDeltaTime *12);
		}
		else
		{
			MATH.Lerp(&this->vScale, this->vScale, Vector2(1.f, 1.f), FixedDeltaTime * 12);
		}
	}
	else if (Type == ButtonType::Coloring)
	{
		if (this->Status == ButtonStatus::BS_ONCURSOR)
		{
			D3DXColorLerp(&RenderColor, &RenderColor, &D3DXCOLOR(0.4f, 0.4f, 0.4f, 1.f), FixedDeltaTime * 12);
		}
		else
		{
			D3DXColorLerp(&RenderColor, &RenderColor, &D3DXCOLOR(1.f, 1.f, 1.f, 1.f), FixedDeltaTime * 12);
		}
	}

}

void Button::Render()
{
	RENDER.RenderSprite(this->pSprite, this->vPos, this->vScale,0.f,D3DCOLOR_ARGB((INT)(RenderColor.a * 255.f), (INT)(RenderColor.r * 255.f), (INT)(RenderColor.g* 255.f), (INT)(RenderColor.b * 255.f)));
}

void Button::Release()
{
}
