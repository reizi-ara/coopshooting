#pragma once
#include "main.h"

//�v���C���[
class Player :public Bace
{
private:
	bool ShotFlag = false;
	bool Shot_Flag = false;

	//���[�U�[�e�ۂ�3���Ń����[�h�͏\�b
	int lb = 3;

	int time = 0;

public:
	int img{ 0 };//�摜
	Pos pos{ 0.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��
	//�R���X�g���N�^
	Player();

	//hp�̒l
	int hp = 1;

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
	Enemy(float _x, float _y,int _id,float _vx,float _vy,float speed);

	int hp = 10;//hp�̒l
	int time = 0;//���ԂŒe���Ǘ�����p

	bool e_hit;

	float e_speed = 0.0f;

	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};


//�G:�{�X
class boss :public Bace
{
private:

public:
	int img{ 0 };//�摜
	Pos pos{ 0.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��
	//�R���X�g���N�^
	boss(float _x, float _y, int _id);

	int hp = 30;//hp�̒l
	int time = 0;//���ԂŒe���Ǘ�����p

	bool e_hit;
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};

//�e
class Bullet :public Bace
{
private:
	float x = 0;
	float y = 0;

	//�G�l�~�[�̍��W��ۑ�����p
	float ex = 0;
	float ey = 0;

	//player�̍��W��ۑ�����p
	float px = 0;
	float py = 0;

	//boss�̍��W��ۑ�����p
	float bx = 0;
	float by = 0;

	Vec v = { 0.0f,0.0f };

	//���ꂼ��̓����������̔���p�t���O
	bool eb_hit = false;
	bool pb_hit = false;
	bool bb_hit = false;

	int Hit_id = 0;

public:
	int img{ 0 };//�摜
	int img1{ 0 };
	Pos pos{ 250.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��

	bool flag = true;
	//�����蔻��p
	int hit = -1;

	bool hit_bullet() { return eb_hit; }
	//�R���X�g���N�^
	Bullet(float _x, float _y, int _ID,float _vy);

	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};

//�G�@�U�e
class ShotGunEnemy :public Bace
{
private:
	//player�̍��W��ۑ�����p
	float px = 0;
	float py = 0;

	Vec v = { 0.0f,0.0f };

	bool b_hit = false;

	float r_x = 0.0f;//�����W
	float r_y = 0.0f;//�����W
	float r = 0.0f;//�ړ�����p�x
	float speed = 0.0f;//���x

public:
	int img{ 0 };//�摜
	Pos pos{ 0.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��
	//�R���X�g���N�^
	ShotGunEnemy(float _x, float _y, float _r, float _speed);
	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};


//�e
class LaserBullet :public Bace
{
private:
	float x = 0;
	float y = 0;

	//�G�l�~�[�̍��W��ۑ�����p
	float ex = 0;
	float ey = 0;

	//boss�̍��W��ۑ�����p
	float bx = 0;
	float by = 0;

	Vec v = { 0.0f,0.0f };

	bool b_hit = 0;

	bool eb_hit = false;
	bool pb_hit = false;
	bool bb_hit = false;

	int Hit_id = 0;

public:
	int img{ 0 };//�摜
	Pos pos{ 250.0f,0.0f };//�ʒu
	Vec vec{ 0.0f,0.0f };//�ړ��x�N�g��

	bool flag = true;
	//�����蔻��p
	int hit = 0;

	bool hit_bullet() { return b_hit; }
	//�R���X�g���N�^
	LaserBullet(float _x, float _y, int _ID);

	int Action(list<unique_ptr<Bace>>& bace);
	void Draw();
};