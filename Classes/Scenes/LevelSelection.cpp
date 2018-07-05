#include "LevelSelection.h"

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
	string levelFourPngBlocked = "Png/nothingSelected.png";

	// MENU PNG PATH
	string goToMainMenuPng = "";
	string goToMainMenuPngSelected = "";

	//string goToGeneSelectionPng = "Png/continue.png"; **********DELETED
	//string goToGeneSelectionPngSelected = "Png/continue.png"; **********DELETED

	// Buttons
	levelOneButton = MenuItemImage::create(levelOnePng, levelOnePngSelected, levelOnePngBlocked,CC_CALLBACK_1(LevelSelection::StartLevelOne, this));
	levelTwoButton = MenuItemImage::create(levelTwoPng, levelTwoPngSelected, levelTwoPngBlocked, CC_CALLBACK_1(LevelSelection::StartLevelTwo, this));
	levelThreeButton = MenuItemImage::create(levelThreePng, levelThreePngSelected, levelThreePngBlocked, CC_CALLBACK_1(LevelSelection::StartLevelThree, this));
	levelFourButton = MenuItemImage::create(levelFourPng, levelFourPngSelected, levelFourPngBlocked, CC_CALLBACK_1(LevelSelection::StartLevelFour, this));

	goToMainMenuButton = MenuItemImage::create(goToMainMenuPng, goToMainMenuPngSelected, CC_CALLBACK_1(LevelSelection::GoToMainMenuScene, this));
	//goToGeneSelectionButton = MenuItemImage::create(goToGeneSelectionPng, goToGeneSelectionPngSelected, CC_CALLBACK_1(LevelSelection::GoToGeneSelectionScene, this)); **********DELETED

	auto menu = Menu::create(levelOneButton, levelTwoButton, levelThreeButton, levelFourButton, goToMainMenuButton,/* goToGeneSelectionButton**********DELETED,*/ nullptr);

	menu->setPosition(Point::ZERO);

	//Level Selection Position
	levelOneButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 50);
	levelTwoButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 100);
	levelThreeButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 150);
	levelFourButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 200);

	goToMainMenuButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 400);
	//goToGeneSelectionButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 450); **********DELETED

	levelTwoButton->setEnabled(false);
	levelThreeButton->setEnabled(false);
	levelFourButton->setEnabled(false);

	this->addChild(menu);

	return true;
}

// Scene handlings
void LevelSelection::GoToMainMenuScene(Ref* pSender)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}


void LevelSelection::GoToGeneSelectionScene(Ref* pSender)
{
	// Declare variables.
	Scene* scene = GeneSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

// Set level id.
void LevelSelection::StartLevelOne(Ref* pSender)
{
	Scene* scene = GeneSelection::createScene();
	LevelManager::SetLevelId(1);
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(scene);
}
void LevelSelection::StartLevelTwo(Ref* pSender)
{
	Scene* scene = GeneSelection::createScene();
	LevelManager::SetLevelId(2);
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(scene);

}
void LevelSelection::StartLevelThree(Ref* pSender)
{
	Scene* scene = GeneSelection::createScene();
	LevelManager::SetLevelId(3);
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(scene);
}
void LevelSelection::StartLevelFour(Ref* pSender)
{
	Scene* scene = GeneSelection::createScene();
	LevelManager::SetLevelId(4);
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(scene);
}