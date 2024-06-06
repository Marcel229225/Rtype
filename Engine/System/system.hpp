/*
** EPITECH PROJECT, 2022
** R Type
** File description:
** systeme hpp
*/

#include "../Registry/registry.hpp"
#include "../Sparse_array/component.hpp"
#include "../../Game/Lib/iLib.hpp"

#include<dlfcn.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <regex>
#include <sstream>

#ifndef System
#define System

class ISystem {
    public:
        ISystem() {}
        ~ISystem() {}
        void create_window(registry &reg, float height, float width, std::string name, std::string resolution);
        void init_sparse(registry &reg);
        void insert_in_sparse(registry &reg);
        void create_drawable(registry &reg, int idx, std::string path, float posX, float posY, float scaleX, float scaleY);
        void create_drawable(registry &reg, int idx, std::string path, float posX, float posY, float scaleX, float scaleY, Components::Rect rect);
        void create_player(registry &reg, int idx, std::string path, float posX, float posY, float scaleX, float scaleY, Components::Rect rect);
        void create_text(registry &reg, int idx, std::string txt, float posX, float posY, std::string font, std::string color, int size, int gras, std::string style);
        void create_pos(registry &reg, int idx, float x, float y);
        void create_fire(registry &reg, int idx, int id, std::string path, float posX, float posY, float scaleX, float scaleY, Components::Rect rect);
        void create_sound(registry &reg, int idx, std::string path, bool inLoop, bool is_play, float volume);
        void create_power(registry &reg, int idx, std::string action, std::string path, float posX, float posY, float scaleX, float scaleY);
        void load_lib(registry &reg);
        void move_bg(registry &reg);
        void move_planete(registry &reg);
        void move_car(registry &reg, int idx, Components::Inputs input);
        void change_rect(registry &reg);
        void play_rect(registry &reg);
        void shoot(registry &reg);
        void set_sound(registry &reg, int idx, bool is_play);
        // void set_shoot(registry &reg);
        void update_mouse(registry &reg, Components::Position pos);
        std::string update_server_pos(registry &reg, std::string message);
        void update_client_pos(registry &reg, std::string message);
        int get_id(std::string message);
        bool check;
        int where = -1;
        Components::player_new_pos extract_new_pos(std::string message);
        std::shared_ptr<Sfml> (*se)(void);
        std::shared_ptr<Sfml> sec;
        // menu functions
        void change_menu_rect(registry &reg);
        void event_mouse(registry &reg, Components::Inputs input);
        void update_credit(registry &reg);
        void move_credit(registry &reg, Components::Inputs input);
        void update_setting(registry &reg);
        void change_screen(registry &reg);
        void update_inventory(registry &reg);
        void update_quit(registry &reg);
        // fin menu functions

        // shoot
        void set_shoot(registry &reg);
        std::string set_shoot_pos(registry &reg, std::string message);
        void change_fire_rect(registry &reg);
        std::vector<std::string> check_shoot(registry &reg);
        int get_pos(std::string message);
        void set_server_shoot(registry &reg, std::string message);

        // end shoot
        void set_speed(registry &reg, int id);
        // ENNEMY
        void create_ennemy(registry &reg, int idx, std::string path, float posX, float posY, float scaleX, float scaleY, Components::Rect rect, std::string status, bool alive);
        std::vector<std::string> move_ennemy(registry &reg);
        void set_ennemy_client(registry &reg, std::string message);
        void set_ennemy_shoot(registry &reg);
        void check_boss(registry &reg, int score, int i);
        void check_boss2(registry &reg, int score, int i);
        // END ENNEMY

        // COLLISION
        //std::string is_collision(registry &reg);
        // END COLLISION
        
        // CINEMATIQUE
        std::vector<std::string> cine;
        void set_cine_vector(registry &reg);
        void set_cine(registry &reg, int idx);

        std::vector<std::string> cine2;
        void set_cine_vector2(registry &reg);
        void set_cine2(registry &reg, int idx);

        std::vector<std::string> cine3;
        void set_cine_vector3(registry &reg);
        void set_cine3(registry &reg, int idx);

        std::vector<std::string> cine4;
        void set_cine_vector4(registry &reg);
        void set_cine4(registry &reg, int idx);
        // END CINEMATIQUE

        void move_power(registry &reg);

        bool change_stage(registry &reg, int score);
        void move_IA(registry &reg);

        bool check_shield(registry &reg);
        bool is_infini = false;
        bool is_over(registry &reg);
        void game_over(registry &reg, int score);

        // void restart(registry &reg);
    protected:
};

#endif /* !System */
