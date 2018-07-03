#pragma once

#ifndef LEVEL_H
#define LEVEL_H

#include "cocos2d.h"
#include "../Levels/One.h"
#include "../Levels/Two.h"
#include "../Levels/Three.h"
#include "../Levels/Four.h"
#include "../Outsourcing/ScreenShake.h"
#include "../Outsourcing/Definitions.h"
#include "Load.h"
#include "LevelSelection.h"

using namespace cocos2d;

class Level : public Scene
{
private:
	// Constants.
	const float PLAYERSPEED = 200;
	const float CAMERASPEED = PLAYERSPEED / 4;

private:
	// Declare variables.
	Camera* camera;
	float cameraEndPositionX, cameraShakePositionX;
	Vec2 cameraPosition;
	Sprite* helloWorldSprite;
	Vec2 helloWorldSpritePosition;
	float tick = PLAYERSPEED;
	Size visibleSize;
	Vec2 origin;
	EventListenerTouchOneByOne* eventListenerTouchOneByOne;
	bool isTouched = false, moveLeft = false, moveRight = false, moveDown = false, jump = false;
	float initialTouchPosition[2] =
	{
		0,
		0
	};
	float currentTouchPosition[2];
	CCJumpTo* jumpTo;

public:
	// Create the prolog scene.
	static Scene* createScene();
	// Implement the create function.
	CREATE_FUNC(Level);

	// Initializing.
	virtual bool init();

	// Calling per frame.
	void update(float delta);

	// Touch events.
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	void onTouchCancelled(Touch* touch, Event* event);

private:
	// Shake the screen.
	void ShakeScreen();
	// Scene handlings.
	void GoToLoadScene(float delta);
	void GoToLevelSelectionScene(float delta);
};

#endif