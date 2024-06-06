/*
** EPITECH PROJECT, 2022
** R TYPE
** File description:
** sfml cpp
*/

#include "sfml.hpp"

void Game_SFML::Load_lib()
{
    void *handle = dlopen("./build/lib/libsfml.so", RTLD_NOW);
    //void *handle = dlopen("./Game/librairies/sfml_lib.so", RTLD_NOW);
    std::shared_ptr<Sfml> create_t;
    this->se = reinterpret_cast<std::shared_ptr<Sfml>(*)(void)>(dlsym(handle, "entryPoint"));
    this->sec = this->se();
    if (!handle) std::cerr << dlerror() << std::endl;
    if (!this->sec) std::cerr << dlerror() << std::endl;
}

void Game_SFML::create_game_window(registry &reg)
{
    this->Load_lib();
    auto &wind = reg.get_components<Components::Window>();
    auto &win = wind[0];
    this->sec->createGameWindow(win.value().x, win.value().y, win.value().name, win.value().resolution);
}

void Game_SFML::create_draw(registry &reg, int idx)
{
    auto &dra = reg.get_components<Components::drawable>();
    auto &dr = dra[idx];
    this->sec->createdraw(idx, dr.value().path);
}

void Game_SFML::display_draw(registry &reg, int idx)
{
    auto &dra = reg.get_components<Components::drawable>();
    auto &dr = dra[idx];
    Components::Frame frame = this->sec->displaydraw(idx, dr.value().posX, dr.value().posY, dr.value().scaleX, dr.value().scaleY);
    dr.value().frame = frame;
}

void Game_SFML::create_draw_rect(registry &reg, int idx)
{
    Components::Frame frame;
    auto &dra = reg.get_components<Components::drawable_rect>();
    auto &dr = dra[idx];
    this->sec->createdrawrect(idx, dr.value().path);
    //dr.value().frame = frame;
}

void Game_SFML::display_draw_rect(registry &reg, int idx)
{
    Components::Frame frame;
    auto &dra = reg.get_components<Components::drawable_rect>();
    auto &dr = dra[idx];
    frame = this->sec->displaydraw(idx, dr.value().posX, dr.value().posY, dr.value().scaleX, dr.value().scaleY, dr.value().rect);
    dr.value().frame = frame;
}

void Game_SFML::create_player_rect(registry &reg, int nbr)
{
    Components::Frame frame;
    auto &dra = reg.get_components<Components::Player>();
    for (int i =0; i < nbr; i++) {
        this->sec->createdrawplayer(i, dra[i].value().rect.path);
    }
}

void Game_SFML::display_player_rect(registry &reg, int nbr)
{
    Components::Frame frame;
    auto &dra = reg.get_components<Components::Player>();
    for (int i = 0; i < nbr; i++) {
        if (dra[i].value().alive == true) {
            frame = this->sec->displaydrawplayer(i, dra[i].value().rect.posX, dra[i].value().rect.posY, dra[i].value().rect.scaleX, dra[i].value().rect.scaleY, dra[i].value().rect.rect);
            dra[i].value().rect.frame = frame;
        }
    }
}

void Game_SFML::display_player_rect(registry &reg, int nbr, int idx)
{
    Components::Frame frame;
    auto &dra = reg.get_components<Components::Player>();
    //for (int i = 0; i < nbr; i++) {
        if (dra[idx].value().alive == true) {
            frame = this->sec->displaydrawplayer(idx, dra[idx].value().rect.posX, dra[idx].value().rect.posY, dra[idx].value().rect.scaleX, dra[idx].value().rect.scaleY, dra[idx].value().rect.rect);
            dra[idx].value().rect.frame = frame;
        }
    //}
}

void Game_SFML::create_ennemy(registry &reg)
{
    Components::Frame frame;
    auto &dra = reg.get_components<Components::Ennemy>();
    for (int  i = 0; i < dra.size(); i++) {
        this->sec->createdrawennemy(i, dra[i].value().rect.path);
    }
}

