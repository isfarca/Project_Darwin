#include "MainMenu.h"
#define BUTTON_SFX "sounds/Button_Sound.wav"

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
	string infoPng = "Menu/Info.png";
	string infoPngSelected = "Png/InfoSelected.png";

	string helpPng = "Menu/helppressed.png";
	string helpPngSelected = "Menu/help.png";

	string levelSelectionPng = "Menu/Play.png";
	string levelSelectionPngSelected = "Menu/playpressed.png";

	string settingsPng = "Menu/settings.png";
	string settingsPngSelected = "Menu/settingspressed.png";

	string exitGamePng = "Icons/exit.png";
	string exitGamePngSelected = "exitSelected.png";

	exitGameButton = MenuItemImage::create(exitGamePng, exitGamePngSelected, CC_CALLBACK_1(MainMenu::ExitGame, this));
	infoButton = MenuItemImage::create(infoPng, infoPngSelected, CC_CALLBACK_1(MainMenu::GoToInfoScene, this));
	//helpButton = MenuItemImage::create(helpPng, helpPngSelected, CC_CALLBACK_1(MainMenu::GoToHelpScene, this));
	levelSelectionButton = MenuItemImage::create(levelSelectionPng, levelSelectionPngSelected, CC_CALLBACK_1(MainMenu::GoToLevelSelectionScene, this));
	settingsButton = MenuItemImage::create(settingsPng, settingsPngSelected, CC_CALLBACK_1(MainMenu::GoToSettingsScene, this));

	settingsButton->setScale(0.15f, 0.15f);
	levelSelectionButton->setScale(0.15f, 0.15f);


	auto menu = Menu::create(levelSelectionButton, settingsButton, infoButton, exitGameButton, nullptr);

	menu->setPosition(Point::ZERO);

	levelSelectionButton->setPosition(Vec2(visibleSize.width / 2, 1000));
	settingsButton->setPosition(Vec2(visibleSize.width / 2, 800));
	infoButton->setPosition(Vec2(visibleSize.width / 2, 600));
	//helpButton->setPosition(visibleSize.width / 2, visibleSize.height / 2+200);
	exitGameButton->setPosition(Vec2(200, 1200));

	this->addChild(menu);

	return true;
}

// Scene handlings
void MainMenu::GoToSettingsScene(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	// Declare variables.
	Scene* scene = Settings::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenu::GoToInfoScene(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	// Declare variables.
	Scene* scene = Info::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenu::GoToHelpScene(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	Scene* scene = Help::createScene();

	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenu::GoToLevelSelectionScene(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	// Declare variables.
	Scene* scene = LevelSelection::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}

// ExitGame
void MainMenu::ExitGame(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->playEffect(BUTTON_SFX);
	Director::getInstance()->end();
}