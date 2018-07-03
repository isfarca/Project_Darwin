/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    //printf("Error while loading: %s\n", filename);
    //printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{

	

	/*
	//for soundtrack from tutorial
	if (!Layer::init())
		return false;

	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->preloadBackgroundMusic("song.mp3");
	audio->playBackgroundMusic("song.mp3");

	auto eventListener = cocos2d::EventListenerKeyboard::create();
	eventListener->onKeyPressed = [audio](EventKeyboard::KeyCode keyCode, Event* event) {

		switch (keyCode) {
		case EventKeyboard::KeyCode::KEY_SPACE:
			if (audio->isBackgroundMusicPlaying())
				audio->pauseBackgroundMusic();
			else
				audio->resumeBackgroundMusic();
			break;

		case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
			audio->playBackgroundMusic("song2.mp3");
			break;

		case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
			audio->playBackgroundMusic("song.mp3");
			break;
		}
	};

	_eventDispatcher->addEventListenerWithFixedPriority(eventListener, 2);

	return true;
	*/

	if (!Scene::init())
		return false;

	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();

	audio->preloadEffect("gun-cocking-01.wav");
	audio->preloadEffect("gun-shot-01.wav");

	audio->playEffect("gun-cocking-01.wav");

	Director::getInstance()->getScheduler()->schedule([audio](float delta) {
		audio->playEffect("gun-gunshot-01.wav");
		audio->unloadEffect("gun-cocking-01.wav");
	}, this, 1.5f, 0, 0.0f, false, "myCallbackKey");

	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
