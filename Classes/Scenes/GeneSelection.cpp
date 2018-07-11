#include "GeneSelection.h"
#define BUTTON_SFX "sounds/Button_Sound.wav"

// Create the prolog scene.
Scene* GeneSelection::createScene()
{
	return GeneSelection::create();
}

// Initializing.
bool GeneSelection::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// icon size multiplier
	sizeMultiplierMutations = 0.15f;

	// png reference mutation
	mutationOnePng = "Menu/hawkselect.png";
	mutationOnePngSelected = "Menu/hawkdeselected.png";
	mutationOnePngBlocked = "Menu/hawkcrossed.png";

	mutationTwoPng = "Menu/rhinoselect.png";
	mutationTwoPngSelected = "Menu/rhinodeselected.png";
	mutationTwoPngBlocked = "Menu/rhinocrossed.png";

	mutationThreePng = "Menu/elephantselect.png";
	mutationThreePngSelected = "Menu/elephantdeselected.png";
	mutationThreePngBlocked = "Menu/elephantcrossed.png";

	mutationFourPng = "Menu/fishselect.png";
	mutationFourPngSelected = "Menu/fishdeselected.png";
	mutationFourPngBlocked = "Menu/fishcrossed.png";

	mutationFivePng = "Menu/turtleselect.png";
	mutationFivePngSelected = "Menu/turtledeselected.png";
	mutationFivePngBlocked = "Menu/turtlecrossed.png";

	// Available character mutations png
	characterWithMutationOne = "Menu/hawkselect.png";
	characterWithMutationTwo = "Menu/rhinoselect.png";
	characterWithMutationThree = "Menu/elephantselect.png";
	characterWithMutationFour = "Menu/fishselect.png";
	characterWithMutationFive = "Menu/turtleselect.png";

	characterWithMutationClear = "Menu/bethereorbesquare.png";

	currentCharacter = "Menu/bethereorbesquare.png";


	// png reference start
	startPng = "Menu/continuepressed.png";
	startPngSelected = "Menu/continue.png";
	startPngBlocked = "Menu/continuegrey.png";


	// png reference reset
	reset = "Menu/resetpressed.png";
	resetSelected = "Menu/reset.png";

	// mutations that are selected PNG reference
	chosenMutationPngFirst = "Menu/bethereorbesquare.png";
	chosenMutationPngSecond = "Menu/bethereorbesquare.png";
	chosenMutationPngThird = "Menu/bethereorbesquare.png";

	// png reference return to MainMenu/GeneSelection

	returnToMainMenuPng = "Icons/home.png";
	returnToMainMenuPngSelected = "MainMenuSelected.png";

	returnToLevelSelectionPng = "Icons/arrow.png";
	returnToLevelSelectionPngSelected = "BackToLevelSelectionSelected.png";


	/*
	// mutations that are selected Sprite create
	firstGeneSprite = Sprite::create(chosenMutationPngFirst);
	secondGeneSprite = Sprite::create(chosenMutationPngSecond);
	thirdGeneSprite = Sprite::create(chosenMutationPngThird);

	// current character mutation png
	ChosenCharacterMutation = Sprite::create(currentCharacter);
	*/

	// mutation buttons created
	mutationOneBtn = MenuItemImage::create(mutationOnePng, mutationOnePngSelected, mutationOnePngBlocked, CC_CALLBACK_1(GeneSelection::mutationOne, this));
	mutationTwoBtn = MenuItemImage::create(mutationTwoPng, mutationTwoPngSelected, mutationTwoPngBlocked, CC_CALLBACK_1(GeneSelection::mutationTwo, this));
	mutationThreeBtn = MenuItemImage::create(mutationThreePng, mutationThreePngSelected, mutationThreePngBlocked, CC_CALLBACK_1(GeneSelection::mutationThree, this));
	mutationFourBtn = MenuItemImage::create(mutationFourPng, mutationFourPngSelected, mutationFourPngBlocked, CC_CALLBACK_1(GeneSelection::mutationFour, this));
	mutationFiveBtn = MenuItemImage::create(mutationFivePng, mutationFivePngSelected, mutationFivePngBlocked, CC_CALLBACK_1(GeneSelection::mutationFive, this));

	mutationOneBtn->setScale(sizeMultiplierMutations, sizeMultiplierMutations);
	mutationTwoBtn->setScale(sizeMultiplierMutations, sizeMultiplierMutations);
	mutationThreeBtn->setScale(sizeMultiplierMutations, sizeMultiplierMutations);
	mutationFourBtn->setScale(sizeMultiplierMutations, sizeMultiplierMutations);
	mutationFiveBtn->setScale(sizeMultiplierMutations, sizeMultiplierMutations);

	// start game button create
	startGameBtn = MenuItemImage::create(startPng, startPngSelected, startPngBlocked, CC_CALLBACK_1(GeneSelection::startGame, this));

	startGameBtn->setScale(0.15f, 0.15f);

	// MainMenu / Return to Level Selection create
	returnToMainMenuBtn = MenuItemImage::create(returnToMainMenuPng, returnToMainMenuPngSelected, CC_CALLBACK_1(GeneSelection::ReturnToMainMenu, this));
	returnToMainMenuBtn->setScale(0.15f, 0.15f);

	returnToLevelSelectionBtn = MenuItemImage::create(returnToLevelSelectionPng, returnToLevelSelectionPngSelected, CC_CALLBACK_1(GeneSelection::ReturnToLevelSelection, this));
	returnToLevelSelectionBtn->setScale(0.15f, 0.15f);
	// reset selected mutations create
	resetSelectedMutationBtn = MenuItemImage::create(reset, resetSelected, CC_CALLBACK_1(GeneSelection::ResetSelectedMutation, this));
	resetSelectedMutationBtn->setScale(0.15f, 0.15f);


	auto menu = Menu::create(mutationOneBtn, mutationTwoBtn, mutationThreeBtn, mutationFourBtn, mutationFiveBtn, resetSelectedMutationBtn, startGameBtn, returnToMainMenuBtn, returnToLevelSelectionBtn, nullptr);
	menu->setPosition(Point::ZERO);


	
	// mutation button position
	mutationOneBtn->setPosition(Vec2(visibleSize.width / 2 - 800, 1200));
	mutationTwoBtn->setPosition(Vec2(visibleSize.width / 2 - 800, 1000));
	mutationThreeBtn->setPosition(Vec2(visibleSize.width / 2 - 800, 800));
	mutationFourBtn->setPosition(Vec2(visibleSize.width / 2 - 800, 600));
	mutationFiveBtn->setPosition(Vec2(visibleSize.width / 2 - 800, 400));

	// MainMenu / LevelSelection button position
	returnToMainMenuBtn->setPosition(Vec2(visibleSize.width / 2 + 800, 1200));
	returnToLevelSelectionBtn->setPosition(Vec2(visibleSize.width / 2 + 600, 1200));


	//ChosenCharacterMutation->setPosition(Vec2(visibleSize.width / 2 + 300, 1200));

	// selected mutations sprite position
	//firstGeneSprite->setPosition(Vec2(visibleSize.width / 2, 1000));
	//secondGeneSprite->setPosition(Vec2(visibleSize.width / 2, 950));
	//thirdGeneSprite->setPosition(Vec2(visibleSize.width / 2, 900));

	// reset selected mutations position	
	resetSelectedMutationBtn->setPosition(Vec2(visibleSize.width / 2 - 400, 400));

	// start game button position
	startGameBtn->setPosition(Vec2(visibleSize.width / 2, 300));

	startGameBtn->setEnabled(false);

	/*
	// adding to scene
	this->addChild(firstGeneSprite);
	this->addChild(secondGeneSprite);
	this->addChild(thirdGeneSprite);

	this->addChild(ChosenCharacterMutation);
	*/
	this->addChild(menu);

	this->scheduleUpdate();



	return true;

}

