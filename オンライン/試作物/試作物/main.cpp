//���X�g��
//Dx���C�u�����g�p
#pragma once
#include "main.h"
#include "char.h"

//���X�g
list<unique_ptr<Bace>> bace;


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

	//���X�g�I�u�W�F�N�g�𐶐�
	auto a = (unique_ptr<Bace>)new Player();
	bace.emplace_back(move(a));

	int time = 0;
	
	auto b = (unique_ptr<Bace>)new Enemy(100.0f, 5.0f,1,5.0f,0.0f);
	bace.emplace_back(move(b));

	auto c = (unique_ptr<Bace>)new Enemy(300.0f, 5.0f,2, 0.0f, 0.0f);
	bace.emplace_back(move(c));

	auto d = (unique_ptr<Bace>)new Enemy(500.0f, 5.0f, 3, 0.0f, 0.0f);
	bace.emplace_back(move(d));

	auto e = (unique_ptr<Bace>)new Enemy(600.0f, 5.0f, 4, 0.0f, 0.0f);
	bace.emplace_back(move(e));

	auto z = (unique_ptr<Bace>)new boss(0.0f, 0.0f, 80);
	bace.push_back(move(z));

	//���C�����[�v
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();//��ʃN���A

		/*if (time == 10)
		{
			auto b = (unique_ptr<Bace>)new Enemy(100.0f, 5.0f);
			bace.emplace_back(move(b));
		}
		if (time == 20)
		{
			auto c = (unique_ptr<Bace>)new Enemy(300.0f, 5.0f);
			bace.emplace_back(move(c));
		}*/


		//���X�g�̃��\�b�h�����s
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Action(bace);//�e�I�u�W�F�N�g�̏���
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			(*i)->Draw();//�e�I�u�W�F�N�g�̏���
		}
		for (auto i = bace.begin(); i != bace.end(); i++)
		{
			if (((Enemy*)(*i).get())->ID == -999)
			{
				i = bace.erase(i);
				break;
			}
		}


		ScreenFlip();//��ʍX�V
		//��O����
		if ((ProcessMessage() == -1)) break;

		time++;
	}
	return 0;

}
