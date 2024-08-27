#pragma once

class SCENE_TITLE {
public:
	const std::string TITLE_LOGO_STR = "魔女シューティング";  //タイトル文字
	const tnl::Vector3 TITLE_LOGO_POS = { 180, 150, 0 };  //タイトル文字座標

	const std::string TITLE_MENU_STR = "start enter";  //ゲームスタートボタン
	const tnl::Vector3 TITLE_MENU_POS = { 575, 400, 0 };  //ゲームスタートボタン座標

	float TITLE_MENU_FLASHINTIME = 0.5f;  //ゲームスタートボタン点滅
	float g_title_menu_flashing_time_cont = 0;  
	bool g_is_title_menu_on_draw = true;

	int g_gpc_title; //タイトル背景
	tnl::Vector3 g_gpc_title_pos = { 650, 360, 0 }; //タイトル背景座標

	int snd_bgm_hdl = 0;  //音　BGM
	int snd_se_hdl = 0;  //音　SE

	void sound_load();  //音読み込み
	void sound_bgm_play();  //BGM再生
	void sound_bgm_stop();  //BGM停止
	void sound_se_play();  //SE再生

	void graph();	//タイトル背景読み込み
	void graph_draw();	//タイトル背景描画
	void string();	//タイトル文字
	void menu(float delta_time);  //タイトルメニュー
};
