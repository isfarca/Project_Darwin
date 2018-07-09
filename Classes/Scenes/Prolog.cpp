#include "Prolog.h"

// Create the prolog scene.
Scene* Prolog::createScene()
{
	return Prolog::create();
}

// Initializing.
bool Prolog::init()
{
	// When the scene don't init, then stop the init process.
	if (!Scene::init())
		return false;

	return true;
}

// Scene handlings.
void Prolog::GoToMainMenuScene(float delta)
{
	// Declare variables.
	Scene* scene = MainMenu::createScene();

	// Replace the scene.
	this->removeAllChildrenWithCleanup(true);
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}