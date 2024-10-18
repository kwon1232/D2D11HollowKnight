#include "stdafx.h"
#include "Button.h"
#include "Cursur.h"
#include "UIManager.h"
#include "LevelManager.h"
#include "Fade.h"
#include "MainMenu.h"

MainMenu::MainMenu()
{
	titleTop = new ObImage(L"Menu/prompt_divider.png");
	titleTop->scale = Vector2(900.f, 40.f);
	titleTop->SetWorldPos(Vector2(10.f, 400.f));

	titleText = new ObImage(L"Menu/Text/HollowKnight.png");
	titleText->scale = Vector2(950.f, 320.f);
	titleText->SetWorldPos(Vector2(10.f, 300.f));

	gameStartBnt = new Button(L"Menu/Text/GameStart.png");
	gameStartBnt->buttonIm->scale = Vector2(450.f, 125.f);
	gameStartBnt->buttonIm->SetLocalPos(Vector2(-10.f, 0.f));
	gameStartBnt->col->scale = Vector2(180.f, 50.f);
	gameStartBnt->col->SetWorldPos(Vector2(10.f, 160.f));
	gameStartBnt->col->isVisible = false;

	gameSettingBnt = new Button(L"Menu/Text/GameSetting.png");
	gameSettingBnt->buttonIm->scale = Vector2(450.f, 125.f);
	gameSettingBnt->buttonIm->SetLocalPos(Vector2(-10.f, 0.f));
	gameSettingBnt->col->scale = Vector2(180.f, 50.f);
	gameSettingBnt->col->SetWorldPos(Vector2(10.f, 55.f));
	gameSettingBnt->col->isVisible = false;

	achievementBnt = new Button(L"Menu/Text/Achievement.png");
	achievementBnt->buttonIm->scale = Vector2(450.f, 125.f);
	achievementBnt->buttonIm->SetLocalPos(Vector2(-10.f, 0.f));
	achievementBnt->col->scale = Vector2(115.f, 50.f);
	achievementBnt->col->SetWorldPos(Vector2(13.f, -40.f));
	achievementBnt->col->isVisible = false;

	gameExitBnt = new Button(L"Menu/Text/GameExit.png");
	gameExitBnt->buttonIm->scale = Vector2(450.f, 125.f);
	gameExitBnt->buttonIm->SetLocalPos(Vector2(-10.f, 0.f));
	gameExitBnt->col->scale = Vector2(180.f, 50.f);
	gameExitBnt->col->SetWorldPos(Vector2(10.f, -140.f));
	gameExitBnt->col->isVisible = false;

	for (int i = 0; i < 2; i++)
	{
		Slider[i] = new ObImage(L"Menu/Slider.png");
		Slider[i]->maxFrame.x = 11;
		Slider[i]->scale = Vector2(60.f, 60.f);
	}
	Slider[1]->rotation = 180 * ToRadian;

	collisionState = EMainMenuCollisionState::None;
	menuState = EMainMenuState::None;

	colorAlpha = 0.5f;

	isVisible = true;
}

MainMenu::~MainMenu()
{
	SafeDelete(titleTop);
	SafeDelete(titleText);
	SafeDelete(gameStartBnt);
	SafeDelete(gameSettingBnt);
	SafeDelete(achievementBnt);
	SafeDelete(gameExitBnt);
	for (int i = 0; i < 2; i++)
	{
		SafeDelete(Slider[i]);
	}
}

void MainMenu::Init(UIManager* uiManager,LevelManager* levelManager)
{
	this->uiManager = uiManager;
	this->levelManager = levelManager;

	this->uiManager->hudMap.insert({ "MainMenuHUD",this });

	colorAlpha = 0.5f;
}

void MainMenu::Update()
{
	if (!isVisible) return;
	CollideWithMouse();

	InOutHUDMenu(HUDname);

	titleTop->Update();
	titleText->Update();
	for (int i = 0; i < 2; i++)
	{
		Slider[i]->Update();
	}

	gameStartBnt->Update();
	gameSettingBnt->Update();
	achievementBnt->Update();
	gameExitBnt->Update();

}

void MainMenu::Render()
{
	if (!isVisible) return;
	titleTop->Render();
	titleText->Render();
	gameStartBnt->Render();
	gameSettingBnt->Render();
	achievementBnt->Render();
	gameExitBnt->Render();
	for (int i = 0; i < 2; i++)
	{
		Slider[i]->Render();
	}
}

void MainMenu::LateUpdate()
{
}

