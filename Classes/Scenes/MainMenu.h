#pragma once

#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>
#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "Settings.h"
#include "Info.h"
#include "Help.h"
#include "LevelSelection.h"

using namespace cocos2d;
using namespace std;

class MainMenu : public Scene
{
public:
	// Declare variables.
	// Buttons
	MenuItemImage * infoButton;
	MenuItemImage* helpButton;
	MenuItemImage* settingsButton;
	MenuItemImage* levelSelectionButton;
	MenuItemImage* exitGameButton;

	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(MainMenu);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToSettingsScene(Ref* pSender); // Settings Screen
	void GoToInfoScene(Ref* pSender); // Info Screen
	void GoToHelpScene(Ref* pSender); // HelpScreen
	void GoToLevelSelectionScene(Ref* pSender); // Level Selection
	void ExitGame(Ref* pSender); // Exit Game
};

#endif