#pragma once
#include "main.h"

//�v���C���[
class Player :public Bace
{
private:
	bool ShotFlag = false;
public:
	int img{ 0 };//�摜
	Pos pos{ 0.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��
	//�R���X�g���N�^
	Player();

	int Action(list<Bace*>* bace);
	void Draw();
};

//�G
class Enemy :public Bace
{
private:
public:
	int img{ 0 };//�摜
	Pos pos{ 0.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��
	//�R���X�g���N�^
	Enemy(float _x, float _y);

	int Action(list<Bace*>* bace);
	void Draw();
};

//�e
class Bullet :public Bace
{
private:
	int hit = 0;//�����蔻��p
	float x = 0;
	float y = 0;

	//�G�l�~�[�̍��W��ۑ�����p
	float ex = 0;
	float ey = 0;

	Vec v = { 0.0f,0.0f };



public:
	int img{ 0 };//�摜
	Pos pos{ 0.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��
	//�R���X�g���N�^
	Bullet(float _x, float _y, int _ID);

	int Action(list<Bace*>* bace);
	void Draw();
};