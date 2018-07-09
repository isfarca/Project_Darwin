#include "MainMenu.h"

// Create the prolog scene.
Scene* MainMenu::createScene()
{
	return MainMenu::create();
}

// Initializing.
bool MainMenu::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// INSERT PNG PATH LOCATION
	string infoPng = "Png/Info.png";
	string infoPngSelected = "Png/InfoSelected.png";

	string helpPng = "Png/help.png";
	string helpPngSelected = "Png/helpSelected.png";

	string levelSelectionPng = "Png/LevelSelection.png";
	string levelSelectionPngSelected = "Png/LevelSelectionSelected.png";

	string settingsPng = "Png/settings.png";
	string settingsPngSelected = "Png/settingsSelected.png";

	string exitGamePng = "exit.png";
	string exitGamePngSelected = "exitSelected.png";

	exitGameButton = MenuItemImage::create(exitGamePng, exitGamePngSelected, CC_CALLBACK_1(MainMenu::ExitGame, this));
	infoButton = MenuItemImage::create(infoPng, infoPngSelected, CC_CALLBACK_1(MainMenu::GoToInfoScene, this));
	//helpButton = MenuItemImage::create(helpPng, helpPngSelected, CC_CALLBACK_1(MainMenu::GoToHelpScene, this));
	levelSelectionButton = MenuItemImage::create(levelSelectionPng, levelSelectionPngSelected, CC_CALLBACK_1(MainMenu::GoToLevelSelectionScene, this));
	settingsButton = MenuItemImage::create(settingsPng, settingsPngSelected, CC_CALLBACK_1(MainMenu::GoToSettingsScene, this));

	auto menu = Menu::create(levelSelectionButton, settingsButton, infoButton, exitGameButton, nullptr);

	menu->setPosition(Point::ZERO);

	levelSelectionButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 50);
	settingsButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 100);
	infoButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 150);
	//helpButton->setPosition(visibleSize.width / 2, visibleSize.height / 2+200);
	exitGameButton->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 250);

	this->addChild(menu);

	return true;
}

// Scene handlings
void MainMenu::GoToSettingsScene(Ref* pSender)
{
	// Declare variables.
	Scene* scene = Settings::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenu::GoToInfoScene(Ref* pSender)
{
	// Declare variables.
	Scene* scene = Info::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenu::GoToHelpScene(Ref* pSender)
{
	Scene* scene = Help::createScene();

	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenu::GoToLevelSelectionScene(Ref* pSender)
{
	// Declare variables.
	Scene* scene = LevelSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

// ExitGame
void MainMenu::ExitGame(Ref* pSender)
{
	Director::getInstance()->end();
}