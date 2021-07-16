//���X�g��
//Dx���C�u�����g�p
#pragma once
#include "main.h"
#include "char.h"

//���X�g
list<unique_ptr<Bace>> bace;

int spawn_time = 0;



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

<<<<<<< Updated upstream
	int time = 0;
	int ID =0;
	
	auto b = (unique_ptr<Bace>)new Enemy(100.0f, 5.0f,1,5.0f,3.0f);
	bace.emplace_back(move(b));
=======
	//�����Ői�ޓG
	/*auto e1 = (unique_ptr<Bace>)new Enemy(200.0f, 5.0f,1,0.0f,1.5f,0.0f);
	bace.emplace_back(move(e1));
>>>>>>> Stashed changes

	auto e2 = (unique_ptr<Bace>)new Enemy(700.0f, 5.0f, 2, 0.0f, 1.5f,0.0f);
	bace.emplace_back(move(e2));*/

	//�E�΂ߑO�ɐi�ޓG
	/*auto e3 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 3, 2.5f, 1.0f, 0.0f);
	bace.emplace_back(move(e3));

	//���΂ߑO�ɐi�ޓG
	auto e4 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 0.0f);
	bace.emplace_back(move(e4));
	

	auto z = (unique_ptr<Bace>)new boss(0.0f, 0.0f, 80);
	bace.push_back(move(z));*/

	//���C�����[�v
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();//��ʃN���A

		//���E�F�[�u
		if (spawn_time == 10)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(200.0f, 5.0f, 1, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(700.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e2));
		}

		//���E�F�[�u
		if (spawn_time == 500)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 3, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e2));
		}
		if (spawn_time == 600)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 5, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 6, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e2));
		}
		if (spawn_time == 700)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 7, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 8, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e2));
		}

		//��O�E�F�[�u
		if (spawn_time == 1500)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(200.0f, 5.0f, 9, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(700.0f, 5.0f, 10, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e2));
		}
		if (spawn_time == 1800)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(100.0f, 5.0f, 11, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(450.0f, 5.0f, 12, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e2));

			auto e3 = (unique_ptr<Bace>)new Enemy(800.0f, 5.0f, 13, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e3));
		}

		//��l�E�F�[�u
		if (spawn_time == 2300)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 14, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));
		}
		if (spawn_time == 2400)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 15, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));
		}
		if (spawn_time == 2500)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 16, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));
		}
		if (spawn_time == 2600)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 17, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));

		}
		if (spawn_time == 2700)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(0.0f, 100.0f, 18, 2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));
		}

		//��܃E�F�[�u
		if (spawn_time == 3200)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e1));
		}
		if (spawn_time == 3300)
		{
			auto e2 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e2));
		}
		if (spawn_time == 3400)
		{
			auto e3 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e3));
		}
		if (spawn_time == 3500)
		{
			auto e4 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e4));
		}
		if (spawn_time == 3600)
		{
			auto e5 = (unique_ptr<Bace>)new Enemy(920.0f, 100.0f, 4, -2.5f, 1.0f, 1.5f);
			bace.emplace_back(move(e5));
		}

		//��Z�E�F�[�u
		if (spawn_time == 4300)
		{
			auto e1 = (unique_ptr<Bace>)new Enemy(100.0f, 5.0f, 1, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e1));

			auto e2 = (unique_ptr<Bace>)new Enemy(200.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e2));

			auto e3 = (unique_ptr<Bace>)new Enemy(300.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e3));

			auto e4 = (unique_ptr<Bace>)new Enemy(400.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e4));

			auto e5 = (unique_ptr<Bace>)new Enemy(500.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e5));

			auto e6 = (unique_ptr<Bace>)new Enemy(600.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e6));

			auto e7 = (unique_ptr<Bace>)new Enemy(700.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e7));

			auto e8 = (unique_ptr<Bace>)new Enemy(800.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e8));

			auto e9 = (unique_ptr<Bace>)new Enemy(900.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e9));

			auto e10 = (unique_ptr<Bace>)new Enemy(0.0f, 5.0f, 2, 0.0f, 1.5f, 0.9f);
			bace.emplace_back(move(e10));

		}

		//�{�X
		if (spawn_time == 5800)
		{
			auto z = (unique_ptr<Bace>)new boss(450.0f, 0.0f, 80);
			bace.push_back(move(z));
		}


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

		spawn_time++;
	}
	return 0;

}
