#include "stdafx.h"
#include "VillageLevel.h"

VillageLevel::VillageLevel()
{
	player = nullptr; uiManager = nullptr; levelManager = nullptr;

	//bg = new ObImage(L"");
}

VillageLevel::~VillageLevel()
{
	//SafeDelete(bg);
}

void VillageLevel::Init(Player* player, UIManager* uiManager, LevelManager* levelManager)
{
}

void VillageLevel::Release()
{
}

void VillageLevel::Update()
{
}

void VillageLevel::LateUpdate()
{
}

void VillageLevel::Render()
{
}
