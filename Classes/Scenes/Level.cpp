#include "Level.h"

// Create the prolog scene.
Scene* Level::createScene()
{
	return Level::create();
}

// Initializing.
bool Level::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	// Get the default camera and set the start value for .
	camera = Level::getDefaultCamera();
	cameraShakePositionX = camera->getPositionX() * 0.9f;
	cameraEndPositionX = camera->getPositionX() * 1.1f;

	// Get the sizes.
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	// Add the hello world sprite.
	helloWorldSprite = Sprite::create("HelloWorld.png");
	helloWorldSprite->setPosition(Vec2(origin.x + visibleSize.width / 8, origin.y + visibleSize.height * 0.2f));
	this->addChild(helloWorldSprite, 0);

	// Initialize the event listener for touch events.
	eventListenerTouchOneByOne = EventListenerTouchOneByOne::create();
	eventListenerTouchOneByOne->setSwallowTouches(true);

	// Callbacks for touch events.
	eventListenerTouchOneByOne->onTouchBegan = CC_CALLBACK_2(Level::onTouchBegan, this);
	eventListenerTouchOneByOne->onTouchMoved = CC_CALLBACK_2(Level::onTouchMoved, this);
	eventListenerTouchOneByOne->onTouchEnded = CC_CALLBACK_2(Level::onTouchEnded, this);
	eventListenerTouchOneByOne->onTouchCancelled = CC_CALLBACK_2(Level::onTouchCancelled, this);

	// Get the event dispatcher for touch event listeners.
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListenerTouchOneByOne, this);

	// Call the update function.
	this->scheduleUpdate();

	return true;
}

// Calling per frame.
void Level::update(float delta)
{
	// Move the camera to the right automatically.
	cameraPosition = camera->getPosition();
	cameraPosition.x += CAMERASPEED * delta;
	camera->setPosition(cameraPosition);

	// When the screen is touched, than get the swipe direction.
	if (isTouched)
	{
		if (initialTouchPosition[0] - currentTouchPosition[0] > visibleSize.width * 0.05f)
		{
			moveLeft = true;
			moveRight = false;
			moveDown = false;

			isTouched = false;

			tick = PLAYERSPEED;
		}
		else if (initialTouchPosition[0] - currentTouchPosition[0] < -visibleSize.width * 0.05f)
		{
			moveLeft = false;
			moveRight = true;
			moveDown = false;

			isTouched = false;

			tick = PLAYERSPEED;
		}
		else if (initialTouchPosition[1] - currentTouchPosition[1] > visibleSize.width * 0.05f)
		{
			moveDown = true;

			isTouched = false;
		}
		else if (initialTouchPosition[1] - currentTouchPosition[1] < -visibleSize.width * 0.05f)
		{
			jump = true;

			isTouched = false;
		}
	}

	// Auto movement by setting with swipe the direction.
	helloWorldSpritePosition = helloWorldSprite->getPosition();
	if (moveLeft)
	{
		// Go to left or stop slowly.
		if (!moveDown)
		{
			CCLOG("Go to LEFT!");
			helloWorldSpritePosition.x -= PLAYERSPEED * delta;
		}
		else if (moveDown && tick > 0)
		{
			tick -= PLAYERSPEED * delta;
			helloWorldSpritePosition.x -= tick * delta;
		}
		else if (moveDown && tick <= 0)
		{
			moveLeft = false;
			moveDown = false;
			tick = PLAYERSPEED;
		}
	}
	else if (moveRight)
	{
		// Go to right or stop slowly.
		if (!moveDown)
		{
			CCLOG("Go to RIGHT!");
			helloWorldSpritePosition.x += PLAYERSPEED * delta;
		}
		else if (moveDown && tick > 0)
		{
			tick -= PLAYERSPEED * delta;
			helloWorldSpritePosition.x += tick * delta;
		}
		else if (moveDown && tick <= 0)
		{
			moveRight = false;
			moveDown = false;
			tick = PLAYERSPEED;
		}
	}
	helloWorldSprite->setPosition(helloWorldSpritePosition);
	 
	// Jump by swiping up.
	if (jump)
	{
		jumpTo = new CCJumpTo();
		jumpTo->initWithDuration(1, ccp(helloWorldSprite->getPositionX(), helloWorldSprite->getPositionY()), 300, 1);
		helloWorldSprite->runAction(jumpTo);
		jumpTo->autorelease();
		CCLOG("JUMP!");
		jump = false;
	}

	// Debug output.
	CCLOG("CameraPositionX: %f", camera->getPositionX());
	CCLOG("HelloWorldSpritePositionX: %f", helloWorldSprite->getPositionX());

	// At screen ends, do activate the screen shake.
	if (camera->getPositionX() > helloWorldSprite->getPositionX() + cameraShakePositionX)
	{
		ShakeScreen();
	}
	else if (helloWorldSprite->getPositionX() > camera->getPositionX() + cameraShakePositionX)
	{
		ShakeScreen();
	}

	// By lost, go to the loading screen.
	if (camera->getPositionX() > helloWorldSprite->getPositionX() + cameraEndPositionX)
	{
		// Go to next scene and disable the loading progress.
		this->scheduleOnce(schedule_selector(Level::GoToLoadScene), DISPLAY_TIME_NEXT_SCENE);
		this->unscheduleUpdate();
	}
	else if (helloWorldSprite->getPositionX() > camera->getPositionX() + cameraEndPositionX)
	{
		// Go to next scene and disable the loading progress.
		this->scheduleOnce(schedule_selector(Level::GoToLoadScene), DISPLAY_TIME_NEXT_SCENE);
		this->unscheduleUpdate();
	}
}

// Touch events.
bool Level::onTouchBegan(Touch* touch, Event* event)
{
	// By touching the screen, get the location x and y.
	initialTouchPosition[0] = touch->getLocation().x;
	initialTouchPosition[1] = touch->getLocation().y;
	currentTouchPosition[0] = touch->getLocation().x;
	currentTouchPosition[1] = touch->getLocation().y;

	// The screen is touched.
	isTouched = true;

	return true;
}
void Level::onTouchMoved(Touch* touch, Event* event)
{
	// By moving the touch, get the location x and y.
	currentTouchPosition[0] = touch->getLocation().x;
	currentTouchPosition[1] = touch->getLocation().y;
}
void Level::onTouchEnded(Touch* touch, Event* event)
{
	// Touch is ended.
	isTouched = false;
}
void Level::onTouchCancelled(Touch* touch, Event* event)
{
	// Touch is ended.
	onTouchEnded(touch, event);
}

// Shake the screen.
void Level::ShakeScreen()
{
	// Declare variables.
	float interval = 1 / 60;
	float duration = 0.8f;
	float speed = 6.0f;
	float magnitude = 4.0f;

	this->runAction(ScreenShake::create(duration, speed, magnitude));

	return;
}

// Scene handlings
void Level::GoToLoadScene(float delta)
{
	// Declare variables.
	Scene* scene = Load::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void Level::GoToLevelSelectionScene(float delta)
{
	// Declare variables.
	Scene* scene = LevelSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}