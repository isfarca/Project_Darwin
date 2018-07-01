#pragma once

#ifndef  APPDELEGATE_H
#define  APPDELEGATE_H

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class  AppDelegate : private Application
{
private:
	void initOpenGL();
	void initMultiResolution();
	void initDirector();
	void createAndRunScene();

public:
	virtual void initGLContextAttrs();
	virtual bool applicationDidFinishLaunching();
	virtual void applicationDidEnterBackground();
	virtual void applicationWillEnterForeground();
};

#endif