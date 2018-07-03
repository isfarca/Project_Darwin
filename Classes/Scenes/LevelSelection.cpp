#include "LevelSelection.h"
#include <string>

// Create the prolog scene.
Scene* LevelSelection::createScene()
{
	return LevelSelection::create();
}

// Initializing.
bool LevelSelection::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	int selectedLevel = 0;
	
	// LEVEL PNG PATH

	string levelOnePng = "Png/Level_1.png";
	string levelOnePngSelected = "Png/Level_1Selected.png";
	string levelOnePngBlocked = "";

	string levelTwoPng = "Png/Level_2.png";
	string levelTwoPngSelected = "Png/Level_2Selected.png";
	string levelTwoPngBlocked = "";

	string levelThreePng = "Png/Level_3.png";
	string levelThreePngSelected = "Png/Level_3Selected.png";
	string levelThreePngBlocked = "Png/.png";

	string levelFourPng = "Png/Level_4.png";
	string levelFourPngSelected = "Png/Level_4Selected.png";
	string levelFourPngBlocked = "Png/.png";


	// MENU PNG PATH

	string goToMainMenuPng = "";
	string goToMainMenuPngSelected = "";

	string goToGeneSelectionPng = "Png/continue.png";
	string goToGeneSelectionPngSelected = "Png/continue.png";
	

	// Buttons
	levelOneButton = MenuItemImage::create(levelOnePng, levelOnePngSelected, CC_CALLBACK_1(LevelSelection::StartLevelOne, this));
	levelTwoButton = MenuItemImage::create(levelTwoPng, levelTwoPngSelected, CC_CALLBACK_1(LevelSelection::StartLevelTwo, this));
	levelThreeButton = MenuItemImage::create(levelThreePng, levelThreePngSelected, CC_CALLBACK_1(LevelSelection::StartLevelThree, this));
	levelFourButton = MenuItemImage::create(levelFourPng, levelFourPngSelected, CC_CALLBACK_1(LevelSelection::StartLevelFour, this));

	goToMainMenuButton = MenuItemImage::create(goToMainMenuPng, goToMainMenuPngSelected, CC_CALLBACK_1(LevelSelection::GoToMainMenuScene, this));
	goToGeneSelectionButton = MenuItemImage::create(goToGeneSelectionPng, goToGeneSelectionPngSelected, CC_CALLBACK_1(LevelSelection::GoToGeneSelectionScene, this));


	auto menu = Menu::create(levelOneButton, levelTwoButton, levelThreeButton, levelFourButton, goToMainMenuButton,goToGeneSelectionButton, nullptr);


	menu->setPosition(Point::ZERO);

	//Level Selection Position
	levelOneButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 50);
	levelTwoButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 100);
	levelThreeButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 150);
	levelFourButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 200);

	goToMainMenuButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 400);
	goToGeneSelectionButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 450);

	this->addChild(menu);

	return true;
}




// Scene handlings
void LevelSelection::GoToMainMenuScene(Ref *pSender)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void LevelSelection::GoToGeneSelectionScene(Ref *pSender)
{
	// Declare variables.
	Scene* scene = GeneSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void LevelSelection::StartLevelOne(Ref *pSender) 
{
	Scene* scene = GeneSelection::createScene();
	selectedLevel = 1;
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void LevelSelection::StartLevelTwo(Ref *pSender)
{
	Scene* scene = GeneSelection::createScene();
	selectedLevel = 2;
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}

void LevelSelection::StartLevelThree(Ref *pSender)
{
	Scene* scene = GeneSelection::createScene();
	selectedLevel = 3;
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

void LevelSelection::StartLevelFour(Ref *pSender)
{
	Scene* scene = GeneSelection::createScene();
	selectedLevel = 4;
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}