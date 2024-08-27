#pragma once

const float SHOT_SPEED = 8;

//�e�̕ϐ�
struct BULLET {

	bool flag = false;
	float x = 0;
	float y = 0;
	int gh;
	int width, height = 36;
	int shot_sound = 0;
};

class PLAYER {
public:

	int life_stock = 5;
	bool life = true;  //�����Ă邩�ǂ���

	int bullet_count;  // �e�̔��ˊԊu

	int player_hit_sound = 0;

	BULLET bullet_z[20];
	BULLET bullet_x[20];
	BULLET bullet_c[20];

	int gpc_hdl = 0;
	int width = 32;	 // ��
	int height = 32;  // ����
	tnl::Vector3 pos = { 645, 685, 0 };	 //�v���C���[���W

	void init();  //�ϐ��̏�����
	void graph();	//�v���C���[�@�e�@�摜�ǂݍ���
	void move();	//�v���C���[�𓮂����֐�
	void draw();	//�v���C���[��\������֐�

	void hit_precess();  //�G�ɓ����������̓���
	void lifeflag();  //�v���C���[�����񂾂��ǂ���

	void shot_z();  //�e_z
	void shot_x();  //�e_x
	void shot_c();  //�e_c
};