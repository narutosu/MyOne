#include "BackgroundLayer.h"
#include "TollgateScene.h"
BackgroundLayer::BackgroundLayer()
{
}
BackgroundLayer::~BackgroundLayer()
{
}
bool BackgroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}


	Size visibleSize = Director::getInstance()->getVisibleSize();
	m_bg1 = Sprite::createWithSpriteFrameName("background.jpg");
	m_bg1->setPosition(Vect(visibleSize.width/2,visibleSize.height/2));
	addChild(m_bg1);
	m_bg2 = Sprite::createWithSpriteFrameName("background.jpg");
	m_bg2->setPosition(Vect(visibleSize.width / 2, -visibleSize.height / 2));
	addChild(m_bg2);

	auto border = Sprite::createWithSpriteFrameName("border.png");
	Size borderSize = border->getContentSize();
	auto border1 = createBorder(Point(borderSize.width*0.5f,borderSize.height*0.5f));
	auto border2 = createBorder(Point(visibleSize.width-borderSize.width*0.5f, borderSize.height*0.5f));
	border2->setScaleX(-1);

	auto border3 = createBorder(Point(visibleSize.width*0.5f, visibleSize.height*0.15f));
	border3->setRotation(90.0f);
	return true;
}

Sprite* BackgroundLayer::createBorder(Point pos)
{
	auto border = Sprite::createWithSpriteFrameName("border.png");
	Size borderSize = border->getContentSize();
	auto body = PhysicsBody::createBox(borderSize);
	body->setDynamic(false);
	body->setCategoryBitmask(1);    // 0001
	body->setCollisionBitmask(1);   // 0001
	body->setContactTestBitmask(1); // 0001
	border->setPhysicsBody(body);
	border->setPosition(pos);
	this->addChild(border);
	return border;
}