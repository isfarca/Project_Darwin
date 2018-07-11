#pragma once

#ifndef PROLOGSCENE_H
#define PROLOGSCENE_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "MainMenu.h"


using namespace cocos2d;

class Prolog : public Scene
{
public:
	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(Prolog);

	// Initializing.
	virtual bool init();

	///// ADDED

	bool onTouchBegan(Touch *touch, Event * event);



	///// ADDED END

private:
	// Scene handlings.
	void GoToMainMenuScene(float delta);
};

#endif