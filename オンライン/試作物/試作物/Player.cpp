#pragma once
#include "char.h"

//�R���X�g���N�^
Player::Player() {
	img = LoadGraph("image\\Player11.png");

	ID = 0;

	ShotFlag = true;

	pos.x = 1.0f;
	pos.y = 1.0f;
}

//����
int Player::Action(list<Bace*>* bace) {


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

	if (pos.x > 736.0f)
	{
		pos.x = 736.0f;
	}

	if (pos.y < 0.0f)
	{
		pos.y = 0.0f;
	}

	if (pos.y > 536.0f)
	{
		pos.y = 536.0f;
	}

	if (CheckHitKey(KEY_INPUT_Z) == true && ShotFlag == true)
	{
		auto b = (Bace*)new Bullet(pos.x + 20, pos.y, PLAYER_BULLET);
		bace->push_back(b);
		ShotFlag = false;
	}
	else if (CheckHitKey(KEY_INPUT_Z) == false)
	{
		ShotFlag = true;
	}


	return 0;
}

//�`��
void Player::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}