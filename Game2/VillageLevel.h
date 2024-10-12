#pragma once
#include "Level.h"
class ObImage;

class VillageLevel : public Level
{
public:
	VillageLevel();
	virtual ~VillageLevel();
	virtual void Init(class Player* player, class UIManager* uiManager, class LevelManager* levelManager);
	virtual void Release();
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render();

private:
	Player* player;
	UIManager* uiManager; 
	LevelManager* levelManager;

	
};