void GeneSelection::update(float delta)
{
	// Check what png the sprite currently has and update it
	firstGeneSprite = Sprite::create(chosenMutationPngFirst);
	secondGeneSprite = Sprite::create(chosenMutationPngSecond);
	thirdGeneSprite = Sprite::create(chosenMutationPngThird);

	// current character mutation png
	ChosenCharacterMutation = Sprite::create(currentCharacter);

	firstGeneSprite->setScale(sizeMultiplierMutations, sizeMultiplierMutations);
	secondGeneSprite->setScale(sizeMultiplierMutations, sizeMultiplierMutations);
	thirdGeneSprite->setScale(sizeMultiplierMutations, sizeMultiplierMutations);
	ChosenCharacterMutation->setScale(sizeMultiplierMutations, sizeMultiplierMutations);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	ChosenCharacterMutation->setPosition(visibleSize.width / 2 + 500, visibleSize.height / 2);

	// selected gene position
	firstGeneSprite->setPosition(Vec2(visibleSize.width / 2, 1100));
	secondGeneSprite->setPosition(Vec2(visibleSize.width / 2, 850));
	thirdGeneSprite->setPosition(Vec2(visibleSize.width / 2, 600));

	this->addChild(firstGeneSprite);
	this->addChild(secondGeneSprite);
	this->addChild(thirdGeneSprite);
	this->addChild(ChosenCharacterMutation);
}
// MainMenu
void GeneSelection::ReturnToMainMenu(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}

