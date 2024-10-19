#include "stdafx.h"
#include "Button.h"
#include "Cursur.h"
#include "UIManager.h"
#include "LevelManager.h"
#include "Fade.h"
#include "ProfileButton.h"

#include "ProfileMenu.h"

ProfileMenu::ProfileMenu()
{
	titleTop = new ObImage(L"Menu/GameExit/creditsfleur.png");
	titleTop->scale = Vector2(920.f, 30.f);
	titleTop->SetWorldPos(Vector2(0.f, 350.f));
	profileText = new ObImage(L"Menu/Profile/SelectProfileText.png");
	//ProfileButton* saveProfile1 = new ProfileButton(L"Menu/Profile/SelectProfileText.png");
	//ProfileButton* saveProfile2 = new ProfileButton(L"Menu/Profile/SelectProfileText.png");
	//ProfileButton* saveProfile3 = new ProfileButton(L"Menu/Profile/SelectProfileText.png");
	//ProfileButton* saveProfile4 = new ProfileButton(L"Menu/Profile/SelectProfileText.png");
}

ProfileMenu::~ProfileMenu()
{
	SafeDelete(titleTop);
	SafeDelete(profileText);
	//SafeDelete(saveProfile1);
	//SafeDelete(saveProfile2);
	//SafeDelete(saveProfile3);
	//SafeDelete(saveProfile4);
}

void ProfileMenu::Init(UIManager* uiManager, LevelManager* levelManager)
{
}

void ProfileMenu::Update()
{
}

void ProfileMenu::Render()
{
}

void ProfileMenu::LateUpdate()
{
}

void ProfileMenu::CollideWithMouse()
{
}

void ProfileMenu::InOutHUDMenu(string HUDname)
{
}

void ProfileMenu::BlurAlphaValue(float forceValue)
{
}
