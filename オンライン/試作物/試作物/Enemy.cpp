#pragma once
#include "char.h"

//�R���X�g���N�^
Enemy::Enemy(float _x, float _y) {

	img = LoadGraph("image\\Player2.png");

	pos.x = _x;
	pos.y = _y;

	vec.x = 4.0f;
	vec.y = 3.0f;

	ID = 1;

	e_hit = 0;
}

//����
int Enemy::Action(list<unique_ptr<Bace>>& bace) {

	//�ړ��x�N�g�������Z
	pos.x += vec.x;
	pos.y += vec.y;

	//��ʂ̒[�ɗ�����A�ړ��x�N�g�����t�ɂ���
	if (pos.x < 0 || pos.x>736.0f)vec.x = -vec.x;
	if (pos.y < 0 || pos.y>546.0f)vec.y = -vec.y;

	/*auto b = (Bace*)new Bullet(pos.x + 20, pos.y, ENEMY_BULLET);
	bace->push_back(b);*/

	/*if (pos.x < 0 || pos.x > 736.0f)
	{
		ID = -999;
	}
	if (pos.y < 0 ||pos.y > 736.0f)
	{
		ID = -999;
	}*/

	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if (((Bullet*)(*i).get())->hit == 1)
		{
			ID = -999;
			((Bullet*)(*i).get())->ID = -999;
		}

		else if (((LaserBullet*)(*i).get())->hit == 1)
		{
			ID = -999;
			((LaserBullet*)(*i).get())->ID = -999;
		}
	}

	return 0;
}

//�`��
void Enemy::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}