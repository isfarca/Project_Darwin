#include "Info.h"

// Create the prolog scene.
Scene* Info::createScene()
{
	return Info::create();
}

// Initializing.
bool Info::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	return true;
}

// Scene handlings
void Info::GoToCreditsScene(float delta)
{
	// Declare variables.
	Scene* scene = Credits::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
void Info::GoToMainMenuScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}