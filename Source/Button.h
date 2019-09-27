#pragma once
enum class ButtonStatus {BS_IDLE, BS_ONCURSOR};
enum class ButtonType {Scaling, Coloring};
class Button
{
public:
	Button();
	~Button();
	
public:
	void Init(Sprite * _pSprite,Vector2 _vPos, ButtonType _Type);
	void Update();
	void Render();
	void Release();

private:
	Sprite * pSprite = nullptr;
	Rect reRect;
	Vector2 vPos;
	Vector2 vScale;

	ButtonStatus Status;
	ButtonType Type;
	D3DXCOLOR RenderColor;

};