void GeneSelection::ReturnToLevelSelection(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	Scene* scene = LevelSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

// Scene handlings
void GeneSelection::GoToMainMenuScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void GeneSelection::GoToLoadScene(float delta)
{
	// Declare variables.
	Scene* scene = Load::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

// Mutation handlings.
void GeneSelection::mutationOne(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	GeneSelection::mutationOneInt = 1;
	ChosenMutation(1, mutationOnePng/***DELETED, mutationFourPng*/);

	mutationOneBtn->setEnabled(false);

	currentCharacter = characterWithMutationOne;

	/* DEBUG REASONS
	log("%d", specialOne);
	log("%d", specialTwo);
	log("%d", specialThree);

	log("%s", chosenMutationPngFirst.c_str());
	log("%s", chosenMutationPngSecond.c_str());
	log("%s", chosenMutationPngThird.c_str());
	*/
}

void GeneSelection::mutationTwo(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	GeneSelection::mutationTwoInt = 2;
	ChosenMutation(2, mutationTwoPng/***DELETED, mutationFourPng*/);

	mutationTwoBtn->setEnabled(false);

	currentCharacter = characterWithMutationTwo;

	//mutationTwoBtn->setDisabledImage(disabledTest);

	/* DEBUG REASONS
	log("%d", specialOne);
	log("%d", specialTwo);
	log("%d", specialThree);

	log("%s", chosenMutationPngFirst.c_str());
	log("%s", chosenMutationPngSecond.c_str());
	log("%s", chosenMutationPngThird.c_str());
	*/
}

void GeneSelection::mutationThree(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	GeneSelection::mutationThreeInt = 3;
	ChosenMutation(3, mutationThreePng/***DELETED, mutationFourPng*/);
	mutationThreeBtn->setEnabled(false);

	currentCharacter = characterWithMutationThree;

	//mutationThreeBtn->setDisabledImage(disabledTest);

	/* DEBUG REASONS
	log("%d", specialOne);
	log("%d", specialTwo);
	log("%d", specialThree);

	log("%s", chosenMutationPngFirst.c_str());
	log("%s", chosenMutationPngSecond.c_str());
	log("%s", chosenMutationPngThird.c_str());
	*/
}

void GeneSelection::mutationFour(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	GeneSelection::mutationFourInt = 4;
	ChosenMutation(4, mutationFourPng/***DELETED, mutationFourPng*/);
	mutationFourBtn->setEnabled(false);

	currentCharacter = characterWithMutationFour;

	//mutationFourBtn->setDisabledImage(disabledTest);
	/* DEBUG REASONS
	log("%d", specialOne);
	log("%d", specialTwo);
	log("%d", specialThree);

	log("%s", chosenMutationPngFirst.c_str());
	log("%s", chosenMutationPngSecond.c_str());
	log("%s", chosenMutationPngThird.c_str());
	*/
}

void GeneSelection::mutationFive(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	GeneSelection::mutationFiveInt = 5;

	ChosenMutation(5, mutationFivePng/***DELETED, mutationFivePng*/);

	mutationFiveBtn->setEnabled(false);

	currentCharacter = characterWithMutationFive;

	//mutationFiveBtn->setDisabledImage(disabledTest);
	/* DEBUG REASONS
	log("%d", specialOne);
	log("%d", specialTwo);
	log("%d", specialThree);

	log("%s", chosenMutationPngFirst.c_str());
	log("%s", chosenMutationPngSecond.c_str());
	log("%s", chosenMutationPngThird.c_str());
	*/
}

void GeneSelection::ResetSelectedMutation(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	specialOne = 0;
	specialTwo = 0;
	specialThree = 0;

	chosenMutationPngFirst = "Menu/bethereorbesquare.png";
	chosenMutationPngSecond = "Menu/bethereorbesquare.png";
	chosenMutationPngThird = "Menu/bethereorbesquare.png";

	// not selected png due to selection reset
	specialOnePng = "Menu/bethereorbesquare.png";
	specialTwoPng = "Menu/bethereorbesquare.png";
	specialThreePng = "Menu/bethereorbesquare.png";

	startGameBtn->setEnabled(false);

	// enable all buttons due to selection reset
	mutationOneBtn->setEnabled(true);
	mutationTwoBtn->setEnabled(true);
	mutationThreeBtn->setEnabled(true);
	mutationFourBtn->setEnabled(true);
	mutationFiveBtn->setEnabled(true);

	currentCharacter = characterWithMutationClear;
}

void GeneSelection::startGame(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	Scene* scene = Load::createScene();
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(scene);
}


void GeneSelection::ChosenMutation(int mutationKind, string mutationPng/***DELETED, string specialPngSelected*/)
{
	if (specialOne == 0)
	{
		// first mutation information
		specialOne = mutationKind;
		chosenMutationPngFirst = mutationPng;
		//LevelOne::ButtonValues(1, specialOne, chosenMutationPngFirst, chosenMutationPngFirstSelected);

	}
	else if (specialTwo == 0)
	{
		// second mutation information
		specialTwo = mutationKind;
		chosenMutationPngSecond = mutationPng;
		//LevelOne::ButtonValues(2, specialTwo, chosenMutationPngSecond, chosenMutationPngSecondSelected);
	}
	else if (specialThree == 0)
	{
		// third mutation information
		specialThree = mutationKind;
		chosenMutationPngThird = mutationPng;
		//LevelOne::ButtonValues(3, specialThree, chosenMutationPngThird, chosenMutationPngThirdSelected);
		startGameBtn->setEnabled(true);

		mutationOneBtn->setEnabled(false);
		mutationTwoBtn->setEnabled(false);
		mutationThreeBtn->setEnabled(false);
		mutationFourBtn->setEnabled(false);
		mutationFiveBtn->setEnabled(false);
	}
	else
	{
		return;
	}
}