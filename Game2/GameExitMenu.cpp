#include "stdafx.h"
#include "Button.h"

#include "UIManager.h"
#include "Cursur.h"

#include "GameExitMenu.h"


GameExitMenu::GameExitMenu()
{
	menuTopIm = new ObImage(L"Menu/GameExit/creditsfleur.png");
	menuTopIm->scale = Vector2(920.f, 30.f);
	menuTopIm->SetWorldPos(Vector2(0.f, 350.f));

	menubottomIm = new ObImage(L"Menu/GameExit/creditsfleur.png");
	menubottomIm->rotation = 180.f * ToRadian;
	menubottomIm->scale = Vector2(920.f, 30.f);
	menubottomIm->SetWorldPos(Vector2(0.f, -250.f));

	continueBnt = new Button(L"Menu/GameExit/Continue.png");
	continueBnt->buttonIm->scale = Vector2(120.f, 60.f);
	continueBnt->buttonIm->SetWorldPos(Vector2(0.f, -250.f));
	continueBnt->col->scale = Vector2(120.f, 60.f);
	continueBnt->col->SetWorldPos(Vector2(0.f, -250.f));

	settingBut = new Button(L"Menu/GameExit/Setting.png");
	goMenuBnt = new Button(L"Menu/GameExit/ExitAndGoMenu.png");

	wantToExit = new ObImage(L"Menu/GameExit/WantToExit.png");
	wantToExit->scale = Vector2(450.f, 120.f);
	wantToExit->SetWorldPos(Vector2(0.f, 200.f));

	yesBnt = new Button(L"Menu/GameExit/Yes.png");
	yesBnt->buttonIm->scale = Vector2(450.f, 120.f);
	yesBnt->buttonIm->SetWorldPos(Vector2(-10.f, -5.f));
	yesBnt->col->scale = Vector2(50.f, 40.f);
	yesBnt->col->SetWorldPos(Vector2(0.f, 50.f));
	yesBnt->col->isVisible = false;

	noBnt = new Button(L"Menu/GameExit/No.png");
	noBnt->buttonIm->scale = Vector2(450.f, 120.f);
	noBnt->buttonIm->SetWorldPos(Vector2(-5.f, 0.f));
	noBnt->col->scale = Vector2(115.f, 40.f);
	noBnt->col->SetWorldPos(Vector2(0.f, -50.f));
	noBnt->col->isVisible = false;

	for (int i = 0; i < 2; i++)
	{
		Slider[i] = new ObImage(L"Menu/Slider.png");
		Slider[i]->maxFrame.x = 11;
		Slider[i]->scale = Vector2(60.f, 60.f);
	}
	Slider[1]->rotation = 180 * ToRadian;

	isVisible = false;

	gameState = EGameState::None;

	collisionState = EGameExitCollisionState::None;
}

GameExitMenu::~GameExitMenu()
{
	SafeDelete(menuTopIm);
	SafeDelete(menubottomIm);
	SafeDelete(continueBnt);
	SafeDelete(settingBut);
	SafeDelete(goMenuBnt);
	SafeDelete(wantToExit);
	SafeDelete(yesBnt);
	SafeDelete(noBnt);
	for (int i = 0; i < 2; i++)
	{
		SafeDelete(Slider[i]);
	}
}

void GameExitMenu::Init(UIManager* uiManager, LevelManager* levelManager)
{
	this->uiManager = uiManager;
	this->levelManager = levelManager;
	this->uiManager->hudMap.insert({ "ExitMenuHUD", this });
}

void GameExitMenu::Update()
{
	if (!isVisible) return;

	CollideWithMouse();

	switch (gameState)
	{
	case EGameState::MainMenu:
		menuTopIm->Update();
		menubottomIm->Update();
		wantToExit->Update();
		yesBnt->Update();
		noBnt->Update();
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->Update();
		}
		break;
	case EGameState::InGame:
		menuTopIm->Update();
		menubottomIm->Update();
		continueBnt->Update();
		settingBut->Update();
		goMenuBnt->Update();
		wantToExit->Update();
		yesBnt->Update();
		noBnt->Update();
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->Update();
		}
		break;
	default:
		break;
	}
}

void GameExitMenu::Render()
{
	if (!isVisible) return;

	switch (gameState)
	{
	case EGameState::MainMenu:
		menuTopIm->Render();
		menubottomIm->Render();
		wantToExit->Render();
		yesBnt->Render();
		noBnt->Render();
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->Render();
		}
		break;
	case EGameState::InGame:
		menuTopIm->Render();
		menubottomIm->Render();
		continueBnt->Render();
		settingBut->Render();
		goMenuBnt->Render();
		wantToExit->Render();
		yesBnt->Render();
		noBnt->Render();
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->Render();
		}
		break;
	default:
		break;
	}
}

void GameExitMenu::LateUpdate()
{
}

void GameExitMenu::CollideWithMouse()
{
	if (uiManager->cursur->col->Intersect(yesBnt->col) && collisionState != EGameExitCollisionState::YesBnt)
	{
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-113.f, 50.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(113.f, 57.f));

		collisionState = EGameExitCollisionState::YesBnt;
	}
	else if (!uiManager->cursur->col->Intersect(yesBnt->col) && collisionState == EGameExitCollisionState::YesBnt)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}
		collisionState = EGameExitCollisionState::None;
	}
	else if (uiManager->cursur->col->Intersect(yesBnt->col) && collisionState == EGameExitCollisionState::YesBnt)
	{
		if(INPUT->KeyPress(VK_LBUTTON))
			PostQuitMessage(0);
	}
	else if (uiManager->cursur->col->Intersect(noBnt->col) && collisionState != EGameExitCollisionState::NoBnt)
	{
		Slider[0]->isVisible = true;
		Slider[0]->SetWorldPos(Vector2(-113.f, -50.f));
		Slider[1]->isVisible = true;
		Slider[1]->SetWorldPos(Vector2(113.f, -43.f));

		collisionState = EGameExitCollisionState::NoBnt;
	}
	else if (!uiManager->cursur->col->Intersect(noBnt->col) && collisionState == EGameExitCollisionState::NoBnt)
	{
		for (int i = 0; i < 2; i++)
		{
			Slider[i]->isVisible = false;
			Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
			Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
		}

		collisionState = EGameExitCollisionState::None;
	}
	else if (uiManager->cursur->col->Intersect(noBnt->col) && collisionState == EGameExitCollisionState::NoBnt)
	{
		if (INPUT->KeyPress(VK_LBUTTON)) 
			this->gameState = EGameState::Back;
	}
}
