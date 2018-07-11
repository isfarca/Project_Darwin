#pragma once

#ifndef LEVELSELECTION_H
#define LEVELSELECTION_H

#include <string>
#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "MainMenu.h"
#include "GeneSelection.h"
#include "LevelManager.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
using namespace cocos2d;
using namespace std;

class LevelSelection : public Scene
{
public:
	// Declare variables.
	
	// Levels
	MenuItemImage* levelOneButton;
	MenuItemImage* levelTwoButton;
	MenuItemImage* levelThreeButton;
	MenuItemImage* levelFourButton;

	MenuItemImage* goToMainMenuButton;

	Sprite* LevelOneSprite;
	Sprite* LevelTwoSprite;
	Sprite* LevelThreeSprite;
	Sprite* LevelFourSprite;
	// MenuItemImage* goToGeneSelectionButton; **********DELETED

	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(LevelSelection);

	// Initializing.
	virtual bool init();

private:
	// Scene handlings.
	void GoToMainMenuScene(Ref* pSender);
	void GoToGeneSelectionScene(Ref* pSender);

	void StartLevelOne(Ref* pSender);
	void StartLevelTwo(Ref* pSender);
	void StartLevelThree(Ref* pSender);
	void StartLevelFour(Ref* pSender);
};

#endif