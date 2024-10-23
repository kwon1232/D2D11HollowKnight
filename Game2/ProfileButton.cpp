#include "stdafx.h"
#include "Button.h"

#include "ProfileButton.h"

ProfileButton::ProfileButton(std::wstring numTxtIm, int fileN)
{
	fileNum = fileN;

	col = new ObRect();
	col->isFilled = false;
	col->scale = Vector2(1250.f, 125.f);
	profileBnt->col->SetParentRT(*col);
	deleteProfileBnt = new Button(L"Menu/Profile/delete.png");
	deleteProfileBnt->col->SetParentRT(*col);
	mainHPIm = new ObImage(L"Player/UI/select_game_HUD_0002_health_frame.png");
	mainHPIm->SetParentRT(*col);

	for (int i = 0; i < 10; i++) {
		HPim[i] = new ObImage(L"Player/UI/select_game_HUD_0001_health.png");
		HPim[i]->SetParentRT(*mainHPIm);
	}
	// ToDo : 파일입출력으로 정보 가져와서 생성자에서 입출력 정보 가져오기
	profileNum = new ObImage(numTxtIm);

	ReadFile(profileBntPath, profileTxtPath, profilePlayTimePath);
	
	profileBnt = new Button(profileBntPath);
	profileTxt = new ObImage(profileTxtPath);
	profilePlayTime = new ObImage(profilePlayTimePath);
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
	SafeDelete(profileTxt);
	SafeDelete(profileNum);
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
	profileTxt->Update();
	profileNum->Update();
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
	profileTxt->Render();
	profileNum->Render();
}

void ProfileButton::SetColWorldPosY(float val)
{
	col->SetWorldPosY(val);
}

void ProfileButton::ReadFile(std::wstring& profileBntPath, std::wstring& profileTxtPath, std::wstring profilePlayTimePath)
{

}
