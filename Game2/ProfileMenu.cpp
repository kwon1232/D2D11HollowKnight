#include "stdafx.h"
#include "Cursur.h"
#include "UIManager.h"
#include "LevelManager.h"
#include "Fade.h"

#include "Button.h"
#include "ProfileButton.h"

#include "ProfileMenu.h"

ProfileMenu::ProfileMenu()
{
	titleTop = new ObImage(L"Menu/GameExit/creditsfleur.png");
	titleTop->scale = Vector2(920.f, 30.f);
	titleTop->SetWorldPos(Vector2(0.f, 340.f));
	profileText = new ObImage(L"Menu/Profile/SelectProfile.png");
	profileText->scale = Vector2(550.f, 160.f);
	profileText->SetWorldPos(Vector2(-20.f,385.f));
	saveProfile1 = new ProfileButton(L"Menu/Profile/Profile01BgIm.png");
	saveProfile1->SetColWorldPosY(200.f);
	saveProfile2 = new ProfileButton(L"Menu/Profile/Profile02BgIm.png");
	saveProfile2->SetColWorldPosY(20.f);
	saveProfile3 = new ProfileButton(L"Menu/Profile/Profile01BgIm.png");
	saveProfile3->SetColWorldPosY(-180.f);
	backBnt = new Button(L"Menu/Text/Back.png");
	backBnt->col->scale = Vector2(220.f, 100.f);
	backBnt->SetColWorldPosY(-360.f);

	for (int i = 0; i < 2; i++)
	{
		Slider[i] = new ObImage(L"Menu/Slider.png");
		Slider[i]->maxFrame.x = 11;
		Slider[i]->scale = Vector2(60.f, 60.f);
	}
	Slider[1]->rotation = 180 * ToRadian;
}

ProfileMenu::~ProfileMenu()
{
	SafeDelete(titleTop);
	SafeDelete(profileText);
	SafeDelete(saveProfile1);
	SafeDelete(saveProfile2);
	SafeDelete(saveProfile3);
	SafeDelete(backBnt);
	for (int i = 0; i < 2; i++)
	{
		SafeDelete(Slider[i]);
	}
}

void ProfileMenu::Init(UIManager* uiManager, LevelManager* levelManager)
{
	this->uiManager = uiManager;
	this->levelManager = levelManager;

	this->uiManager->hudMap.insert({ "ProfileMenuHUD",this });

	colorAlpha = 0.5f;
}

void ProfileMenu::Update()
{
	if (!isVisible) return;
	titleTop->Update();
	profileText->Update();
	saveProfile1->Update();
	saveProfile2->Update();	
	saveProfile3->Update();
	backBnt->Update();
	for (int i = 0; i < 2; i++)
	{
		Slider[i]->Update();
	}
}

void ProfileMenu::Render()
{
	if (!isVisible) return;
	titleTop->Render();
	profileText->Render();
	saveProfile1->Render();
	saveProfile2->Render();
	saveProfile3->Render();
	backBnt->Render();
	for (int i = 0; i < 2; i++)
	{
		Slider[i]->Update();
	}
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
