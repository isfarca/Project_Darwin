#pragma once

#ifndef INFO_H
#define INFO_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "Credits.h"
#include "MainMenu.h"

using namespace cocos2d;

class Info : public Scene
{
public:

	///// added BEGIN
	MenuItemImage* mainMenuButton;
	MenuItemImage* creditsButton;

	void returnToMainMenu(Ref* pSender);
	void goToCredits(Ref* pSender);
	///// added END

	// Create the info scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(Info);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToCreditsScene(float delta);
	void GoToMainMenuScene(float delta);
};

#endif