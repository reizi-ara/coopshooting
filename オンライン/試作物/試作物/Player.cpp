#pragma once
#include "char.h"

//�R���X�g���N�^
Player::Player() {
	img = LoadGraph("image\\kurumi(64).jpg");

	ID = 0;
}

//����
int Player::Action(list<unique_ptr<Bace>>& bace) {
	//�L�[����
	Vec v{ 0.0f,0.0f };
	if (CheckHitKey(KEY_INPUT_UP))v.y = -4.0f;
	if (CheckHitKey(KEY_INPUT_DOWN))v.y = 4.0f;
	if (CheckHitKey(KEY_INPUT_LEFT))v.x = -4.0f;
	if (CheckHitKey(KEY_INPUT_RIGHT))v.x = 4.0f;

	

	//�ړ��x�N�g�������Z
	pos.x += v.x;
	pos.y += v.y;

	return 0;
}

//�`��
void Player::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}