#include "LevelOne.h"

// Create the prolog scene.
Scene* LevelOne::createScene()
{
	return LevelOne::create();
}

// Initializing.
bool LevelOne::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	#pragma region Fethi Isfarca
	// ************************************************** Fethi Isfarca *******************************************************************************************************

	// Get the default camera and set the start value for .
	camera = LevelOne::getDefaultCamera();
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
	eventListenerTouchOneByOne->onTouchBegan = CC_CALLBACK_2(LevelOne::onTouchBegan, this);
	eventListenerTouchOneByOne->onTouchMoved = CC_CALLBACK_2(LevelOne::onTouchMoved, this);
	eventListenerTouchOneByOne->onTouchEnded = CC_CALLBACK_2(LevelOne::onTouchEnded, this);
	eventListenerTouchOneByOne->onTouchCancelled = CC_CALLBACK_2(LevelOne::onTouchCancelled, this);

	// Get the event dispatcher for touch event listeners.
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListenerTouchOneByOne, this);

	// ************************************************************************************************************************************************************************
	#pragma endregion

	#pragma region Alexander Sinzig
	// ************************************************** Alexander Sinzig *******************************************************************************************************

	//create health and hearts
	Health::InitialHealth(this);
	SpecialAbilities::Initiation();

	//testwerte -> später löschen
	mutationButtonPicture1_1 = "CloseNormal.png";
	mutationButtonPicture1_2 = "CloseSelected.png";
	mutationButtonEffect1 = 2;
	mutationButtonPicture2_1 = "CloseNormal.png";
	mutationButtonPicture2_2 = "CloseSelected.png";
	mutationButtonEffect2 = 3;
	mutationButtonPicture3_1 = "CloseNormal.png";
	mutationButtonPicture3_2 = "CloseSelected.png";
	mutationButtonEffect3 = 5;

	abilityPicture1 = "CloseNormal.png";
	abilityPicture2 = "CloseSelected.png";

	//später müssen mutationbuttoneffects auf die strings von robin gesetzt werden


	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//create the 3 mutationButtons
	mutationButton1 = MenuItemImage::create(mutationButtonPicture1_1, mutationButtonPicture1_2, CC_CALLBACK_1(LevelOne::Transmitter1, this));
	mutationButton2 = MenuItemImage::create(mutationButtonPicture2_1, mutationButtonPicture2_2, CC_CALLBACK_1(LevelOne::Transmitter2, this));
	mutationButton3 = MenuItemImage::create(mutationButtonPicture3_1, mutationButtonPicture3_2, CC_CALLBACK_1(LevelOne::Transmitter3, this));

	specialAbilityButton = MenuItemImage::create(abilityPicture1, abilityPicture2, CC_CALLBACK_1(LevelOne::UseAbility, this));


	auto menu = Menu::create(mutationButton1, mutationButton2, mutationButton3, specialAbilityButton, nullptr);
	menu->setPosition(Point::ZERO);
	mutationButton1->setPosition(visibleSize.width * 3 / 10 + origin.x, origin.y + 20);
	mutationButton2->setPosition(visibleSize.width * 4 / 10 + origin.x, origin.y + 20);
	mutationButton3->setPosition(visibleSize.width * 5 / 10 + origin.x, origin.y + 20);
	specialAbilityButton->setPosition(visibleSize.width * 6 / 10 + origin.x, origin.y + 20);
	this->addChild(menu);

	// ************************************************************************************************************************************************************************
	#pragma endregion

	// Call the update function.
	this->scheduleUpdate();

	return true;
}