void Game_SFML::display_ennemy(registry &reg, int idx)
{
    Components::Frame frame;
    auto &dra = reg.get_components<Components::Ennemy>();
    //for (int  i = 0; i < dra.size(); i++) {
    if (dra[idx].value().alive == true) {
        //dra[idx].value().alive = true;
        frame = this->sec->displaydrawennemy(idx, dra[idx].value().rect.posX, dra[idx].value().rect.posY, dra[idx].value().rect.scaleX, dra[idx].value().rect.scaleY, dra[idx].value().rect.rect);
        dra[idx].value().rect.frame = frame;
    }
    //}
}

void Game_SFML::create_text(registry &reg, int idx)
{
    auto &dra = reg.get_components<Components::Text>();
    auto &dr = dra[idx];
    this->sec->createText(idx, dr.value().txt, dr.value().font, dr.value().color, dr.value().style);
}

void Game_SFML::display_text(registry &reg, int idx)
{
    auto &dra = reg.get_components<Components::Text>();
    auto &dr = dra[idx];
    this->sec->displayText(idx, dr.value().txt, dr.value().posX, dr.value().posY, dr.value().charactere_size, dr.value().gras);
}

void Game_SFML::display_player_score(registry reg, int idx, std::string name)
{
    auto &player = reg.get_components<Components::Player>();
    this->sec->displayText(idx, std::to_string(player[idx].value().score), 480, 10, 50, 0);
    this->sec->displayText(idx, "score", 300, 10, 35, 1.4);
    this->sec->displayText(idx, name, 10, 10, 35, 1.4);
}

void Game_SFML::create_fire(registry &reg)
{
    Components::Frame frame;
    auto &dra = reg.get_components<Components::fire>();
    for (int idx = 0; idx < dra.size(); idx++) {
        //if(dra[idx].value().is_fire == true) {
            this->sec->createdrawfire(idx, dra[idx].value().rect.path);
            dra[idx].value().rect.frame = frame;
            // this->system.set_shoot(reg);
        //}
    }
}

void Game_SFML::create_fire(registry &reg, int id)
{
    Components::Frame frame;
    auto &dra = reg.get_components<Components::fire>();
    for (int idx = 0; idx < dra.size(); idx++) {
        //if(dra[idx].value().is_fire == true) {
            if (dra[idx].value().id == id) {
                this->sec->createdrawfire(idx, dra[idx].value().rect.path);
                dra[idx].value().rect.frame = frame;
            }
            // this->system.set_shoot(reg);
        //}
    }
}

void Game_SFML::display_fire(registry &reg)
{
    Components::Frame frame;
    auto &dra = reg.get_components<Components::fire>();
    for (int idx = 0; idx < dra.size(); idx++) {
        //if(dra[idx].value().is_fire == true) {
            frame = this->sec->displaydrawfire(idx, dra[idx].value().rect.posX, dra[idx].value().rect.posY, dra[idx].value().rect.scaleX, dra[idx].value().rect.scaleY, dra[idx].value().rect.rect);
            dra[idx].value().rect.frame = frame;
            this->system.set_shoot(reg);
        //}
    }
}

void Game_SFML::create_power(registry &reg)
{
    Components::Frame frame;
    auto &power = reg.get_components<Components::Power_up>();
    for (int idx = 0; idx < power.size(); idx++) {
        //if(dra[idx].value().is_fire == true) {
            this->sec->createdrawpower(idx, power[idx].value().rect.path);
            power[idx].value().rect.frame = frame;
            // this->system.set_shoot(reg);
        //}
    }
}

void Game_SFML::display_power(registry &reg)
{
    Components::Frame frame;
    auto &power = reg.get_components<Components::Power_up>();
    for (int idx = 0; idx < power.size(); idx++) {
        //if(dra[idx].value().is_fire == true) {
            frame = this->sec->displaydrawpower(idx, power[idx].value().rect.posX, power[idx].value().rect.posY, power[idx].value().rect.scaleX, power[idx].value().rect.scaleY);
            power[idx].value().rect.frame = frame;
            //this->system.set_shoot(reg);
        //}
    }
}

void Game_SFML::create_sound(registry &reg, int idx)
{
    auto &sound = reg.get_components<Components::Sound>();
    this->sec->play_song(sound[idx].value().path, idx, sound[idx].value().inLoop, sound[idx].value().is_play, sound[idx].value().volume);
}

