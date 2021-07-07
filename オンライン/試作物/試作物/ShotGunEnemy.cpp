#pragma once
#include "char.h"
#include <math.h>

//�R���X�g���N�^
ShotGunEnemy::ShotGunEnemy(float _x, float _y,float _r,float _speed) {

	img = LoadGraph("image\\EnemyBullet.png");

	pos.x = _x;
	pos.y = _y;

	r = _r;
	speed = _speed;

	ID = 2;

	px = 0;
	py = 0;
}

//�����蔻��p�֐�
int ShotGunCheckHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	int L1 = x1;      // ��
	int R1 = x1 + w1; // �E(��+����)
	int L2 = x2;      // ��
	int R2 = x2 + w2; // �E(��+����)
	
	if (R1 < L2) return 0;
	if (R2 < L1) return 0;

	int U1 = y1;      // ��
	int D1 = y1 + h1; // ��(��+�c��)
	int U2 = y2;      // ��
	int D2 = y2 + h2; // ��(��+�c��)B

	if (D1 < U2) return 0;
	if (D2 < U1) return 0;

	// ����ȊO�̏ꍇ�͓������Ă���
	return 1;
}

//����
int ShotGunEnemy::Action(list<unique_ptr<Bace>>& bace) 
{
	//���x
	v.y += 4.0f;

	v.x = cos(3.14f / 180.0f * r);
	v.y = sin(3.14f / 180.0f * r);



	//��l���̍��W�擾
	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if ((*i)->ID == 1) {
			px = ((Player*)(*i).get())->pos.x;//player��X���W������
			py = ((Player*)(*i).get())->pos.y;//player���W������
		}
	}

	//�ړ��x�N�g�������Z
	pos.x += v.x*speed;
	pos.y += v.y*speed;
	
	//��l���ɓ���������t���O��true�ɂ���
	if (ShotGunCheckHit(px, py, 64, 55, pos.x, pos.y, 24, 24) == 1)
	{
		b_hit = true;
	}
	else
		b_hit = false;

	//�������Ă������l���Ƀ_���[�W��^���āA�e��������
	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if (((Player*)(*i).get())->ID == 1)
		{
			if (b_hit == true)
			{
				ID = -999;
				((Player*)(*i).get())->hp -= 2;
			}
		}
	}

	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		;
	}
	//�̈�O�̏���
	if (pos.x < -24.0f)
	{
		ID = -999;
	}

	if (pos.x > WIDTH - 24.0f)
	{
		ID = -999;
	}

	if (pos.y < -24.0f)
	{
		ID = -999;
	}

	if (pos.y > HEIGHT - 24.0f)
	{
		ID = -999;
	}

	return 0;
}

//�`��
void ShotGunEnemy::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}