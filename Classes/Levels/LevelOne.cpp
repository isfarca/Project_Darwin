#include "LevelOne.h"

#pragma region Declare variables
//jumping / falling-properties
bool inWater;
bool isGrounded, midAirJumping;
float jumpingDuration, fallingDuration;
int jumpingOffset, jumpingExtremum, fallingOffset, fallingExtremum;
//abilityStates
bool hawkReady, rhinoReady, elephantReady, turtleReady;
//buttonValues
int mutationButtonEffect1, mutationButtonEffect2, mutationButtonEffect3;
string mutationButtonPicture1_1, mutationButtonPicture1_2, mutationButtonPicture2_1, mutationButtonPicture2_2, mutationButtonPicture3_1, mutationButtonPicture3_2;

//>>>>>>>>>>>>>> added
bool charge, trample, barsExist, doorExists;
//<<<<<<<<<<<<<<
#pragma endregion

// Create the level one scene.
Scene* LevelOne::createScene()
{
	return LevelOne::create();
}

// Initializing.
bool LevelOne::init()
{
	// When the scene doesn't init, then stop the init process.
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

	// Add the map sprite.
	mapSprite = Sprite::create("LevelOne.png");
	mapSprite->setPosition(2900, 780);
	mapSprite->setScale(1.7f, 1.7f);
	this->addChild(mapSprite, 0);
	// Collider.
	mapCollider = Sprite::create("Collider.png");
	mapCollider->setPosition(1450, 345);
	mapCollider->setScaleX(215);
	mapCollider->setVisible(false);
	this->addChild(mapCollider, 0);

	// Add the player sprite.
	playerSprite = Sprite::create("HelloWorld.png");
	playerSprite->setPosition(600, 495);
	this->addChild(playerSprite, 0);
	// Left collider.
	playerLeftCollider = Sprite::create("Collider.png");
	playerLeftCollider->setPosition(playerSprite->getPositionX() - 80, playerSprite->getPositionY());
	playerLeftCollider->setScaleY(3);
	playerLeftCollider->setVisible(false);
	this->addChild(playerLeftCollider, 0);
	// Top collider.
	playerTopCollider = Sprite::create("Collider.png");
	playerTopCollider->setPosition(playerSprite->getPositionX(), playerSprite->getPositionY() + 115);
	playerTopCollider->setScaleX(3);
	playerTopCollider->setVisible(false);
	this->addChild(playerTopCollider, 0);
	// Right collider.
	playerRightCollider = Sprite::create("Collider.png");
	playerRightCollider->setPosition(playerSprite->getPositionX() + 80, playerSprite->getPositionY());
	playerRightCollider->setScaleY(3);
	playerRightCollider->setVisible(false);
	this->addChild(playerRightCollider, 0);
	// Bottom collider.
	playerBottomCollider = Sprite::create("Collider.png");
	playerBottomCollider->setPosition(playerSprite->getPositionX(), playerSprite->getPositionY() - 115);
	playerBottomCollider->setScaleX(3);
	playerBottomCollider->setVisible(false);
	this->addChild(playerBottomCollider, 0);

	// Add collidable boxes.
	LevelOne::InitBoxesWithCollider();

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
	//create special abilities
	SpecialAbilities::Initiation();
	//>>>>>>>>> added
	//create obstacles
	LevelOne::InitBarsWithCollider();
	LevelOne::InitDoorWithCollider();
	//<<<<<<<<<<

	//starting values for jumping / falling properties
	bool inWater = false;
	midAirJumping = false;
	isGrounded = true;

	//default-values for the buttons if GeneSelection did not hand over values
	if (mutationButtonPicture1_1 == "")
	{
		mutationButtonPicture1_1 = "CloseNormal.png";
		mutationButtonPicture1_2 = "CloseSelected.png";
		mutationButtonEffect1 = 1;
	}
	if (mutationButtonPicture2_1 == "")
	{
		mutationButtonPicture2_1 = "CloseNormal.png";
		mutationButtonPicture2_2 = "CloseSelected.png";
		mutationButtonEffect2 = 2;
	}
	if (mutationButtonPicture3_1 == "")
	{
		mutationButtonPicture3_1 = "CloseNormal.png";
		mutationButtonPicture3_2 = "CloseSelected.png";
		mutationButtonEffect3 = 5;
	}

	//a new Object to spawn the smoke for ChangeForm
	smokeParent = Sprite::create("CloseSelected.png");
	playerSprite->addChild(smokeParent);

	//create the 3 mutationButtons
	mutationButton1 = MenuItemImage::create(mutationButtonPicture1_1, mutationButtonPicture1_2, CC_CALLBACK_1(LevelOne::Transmitter1, this));
	mutationButton2 = MenuItemImage::create(mutationButtonPicture2_1, mutationButtonPicture2_2, CC_CALLBACK_1(LevelOne::Transmitter2, this));
	mutationButton3 = MenuItemImage::create(mutationButtonPicture3_1, mutationButtonPicture3_2, CC_CALLBACK_1(LevelOne::Transmitter3, this));

	specialAbilityButton = MenuItemImage::create("dna6-2.png", "dna_line6.png", "dna_empty.png", CC_CALLBACK_1(LevelOne::UseAbility, this));
	specialAbilityButton->setScale(0.1f, 0.1f);

	auto menu = Menu::create(mutationButton1, mutationButton2, mutationButton3, specialAbilityButton, nullptr);
	menu->setPosition(Point::ZERO);
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

			tick = playerSpeed;
		}
		else if (initialTouchPosition[0] - currentTouchPosition[0] < -visibleSize.width * 0.05f)
		{
			moveLeft = false;
			moveRight = true;
			moveDown = false;

			isTouched = false;

			tick = playerSpeed;
		}
		else if (initialTouchPosition[1] - currentTouchPosition[1] > visibleSize.width * 0.05f)
		{
			moveDown = true;

			isTouched = false;
		}
		else if (initialTouchPosition[1] - currentTouchPosition[1] < -visibleSize.width * 0.05f)
		{
			if (isGrounded || midAirJumping)
			{
				jump = true;
			}
			else
				jump = false;

			isTouched = false;
		}
	}

	// Auto movement by setting with swipe the direction.
	playerSpritePosition = playerSprite->getPosition();
	if (moveLeft)
	{
		// Go to left or stop slowly.
		if (!moveDown)
			playerSpritePosition.x -= playerSpeed * delta;
		else if (moveDown && tick > 0)
		{
			tick -= playerSpeed * delta;
			playerSpritePosition.x -= tick * delta;
		}
		else if (moveDown && tick <= 0)
		{
			moveLeft = false;
			moveDown = false;
			tick = playerSpeed;
		}
	}
	else if (moveRight)
	{
		// Go to right or stop slowly.
		if (!moveDown)
			playerSpritePosition.x += playerSpeed * delta;
		else if (moveDown && tick > 0)
		{
			tick -= playerSpeed * delta;
			playerSpritePosition.x += tick * delta;
		}
		else if (moveDown && tick <= 0)
		{
			moveRight = false;
			moveDown = false;
			tick = playerSpeed;
		}
	}
	playerSprite->setPosition(playerSpritePosition);
	playerLeftCollider->setPosition(playerSprite->getPositionX() - 80, playerSprite->getPositionY());
	playerTopCollider->setPosition(playerSprite->getPositionX(), playerSprite->getPositionY() + 115);
	playerRightCollider->setPosition(playerSprite->getPositionX() + 80, playerSprite->getPositionY());
	playerBottomCollider->setPosition(playerSprite->getPositionX(), playerSprite->getPositionY() - 115);

	// Jump by swiping up.
	if (jump)
	{
		jumpTo = new JumpTo();
		jumpTo->initWithDuration(jumpingDuration, Vec2(playerSprite->getPositionX(), playerSprite->getPositionY() + jumpingOffset), 0, 1);
		jumpTo->autorelease();
		playerSprite->runAction(jumpTo);
		jump = false;
	}

	// Get colliders.
	playerLeftColliderRect = playerLeftCollider->getBoundingBox();
	playerTopColliderRect = playerTopCollider->getBoundingBox();
	playerRightColliderRect = playerRightCollider->getBoundingBox();
	playerBottomColliderRect = playerBottomCollider->getBoundingBox();
	mapColliderRect = mapCollider->getBoundingBox();

	// Is falling?
	isGrounded = playerBottomColliderRect.intersectsRect(mapColliderRect) ? true : false;
	if (!isGrounded && falling)
	{
		playerSpritePosition.y -= playerSpeed * delta;
		playerSprite->setPosition(playerSpritePosition);
	}

	// At screen ends, do activate the screen shake.
	if (camera->getPositionX() > playerSprite->getPositionX() + cameraShakePositionX)
		LevelOne::ShakeScreen();
	else if (playerSprite->getPositionX() > camera->getPositionX() + cameraShakePositionX)
		cameraSpeed = playerSpeed;
	else
		cameraSpeed = playerSpeed / 4;

	// By lost, go to the loading screen.
	if (camera->getPositionX() > playerSprite->getPositionX() + cameraEndPositionX)
	{
		// Go to next scene and disable the loading progress.
		this->scheduleOnce(schedule_selector(LevelOne::GoToLoseLoadScene), DISPLAY_TIME_NEXT_SCENE);
		this->unscheduleUpdate();
	}

	// Check collisions between player and boxes.
	LevelOne::PlayerBoxesCollisionDetection();
	// ************************************************************************************************************************************************************************
	#pragma endregion

	#pragma region Alexander Sinzig
	// ************************************************** Alexander Sinzig *******************************************************************************************************

	//call 'FakeUpdate' for 'SpecialAbilities'
	SpecialAbilities::TimingHandler();
	ChangeForm::SmokeTimer(smokeParent);

	//>>>>>>>>>>>>>>>>>>> added
	// Check collisions between player and bars.
	if (barsExist == true)
		LevelOne::PlayerBarsCollisionDetection();

	if (doorExists == true)
		LevelOne::PlayerDoorCollisionDetection();
	//<<<<<<<<<<<<<<<<<<<

	//hand over cameraX to Health-script
	cameraX = camera->getPositionX();
	cameraY = camera->getPositionY() - visibleSize.width / 4;
	Health::MoveHearts(cameraX, cameraY);

	//tell SpecialAbilities if player is in water
	SpecialAbilities::Water(inWater);

	//set mutationButton-Positions
	mutationButton1->setPosition(camera->getPositionX() - 40, camera->getPositionY() - visibleSize.width / 4 + 40);
	mutationButton2->setPosition(camera->getPositionX(), camera->getPositionY() - visibleSize.width / 4 + 40);
	mutationButton3->setPosition(camera->getPositionX() + 40, camera->getPositionY() - visibleSize.width / 4 + 40);
	specialAbilityButton->setPosition(camera->getPositionX() + 90, camera->getPositionY() - visibleSize.width / 4 + 40);

	//enable/disable special-ability depending on currentForm and cooldowns
	switch (currentForm)
	{
	case 1:
		if (hawkReady)
			specialAbilityButton->setEnabled(true);
		else
			specialAbilityButton->setEnabled(false);
		break;
	case 2:
		if (rhinoReady)
			specialAbilityButton->setEnabled(true);
		else
			specialAbilityButton->setEnabled(false);
		break;
	case 3:
		if (elephantReady)
			specialAbilityButton->setEnabled(true);
		else
			specialAbilityButton->setEnabled(false);
		break;
	case 5:
		if (turtleReady)
			specialAbilityButton->setEnabled(true);
		else
			specialAbilityButton->setEnabled(false);
		break;
	default:
		break;
	}

	// ************************************************************************************************************************************************************************
	#pragma endregion
}

