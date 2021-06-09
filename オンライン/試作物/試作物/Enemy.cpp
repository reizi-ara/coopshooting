#pragma once
#include "char.h"

//�R���X�g���N�^
Enemy::Enemy(float _x,float _y) {
	img = LoadGraph("image\\ai(64).jpg");
	vec.x = 4.0f + _x;
	vec.y = 3.0f + _y;

	ID = 1;
}

//����
int Enemy::Action(list<unique_ptr<Bace>>& bace) {

	//�ړ��x�N�g�������Z
	pos.x += vec.x;
	pos.y += vec.y;

	//��ʂ̒[�ɗ�����A�ړ��x�N�g�����t�ɂ���
	if (pos.x < 0 || pos.x>736.0f)vec.x = -vec.x;
	if (pos.y < 0 || pos.y>546.0f)vec.y = -vec.y;

	return 0;
}

//�`��
void Enemy::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}