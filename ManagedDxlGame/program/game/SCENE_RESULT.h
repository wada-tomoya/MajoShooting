#pragma once

class SCENE_RESULT {
public:
	const tnl::Vector3 GameOver_Logo_pos = { 400,100,0 };
	const std::string GameOver_Logo_str = "GAME OVER";

	const tnl::Vector3 Score_Logo_pos = { 550,300,0 };
	const std::string Score_Logo_str = "ÉXÉRÉA";

	const tnl::Vector3 Score_pos = { 500,350,0 };

	const tnl::Vector3 Menu_Logo_pos = { 550,500,0 };
	const std::string Menu_Logo_str = "please enter";
	const float Menu_Logo_flashintime = 0.5f;
	float flashing_timecount = 0;
	bool Menu_Logo_flash_flag = true;

	int snd_bgm_hdl = 0;

	void gameover_draw();
	void score_draw();
	void menu_draw(float delta_time);

	void sound_load();
	void sound_bgm_play();
	void sound_bgm_stop();
};