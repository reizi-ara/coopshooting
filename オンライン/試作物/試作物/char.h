#pragma once
#include "main.h"

//�v���C���[
class Player :public Bace
{
private:
public:
	int img{ 0 };//�摜
	Pos pos{ 0.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��
	//�R���X�g���N�^
	Player();

	int Action(list<unique_ptr<Bace>>& bace);
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

	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};