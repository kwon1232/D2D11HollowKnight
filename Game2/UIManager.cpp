#include "stdafx.h"
#include "Cursur.h"

#include "UIManager.h"

UIManager::UIManager()
{
	cursur = new Cursur();
}

UIManager::~UIManager()
{
	SafeDelete(cursur);
}

void UIManager::Init()
{
}

void UIManager::Update()
{
	cursur->Update();
}

void UIManager::Render()
{
	cursur->Render();
}

void UIManager::LateUpdate()
{
}

void UIManager::Release()
{

}
