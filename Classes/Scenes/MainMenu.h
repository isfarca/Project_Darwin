#pragma once

#ifndef MAINMENU_H
#define MAINMENU_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "Settings.h"
#include "Info.h"
#include "LevelSelection.h"

using namespace cocos2d;

class MainMenu : public Scene
{
public:
	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(MainMenu);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToSettingsScene(float delta);
	void GoToInfoScene(float delta);
	void GoToLevelSelectionScene(float delta);
};

#endif