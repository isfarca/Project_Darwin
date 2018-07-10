#pragma once

#ifndef SETTINGS_H
#define SETTINGS_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "MainMenu.h"
#include "Help.h"
#include "Prolog.h"

using namespace cocos2d;

class Settings : public Scene
{
public:

	///// added BEGIN
	MenuItemImage* mainMenuButton;
	MenuItemImage* goToHelpButton;

	void goToHelp(Ref* pSender);
	void returnToMainMenu(Ref* pSender);
	///// added END

	// Create the settings scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(Settings);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToHelpScene(float delta);
	void GoToPrologScene(float delta);
	void returnToMainMenuScene(Ref* pSender);
};

#endif