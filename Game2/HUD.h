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

	// Bnt�� ���콺�� �浹�Ѵٸ� Ŀ�� ��������Ʈ ���
	virtual void CollideWithMouse();

	// ExitBntMenu �� �� ���� �� ���� �Լ�
	virtual void BlurAlphaValue(float forceValue);
	virtual void InOutHUDMenu(string HUDname);
};

