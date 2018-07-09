#include "GeneSelection.h"

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

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// png reference mutation
	mutationOnePng = "Png/Mutation/mutation1.png";
	mutationOnePngSelected = "Png/Mutation/mutation1Selected.png";
	mutationOnePngBlocked = "Png/nothingSelected.png";

	mutationTwoPng = "Png/Mutation/mutation2.png";
	mutationTwoPngSelected = "Png/Mutation/mutation2Selected.png";
	mutationTwoPngBlocked = "Png/nothingSelected.png";

	mutationThreePng = "Png/Mutation/mutation3.png";
	mutationThreePngSelected = "Png/Mutation/mutation3Selected.png";
	mutationThreePngBlocked = "Png/nothingSelected.png";

	mutationFourPng = "Png/Mutation/mutation4.png";
	mutationFourPngSelected = "Png/Mutation/mutation4Selected.png";
	mutationFourPngBlocked = "Png/nothingSelected.png";

	mutationFivePng = "Png/Mutation/mutation5.png";
	mutationFivePngSelected = "Png/Mutation/mutation5Selected.png";
	mutationFivePngBlocked = "Png/nothingSelected.png";

	// Available character mutations png
	characterWithMutationOne = "Png/Mutation/mutation1.png";
	characterWithMutationTwo = "Png/Mutation/mutation2.png";
	characterWithMutationThree = "Png/Mutation/mutation3.png";
	characterWithMutationFour = "Png/Mutation/mutation4.png";
	characterWithMutationFive = "Png/Mutation/mutation5.png";

	characterWithMutationClear = "Png/nothingSelected.png";

	currentCharacter = "Png/nothingSelected.png";


	// png reference start
	startPng = "Png/continue.png";
	startPngSelected = "Png/continueSelected.png";


	// png reference reset
	reset = "Png/Mutation/reset.png";
	resetSelected = "Png/Mutation/resetSelected";

	// mutations that are selected PNG reference
	chosenMutationPngFirst = "Png/nothingSelected.png";
	chosenMutationPngSecond = "Png/nothingSelected.png";
	chosenMutationPngThird = "Png/nothingSelected.png";

	// png reference return to MainMenu/GeneSelection

	returnToMainMenuPng = "MainMenu.png";
	returnToMainMenuPngSelected = "MainMenuSelected.png";

	returnToLevelSelectionPng = "BackToLevelSelection.png";
	returnToLevelSelectionPngSelected = "BackToLevelSelectionSelected.png";

	// mutations that are selected Sprite create
	firstGeneSprite = Sprite::create(chosenMutationPngFirst);
	secondGeneSprite = Sprite::create(chosenMutationPngSecond);
	thirdGeneSprite = Sprite::create(chosenMutationPngThird);

	// current character mutation png
	ChosenCharacterMutation = Sprite::create(currentCharacter);

	// mutation buttons created
	mutationOneBtn = MenuItemImage::create(mutationOnePng, mutationOnePngSelected, mutationOnePngBlocked, CC_CALLBACK_1(GeneSelection::mutationOne, this));
	mutationTwoBtn = MenuItemImage::create(mutationTwoPng, mutationTwoPngSelected, mutationTwoPngBlocked, CC_CALLBACK_1(GeneSelection::mutationTwo, this));
	mutationThreeBtn = MenuItemImage::create(mutationThreePng, mutationThreePngSelected, mutationThreePngBlocked, CC_CALLBACK_1(GeneSelection::mutationThree, this));
	mutationFourBtn = MenuItemImage::create(mutationFourPng, mutationFourPngSelected, mutationFourPngBlocked, CC_CALLBACK_1(GeneSelection::mutationFour, this));
	mutationFiveBtn = MenuItemImage::create(mutationFivePng, mutationFivePngSelected, mutationFivePngBlocked, CC_CALLBACK_1(GeneSelection::mutationFive, this));

	// start game button create
	startGameBtn = MenuItemImage::create(startPng, startPngSelected, CC_CALLBACK_1(GeneSelection::startGame, this));


	// MainMenu / Return to Level Selection create
	returnToMainMenuBtn = MenuItemImage::create(returnToMainMenuPng, returnToMainMenuPngSelected, CC_CALLBACK_1(GeneSelection::ReturnToMainMenu, this));

	returnToLevelSelectionBtn = MenuItemImage::create(returnToLevelSelectionPng,returnToLevelSelectionPngSelected, CC_CALLBACK_1(GeneSelection::ReturnToLevelSelection, this));

	// reset selected mutations create
	resetSelectedMutationBtn = MenuItemImage::create(reset, resetSelected, CC_CALLBACK_1(GeneSelection::ResetSelectedMutation, this));

	auto menu = Menu::create(mutationOneBtn, mutationTwoBtn, mutationThreeBtn, mutationFourBtn, mutationFiveBtn, resetSelectedMutationBtn, startGameBtn,returnToMainMenuBtn, returnToLevelSelectionBtn, nullptr);
	menu->setPosition(Point::ZERO);

	// mutation button position
	mutationOneBtn->setPosition(Vec2(visibleSize.width / 2 - 800, 1200));
	mutationTwoBtn->setPosition(Vec2(visibleSize.width / 2 - 800, 1150));
	mutationThreeBtn->setPosition(Vec2(visibleSize.width / 2 - 800, 1100));
	mutationFourBtn->setPosition(Vec2(visibleSize.width / 2 - 800, 1050));
	mutationFiveBtn->setPosition(Vec2(visibleSize.width / 2 - 800, 1000));

	// MainMenu / LevelSelection button position
	returnToMainMenuBtn->setPosition(Vec2(visibleSize.width / 2 + 800, 1200));
	returnToLevelSelectionBtn->setPosition(Vec2(visibleSize.width / 2 + 700, 1200));


	//ChosenCharacterMutation->setPosition(Vec2(visibleSize.width / 2 + 300, 1200));

	// selected mutations sprite position
	//firstGeneSprite->setPosition(Vec2(visibleSize.width / 2, 1000));
	//secondGeneSprite->setPosition(Vec2(visibleSize.width / 2, 950));
	//thirdGeneSprite->setPosition(Vec2(visibleSize.width / 2, 900));

	// reset selected mutations position	
	resetSelectedMutationBtn->setPosition(Vec2(visibleSize.width / 2 - 800, 800));

	// start game button position
	startGameBtn->setPosition(Vec2(visibleSize.width / 2 , 300));

	startGameBtn->setEnabled(false);

	// adding to scene
	this->addChild(firstGeneSprite);
	this->addChild(secondGeneSprite);
	this->addChild(thirdGeneSprite);

	this->addChild(ChosenCharacterMutation);

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



	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	ChosenCharacterMutation->setPosition(visibleSize.width / 2 + 500, visibleSize.height / 2);

	// selected gene position
	firstGeneSprite->setPosition(Vec2(visibleSize.width / 2, 1000));
	secondGeneSprite->setPosition(Vec2(visibleSize.width / 2, 950));
	thirdGeneSprite->setPosition(Vec2(visibleSize.width / 2, 900));

	this->addChild(firstGeneSprite);
	this->addChild(secondGeneSprite);
	this->addChild(thirdGeneSprite);
	this->addChild(ChosenCharacterMutation);
}
	// MainMenu
void GeneSelection::ReturnToMainMenu(Ref* pSender)
{
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}

void GeneSelection::ReturnToLevelSelection(Ref* pSender)
{
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
	specialOne = 0;
	specialTwo = 0;
	specialThree = 0;

	chosenMutationPngFirst = "Png/nothingSelected.png";
	chosenMutationPngSecond = "Png/nothingSelected.png";
	chosenMutationPngThird = "Png/nothingSelected.png";

	// not selected png due to selection reset
	specialOnePng = "Png/nothingSelected.png";
	specialTwoPng = "Png/nothingSelected.png";
	specialThreePng = "Png/nothingSelected.png";

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