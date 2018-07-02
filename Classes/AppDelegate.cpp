#include "AppDelegate.h"
#include "Scenes/Load.h"
#include "Scenes/MainMenu.h"



static Size designResolutionSize = Size(2048, 1536);
static Size smallResolutionSize = Size(512, 384);
static Size mediumResolutionSize = Size(1024, 768);
static Size largeResolutionSize = Size(2048, 1536);

void AppDelegate::initMultiResolution()
{
	// Declare variables.
	Director *director = Director::getInstance();
	GLView *glview = director->getOpenGLView();
	vector<string> searchPaths;
	float scaleFactor = 1.0f;
	Size frameSize;

	glview->setDesignResolutionSize
	(
		designResolutionSize.width,
		designResolutionSize.height,
		ResolutionPolicy::NO_BORDER
	);

	frameSize = glview->getFrameSize();

	if (frameSize.height > mediumResolutionSize.height)
	{
		searchPaths.push_back("res/HDR");
		scaleFactor = largeResolutionSize.height / designResolutionSize.height;
	}
	else if (frameSize.height > smallResolutionSize.height)
	{
		searchPaths.push_back("res/HD");
		scaleFactor = mediumResolutionSize.height / designResolutionSize.height;
	}
	else
	{
		searchPaths.push_back("res/SD");
		scaleFactor = smallResolutionSize.height / designResolutionSize.height;
	}

	director->setContentScaleFactor(scaleFactor);
	FileUtils::getInstance()->setSearchPaths(searchPaths);
}

void AppDelegate::initOpenGL()
{
	// Declare variables.
	Director* director = Director::getInstance();
	GLView* glview = director->getOpenGLView();

	if (!glview)
	{
		#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
			glview = GLViewImpl::createWithRect("Darwin", Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
		#else
			glview = GLViewImpl::create("Darwin");
		#endif

		director->setOpenGLView(glview);
	}
}

void AppDelegate::initDirector()
{
	// Declare variables.
	Director *director = Director::getInstance();

	director->setAnimationInterval(1.0f / 60);
	director->setDisplayStats(false);
}

void AppDelegate::createAndRunScene()
{
	// Declare variables.
	Scene *scene = MainMenu::createScene();

	Director::getInstance()->runWithScene(scene);
}

bool AppDelegate::applicationDidFinishLaunching()
{
	initOpenGL();
	initDirector();
	initMultiResolution();
	createAndRunScene();

	return true;
}

void AppDelegate::applicationDidEnterBackground()
{
	Director::getInstance()->stopAnimation();
	// SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground()
{
	Director::getInstance()->startAnimation();
	// SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };
	GLView::setGLContextAttrs(glContextAttrs);
}