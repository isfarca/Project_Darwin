#pragma once

#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "cocos2d.h"
#include "../Levels/LevelOne.h"
#include "../Levels/LevelTwo.h"
#include "../Levels/LevelThree.h"
#include "../Levels/LevelFour.h"
#include "../Outsourcing/Definitions.h"
#include "Load.h"
#include "LevelSelection.h"

using namespace cocos2d;

class LevelManager : public Scene
{
public:
	// Create the level manager scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(LevelManager);

	// Initializing.
	virtual bool init();

public:
	// Property for loading the current level.
	int GetLevelId();
	static void SetLevelId(int value);

private:
	// Scene handlings.
	void GoToLevelOne(float delta);
	void GoToLevelTwo(float delta);
	void GoToLevelThree(float delta);
	void GoToLevelFour(float delta);
};

#endif