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

	return true;
}

// Scene handlings
void MainMenu::GoToSettingsScene(float delta)
{
	// Declare variables.
	Scene* scene = Settings::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenu::GoToInfoScene(float delta)
{
	// Declare variables.
	Scene* scene = Info::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void MainMenu::GoToLevelSelectionScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}