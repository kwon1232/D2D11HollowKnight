#pragma once
class ObImage;

enum class EGameState
{
	MainMenu,
	InGame,
	Back,// planning to delete
	First,
	Change,
	None
};

class HUD
{
public:
	HUD();
	virtual ~HUD();
	virtual void Init(class UIManager* uiManager, class LevelManager* levelManager);
	virtual void Update();
	virtual void Render();
	virtual void LateUpdate();

	bool isVisible;

	bool bWordFade;
	float colorAlpha;

	EGameState gameState;

	string HUDname;
	HUD* hud;
	UIManager* uiManager;
	LevelManager* levelManager;

	ObImage* Slider[2];
	//vector<ObImage*> imArr;

	// Bnt와 마우스가 충돌한다면 커서 스프라이트 재생
	virtual void CollideWithMouse();

	// ExitBntMenu 들어갈 때 나올 때 관련 함수
	virtual void BlurAlphaValue(float forceValue);
	virtual void InOutHUDMenu(string HUDname);
};