#pragma region Touch events
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
#pragma endregion

#pragma region Alexander Sinzig
// ************************************************** Alexander Sinzig *******************************************************************************************************

//called from from gene-selection to fill the button-variables with values
void LevelOne::ButtonValues(int slot, int chosenSpecialAbility, string chosenPic, string chosenPicSelected)
{
	switch (slot)
	{
	case 1:
		mutationButtonEffect1 = chosenSpecialAbility;
		mutationButtonPicture1_1 = chosenPic;
		mutationButtonPicture1_2 = chosenPicSelected;
		break;
	case 2:
		mutationButtonEffect2 = chosenSpecialAbility;
		mutationButtonPicture2_1 = chosenPic;
		mutationButtonPicture2_2 = chosenPicSelected;
		break;
	case 3:
		mutationButtonEffect3 = chosenSpecialAbility;
		mutationButtonPicture3_1 = chosenPic;
		mutationButtonPicture3_2 = chosenPicSelected;
		break;
	default:
		break;
	}
}

//change jumping and falling-properties when called
void LevelOne::JumpValues(bool midAirJump, float jumpDuration, int jumpOffset, float fallDuration, int fallOffset)
{
	midAirJumping = midAirJump;
	jumpingDuration = jumpDuration;
	jumpingOffset = jumpOffset;
	fallingDuration = fallDuration;
	fallingOffset = fallOffset;
}

