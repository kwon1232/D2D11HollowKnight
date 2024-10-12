#include "stdafx.h"
#include "Cursur.h"

Cursur::Cursur()
{
	col = new ObRect();
	col->SetWorldPos(Vector2(0.f, 0.f));
	col->scale = Vector2(25.f, 25.f);
	col->pivot = OFFSET_N;
	col->isFilled = false;
	col ->isVisible = false;

	cursurIm = new ObImage(L"Cursor.png");
	cursurIm->scale = Vector2(25.f, 25.f);
	cursurIm->SetParentRT(*col);

	isCursurVisible = false;
	isVisible = true;
}

Cursur::~Cursur()
{
	SafeDelete(col);
	SafeDelete(cursurIm);
}

void Cursur::Update()
{
	GetCursulVisible();

	mousePos = Vector2(INPUT->GetWorldMousePos().x, INPUT->GetWorldMousePos().y);

	if (!isVisible) return;
	col->SetWorldPos(mousePos);

	col->Update();
	cursurIm->Update();
}

void Cursur::Render()
{
	if (!isVisible) return;
	col->Render();
	cursurIm->Render();
}

void Cursur::LateUpdate()
{
}

void Cursur::Release()
{

}

void Cursur::SetCursulVisible(bool onOff)
{
	isCursurVisible = onOff;
}

void Cursur::GetCursulVisible()
{
	if (isCursurVisible)	ShowCursor(true);
	else	ShowCursor(false);
}
