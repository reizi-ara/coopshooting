#pragma once
#include "char.h"

//�R���X�g���N�^
Player::Player() {
	img = LoadGraph("image\\Player11.png");

	ID = 0;

	ShotFlag = true;
	Shot_Flag = true;

	pos.x = 200.0f;
	pos.y = 200.0f;
}

//����
int Player::Action(list<unique_ptr<Bace>>& bace)
{

	//�L�[����
	if (CheckHitKey(KEY_INPUT_UP))vec.y = -4.0f;
	if (CheckHitKey(KEY_INPUT_DOWN))vec.y = 4.0f;
	if (CheckHitKey(KEY_INPUT_DOWN) == false && CheckHitKey(KEY_INPUT_UP) == false)
		vec.y = 0.0f;
	if (CheckHitKey(KEY_INPUT_LEFT))vec.x = -4.0f;
	if (CheckHitKey(KEY_INPUT_RIGHT))vec.x = 4.0f;
	if (CheckHitKey(KEY_INPUT_RIGHT) == false && CheckHitKey(KEY_INPUT_LEFT) == false)
		vec.x = 0.0f;


	/*
	for (auto i = bace->begin(); i != bace->end(); i++)
	{
		if ((*i)->ID == 20) {
			((Bullet*)(*i))->pos.x;//�G�l�~�[��X���W������
			((Bullet*)(*i))->pos.y;//�G�l�~�[��y���W������
		}
	}*/

	//�ړ��x�N�g�������Z
	pos.x += vec.x;
	pos.y += vec.y;

	if (pos.x < 0.0f)
	{
		pos.x = 0.0f;
	}

	if (pos.x > WIDTH - 64.0f)
	{
		pos.x = WIDTH - 64.0f;
	}

	if (pos.y < 0.0f)
	{
		pos.y = 0.0f;
	}

	if (pos.y > HEIGHT - 64.0f)
	{
		pos.y = HEIGHT - 64.0f;
	}

	if (CheckHitKey(KEY_INPUT_Z) == true && ShotFlag == true)
	{
		auto b = (unique_ptr<Bace>)new Bullet(pos.x + 20, pos.y, PLAYER_BULLET);
		bace.emplace_back(move(b));
		ShotFlag = false;
	}
	else if (CheckHitKey(KEY_INPUT_Z) == false)
	{
		ShotFlag = true;
	}

	if (CheckHitKey(KEY_INPUT_X) == true && Shot_Flag == true && lb > 0)
	{
		auto c = (unique_ptr<Bace>)new LaserBullet(pos.x + 20, pos.y - 100, PLAYER_BULLET);
		bace.emplace_back(move(c));
		Shot_Flag = false;
		lb--;
	}
	else if (CheckHitKey(KEY_INPUT_X) == false)
	{
		Shot_Flag = true;
	}

	if (lb == 0)
	{
		time++;
	}

	if (time == 1200)
	{
		lb = 3;
		time = 0;
	}

	return 0;
}

//�`��
void Player::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}