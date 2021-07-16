#pragma once
#include "char.h"


LaserBullet::LaserBullet(float _x, float _y, int _ID)
{
	img = LoadGraph("image\\���[�U�[.png");

	pos.x = _x;
	pos.y = _y;

	ID = _ID;

	ex = 0;
	ey = 0;
}


//�����蔻��p�֐�
int LaserCheckHit(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
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

int LaserBullet::Action(list<unique_ptr<Bace>>& bace)
{

	v.y = -4.0f;


	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if ((*i)->ID == 1) {

			ex = ((Enemy*)(*i).get())->pos.x;//PosXSave(bace);//�G�l�~�[��X���W������
			ey = ((Enemy*)(*i).get())->pos.y;//PosYSave(bace);//�G�l�~�[��y���W������
			if (LaserCheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
			{
				if (ID == PLAYER_BULLET)
				{
					eb_hit = true;
					Hit_id = 1;
					break;
				}

			}
			else
				eb_hit = false;
		}

		else if ((*i)->ID == 2) {

			ex = ((Enemy*)(*i).get())->pos.x; //PosXSave(bace);//�G�l�~�[��X���W������
			ey = ((Enemy*)(*i).get())->pos.y;//PosYSave(bace);//�G�l�~�[��y���W������
			if (LaserCheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
			{
				if (ID == PLAYER_BULLET)
				{
					eb_hit = true;
					Hit_id = 2;
					break;
				}
			}
			else
				eb_hit = false;
		}

		else if ((*i)->ID == 3) {

			ex = ((Enemy*)(*i).get())->pos.x; //PosXSave(bace);//�G�l�~�[��X���W������
			ey = ((Enemy*)(*i).get())->pos.y;//PosYSave(bace);//�G�l�~�[��y���W������
			if (LaserCheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
			{
				if (ID == PLAYER_BULLET)
				{
					eb_hit = true;
					Hit_id = 3;
					break;
				}
			}
			else
				eb_hit = false;
		}

		else if ((*i)->ID == 4) {

			ex = ((Enemy*)(*i).get())->pos.x; //PosXSave(bace);//�G�l�~�[��X���W������
			ey = ((Enemy*)(*i).get())->pos.y;//PosYSave(bace);//�G�l�~�[��y���W������
			if (LaserCheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
			{
				if (ID == PLAYER_BULLET)
				{
					eb_hit = true;
					Hit_id = 4;
					break;
				}
			}
			else
				eb_hit = false;
		}

		else if ((*i)->ID == 5) {

			ex = ((Enemy*)(*i).get())->pos.x; //PosXSave(bace);//�G�l�~�[��X���W������
			ey = ((Enemy*)(*i).get())->pos.y;//PosYSave(bace);//�G�l�~�[��y���W������
			if (LaserCheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
			{
				if (ID == PLAYER_BULLET)
				{
					eb_hit = true;
					Hit_id = 5;
					break;
				}
			}
			else
				eb_hit = false;
		}

		else if ((*i)->ID == 6) {

			ex = ((Enemy*)(*i).get())->pos.x; //PosXSave(bace);//�G�l�~�[��X���W������
			ey = ((Enemy*)(*i).get())->pos.y;//PosYSave(bace);//�G�l�~�[��y���W������
			if (LaserCheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
			{
				if (ID == PLAYER_BULLET)
				{
					eb_hit = true;
					Hit_id = 6;
					break;
				}
			}
			else
				eb_hit = false;
		}

		else if ((*i)->ID == 4) {

		ex = ((Enemy*)(*i).get())->pos.x; //PosXSave(bace);//�G�l�~�[��X���W������
		ey = ((Enemy*)(*i).get())->pos.y;//PosYSave(bace);//�G�l�~�[��y���W������
		if (LaserCheckHit(ex, ey, 64, 55, pos.x, pos.y, 24, 24) == 1)
		{
			if (ID == PLAYER_BULLET)
			{
				eb_hit = true;
				Hit_id = 4;
				break;
			}
		}
		else
			eb_hit = false;
		}
	}

	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if ((*i)->ID == 80) {
			bx = ((boss*)(*i).get())->pos.x;//�{�X��X���W������
			by = ((boss*)(*i).get())->pos.y;//�{�X��y���W������
			if (LaserCheckHit(bx, by, 256, 282, pos.x, pos.y, 24, 24) == 1)
			{
				if (ID == PLAYER_BULLET)
				{
					bb_hit = true;
					Hit_id = 80;
					break;
				}
			}
			else
				bb_hit = false;
		}
	}


	pos.x += v.x;
	pos.y += v.y;

	
	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if (((Enemy*)(*i).get())->ID == Hit_id)
		{
			if (eb_hit == true)
			{
				ID = -999;
				if (Hit_id == 1)
				{
					if ((*i)->ID == 1) {
						((Enemy*)(*i).get())->hp -= 5;
					}
				}
				else if (Hit_id == 2)
				{
					if ((*i)->ID == 2) {
						((Enemy*)(*i).get())->hp -= 5;
					}
				}
				else if (Hit_id == 3)
				{
					if ((*i)->ID == 3) {
						((Enemy*)(*i).get())->hp -= 5;
					}
				}
				else if (Hit_id == 4)
				{
					if ((*i)->ID == 4) {
						((Enemy*)(*i).get())->hp -= 5;
					}
				}
			}
		}
	}

	//�������Ă�����boss�Ƀ_���[�W��^���āA�e��������
	for (auto i = bace.begin(); i != bace.end(); i++)
	{
		if (((boss*)(*i).get())->ID == 80)
		{
			if (bb_hit == true)
			{
				ID = -999;
				((boss*)(*i).get())->hp -= 5;
			}
		}
	}

	if (pos.x < 0.0f)
	{
		ID = -999;
	}

	if (pos.x > WIDTH - 22.0f)
	{
		ID = -999;
	}

	if (pos.y < -119.0f)
	{
		ID = -999;
	}

	if (pos.y > HEIGHT - 119.0f)
	{
		ID = -999;
	}

	return 0;
}

void LaserBullet::Draw()
{

	DrawGraphF(pos.x, pos.y, img, TRUE);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "ex=%f:ey=%f", pos.x, pos.y);
}