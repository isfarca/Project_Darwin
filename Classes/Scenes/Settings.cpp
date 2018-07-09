#include "Settings.h"

// Create the prolog scene.
Scene* Settings::createScene()
{
	return Settings::create();
}

// Initializing.
bool Settings::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	return true;
}

// Scene handlings.
void Settings::GoToHelpScene(float delta)
{
	// Declare variables.
	Scene* scene = Help::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void Settings::GoToPrologScene(float delta)
{
	// Declare variables.
	Scene* scene = Prolog::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void Settings::GoToMainMenuScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}