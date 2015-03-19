#pragma once
#include "cocos2d.h"
USING_NS_CC;
class BackgroundLayer : public Layer
{
public:
	BackgroundLayer();
	~BackgroundLayer();
	CREATE_FUNC(BackgroundLayer);
	virtual bool init();
private:
	Sprite* m_bg1;
	Sprite* m_bg2;
	Sprite* createBorder(Point pos);
};