void LevelOne::ChargeMode(bool enabled, float speedMulitplyer)
{
	//change speed and check collision with trapdoors
	charge = enabled;
}

void LevelOne::TrampleMode(bool enabled, float speedMulitplyer)
{
	//change speed and check collision with doors
	trample = enabled;
}

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
		ChangeForm::mutationHawk(smokeParent);
		break;
	case 2:
		ChangeForm::mutationRhino(smokeParent);
		break;
	case 3:
		ChangeForm::mutationElephant(smokeParent);
		break;
	case 4:
		ChangeForm::mutationFish(smokeParent);
		break;
	case 5:
		ChangeForm::mutationTurtle(smokeParent);
		break;
	default:
		break;
	}
}

void LevelOne::UseAbility(Ref *pSender)
{
	switch (currentForm)
	{
	case 1:
		SpecialAbilities::HawkAbility();
		
		break;
	case 2:
		SpecialAbilities::RhinoAbility();
		break;
	case 3:
		SpecialAbilities::ElephantAbility();
		break;
	case 4:
		SpecialAbilities::FishAbility();
		break;
	case 5:
		SpecialAbilities::TurtleAbility();
		break;
	default:
		break;
	}
}
void LevelOne::Usable(int abilityNumber, bool usabilityState)
{
	switch (abilityNumber)
	{
	case 1:
		hawkReady = usabilityState;
		break;
	case 2:
		rhinoReady = usabilityState;
		break;
	case 3:
		elephantReady = usabilityState;
		break;
	case 5:
		turtleReady = usabilityState;
		break;
	default:
		break;
	}
}

