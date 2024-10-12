#pragma once
#include <vector>
#include "Floor.h"
#include "Wall.h"

class Player;
class ObImage;

class Level
{
public:
	Level();
	virtual ~Level();
	virtual void Init(Player* player, class UIManager* uiManager, class LevelManager* levelManager);
	virtual void Release();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();
	virtual void ResizeScreen();

	bool isVisible;

	std::vector <Wall> wall;
	std::vector <Floor> floor;
};

