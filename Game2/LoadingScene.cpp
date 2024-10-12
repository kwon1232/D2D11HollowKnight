#include "stdafx.h"

int initCount = 0;
mutex m;

void CreateScene()
{
	Scene02* temp = new Scene02;
	SCENE->AddScene("Scene02", temp);

	m.lock();
	Sleep(1000);
	initCount++;
	m.unlock();

	m.lock();
	Sleep(1000);
	initCount++;
	m.unlock();

	m.lock();
	Sleep(1000);
	initCount++;
	m.unlock();

	m.lock();
	Sleep(1000);
	initCount++;
	m.unlock();

	m.lock();
	Sleep(1000);
	initCount++;
	m.unlock();
}

LoadingScene::LoadingScene()
{
	bg = new ObImage(L"ruffy.jpg");
	bg->scale = Vector2(app.GetWidth(), app.GetHeight());

	bar = new ObRect;
	bar->pivot = OFFSET_L;
	bar->SetWorldPosX(-app.GetHalfWidth());
	bar->scale = Vector2(200.0f, 100.0f);

	LIGHT->light.lights[0].radius = 2000.0f;
	LIGHT->light.inColor.x = 0.5f;
	LIGHT->light.inColor.y = 0.5f;
	LIGHT->light.inColor.z = 0.5f;

	th = new thread(CreateScene);
}

LoadingScene::~LoadingScene()
{
	th->join();
	delete th;

	SafeDelete(bg);
	SafeDelete(bar);
}

void LoadingScene::Init()
{
	
}

void LoadingScene::Release()
{
	
}

void LoadingScene::Update()
{
	cout << initCount << endl;

	bar->scale.x = app.GetWidth() / 5 * initCount;

	if (initCount == 5)
	{
		SCENE->ChangeScene("Scene02");
		return;
	}

	bg->Update();
	bar->Update();
}

void LoadingScene::LateUpdate()
{
}

void LoadingScene::Render()
{
	bg->Render();
	bar->Render();
}

void LoadingScene::ResizeScreen()
{
}
