#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "GameScene.h"
#include "behaviac/agent/agent.h"
#include "hero.h"
#include "NPC.h"
#include "enemy.h"
// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);



AppDelegate::AppDelegate()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	FileUtils::getInstance()->addSearchPath("../../res/");
#else
	FileUtils::getInstance()->addSearchPath("res/");
#endif

#if BEHAVIAC_COMPILER_ANDROID && (BEHAVIAC_COMPILER_ANDROID_VER > 8)
	behaviac::CFileManager::GetInstance()->SetAssetManager(cocos2d::FileUtilsAndroid::getAssetManager());
#endif

	//std::string path = cocos2d::FileUtils::getInstance()->fullPathForFilename("behaviac/data.xml");
	//std::string path = "./exported";
	std::string path = cocos2d::FileUtils::getInstance()->fullPathForFilename("exported/fish.xml");
	path = path.substr(0, path.rfind('/'));
	behaviac::Config::SetSocketBlocking(false);

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	//auto expPath = path;
	//expPath.append("/data.xml");
	//behaviac::Workspace::GetInstance()->ExportMetas(expPath.c_str());
#endif
	//CCLOG("--->PATH:%s\n", path.c_str());
	//path = path.append("./exported/");

	CCLOG("--->PATH:%s\n", path.c_str());
	behaviac::Workspace::GetInstance()->SetFilePath(path.c_str());
	//behaviac::Workspace::GetInstance()->SetFilePath("./exported");
	behaviac::Workspace::GetInstance()->SetFileFormat(behaviac::Workspace::EFF_xml);
	CCLOG("--->PATH:%s\n", path.c_str());
	CCLOG("behaviac::Workspace::GetInstance()->GetFilePath:%s", behaviac::Workspace::GetInstance()->GetFilePath());

	//behaviac::Agent::Register<NPC>();
	//behaviac::Agent::Register<Hero>();
	//behaviac::Agent::Register<Enemy>();
	//behaviac::TypeRegister::Register<NPC::refresh_delay>("NPC::refresh_delay");



	//if (!cl.IsProfiling())
	//{
	//    behaviac::Agent::SetIdMask(kIdMask_Wolrd | kIdMask_Opponent);
	//}

	behaviac::Config::SetLogging(true);
}

AppDelegate::~AppDelegate()
{
#if USE_AUDIO_ENGINE
	AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
	SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
	// set OpenGL context attributes: red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
	return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("AirBattleDemo", Rect(0, 0, 540, 960)); //设置PC端的设备分辨率，窗口名。在移动端这行代码无效。
		//glview = GLViewImpl::createWithRect("spaceship", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
		glview = GLViewImpl::create("spaceship");
#endif
		director->setOpenGLView(glview);
	}

	// turn on display FPS
	director->setDisplayStats(true);

	// set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0f / 60);

	// Set the design resolution
	//glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
	glview->setDesignResolutionSize(540, 960, ResolutionPolicy::SHOW_ALL); //设置游戏分辨率，尚未适配移动设备屏幕。
	auto frameSize = glview->getFrameSize();
	// if the frame's height is larger than the height of medium size.
	if (frameSize.height > mediumResolutionSize.height)
	{
		director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height, largeResolutionSize.width / designResolutionSize.width));
	}
	// if the frame's height is larger than the height of small size.
	else if (frameSize.height > smallResolutionSize.height)
	{
		director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height, mediumResolutionSize.width / designResolutionSize.width));
	}
	// if the frame's height is smaller than the height of medium size.
	else
	{
		director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height, smallResolutionSize.width / designResolutionSize.width));
	}

	register_all_packages();

	// create a scene. it's an autorelease object
	//auto scene = HelloWorld::createScene();

	// run
	//director->runWithScene(scene);

	auto scene = GameScene::createScene();

	director->runWithScene(scene);

	return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
	AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
	SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
	AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
	SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}
