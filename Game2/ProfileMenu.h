#pragma once

class ProfileButton;
class ProfileMenu : public HUD
{
public:
	ProfileMenu();
	virtual ~ProfileMenu() override;
	virtual void Init(class UIManager* uiManager, class LevelManager* levelManager) override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void LateUpdate() override;

	// Bnt�� ���콺�� �浹�Ѵٸ� Ŀ�� ��������Ʈ ���
	virtual void CollideWithMouse()override;

	void InOutHUDMenu(string HUDname) override;
	virtual void BlurAlphaValue(float forceValue) override;

	

private:
	ObImage* titleTop;          
	ObImage* profileText;
	ProfileButton* saveProfile1;
	ProfileButton* saveProfile2;
	ProfileButton* saveProfile3;
	class Button* backBnt;
};

