#include "TouchScene.h"

USING_NS_CC;


 /*  Handle Touch/Click Events
Scene* TouchScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TouchScene::create();
	scene->addChild(layer);

	return scene;
}

bool TouchScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	labelTouchInfo = Label::createWithSystemFont("Touch or clicksomewhere to begin", "Arial", 30);

	labelTouchInfo->setPosition(Vec2(
		Director::getInstance()->getVisibleSize().width / 2,
		Director::getInstance()->getVisibleSize().height / 2));

	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(TouchScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(TouchScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(TouchScene::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(TouchScene::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	this->addChild(labelTouchInfo);
	return true;
}

bool TouchScene::onTouchBegan(Touch* touch, Event* event)
{
	labelTouchInfo->setPosition(touch->getLocation());
	labelTouchInfo->setString("You Touched Here");
	return true;
}

void TouchScene::onTouchEnded(Touch* touch, Event* event)
{
	cocos2d::log("touch ended");
}

void TouchScene::onTouchMoved(Touch* touch, Event* event)
{
	cocos2d::log("touch moved");
}

void TouchScene::onTouchCancelled(Touch* touch, Event* event)
{
	cocos2d::log("touch cancelled");
}

// */

Scene* TouchScene::createScene()
{
	auto scene = Scene::create();
	auto layer = TouchScene::create();
	scene->addChild(layer);

	return scene;
}

bool TouchScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
		Director::getInstance()->getVisibleSize().height / 2));

	// Add a "touch" event listener to our sprite
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {

		auto bounds = event->getCurrentTarget()->getBoundingBox();

		if (bounds.containsPoint(touch->getLocation())) {
			std::stringstream touchDetails;
			touchDetails << "Touched at OpenGL coordinates: " <<
				touch->getLocation().x << "," << touch->getLocation().y << std::endl <<
				"Touched at UI coordinate: " <<
				touch->getLocationInView().x << "," << touch->getLocationInView().y << std::endl <<
				"Touched at local coordinate:" <<
				event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).x << "," <<
				event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).y << std::endl <<
				"Touch moved by:" << touch->getDelta().x << "," << touch->getDelta().y;

			MessageBox(touchDetails.str().c_str(), "Touched");
		}
		return true;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, sprite);
	this->addChild(sprite, 0);

	return true;
}