void Game_SFML::display_score(registry &reg, int idx)
{
    auto &dra = reg.get_components<Components::Player>();

    //this->sec->displayText("SCORE :", 300, 10, "./Assets/space_2.ttf", "Cyan", 50, 1.4, "Regular");
    //this->sec->displayText(std::to_string(dra[idx].value().score), 480, 10, "./Assets/space_2.ttf", "White", 50, 1, "Regular");
}

void Game_SFML::set_life(registry &reg, int nbr, bool is_ia)
{
    auto &player = reg.get_components<Components::Player>();

    if (is_ia) player[1].value().alive = true;
    for (int i = 0; i < nbr ; i++) {
        player[i].value().alive = true;
    }
}

void Game_SFML::check_collision(registry &reg)
{
    auto &ennemy = reg.get_components<Components::Ennemy>();
    auto &player = reg.get_components<Components::Player>();
    auto &fire = reg.get_components<Components::fire>();
    auto &draw = reg.get_components<Components::drawable_rect>();
    auto &power = reg.get_components<Components::Power_up>();

    for (int i = 0; i < fire.size(); i++) {
        if (fire[i].value().is_fire == true) {
            for (int j = 0; j < ennemy.size(); j++) {
                if (this->sec->check_collision(ennemy[j].value().rect.frame, fire[i].value().rect.frame) == true && ennemy[j].value().status != "BOSS" 
                    && ennemy[j].value().alive == true) {
                    fire[i].value().rect.posX = 2000;
                    fire[i].value().is_fire = false;
                    ennemy[j].value().rect.posX = 1500;
                    ennemy[j].value().rect.posY = rand() % 750;
                    player[fire[i].value().id].value().score += player[fire[i].value().id].value()._sc;
                    //break;
                }
                if (this->sec->check_collision(ennemy[j].value().rect.frame, player[fire[i].value().id].value().rect.frame) == true && ennemy[j].value().status != "BOSS" 
                    && ennemy[j].value().alive == true) {
                    fire[i].value().rect.posX = 2000;
                    fire[i].value().is_fire = false;
                    ennemy[j].value().rect.posX = 1500;
                    ennemy[j].value().rect.posY = rand() % 750;
                    player[fire[i].value().id].value().score += player[fire[i].value().id].value()._sc;
                    //break;
                }
                if (this->sec->check_collision(ennemy[j].value().rect.frame, fire[i].value().rect.frame) == true && ennemy[j].value().status == "BOSS"
                    && ennemy[j].value().alive == true) {
                    fire[i].value().rect.posX = 2000;
                    fire[i].value().is_fire = false;
                    if (ennemy[j].value().life > 0) {
                        ennemy[j].value().life -= 1;
                        player[fire[i].value().id].value().score += 2 * player[fire[i].value().id].value()._sc;
                    }
                    else {
                        ennemy[j].value().rect.posX = 2000;
                        ennemy[j].value().rect.posY = 0;
                        ennemy[j].value().alive = false;
                        this->stage++;
                    }
                    this->system.set_sound(reg, 2, true);
                    this->create_sound(reg, 2);
                    this->system.set_sound(reg, 2, false);
                }
            }
        }
        if (fire[i].value().id == 4) {
            for (int y = 0; y < player.size(); y++) {
                if (this->sec->check_collision(player[y].value().rect.frame, fire[i].value().rect.frame) == true ) {
                    fire[i].value().rect.posX = 2000;
                    fire[i].value().is_fire = false;
                    if (player[y].value().is_shield == false) {
                        player[y].value().life -= 1;
                        if (draw[16].value().rect.x <= 388 && y == 0) draw[16].value().rect.x += 194;
                        if (draw[17].value().rect.x <= 388 && y == 1) draw[17].value().rect.x += 194;
                        if (draw[18].value().rect.x <= 388 && y == 2) draw[18].value().rect.x += 194;
                        if (draw[19].value().rect.x <= 388 && y == 3) draw[19].value().rect.x += 194;
                    }
                    //if (player[y].value().life == 0) player[y].value().alive = false;
                    //fire[i].value().is_fire = false;
                    //player[j].value().rect.posX = 1500;
                    //break;
                }
            }
        }
    }
    for (int i = 0; i < player.size(); i++) {
        for (int j = 0; j < power.size(); j++) {
            if (this->sec->check_collision(player[i].value().rect.frame, power[j].value().rect.frame) == true) {
                if (power[j].value().action == "LIFE") {
                    if (player[i].value().life < 3) {
                        player[i].value().life += 1;
                        if (draw[16].value().rect.x > 0 && draw[16].value().rect.x <= 388 && i == 0) draw[16].value().rect.x -= 194;
                        if (draw[17].value().rect.x > 0 && draw[17].value().rect.x <= 388 && i == 1) draw[17].value().rect.x -= 194;
                        if (draw[18].value().rect.x > 0 && draw[18].value().rect.x <= 388 && i == 2) draw[18].value().rect.x -= 194;
                        if (draw[19].value().rect.x > 0 && draw[19].value().rect.x <= 388 && i == 3) draw[19].value().rect.x -= 194;
                    }
                }
                if (power[j].value().action == "SPEED") {
                    player[i].value().speed += 150;
                    //if (player[i].value().speed < 25) {
                        //this->system.set_speed(reg, 0);
                       // player[0].value().speed += 150;
                        // if (draw[16].value().rect.x > 0 && draw[16].value().rect.x <= 388 && i == 0) draw[16].value().rect.x -= 194;
                        // if (draw[17].value().rect.x > 0 && draw[17].value().rect.x <= 388 && i == 1) draw[17].value().rect.x -= 194;
                        // if (draw[18].value().rect.x > 0 && draw[18].value().rect.x <= 388 && i == 2) draw[18].value().rect.x -= 194;
                        // if (draw[19].value().rect.x > 0 && draw[19].value().rect.x <= 388 && i == 3) draw[19].value().rect.x -= 194;
                    //}
                }
                if (power[j].value().action == "LASER") {
                    player[i].value()._sc += 5;
                }
                power[j].value().rect.posX = 1600;
                power[j].value().rect.posY = rand() % 700;
            }
        }
    }
}

