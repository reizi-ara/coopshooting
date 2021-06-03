//�}���`�X���b�hTCP�ʐM�@�N���C�A���g��
#pragma once
#include "main.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR IpCmdLine, _In_ int nShowCmd)
{
	//window���[�h�̐؂�ւ�
	ChangeWindowMode(TRUE);
	//window�T�C�Y
	SetGraphMode(WIDTH, HEIGHT, 32);
	//�o�b�N�O���E���h�����̋���
	SetAlwaysRunFlag(TRUE);
	//���d�N���̋���
	SetDoubleStartValidFlag(TRUE);
	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1) return-1;//���s������v���O�����I��

	//�o�b�N�o�b�t�@���g���ݒ�
	SetDrawScreen(DX_SCREEN_BACK);
	//window�̖��O
	SetWindowText("�N���C�A���g");

	//�摜�̓ǂݍ���
	int img = LoadGraph("image\\sigure(64).jpg");

	//����M�̃f�[�^�����p
	char StrBuf[256] = { "null" };//256�o�C�g�܂�

	//�S�Ẵv���C���[�f�[�^
	SendData* Player_ALL = new SendData();

	//�ʐM�֌W
	IPDATA IP;
	//�ʐM�p�̃n���h��
	int NetHandel;
	//�|�[�g
	int Port = 26;
	//�ʐM���IP�A�h���X�̐ݒ�
	IP = IP_set();

	//�v���C���[�f�[�^�쐬
	//���O�̓���
	char name[8] = "null";
	ClearDrawScreen();//��ʂ̃N���A
	DrawString(0, 0, "���O����́@������8����/�S�p�S�����܂�", GetColor(255, 255, 255));
	KeyInputString(0, 16, 8, name, FALSE);

	//���񑗐M�f�[�^�̍쐬
	Data* my_Data = new Data(0.0f, 0.0f, name);

	//����ڑ�����
	NetHandel = ConnectNetWork(IP, Port);//���͂���IP�Ɛݒ肵���|�[�g���g�p

	//�ڑ�����܂őҋ@
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();//��ʂ̃N���A

		if (NetHandel != -1) {
			//�ڑ�����
			//�T�[�o�[�Ƀf�[�^�𑗐M�i���O�������M�j
			NetWorkSend(NetHandel, &my_Data->name, sizeof(my_Data->name));
			//�T�[�o�[����̉����ҋ@
			while (!ProcessMessage()) {
				//����M�f�[�^�𒲂ׂ�
				if (GetNetWorkDataLength(NetHandel) != 0)
					break;
			}

			//��M�f�[�^��ϊ�
			//��M�f�[�^������������StrBuf�ɃR�s�[���āASendData�ɕϊ�
			NetWorkRecv(NetHandel, StrBuf, sizeof(SendData));
			memcpy_s(Player_ALL, sizeof(SendData), StrBuf, sizeof(SendData));//�ϊ�

			DrawString(0, 16, "�ڑ������B�����L�[�������Ă��������B",GetColor(255, 255, 255));

			ScreenFlip();
			WaitKey();
			break;
		}
		else {
			//�ڑ���
			DrawString(0, 0, "�ڑ��m�����E�E�E", GetColor(255, 255, 255));
		}

		ScreenFlip();
	}

	//���C�����[�v(Esc�L�[�ŏI��)
	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen();//��ʃN���A

		if (GetNetWorkDataLength(NetHandel) != 0)
		{
			//�f�[�^����M�����ꍇ
			NetWorkRecv(NetHandel, StrBuf, sizeof(SendData));
			//�v���C���[�S�̃f�[�^�̍X�V
			memcpy_s(Player_ALL, sizeof(SendData), StrBuf, sizeof(SendData));
		}
		else
		{
			//�f�[�^����M���Ă��Ȃ��ꍇ
			//�ړ�����
			Vec v{ 0.0f,0.0f };
			if (CheckHitKey(KEY_INPUT_UP))v.y = -4.0f;
			if (CheckHitKey(KEY_INPUT_DOWN))v.y = 4.0f;
			if (CheckHitKey(KEY_INPUT_LEFT))v.x = -4.0f;
			if (CheckHitKey(KEY_INPUT_RIGHT))v.x = 4.0f;

			//���͂��������ꍇ�Ƀf�[�^�𑗐M
			if (v.x != 0.0f || v.y != 0.0f)
			{
				//�f�[�^���M
				NetWorkSend(NetHandel, &v, sizeof(Vec));
			}
		}
		//�`��
		//Player_All���g���ĉ�ʂ̍X�V
		for (int i = 0; i < MAX; i++) {
			if (Player_ALL->data[i].ID != -1) {
				//�L����
				DrawGraph(Player_ALL->data[i].pos.x, Player_ALL->data[i].pos.y, img, TRUE);
				//���O
				DrawStringF(Player_ALL->data[i].pos.x, Player_ALL->data[i].pos.y, Player_ALL->data[i].name, GetColor(255, 255, 255));
			}
		}
		//DrawGraphF(0.0f, 0.0f, img, TRUE);

		ScreenFlip();//��ʍX�V

		//��O���������Ń��[�v�𔲂���
		if (ProcessMessage() == -1)
			break;
	}

	WaitKey();//�L�[���͂�����܂őҋ@

	DxLib_End();//Dx���C�u�����̉��
	return 0;
}