/*
** EPITECH PROJECT, 2022
** R TYPE
** File description:
** SFML
*/

#include "../../Engine/System/system.hpp"
#include "../Lib/iLib.hpp"

#include <unistd.h>
#include<dlfcn.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <thread>
#include <fstream>

#ifndef SFML
#define SFML

class Game_SFML {
    public:
        Game_SFML() {}
        ~Game_SFML() {}
        void Load_lib();
        void create_game_window(registry &reg);
        void create_draw(registry &reg, int idx);
        void display_draw(registry &reg, int idx);
        void create_draw_rect(registry &reg, int idx);
        void display_draw_rect(registry &reg, int idx);
        void create_player_rect(registry &reg, int nbr);
        void display_player_rect(registry &reg, int nbr, int idx);
        void display_player_rect(registry &reg, int nbr);
        void create_ennemy(registry &reg);
        void display_ennemy(registry &reg, int idx);
        void create_text(registry &reg, int idx);
        void display_text(registry &reg, int idx);
        void create_fire(registry &reg);
        void create_fire(registry &reg, int id);
        void display_fire(registry &reg);
        void create_power(registry &reg);
        void display_power(registry &reg);
        void create_sound(registry &reg, int idx);
        void display_score(registry &reg, int idx);
        void gameLoop(registry &reg, Components::Inputs input, int id, std::string name);
        int main_menu(registry &reg, Components::Inputs input, int id, int time, std::string name);
        void init_game(registry &reg);
        void check_collision(registry &reg);
        void display_player_score(registry reg, int idx, std::string name);
        void set_framerate(registry &reg);
        void draw_shield(registry &reg);
        void set_life(registry &reg, int nbr, bool is_ia);
        void set_config(std::string file);
        ISystem system;
        std::shared_ptr<Sfml> (*se)(void);
        std::shared_ptr<Sfml> sec;
        Components::level config;
        int nbr_client;
        int j = 1;
        int jj = 1;
        int jjj = 1;
        int jjjj = 1;
        int stage = 0;
        int is_change = 0;
        int score1 = 25;
        int score2 = 70;
        bool is_create = false;
    private:
};

#endif /* !SFML */