//>>>>>>>>>>>>>>> added
//create obacles
void LevelOne::InitBarsWithCollider()
{
	// Add 'BarsSprite' with colliders.
	barsSprite[0] = Sprite::create("Greybox.png");
	barsSprite[0]->setPosition(2000, 361);
	barsSprite[0]->setScale(2.9f, 2.9f);
	this->addChild(barsSprite[0], 0);

	barsCollider[0] = Sprite::create("Collider.png");
	barsCollider[0]->setPosition(barsSprite[0]->getPosition());
	barsCollider[0]->setScale(5, 5);
	barsCollider[0]->setVisible(false);
	this->addChild(barsCollider[0], 0);

	//enable search for barsSprite
	barsExist = true;
}
void LevelOne::InitDoorWithCollider()
{
	// Add 'BarsSprite' with colliders.
	doorSprite[0] = Sprite::create("Greybox.png");
	doorSprite[0]->setPosition(2500, 450);
	doorSprite[0]->setScale(2.9f, 2.9f);
	this->addChild(doorSprite[0], 0);

	doorCollider[0] = Sprite::create("Collider.png");
	doorCollider[0]->setPosition(doorSprite[0]->getPosition());
	doorCollider[0]->setScale(5, 5);
	doorCollider[0]->setVisible(false);
	this->addChild(doorCollider[0], 0);

	//enable search for doorSprite
	doorExists = true;
}

