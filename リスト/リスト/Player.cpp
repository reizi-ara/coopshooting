#pragma once
#include "char.h"

//�R���X�g���N�^
Player::Player() {
	img = LoadGraph("image\\yosi.png");
	sound = LoadSoundMem("sound\\Audio1.wav");
	ID = 0;
}

//����
int Player::Action(list<unique_ptr<Bace>>& bace)
//int Player::Action(list<Bace*>* bace)
{
	//�L�[����
	Vec v{ 0.0f,0.0f };
	if (CheckHitKey(KEY_INPUT_UP))v.y = -4.0f;
	if (CheckHitKey(KEY_INPUT_DOWN))v.y = 4.0f;
	if (CheckHitKey(KEY_INPUT_LEFT))v.x = -4.0f;
	if (CheckHitKey(KEY_INPUT_RIGHT))v.x = 4.0f;

	for (auto i = bace.begin(); i !=bace.end(); i++)
	{
		((Player*)(*i).get())->pos.x;
	}

	//for (auto i = bace->begin(); i !=bace->end(); i++)
	//{
	//	if ((*i)->ID == 1)
	//	{
	//		//((Enemy*)(*i))->pos.x; �v���C���[�Ƃ̓����蔻��
	//	}
	//}

	//BGM�𗬂�����
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		PlaySoundMem(sound, DX_PLAYTYPE_BACK, TRUE);
		//StopSoundMem(sound);//�����~�߂�
	}

	//�ړ��x�N�g�������Z
	pos.x += v.x;
	pos.y += v.y;

	return 0;
}

//�`��
void Player::Draw() {
	DrawGraphF(pos.x, pos.y, img, TRUE);
}