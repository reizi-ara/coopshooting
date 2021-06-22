//���X�g��
//Dx���C�u�����g�p
#pragma once
#include "main.h"
#include "char.h"

//���X�g
//std::list<Bace*>bace;

//���j�[�N�|�C���^���g�������X�g
list<unique_ptr<Bace>> bace;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	//window���[�h�̐؂�ւ�
	ChangeWindowMode(TRUE);

	//window�T�C�Y
	SetGraphMode(WIDTH, HEIGHT, 32);

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)return -1;

	//window�̖��O
	SetWindowText("���X�g�T���v��");

	//�o�b�N�o�b�t�@���g���ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//���X�g�փI�u�W�F�N�g��ǉ�

	auto a = (unique_ptr<Bace>)new Player();
	bace.push_back(move(a));

	
	/*auto a = (Bace*)new Player();
	bace.push_back(a);*/

	for (int i= 0; i < 5; i++)
	{
		auto b = (unique_ptr<Bace>)new Enemy(i*1.0f,i*1.0f);
		bace.push_back(move(b));

	}

	//���C�����[�v
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();//��ʃN���A

		//���X�g�̃��\�b�h�����s
		for (auto j = bace.begin(); j != bace.end(); j++)
		{
			((Player*)(*j).get())->Action(bace);
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			((Enemy*)(*i).get())->Action(bace);
		}

		for (auto j = bace.begin(); j != bace.end(); j++)
		{
			((Player*)(*j).get())->Draw();
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			((Enemy*)(*i).get())->Draw();
		}
		//for (auto i = bace.begin(); i != bace.end(); i++)
		//	(*i)->Action(&bace);//�e�I�u�W�F�N�g�̏���

		//for (auto i = bace.begin(); i != bace.end(); i++)
		//	(*i)->Draw();//�e�I�u�W�F�N�g�̕`�揈��

		//���X�g����v�f���폜�iID���[�X�X�X�̎��ɍ폜�j
		//for (auto i = bace.begin(); i != bace.end(); i++)
		//{
		//	if ((*i)->ID==-999)
		//	{
		//		//���X�g����폜
		//		delete(*i);
		//		i = bace.erase(i);
		//		break;
		//	}
		//}

		/*for (auto i = bace.begin(); i !=bace.end(); i++)
		{
			i = bace.erase(i);
			break;
		}*/

		ScreenFlip();//��ʍX�V
		//��O����
		if ((ProcessMessage() == -1))break;
	}

	DxLib_End();

	return 0;
}