void Game_SFML::set_config(std::string file)
{
    std::fstream filename;
    filename.open(file);
    int first_score = 0, second_score = 0, enm1 = 0, enm2 = 0, enm3 = 0, enm4 = 0;
    int boss1 = 0, boss2 = 0; 
    filename >> first_score >> enm1 >> enm2 >> boss1 >> second_score >> enm3 >> enm4 >> boss2;
    config.first_score = first_score;
    config.second_score = second_score;
    config.boss1 = boss1;
    config.boss2 = boss2;    
    config.enm1 = enm1;
    config.enm2 = enm2;
    config.enm3 = enm3;
    config.enm4 = enm4;  
    filename.close();
    this-> score1 = config.first_score, this->score2 = config.second_score;
}

void Game_SFML::draw_shield(registry &reg)
{
    auto &player = reg.get_components<Components::Player>();

    for (int i = 0; i < player.size(); i++) {
        if (player[i].value().is_shield == true) {
            this->create_fire(reg, i);
            this->display_draw(reg, i + 10);
        }
        else this->create_fire(reg, i);
    }
}

void Game_SFML::init_game(registry &reg)
{
    auto &draw = reg.get_components<Components::drawable>();
    auto &draw_rect = reg.get_components<Components::drawable_rect>();
    auto &player = reg.get_components<Components::Player>();
    auto &ennemy = reg.get_components<Components::Ennemy>();
    auto &fire = reg.get_components<Components::fire>();
    auto &text = reg.get_components<Components::Text>();

    this->create_game_window(reg);
    this->create_sound(reg, 0);
    this->create_sound(reg, 1);
    this->create_sound(reg, 2);
    this->create_sound(reg, 3);
    this->system.set_cine_vector(reg);
    this->system.set_cine_vector2(reg);
    this->system.set_cine_vector3(reg);
    this->system.set_cine_vector4(reg);
    for (int i = 0; i < draw.size(); i++) {
        this->create_draw(reg, i);
    }
    for (int i = 0; i < draw_rect.size(); i++) {
        this->create_draw_rect(reg, i);
    }
    //for (int i = 0; i < player.size(); i++) {
        this->create_player_rect(reg, 4);
    //}
    //for (int i = 0; i < ennemy.size(); i++) {
        this->create_ennemy(reg);
    //}
    //for (int i = 0; i < fire.size(); i++) {
        this->create_fire(reg);
    //}
    for (int i = 0; i < text.size(); i++) {
        this->create_text(reg, i);
    }
    this->create_power(reg);
}

