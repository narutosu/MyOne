#include "AppDelegate.h"
#include "TollgateScene.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("Don't Save Me!");
        director->setOpenGLView(glview);
    }
	glview->setFrameSize(640,960);

	glview->setDesignResolutionSize(480, 800, ResolutionPolicy::SHOW_ALL);

	director->setContentScaleFactor(0.3f);
    // turn on display FPS
    director->setDisplayStats(true);
    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
	auto tollScene = TollgateScene::scene();
    // create a scene. it's an autorelease object
	director->runWithScene(tollScene);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
