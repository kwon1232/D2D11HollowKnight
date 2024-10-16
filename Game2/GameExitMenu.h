#pragma once
#include "HUD.h"

class Button;
class ObImage;

enum class EGameExitCollisionState
{
	ContinueBnt,
	SettingBut,
	GoMenuBnt,
	YesBnt,
	NoBnt,
	None
};

enum class EGameExitState
{
	ContinueBnt,
	SettingBut,
	GoMenuBnt,
	YesBnt,
	NoBnt,
	None
};

class GameExitMenu : public HUD
{
public:
	GameExitMenu();
	virtual ~GameExitMenu() override;
	virtual void Init(class UIManager* uiManager, class LevelManager* levelManager) override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void LateUpdate() override;

	// Bnt와 마우스가 충돌한다면 커서 스프라이트 재생
	virtual void CollideWithMouse() override;

	EGameExitCollisionState collisionState;
	EGameExitState menuState;

private:
	ObImage* menuTopIm;
	ObImage* menubottomIm;
	Button* continueBnt;
	Button* settingBut;
	Button* goMenuBnt;

	Button* yesBnt;
	Button* noBnt;
	ObImage* wantToExit;

};