void Game_SFML::gameLoop(registry &reg, Components::Inputs input, int id, std::string name)
{
        if (this->sec->get_clock() > 0.1f) {
            this->system.change_rect(reg);
            //this->create_draw_rect(1);
            this->sec->restart_clock();
        }
        this->system.move_planete(reg);
        this->create_sound(reg, 0);
        this->system.change_fire_rect(reg);

        // this->display_draw(reg, 0);
        // this->display_draw(reg, 1);
        this->system.set_ennemy_shoot(reg);
        //this->system.set_ennemy_shoot(reg);
        // //this->create_draw_rect(0);
        this->display_draw_rect(reg, 0);
        this->display_draw_rect(reg, 1);
        this->display_draw_rect(reg, 2);
        this->display_draw_rect(reg, 13);
        this->display_draw_rect(reg, 14);
        this->display_draw_rect(reg, 15);
        this->display_draw_rect(reg, 1);
        this->display_draw_rect(reg, 0);
        this->display_draw_rect(reg, 2);
        this->display_power(reg);
        this->display_fire(reg);
        this->display_ennemy(reg, 0);
        this->display_ennemy(reg, 1);
        this->display_ennemy(reg, 2);
        this->display_ennemy(reg, 3);
        this->display_ennemy(reg, 4);
        this->display_ennemy(reg, 5);
        this->check_collision(reg);
        this->system.move_ennemy(reg);
        this->system.move_power(reg);
        this->display_player_rect(reg, this->nbr_client);
        if (this->nbr_client == 1) {
            this->display_player_rect(reg, this->nbr_client, 1);
            this->system.move_IA(reg);
        }
        // this->display_player_rect(reg, 1);
        // this->display_player_rect(reg, 2);
        // this->display_player_rect(reg, 3);
        this->display_player_score(reg, id, name);
        this->display_draw_rect(reg, id + 16);
        if (this->stage == 0) this->system.check_boss(reg, this->score1, this->config.boss1);
        if (this->is_change == 0) {
            if (this->system.change_stage(reg, this->score1) == true) {
                this->create_draw_rect(reg, 0);
                this->create_draw_rect(reg, 1);
                this->create_draw_rect(reg, 2);
                
                //this->system.set_sound(reg, 0, false);
                this->system.set_sound(reg, 3, true);
                this->create_sound(reg, 3);
                this->is_change = 1;
            }
        }
        if (this->stage == 1) this->system.check_boss2(reg, this->score2, this->config.boss2);
        //this->display_player_score(reg, 0);
        // if (this->system.check) {
        //     this->display_draw_rect(reg, 0);
        //     this->system.shoot(reg);
        // }
        //if (input == Components::ENTER_KEY) this->sec->closeWindow();
        this->system.check_shield(reg);
        this->draw_shield(reg);
        if (this->system.is_infini == false) this->system.game_over(reg, this->score2);
        if (this->system.is_over(reg) == true) this->system.where = 13;
}

void Game_SFML::set_framerate(registry &reg)
{
    auto &wind = reg.get_components<Components::Window>();
    this->sec->set_framerate(wind[0].value().framerate);
}

