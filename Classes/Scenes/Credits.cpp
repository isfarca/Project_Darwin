#include "Credits.h"

// Create the credits scene.
Scene* Credits::createScene()
{
	return Credits::create();
}

// Initializing.
bool Credits::init()
{
	// When the scene doesn't init, then stop the init process.
	if (!Scene::init())
		return false;

	return true;
}

// Scene handlings
void Credits::GoToMainMenuScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}