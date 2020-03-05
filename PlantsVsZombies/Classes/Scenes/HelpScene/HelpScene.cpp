/**
 *Copyright (c) 2019 LZ.All Right Reserved
 *Author : LZ
 *Date: 2019.7.1
 *Email: 2117610943@qq.com
 */

#include "HelpScene.h"
#include "Scenes/MainMenuScene/MainMenu.h"
#include "ui/CocosGUI.h"
#include "Scenes/EasterEggsScene/GameEasterEggs.h"

Scene* HelpScene::createHelpScene()
{
	return HelpScene::create();
}

bool HelpScene::init()
{
	if (!Scene::init()) return false;

	AudioEngine::setVolume(AudioEngine::play2d(_global->userInformation->getMusicPath().find("paper")->second), _global->userInformation->getSoundEffectVolume());

	createBackground();
	createText();
	createGithubUrl();
	createButton();
	
	return true;
}

void HelpScene::createBackground()
{
	/* ��ȡ���ڴ�С */
	auto const size = Director::getInstance()->getWinSize();

	auto layerColor = LayerColor::create(Color4B(30, 180, 190, 200));
	this->addChild(layerColor);

	auto rotate = Sprite::createWithSpriteFrameName("RunBackground.png");
	rotate->setScale(7.f);
	rotate->setPosition(size / 2);
	this->addChild(rotate);
	rotate->runAction(RepeatForever::create(RotateBy::create(1.0f, -10)));

	auto WorldBackgroundBlack = Sprite::createWithSpriteFrameName("WorldBackgroundBlack.png");
	auto WorldBackgroundBlack1 = Sprite::createWithSpriteFrameName("WorldBackgroundBlack.png");
	WorldBackgroundBlack->setAnchorPoint(Vec2(0, 1));
	WorldBackgroundBlack->setPosition(Vec2(0, 1140));
	WorldBackgroundBlack1->setAnchorPoint(Vec2(0, 0));
	WorldBackgroundBlack1->setPosition(Vec2(0, -60));
	WorldBackgroundBlack1->setFlippedY(true);
	this->addChild(WorldBackgroundBlack);
	this->addChild(WorldBackgroundBlack1);
}

void HelpScene::createText()
{
	/* �������ֱ��� */
	auto note = Sprite::createWithSpriteFrameName("ZombieNote.png");
	note->setScale(1.7f);
	note->setScaleX(2.2f);
	note->setPosition(Vec2(_size.width / 2 + 50, _size.height / 2));
	this->addChild(note);

	auto helptext = Label::createWithTTF("\
		����Ϸȫ���ɱ����Լ�������ɡ��˰汾Ϊ���԰�(����һ���Ŀ�����)�����᲻��ʱ���£��������ƣ���Ŀǰ�Ҽ�����\
����Ŀ��Դ�뿪Դ����GitHub���ڴ˸�л��ҵĹ�ע����                                    ��\n\
		��Ϸ�󲿷ֵ��ز���Դ��ԭ����Ϸ�زģ��ٲ����Ѽ������磬�Լ��Լ�������\n\
		����������Ҫ������ϷΪͬ����Ϸ���ҽ���ѧϰ����ʹ�ã�������Ϸ��Դ���ܴ�����Ȩ�����⣬��������������ҵ��;���������Ը���\n\
		Ŀǰ��7�ֽ�ʬ��13��ֲ�ֲ��ͽ�ʬ�Ķ������Ǳ������ģ��������������������ޣ���Щ��ʬ��ֲ�ﶯ������ʵ�֣�\
�����������������Ը������ҵ��˿���˽���ң���������spine���������Ĺ�����������������ֳ�����ʲô������߶���Ϸ��\
ʲô������Է��͵��ҵ�qq��2117610943\n������˵�������������ť������ת��������ַ���ٶ�������ȡ��3vzm)", "resources/fonts/GameFont.ttf", 35);

	helptext->setPosition(_size / 2.0f);
	helptext->setColor(Color3B::BLACK);
	helptext->setMaxLineWidth(1100);
	this->addChild(helptext);
}

void HelpScene::createGithubUrl()
{
	auto github = Button::create();
	github->setTitleFontName("resources/fonts/GameFont.ttf");
	github->setTitleFontSize(35);
	github->setTitleText("����˴���github��Ŀ");
	github->setPosition(Vec2(1220, 740));
	github->setTitleColor(Color3B(0, 255, 255));
	github->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
		{
			switch (type)
			{
			case Widget::TouchEventType::BEGAN:
				AudioEngine::setVolume(AudioEngine::play2d(_global->userInformation->getMusicPath().find("tap2")->second), _global->userInformation->getSoundEffectVolume());
				break;
			case Widget::TouchEventType::ENDED:
				Application::getInstance()->openURL("https://github.com/ErLinErYi/PlantsVsZombies");
				break;
			}
		});
	this->addChild(github);
	
	auto draw = DrawNode::create();
	draw->drawLine(Vec2(0, 5), Vec2(github->getContentSize().width, 5), Color4F(0, 1, 1, 1));
	draw->setLineWidth(2);
	github->addChild(draw);
}

void HelpScene::createButton()
{
	/* ������ť */
	auto button = Button::create("SeedChooser_Button2.png", "SeedChooser_Button2_Glow.png", "", TextureResType::PLIST);
	button->setTitleText(_global->userInformation->getGameText().find("���˵�")->second);
	button->setTitleColor(Color3B(0, 255, 255));
	button->setTitleFontSize(18);
	button->setScale(2.0f);
	button->setPosition(Vec2(_size.width / 2, 100));
	this->addChild(button);
	button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
		{
			switch (type)
			{
			case Widget::TouchEventType::BEGAN:
				AudioEngine::setVolume(AudioEngine::play2d(_global->userInformation->getMusicPath().find("tap2")->second), _global->userInformation->getSoundEffectVolume());
				break;
			case Widget::TouchEventType::ENDED:
				Director::getInstance()->replaceScene(MainMenu::createScene());
				break;
			}
		});

}