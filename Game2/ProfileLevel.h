#pragma once
#include "Level.h"

class ProfileLevel : public Level
{
public:
	ProfileLevel();
	virtual ~ProfileLevel();
	virtual void Init(Player* player, UIManager* uiManager, LevelManager* levelManager) override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