//collide and destroy bars / trapdoor
void LevelOne::PlayerBarsCollisionDetection()
{
		// Declare variables.
		Rect barsColliderRect[sizeof(LevelOne::barsCollider) / sizeof(*LevelOne::barsCollider)] =
		{
			barsCollider[0]->getBoundingBox()
		};


		// Collision detection with door
		if (playerBottomColliderRect.intersectsRect(barsColliderRect[0]) && trample) // destroy bars
		{
			this->removeChild(barsCollider[0]);
			this->removeChild(barsSprite[0]);
			barsExist = false;
		}
		else if (playerBottomColliderRect.intersectsRect(barsColliderRect[0])) // bars collision standard
			falling = false;
}

//collide and destroy door
void LevelOne::PlayerDoorCollisionDetection()
{
	// Declare variables.
	Rect doorColliderRect[sizeof(LevelOne::doorCollider) / sizeof(*LevelOne::doorCollider)] =
	{
		doorCollider[0]->getBoundingBox()
	};


	// Collision detection with door
	if (playerLeftColliderRect.intersectsRect(doorColliderRect[0]) && charge) // crush door
	{
		this->removeChild(doorCollider[0]);
		this->removeChild(doorSprite[0]);
		doorExists = false;
	}
	else if (playerRightColliderRect.intersectsRect(doorColliderRect[0]) && charge) // crush door
	{
		this->removeChild(doorCollider[0]);
		this->removeChild(doorSprite[0]);
		doorExists = false;
	}
	else if (playerLeftColliderRect.intersectsRect(doorColliderRect[0])) // door collision standard
		moveLeft = false;
	else if (playerRightColliderRect.intersectsRect(doorColliderRect[0])) // door collision standard
		moveRight = false;
}
//<<<<<<<<<<<<<<<

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

// Init collidable boxes.
void LevelOne::InitBoxesWithCollider()
{
	// Add 'greyBoxSprite[0]' with colliders.
	greyBoxSprite[0] = Sprite::create("Greybox.png");
	greyBoxSprite[0]->setPosition(1735, 461);
	greyBoxSprite[0]->setScale(2.9f, 2.9f);
	this->addChild(greyBoxSprite[0], 0);

	greyBoxCollider[0] = Sprite::create("Collider.png");
	greyBoxCollider[0]->setPosition(greyBoxSprite[0]->getPosition());
	greyBoxCollider[0]->setScale(5, 5);
	greyBoxCollider[0]->setVisible(false);
	this->addChild(greyBoxCollider[0], 0);
}

// Collision detection between player and boxes.
void LevelOne::PlayerBoxesCollisionDetection()
{
	// Declare variuables.
	Rect greyBoxColliderRect[sizeof(LevelOne::greyBoxCollider) / sizeof(*LevelOne::greyBoxCollider)] =
	{
		greyBoxCollider[0]->getBoundingBox()
	};

	// Collision detection with 'greyBoxSprite[0]'.
	if (playerLeftColliderRect.intersectsRect(greyBoxColliderRect[0])) // Left <-> Right.
		moveLeft = false;
	else if (playerTopColliderRect.intersectsRect(greyBoxColliderRect[0])) // Top <-> Bottom.
		this->stopAction(jumpTo);
	else if (playerRightColliderRect.intersectsRect(greyBoxColliderRect[0])) // Right <-> Left.
		moveRight = false;
	else if (playerBottomColliderRect.intersectsRect(greyBoxColliderRect[0])) // Bottom <-> Top.
		falling = false;
	else
		falling = true;
}
// ************************************************************************************************************************************************************************
#pragma endregion

#pragma region Scene handlings
// Scene handlings
void LevelOne::GoToLoseLoadScene(float delta)
{
	// Declare variables.
	Scene* scene = LoseLoad::createScene();

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
#pragma endregion