void MainMenu::CollideWithMouse()
{
	if (menuState == EMainMenuState::None)
	{
		if (uiManager->cursur->col->Intersect(gameStartBnt->col) && collisionState != EMainMenuCollisionState::GameStartBnt)
		{
			SOUND->Play("E_ui_change_selection");
			Slider[0]->isVisible = true;
			Slider[0]->SetWorldPos(Vector2(-113.f, 160.f));
			Slider[1]->isVisible = true;
			Slider[1]->SetWorldPos(Vector2(127.f, 167.f));

			collisionState = EMainMenuCollisionState::GameStartBnt;
		} else if (!uiManager->cursur->col->Intersect(gameStartBnt->col) && collisionState == EMainMenuCollisionState::GameStartBnt)
		{
			for (int i = 0; i < 2; i++)
			{
				Slider[i]->isVisible = false;
				Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
				Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
			}

			collisionState = EMainMenuCollisionState::None;
		} else if (uiManager->cursur->col->Intersect(gameStartBnt->col) && collisionState == EMainMenuCollisionState::GameStartBnt)
		{
			if (INPUT->KeyPress(VK_LBUTTON))
			{
				levelManager->levelState = ELevelState::Change;
				ClickGameStart();
			}
		} else if (uiManager->cursur->col->Intersect(gameSettingBnt->col) && collisionState != EMainMenuCollisionState::GameSettingBnt)
		{
			SOUND->Play("E_ui_change_selection");
			Slider[0]->isVisible = true;
			Slider[0]->SetWorldPos(Vector2(-113.f, 54.f));
			Slider[1]->isVisible = true;
			Slider[1]->SetWorldPos(Vector2(127.f, 61.f));

			collisionState = EMainMenuCollisionState::GameSettingBnt;
		} else if (!uiManager->cursur->col->Intersect(gameSettingBnt->col) && collisionState == EMainMenuCollisionState::GameSettingBnt)
		{
			for (int i = 0; i < 2; i++)
			{
				Slider[i]->isVisible = false;
				Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
				Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
			}

			collisionState = EMainMenuCollisionState::None;
		} else if (uiManager->cursur->col->Intersect(gameSettingBnt->col) && collisionState == EMainMenuCollisionState::GameSettingBnt)
		{
			if (INPUT->KeyPress(VK_LBUTTON))
			{
				menuState = EMainMenuState::GameSettingBnt;
				HUDname = "SettingMenuHUD";
				hud = uiManager->hudMap[HUDname];
			}
		} else if (uiManager->cursur->col->Intersect(achievementBnt->col) && collisionState != EMainMenuCollisionState::AchievementBnt)
		{
			SOUND->Play("E_ui_change_selection");
			Slider[0]->isVisible = true;
			Slider[0]->SetWorldPos(Vector2(-113.f, -40.f));
			Slider[1]->isVisible = true;
			Slider[1]->SetWorldPos(Vector2(127.f, -33.f));

			collisionState = EMainMenuCollisionState::AchievementBnt;
		} else if (!uiManager->cursur->col->Intersect(achievementBnt->col) && collisionState == EMainMenuCollisionState::AchievementBnt)
		{
			for (int i = 0; i < 2; i++)
			{
				Slider[i]->isVisible = false;
				Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
				Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
			}

			collisionState = EMainMenuCollisionState::None;
		} else if (uiManager->cursur->col->Intersect(gameExitBnt->col) && collisionState != EMainMenuCollisionState::GameExitBnt)
		{
			SOUND->Play("E_ui_change_selection");
			Slider[0]->isVisible = true;
			Slider[0]->SetWorldPos(Vector2(-113.f, -140.f));
			Slider[1]->isVisible = true;
			Slider[1]->SetWorldPos(Vector2(127.f, -133.f));

			collisionState = EMainMenuCollisionState::GameExitBnt;
		} else if (!uiManager->cursur->col->Intersect(gameExitBnt->col) && collisionState == EMainMenuCollisionState::GameExitBnt)
		{
			for (int i = 0; i < 2; i++)
			{
				Slider[i]->isVisible = false;
				Slider[i]->SetWorldPos(Vector2(9500.f, 9500.f));
				Slider[i]->ChangeAnim(ANIMSTATE::ONCE, 0.03f);
			}

			collisionState = EMainMenuCollisionState::None;
		} else if (uiManager->cursur->col->Intersect(gameExitBnt->col) && collisionState == EMainMenuCollisionState::GameExitBnt)
		{
			if (INPUT->KeyPress(VK_LBUTTON))
			{
				//	InOutGameExitBntMenu() 함수 발동 조건
				menuState = EMainMenuState::GameExitBnt;
				HUDname = "ExitMenuHUD";
				hud = uiManager->hudMap[HUDname];
			}
		}
	}
}


void MainMenu::InOutHUDMenu(string HUDname)
{
	if (menuState == EMainMenuState::None) return;

	if (hud->gameState != EGameState::Back)
	{
		bWordFade = true;
		BlurAlphaValue(0.5f);

		if (colorAlpha <= 0.0f)
		{
			hud->isVisible = true;
			hud->gameState = EGameState::MainMenu;
		}
	}
	else if (hud->gameState == EGameState::Back)
	{
		bWordFade = false;
		hud->isVisible = false;
		BlurAlphaValue(0.5f);
		if (colorAlpha >= 0.5f)
		{
			hud->gameState = EGameState::None;
			menuState = EMainMenuState::None;
		}
	}
}

void MainMenu::BlurAlphaValue(float forceValue)
{
	if (bWordFade)
	{
		if (colorAlpha >= 0.0f)
		{
			titleTop->color.A(colorAlpha);
			titleText->color.A(colorAlpha);
			Slider[0]->color.A(colorAlpha);
			Slider[1]->color.A(colorAlpha);
			gameStartBnt->buttonIm->color.A(colorAlpha);
			gameSettingBnt->buttonIm->color.A(colorAlpha);
			achievementBnt->buttonIm->color.A(colorAlpha);
			gameExitBnt->buttonIm->color.A(colorAlpha);
			colorAlpha -= forceValue * DELTA;
		}
	} else
	{
		if (colorAlpha <= 0.5f)
		{
			titleTop->color.A(colorAlpha);
			titleText->color.A(colorAlpha);
			Slider[0]->color.A(colorAlpha);
			Slider[1]->color.A(colorAlpha);
			gameStartBnt->buttonIm->color.A(colorAlpha);
			gameSettingBnt->buttonIm->color.A(colorAlpha);
			achievementBnt->buttonIm->color.A(colorAlpha);
			gameExitBnt->buttonIm->color.A(colorAlpha);
			colorAlpha += forceValue * DELTA;
		}
	}
}

void MainMenu::ClickGameStart()
{
	levelManager->fade->SetFadestate(0);
	levelManager->ChangeLevel("ProfileLevel", "IntroLevel");
}