int Game_SFML::main_menu(registry &reg, Components::Inputs input, int id, int time, std::string name)
{
    auto &text = reg.get_components<Components::Text>();
    auto &player = reg.get_components<Components::Player>();
    auto &ennemy = reg.get_components<Components::Player>();
    //this->create_game_window(reg);
    //while (1) {
        //Components::Inputs input = this->sec->getInput();
        //int j = 1;
        Components::Position mouse_pos = this->sec->getMouse();
        this->system.update_mouse(reg, mouse_pos);
        this->system.event_mouse(reg, input);
        this->system.move_bg(reg);
        this->sec->show();
        this->sec->clearWindow();
        //this->set_framerate(reg);
        this->display_draw(reg, 0);
        this->display_draw(reg, 1);
        // MAIN MENU

        if (this->system.where == -1) {
            this->system.set_cine(reg, j);
            this->create_draw(reg, 3);
            this->display_draw(reg, 3);
            this->display_text(reg, 14);
            std::this_thread::sleep_for(std::chrono::microseconds{50000});
            if (j<=84) this->j++;
            if (input == Components::C) this->system.where = 0;
            if (j == 84) this->system.where = 0;
        }

        if (this->system.where == -2) {
            this->system.set_cine2(reg, jj);
            this->create_draw(reg, 4);
            this->display_draw(reg, 4);
            this->display_text(reg, 15);
            std::this_thread::sleep_for(std::chrono::microseconds{50000});
            if (jj<=32) this->jj++;
            if (input == Components::C) this->system.where = 6;
            if (jj == 32) this->system.where = 6;
            //exit(0);
        }

        if (this->system.where == 0) {
        //    this->create_draw(reg, 0);
          //  this->create_draw(reg, 1);
            this->display_text(reg, 0);
            this->display_text(reg, 1);
            this->display_text(reg, 2);
            this->display_text(reg, 3);
            this->display_text(reg, 4);
            this->display_text(reg, 5);
            this->display_draw_rect(reg, 3);
            this->display_draw_rect(reg, 4);
            if (this->sec->get_clock() > 0.1f) {
                this->system.change_menu_rect(reg);
            }
        }

        //GAME LOOP
        if (this->system.where == 1) {
            if (this->sec->get_clock() > 0.1f) {
                this->system.play_rect(reg);
            }
            this->display_text(reg, 10);
            this->display_draw(reg, 5);
            this->display_draw(reg, 6);
            this->display_draw_rect(reg, 22);
            this->display_draw_rect(reg, 23);
            //this->gameLoop(reg, input, id, name);
        }

        // // INVENTORY
        if (this->system.where == 2) {
            if (this->sec->get_clock() > 0.1f) {
                this->system.update_inventory(reg);
                this->sec->restart_clock();
            }
            this->display_draw_rect(reg, 9);
            this->display_draw_rect(reg, 10);
            this->display_text(reg, 10);
            this->display_draw(reg, 9);
        }

        // // SETTING
        if (this->system.where == 3) {
            auto &song = reg.get_components<Components::Sound>();
            auto &wind = reg.get_components<Components::Window>();
            if (this->sec->get_clock() > 0.1f) {
                this->system.update_setting(reg);
                this->sec->restart_clock();
            }
            this->display_draw_rect(reg, 5);
            this->display_draw_rect(reg, 6);
            this->display_text(reg, 6);
            this->display_text(reg, 7);
            this->display_text(reg, 8);
            this->display_text(reg, 9);
            this->display_text(reg, 10);
            this->display_text(reg, 22);
            this->display_text(reg, 23);
            this->display_text(reg, 24);
            this->display_text(reg, 25);
            this->display_text(reg, 26);
            this->display_text(reg, 27);
            this->display_text(reg, 28);
            this->display_text(reg, 29);
            this->display_text(reg, 30);
            this->sec->set_song_vol(song[0].value().volume, 0);
            this->sec->set_framerate(wind[0].value().framerate);
            //this->set_framerate(reg);
        }

        // // CREDIT
        if (this->system.where == 4) {
            if (this->sec->get_clock() > 0.1f) {
                this->system.update_credit(reg);
                this->sec->restart_clock();
            }
            this->system.move_credit(reg, input);
            this->display_draw(reg, 2);
            this->display_draw_rect(reg, 11);
            this->display_draw_rect(reg, 12);
            this->display_text(reg, 10);
        }

        // // QUIT
        if (this->system.where == 5) {
            if (this->sec->get_clock() > 0.1f) {
                this->system.update_quit(reg);
                this->sec->restart_clock();
            }
            this->display_draw_rect(reg, 7);
            this->display_draw_rect(reg, 8);
            this->display_text(reg, 11);
            this->display_text(reg, 12);
            this->display_text(reg, 13);
        }

        //close in quit
        if (this->system.where == 6) {
            this->sec->closeWindow();
            exit(0);
            //break;
        }

        if (this->system.where == 8) {
            if (this->sec->get_clock() > 0.5f) {
                this->system.play_rect(reg);
            }
            this->display_draw_rect(reg, 24);
            this->display_draw_rect(reg, 25);
            this->display_draw_rect(reg, 26);
            this->display_draw_rect(reg, 27);
            this->display_text(reg, 10);
            this->display_text(reg, 16);
        }

        if (this->system.where == 9) {
            this->display_text(reg, 10);
            this->display_text(reg, 17);
            this->display_text(reg, 18);
            this->display_text(reg, 19);
        }

        if (this->system.where == 10) {
            this->system.set_cine3(reg, jjj);
            this->create_draw(reg, 7);
            this->display_draw(reg, 7);
            //this->display_text(reg, 15);
            std::this_thread::sleep_for(std::chrono::microseconds{100000});
            if (jjj<=20) this->jjj++;
            if (input == Components::C) this->system.where = 11;
            if (jjj == 20) jjj = 1;
        }

        if (this->system.where == 11) {
            text[31].value().txt = std::to_string(time);
            this->system.set_cine4(reg, jjjj);
            this->create_draw(reg, 8);
            this->display_draw(reg, 8);
            //this->display_text(reg, 15);
            std::this_thread::sleep_for(std::chrono::microseconds{200000});
            if (jjjj<=10) this->jjjj++;
            //if (input == Components::C) this->system.where = 12;
            if (jjjj == 10) jjjj = 1;
            display_text(reg, 31);
            if (time == 1) this->system.where = 12;
        }
        
        if (this->system.where == 12) {
            this->gameLoop(reg, input, id, name);
        }
        if (this->system.where == 13 && this->nbr_client == 1) {
            this->display_draw(reg, 14);
            this->sec->displayText(10, "CLICK R TO RESTART", 450, 600, 50, 1.4);
            this->sec->displayText(10, "CLICK N TO LEAVE", 450, 700, 50, 1.4);
            if (input == Components::R) {
                //this->system.restart(reg);
                //this->init_game(reg);
                player[0].value().score = 0;
                player[0].value().life = 3;
                player[0].value().rect.posX = 100;
                player[0].value().rect.posY = 100;
                ennemy[0].value().alive = true;
                ennemy[1].value().alive = true;
                ennemy[2].value().alive = false;
                ennemy[3].value().alive = false;
                this->is_change = 0;
                this->system.where = 12;
            }
            if (input == Components::N) {
                //this->system.insert_in_sparse(reg);
                //this->init_game(reg);
                this->system.where = 5;
            }
        }
        if (this->system.where == 13 && this->nbr_client != 1) {
            this->display_draw(reg, 14);
            std::string to_dr = std::to_string(player[id].value().score); 
            this->sec->displayText(1, "YOUR SCORE IS:", 450, 10, 50, 1.4);
            this->sec->displayText(2, to_dr, 800, 10, 50, 1.4);
            // this->sec->displayText(10, "CLICK R TO RESTART", 450, 600, 50, 1.4);
            this->sec->displayText(10, "CLICK N TO LEAVE", 450, 700, 50, 1.4);
            // if (input == Components::R) {
            //     //this->system.restart(reg);
            //     //this->init_game(reg);
            //     this->system.where = 12;
            // }
            if (input == Components::N) {
                //this->system.insert_in_sparse(reg);
                //this->init_game(reg);
                this->system.where = 5;
            }
        }
        if (this->system.where == 14) {
            this->display_draw(reg, 15);
            std::string to_dr = std::to_string(player[id].value().score); 
            this->sec->displayText(1, "YOUR SCORE IS:", 450, 10, 50, 1.4);
            this->sec->displayText(2, to_dr, 800, 10, 50, 1.4);
            this->sec->displayText(3, "CLICK N TO LEAVE", 450, 700, 50, 1.4);
            if (input == Components::N) {
                //this->system.insert_in_sparse(reg);
                //this->init_game(reg);
                this->system.where = 5;
            }
        }
    //}
    return (this->system.where);
}

// int main()
// {
//     Game_SFML ok;
//     registry reg;
//     ok.system.init_sparse(reg);
//     //ok.init_game(reg);
//     ok.main_menu(reg);
//     //ok.gameLoop();
// }