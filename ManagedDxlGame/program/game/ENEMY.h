#pragma once

class ENEMY_1 {  //���ڂ���
public:

	float speed = 1;  //�G�L�����ړ��X�s�[�h

	float life = 1;
	
	bool flag = false;  //�G�L���������t���O

	float enemy_x = 645;
	float enemy_y = -20;

	int enemy_w = 60;  //�G�L������
	int enemy_h = 60;  //�G�L�������� 

	int ene_gpc_hdl;  //�G�L�����摜�n���h��

	bool aiko_flag = false;  //�������̏ꍇ
	float stop_time = 0;

	int death_sound = 0;
	
	void aiko_stop_time();  //�������ŐÎ~����֐�
	void init1();  //�ϐ�������
	void Graph();  //�摜�ǂݍ���
	void Draw();  //�G�\��
	void Move();  //�G�L�����ړ�
	void Enemy();  //�G�L��������
	void sound_load();  //���@�ǂݍ���
	void sound_play();  //���@�Đ�
};

class ENEMY_2 {  //�ق�
public:

	float speed2 = 2;  //�G�L�����ړ��X�s�[�h

	float life2 = 1;

	bool flag2 = false;  //�G�L���������t���O

	float enemy2_x = 645;
	float enemy2_y = -20;

	int enemy2_w = 60;  //�G�L������
	int enemy2_h = 60;  //�G�L�������� 

	int ene_gpc_hdl2 = 0;  //�G�L�����摜�n���h��

	bool aiko_flag = false;  //�������̏ꍇ
	float stop_time = 0;

	int death_sound = 0;

	void aiko_stop_time();  //�������ŐÎ~����֐�

	void init2();  //�ϐ�������
	void Graph2();  //�摜�ǂݍ���
	void Draw2();  //�G�\��
	void Move2();  //�G�L�����ړ�
	void Enemy2();  //�G�L��������
	void sound_load();  //���@�ǂݍ���
	void sound_play();  //���@�Đ�
};

class ENEMY_3 {  //���΂�
public:

	float speed3 = 2;  //�G�L�����ړ��X�s�[�h

	float life3 = 1;

	bool flag3 = false;  //�G�L���������t���O

	float enemy3_x = 645;
	float enemy3_y = -20;

	int enemy3_w = 60;  //�G�L������
	int enemy3_h = 60;  //�G�L�������� 

	int ene_gpc_hdl3 = 0;  //�G�L�����摜�n���h��

	bool aiko_flag = false;  //�������̏ꍇ
	float stop_time = 0;

	int death_sound = 0;

	void aiko_stop_time();  //�������ŐÎ~����֐�

	void init3();  //�ϐ�������
	void Graph3();  //�摜�ǂݍ���
	void Draw3();  //�G�\��
	void Move3();  //�G�L�����ړ�
	void Enemy3();  //�G�L��������
	void sound_load();  //���@�ǂݍ���
	void sound_play();  //���@�Đ�
};