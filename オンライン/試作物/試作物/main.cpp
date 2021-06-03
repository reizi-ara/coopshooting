//���X�g��
//Dx���C�u�����g�p
#pragma once
#include "main.h"
#include "char.h"

//���X�g
std::list<Bace*>bace;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
	//window���[�h�ؑ�
	ChangeWindowMode(TRUE);
	//window�T�C�Y
	SetGraphMode(WIDTH, HEIGHT, 32);

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1)return -1;

	//window�̖��O
	SetWindowText("���X�g�T���v��");

	//�o�b�N�o�b�t�@���g�p
	SetDrawScreen(DX_SCREEN_BACK);
	
	//���X�g�I�u�W�F�N�g��ǉ�
	auto a = (Bace*)new Player();
	bace.push_back(a);

	for (int i = 0; i < 5; i++) {
		auto a = (Bace*)new Enemy(i * 3.0f, i * 5.0f);
		bace.push_back(a);
	}

	//���C�����[�v
	while (CheckHitKey(KEY_INPUT_ESCAPE)==0){
		ClearDrawScreen();//��ʃN���A

		//���X�g�̃��\�b�h�����s
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Action(&bace);//�e�I�u�W�F�N�g�̏���
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Draw();//�e�I�u�W�F�N�g�̏���
		}


		ScreenFlip();//��ʍX�V
		//��O����
		if ((ProcessMessage() == -1)) break;
	}
	return 0;

}
