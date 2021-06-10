#pragma once
#include "char.h"


Bullet::Bullet(float _x, float _y, int _ID)
{
	img = LoadGraph("image\\bullet.png");

	pos.x = _x;
	pos.y = _y;

	ID = _ID;

	ex = 0;
	ey = 0;
}


//�����蔻��p�֐�
int CheckHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
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
	int D2 = y2 + h2; // ��(��+�c��)

	if (D1 < U2) return 0;
	if (D2 < U1) return 0;

	// ����ȊO�̏ꍇ�͓������Ă���
	return 1;
}

//int InitGreaph(void)
//{
//	int ax = 0;
//
//}

int Bullet::Action(list<unique_ptr<Bace>>& bace)
{

	v.y = -4.0f;


	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if ((*i)->ID == 1) {
			ex = ((Enemy*)(*i).get())->pos.x;//�G�l�~�[��X���W������
			ey = ((Enemy*)(*i).get())->pos.y;//�G�l�~�[��y���W������
		}
	}


	pos.x += v.x;
	pos.y += v.y;

	hit = CheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24);

	if (pos.x < 0.0f)
	{
		ID = -999;
	}

	if (pos.x > 776.0f)
	{
		ID = -999;
	}

	if (pos.y < 0.0f)
	{
		ID = -999;
	}

	if (pos.y > 576.0f)
	{
		ID = -999;
	}

	if (hit == 1)
	{
		ID = -999;
	}


	return 0;
}

void Bullet::Draw()
{
	DrawGraphF(pos.x, pos.y, img, TRUE);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ex=%f:ey=%f", ex, ey);
}