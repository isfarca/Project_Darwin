#pragma once

#ifndef CREDITS_H
#define CREDITS_H

#include "cocos2d.h"
#include "../Outsourcing/Definitions.h"
#include "MainMenu.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;

class Credits : public Scene
{
public:
	// Create the credits scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(Credits);

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