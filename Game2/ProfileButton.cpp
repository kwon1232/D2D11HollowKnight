#include "stdafx.h"
#include "Button.h"

#include "ProfileButton.h"

ProfileButton::ProfileButton(std::wstring butImL)
{
	col = new ObRect();
	col->isFilled = false;
	col->scale = Vector2(1250.f, 125.f);
	profileBnt = new Button(butImL);
	profileBnt->col->SetParentRT(*col);
	deleteProfileBnt = new Button(L"Menu/Profile/delete.png");
	deleteProfileBnt->col->SetParentRT(*col);
	mainHPIm = new ObImage(L"Player/UI/select_game_HUD_0002_health_frame.png");
	mainHPIm->SetParentRT(*col);
	for (int i = 0; i < 10; i++) {
		HPim[i] = new ObImage(L"Player/UI/select_game_HUD_0001_health.png");
		HPim[i]->SetParentRT(*mainHPIm);
	}
}

ProfileButton::~ProfileButton()
{
	SafeDelete(col);
	SafeDelete(profileBnt);
	SafeDelete(deleteProfileBnt);
	SafeDelete(mainHPIm);
	for (int i = 0; i < 10; i++) {
		SafeDelete(HPim[i]);
	}
}

void ProfileButton::Init()
{
}

void ProfileButton::Release()
{
}

void ProfileButton::Update()
{
	col->Update();
	profileBnt->Update();
	deleteProfileBnt->Update();
	mainHPIm->Update();
	for (int i = 0; i < 10; i++) {
		HPim[i]->Update();
	}
	//levelTxt->Update();
}

void ProfileButton::LateUpdate()
{
}

void ProfileButton::Render()
{
	col->Render();
	profileBnt->Render();
	deleteProfileBnt->Render();
	mainHPIm->Render();
	for (int i = 0; i < 10; i++) {
		HPim[i]->Render();
	}
	//levelTxt->Render();
}

void ProfileButton::SetColWorldPosY(float val)
{
	col->SetWorldPosY(val);
}
