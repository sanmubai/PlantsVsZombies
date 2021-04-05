/**
 *Copyright (c) 2020 LZ.All Right Reserved
 *Author : LZ
 *Date: 2020.2.6
 *Email: 2117610943@qq.com
 */

#pragma once
#include "LZBattlePlants.h"

class PotatoMine :public BattlePlants
{
public:
	static PotatoMine* create(Node* node = nullptr);
	void setBreakGround(const float time);
	float getBreakGround() const;
	Sprite* createPlantImage() override;
	void createPlantAnimation() override;
	void determineRelativePositionPlantsAndZombies() override;

CC_CONSTRUCTOR_ACCESS:
	PotatoMine(Node* node = nullptr);
	~PotatoMine();

private:
	void plantExplode() override;
	void zombieEatPlant(Zombies* zombie) override;
	void cavePlantInformation(rapidjson::Value& object, rapidjson::Document::AllocatorType& allocator) override;
	void readPlantInforamtion(rapidjson::Document* levelDataDocument, char* key, int i) override;
	SkeletonAnimation* showPlantAnimationAndText() override;
	void createListener();
	void explodeHurtZombies();
	bool getZombieIsInExplodeRange(Zombies* zombie) override;
	
private:
	bool _isReady;                 // �Ƿ�׼����
	bool _isExplodeFinished;       // �Ƿ�ը���
	bool _isBeginExplode;          // �Ƿ�ʼ��ը
	bool _isCanKillZombies;        // �Ƿ����ɱ�ֽ�ʬ
	bool _isKillZombiesFinished;   // �Ƿ�ɱ����ʬ����
	bool _isReadFile;              // �Ƿ��ȡ�ļ�
	float _breakGround;            // ����ʱ��
};