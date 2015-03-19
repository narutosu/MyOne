#include "TollgateScene.h"
#include "BackgroundLayer.h"

TollgateScene::~TollgateScene()
{
}

Scene* TollgateScene::scene()
{
	auto scene = Scene::createWithPhysics();
	Vect gravity(0,-0.5f);
	scene->getPhysicsWorld()->setGravity(gravity);
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto body = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT,3);

	auto node = Node::create();
	node->setPosition(Vect(visibleSize.width / 2, visibleSize.height/2));
	node->setPhysicsBody(body);
	scene->addChild(node);
	auto layer = TollgateScene::create();
	scene->addChild(layer);
	return scene;
}

bool TollgateScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto cache = SpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("image/1mage.plist", "image/1mage.pvr");
	cache->retain();
	auto backLayer = BackgroundLayer::create();
	addChild(backLayer);
	return true; 
}

void TollgateScene::onExit()
{
	Layer::onExit();
}
