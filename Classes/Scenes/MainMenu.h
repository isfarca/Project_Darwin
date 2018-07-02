#pragma once

#ifndef MAINMENU_H
#define MAINMENU_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "Settings.h"
#include "Info.h"
#include "LevelSelection.h"

USING_NS_CC;
using namespace cocos2d;
using namespace std;


class MainMenu : public Scene
{
public:
	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(MainMenu);

	// Initializing.
	virtual bool init();

	

	// Buttons
	MenuItemImage *infoButton;
	MenuItemImage *helpButton;
	MenuItemImage *settingsButton;
	MenuItemImage *levelSelectionButton;
	MenuItemImage* exitGameButton;


private:
	// Scene handlings.
	void GoToSettingsScene(Ref *pSender); // Settings Screen
	void GoToInfoScene(Ref *pSender); // Info Screen
	void GoToHelpScene(Ref *pSender); // HelpScreen
	void GoToLevelSelectionScene(Ref *pSender); // Level Selection
	void ExitGame(Ref *pSender); // Exit Game 5686

};

#endif