// Calling per frame.
void LevelOne::update(float delta)
{
	#pragma region Fethi Isfarca
	// ************************************************** Fethi Isfarca *******************************************************************************************************

	// Move the camera to the right automatically.
	cameraPosition = camera->getPosition();
	cameraPosition.x += cameraSpeed * delta;
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
		jumpTo = new JumpTo();
		jumpTo->initWithDuration(1, Vec2(helloWorldSprite->getPositionX(), helloWorldSprite->getPositionY()), 300, 1);
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
		ShakeScreen();
	else if (helloWorldSprite->getPositionX() > camera->getPositionX() + cameraShakePositionX)
		cameraSpeed = PLAYERSPEED;
	else
		cameraSpeed = PLAYERSPEED / 4;

	// By lost, go to the loading screen.
	if (camera->getPositionX() > helloWorldSprite->getPositionX() + cameraEndPositionX)
	{
		// Go to next scene and disable the loading progress.
		this->scheduleOnce(schedule_selector(LevelOne::GoToLoadScene), DISPLAY_TIME_NEXT_SCENE);
		this->unscheduleUpdate();
	}

	// ************************************************************************************************************************************************************************
	#pragma endregion

	#pragma region Alexander Sinzig
	// ************************************************** Alexander Sinzig *******************************************************************************************************

	//call 'FakeUpdate' for 'SpecialAbilities'
	SpecialAbilities::TimingHandler();

	// ************************************************************************************************************************************************************************
	#pragma endregion



}

// Touch events.
bool LevelOne::onTouchBegan(Touch* touch, Event* event)
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
void LevelOne::onTouchMoved(Touch* touch, Event* event)
{
	// By moving the touch, get the location x and y.
	currentTouchPosition[0] = touch->getLocation().x;
	currentTouchPosition[1] = touch->getLocation().y;
}
void LevelOne::onTouchEnded(Touch* touch, Event* event)
{
	// Touch is ended.
	isTouched = false;
}
void LevelOne::onTouchCancelled(Touch* touch, Event* event)
{
	// Touch is ended.
	onTouchEnded(touch, event);
}

#pragma region Alexander Sinzig
// ************************************************** Alexander Sinzig *******************************************************************************************************

//the 4 transimitters
void LevelOne::Transmitter1(Ref *pSender)
{
	LevelOne::ChangeMutation(mutationButtonEffect1);
}

void LevelOne::Transmitter2(Ref *pSender)
{
	LevelOne::ChangeMutation(mutationButtonEffect2);
}

void LevelOne::Transmitter3(Ref *pSender)
{
	LevelOne::ChangeMutation(mutationButtonEffect3);
}

void LevelOne::ChangeMutation(int effect)
{
	//save current form for ability
	currentForm = effect;
	//different effect depending on the mutation
	//call mutation-function
	switch (currentForm)
	{
	case 1:
		PlaceholderEffect::mutationRhino();
		break;
	case 2:
		PlaceholderEffect::mutationTurtle();
		break;
	case 3:
		PlaceholderEffect::mutationHawk();
		break;
	case 4:
		PlaceholderEffect::mutationElephant();
		break;
	case 5:
		PlaceholderEffect::mutationFish();
		break;
	default:
		log("mutation does not exist");
		break;
	}
}

void LevelOne::UseAbility(Ref *pSender)
{
	switch (currentForm)
	{
	case 1:
		SpecialAbilities::RhinoAbility();
		break;
	case 2:
		SpecialAbilities::TurtleAbility();
		break;
	case 3:
		SpecialAbilities::HawkAbility();
		break;
	case 4:
		SpecialAbilities::ElephantAbility();
		break;
	case 5:
		SpecialAbilities::FishAbility();
		break;
	default:
		log("invalid mutation for ability");
		break;
	}
}

// ************************************************************************************************************************************************************************
#pragma endregion

#pragma region Fethi Isfarca
// ************************************************** Fethi Isfarca *******************************************************************************************************

// Shake the screen.
void LevelOne::ShakeScreen()
{
	// Declare variables.
	float interval = 1 / 60;
	float duration = 0.8f;
	float speed = 6.0f;
	float magnitude = 4.0f;

	this->runAction(ScreenShake::create(duration, speed, magnitude));

	return;
}

// ************************************************************************************************************************************************************************
#pragma endregion

// Scene handlings
void LevelOne::GoToLoadScene(float delta)
{
	// Declare variables.
	Scene* scene = Load::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelOne::GoToLevelSelectionScene(float delta)
{
	// Declare variables.
	Scene* scene = LevelSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}