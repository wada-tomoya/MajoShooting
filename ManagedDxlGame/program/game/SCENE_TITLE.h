#pragma once

class SCENE_TITLE {
public:
	const std::string TITLE_LOGO_STR = "�����V���[�e�B���O";  //�^�C�g������
	const tnl::Vector3 TITLE_LOGO_POS = { 180, 150, 0 };  //�^�C�g���������W

	const std::string TITLE_MENU_STR = "start enter";  //�Q�[���X�^�[�g�{�^��
	const tnl::Vector3 TITLE_MENU_POS = { 575, 400, 0 };  //�Q�[���X�^�[�g�{�^�����W

	float TITLE_MENU_FLASHINTIME = 0.5f;  //�Q�[���X�^�[�g�{�^���_��
	float g_title_menu_flashing_time_cont = 0;  
	bool g_is_title_menu_on_draw = true;

	int g_gpc_title; //�^�C�g���w�i
	tnl::Vector3 g_gpc_title_pos = { 650, 360, 0 }; //�^�C�g���w�i���W

	int snd_bgm_hdl = 0;  //���@BGM
	int snd_se_hdl = 0;  //���@SE

	void sound_load();  //���ǂݍ���
	void sound_bgm_play();  //BGM�Đ�
	void sound_bgm_stop();  //BGM��~
	void sound_se_play();  //SE�Đ�

	void graph();	//�^�C�g���w�i�ǂݍ���
	void graph_draw();	//�^�C�g���w�i�`��
	void string();	//�^�C�g������
	void menu(float delta_time);  //�^�C�g�����j���[
};
