#pragma once
class ObImage;

enum class EGameState
{
	MainMenu,
	InGame,
	Back,
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

	// Bnt�� ���콺�� �浹�Ѵٸ� Ŀ�� ��������Ʈ ���
	virtual void CollideWithMouse();

	bool isVisible;
	bool bWordFade;

	EGameState gameState;

	UIManager* uiManager;
	LevelManager* levelManager;

	ObImage* Slider[2];
};

