/*
** EPITECH PROJECT, 2022
** R TYPE
** File description:
** system cpp
*/

#include "system.hpp"


void ISystem::init_sparse(registry &reg)
{
    reg.register_component<Components::Window>();
    reg.register_component<Components::drawable>();
    reg.register_component<Components::drawable_rect>();
    reg.register_component<Components::fire>();
    reg.register_component<Components::Player>();
    reg.register_component<Components::Ennemy>();
    reg.register_component<Components::Text>();
    reg.register_component<Components::Position>();
    reg.register_component<Components::Sound>();
    reg.register_component<Components::Power_up>();
    this->insert_in_sparse(reg);
}

void ISystem::insert_in_sparse(registry &reg)
{

    this->create_window(reg, 1200, 800, "window", "Full");

    this->create_drawable(reg, 0, "./Assets/star_parallax.png", 0, 0, 1, 1);
    this->create_drawable(reg, 1, "./Assets/star_parallax_2.png", 500, 100, 1, 1);

    this->create_drawable(reg, 0, "./Assets/island.png", 500, -100, 1.5, 1.5, {0, 0, 250, 250});
    this->create_drawable(reg, 1, "./Assets/galaxy.png", 1100, 500, 2, 2, {0, 0, 250, 250});
    this->create_drawable(reg, 2, "./Assets/lave.png", 2000, 250, 1.2, 1.2, {0, 0, 250, 250});

    this->create_player(reg, 0, "./Assets/voiture1.png", 0, 200, 0.5, 0.5, {0, 0, 176, 96});
    this->create_player(reg, 1, "./Assets/voiture2.png", 50, 50, 0.5, 0.5, {0, 0, 176, 125});
    this->create_player(reg, 2, "./Assets/voiture3.png", 200, 250, 0.3, 0.3, {0, 0, 329, 160});
    this->create_player(reg, 3, "./Assets/rick.png", 200, 550, 0.5, 0.5, {0, 0, 192, 144});

    this->create_ennemy(reg, 0, "./Assets/ennemy_1.png", 1220, 170, 0.25, 0.25, {0, 0, 400, 400}, "simple", true);
    this->create_ennemy(reg, 1, "./Assets/ennemy_2.png", 1400, 230, 0.15, 0.15, {0, 0, 550, 500}, "simple", true);
    this->create_ennemy(reg, 2, "./Assets/ennemy_3.png", 800, 450, 0.25, 0.25, {0, 0, 653, 632}, "simple", false);
    this->create_ennemy(reg, 3, "./Assets/ennemy_4.png", 1250, 600, 0.5, 0.5, {0, 0, 560, 462}, "simple", false);
    this->create_ennemy(reg, 4, "./Assets/boss_1.png", 1500, 300, 0.7, 1, {0, 0, 150, 150}, "BOSS", false);
    this->create_ennemy(reg, 5, "./Assets/boss_2.png", 1500, 300, 1, 1, {0, 0, 135, 135}, "BOSS", false);

    // FIRE
    this->create_fire(reg, 0, 0, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 1, 0, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 2, 0, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 3, 0, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 4, 0, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});

    this->create_fire(reg, 5, 1, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 6, 1, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 7, 1, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 8, 1, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 9, 1, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});

    this->create_fire(reg, 10, 2, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 11, 2, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 12, 2, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 13, 2, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 14, 2, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});

    this->create_fire(reg, 15, 3, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 16, 3, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 17, 3, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 18, 3, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});
    this->create_fire(reg, 19, 3, "./Assets/fire.png", -100, -100, 0.75, 0.75, {0, 0, 64, 32});

    this->create_fire(reg, 20, 4, "./Assets/blast_2.png", -100, -100, 0.75, 0.75, {0, 0, 65, 20});
    this->create_fire(reg, 21, 4, "./Assets/blast_2.png", -100, -100, 0.75, 0.75, {0, 0, 65, 20});
    this->create_fire(reg, 22, 4, "./Assets/blast_2.png", -100, -100, 0.75, 0.75, {0, 0, 65, 20});
    this->create_fire(reg, 23, 4, "./Assets/blast_2.png", -100, -100, 0.75, 0.75, {0, 0, 65, 20});
    this->create_fire(reg, 24, 4, "./Assets/blast_2.png", -100, -100, 0.75, 0.75, {0, 0, 65, 20});
    this->create_fire(reg, 25, 4, "./Assets/blast_2.png", -100, -100, 0.75, 0.75, {0, 0, 65, 20});
    
    this->create_fire(reg, 26, 4, "./Assets/blast_3.png", -100, -100, 1, 1, {0, 0, 65, 20});
    this->create_fire(reg, 27, 4, "./Assets/blast_3.png", -100, -100, 1, 1, {0, 0, 65, 20});
    this->create_fire(reg, 28, 4, "./Assets/blast_3.png", -100, -100, 1, 1, {0, 0, 65, 20});
    this->create_fire(reg, 29, 4, "./Assets/blast_3.png", -100, -100, 1, 1, {0, 0, 65, 20});
    
    // END FIRE

    //MENU
    this->create_text(reg, 0, "MAIN MENU", 900, 80, "./Assets/space.otf", "Cyan", 75, 0, "Regular");
    this->create_text(reg, 1, "PLAY GAME", 1000, 200, "./Assets/font.ttf", "Cyan", 50, 0, "Regular");
    this->create_text(reg, 2, "SETTINGS", 1000, 400, "./Assets/font.ttf", "Cyan", 50, 0, "Regular");
    this->create_text(reg, 3, "INVENTORY", 1000, 300, "./Assets/font.ttf", "Cyan", 50, 0, "Regular");
    this->create_text(reg, 4, "CREDITS", 1000, 500, "./Assets/font.ttf", "Cyan", 50, 0, "Regular");
    this->create_text(reg, 5, "QUIT", 1000, 600, "./Assets/font.ttf", "Cyan", 50, 0, "Regular");

    this->create_drawable(reg, 3, "./Assets/terre.png", -400, -50, 3.5, 3.5, {0, 0, 250, 250});
    this->create_drawable(reg, 4, "./Assets/rtype.png", 600, 250, 0.9, 0.9, {0, 0, 250, 250});

    // OPTION
    this->create_drawable(reg, 5, "./Assets/moon.png", 900, -50, 3.5, 3.5, {0, 0, 250, 250});
    this->create_drawable(reg, 6, "./Assets/setting.png", 750, 0, 0.9, 0.9, {0, 0, 250, 250});

    this->create_text(reg, 6, "SETTING", 400, 50, "./Assets/space.otf", "Cyan", 75, 0, "Regular");
    this->create_text(reg, 7, "FRAMERATE:", 50, 200, "./Assets/space_4.ttf", "Cyan", 50, 0, "Regular");
    this->create_text(reg, 8, "SOUND:", 50, 400, "./Assets/space_4.ttf", "Cyan", 50, 0, "Regular");
    this->create_text(reg, 9, "SCREEN RESOLUTION:", 50, 600, "./Assets/space_4.ttf", "Cyan", 50, 0, "Regular");
    this->create_text(reg, 10, "<-", 50, 0, "./Assets/space.otf", "White", 65, 0, "Regular");
    // FIN OPTION

    // QUIT
    this->create_drawable(reg, 7, "./Assets/quit.png", 550, 0, 0.9, 0.9, {0, 0, 250, 250});
    this->create_drawable(reg, 8, "./Assets/galaxy_2.png", 350, 150, 2.5, 2.5, {0, 0, 250, 250});

    this->create_text(reg, 11, "LEAVE ?", 550, 200, "./Assets/space.otf", "Cyan", 75, 0, "Regular");
    this->create_text(reg, 12, "NO", 350, 400, "./Assets/space_3.ttf", "Cyan", 50, 0, "Regular");
    this->create_text(reg, 13, "YES", 900, 400, "./Assets/space_3.ttf", "White", 50, 0, "Regular");
    // FIN QUIT

    // INVENTORY
    this->create_drawable(reg, 9, "./Assets/lave_2.png", 400, -400, 2.5, 2.5, {0, 0, 250, 250});
    this->create_drawable(reg, 10, "./Assets/inventory.png", 1100, 0, 0.9, 0.9, {0, 0, 250, 250});
    // FIN INVENTORY

    // CREDIT
    this->create_drawable(reg, 11, "./Assets/star_2.png", 1150, 550, 1, 1, {0, 0, 300, 300});
    this->create_drawable(reg, 12, "./Assets/cred.png", 50, 500, 0.9, 0.9, {0, 0, 250, 250});
    this->create_drawable(reg, 2, "./Assets/credit.png", 200, 0, 0.5, 0.5);
    // FIN CREDIT
    this->create_pos(reg, 0, 0, 0);
    // FIN MENU

    this->create_drawable(reg, 13, "./Assets/meteorite.png", 800, -1000, 0.7, 0.7, {0, 0, 250, 250});
    this->create_drawable(reg, 14, "./Assets/meteorite.png", 250, 1900, 0.7, 0.7, {0, 0, 250, 250});
    this->create_drawable(reg, 15, "./Assets/meteorite.png", 2200, 200, 0.7, 0.7, {0, 0, 250, 250});

    this->create_drawable(reg, 16, "./Assets/life.png", 130, 15, 0.3, 0.3, {0, 0, 194, 177});
    this->create_drawable(reg, 17, "./Assets/life.png", 130, 15, 0.3, 0.3, {0, 0, 194, 177});
    this->create_drawable(reg, 18, "./Assets/life.png", 130, 15, 0.3, 0.3, {0, 0, 194, 177});
    this->create_drawable(reg, 19, "./Assets/life.png", 130, 15, 0.3, 0.3, {0, 0, 194, 177});
    // SOUND
    this->create_sound(reg, 0, "./Assets/main.ogg", true, true, 25.f);
    this->create_sound(reg, 1, "./Assets/mechant.ogg", false, false, 100.f);
    this->create_sound(reg, 2, "./Assets/explosion.ogg", false, false, 100.f);
    this->create_sound(reg, 3, "./Assets/ambient.ogg", true, false, 100.f);
    // END SOUND
    // CINEMATIQUE
    this->create_text(reg, 14, "PRESS C TO CONTINUE", 800, 650, "./Assets/font.ttf", "White", 50, 0, "Regular");
    this->create_text(reg, 15, "TO BE CONTINUED", 850, 700, "./Assets/font.ttf", "White", 50, 0, "Regular");

    this->create_drawable(reg, 3, "./Assets/cinematique/ezgif-frame1.jpg", 0, 0, 1, 1);
    this->create_drawable(reg, 4, "./Assets/final/ezgif-frame1.jpg", 0, 0, 1, 1);
    // END CINEMATIQUE
    this->check = false;

    //INVENTORY
    this->create_drawable(reg, 20, "./Assets/lave_2.png", 400, -400, 2.5, 2.5, {0, 0, 250, 250}); //moon
    this->create_drawable(reg, 21, "./Assets/inventory.png", 1100, 0, 0.9, 0.9, {0, 0, 250, 250}); //anim1
    //END INVENTORY
    // PLAYGAME
    this->create_drawable(reg, 5, "./Assets/solo.png", 450, 300, 0.25, 0.25); //solo
    this->create_drawable(reg, 6, "./Assets/multiplayer.png", 800, 300, 0.25, 0.25); //multijouer
    this->create_drawable(reg, 22, "./Assets/play_game.png", 400, 500, 2.5, 2.5, {0, 0, 250, 250}); //play_game
    this->create_drawable(reg, 23, "./Assets/rick_pg.png", 50, 500, 0.5, 0.5, {0, 0, 480, 480}); //rick
    this->create_drawable(reg, 24, "./Assets/voiture1.png", 200, 500, 0.5, 0.5, {0, 0, 176, 96}); //voiture1
    this->create_drawable(reg, 25, "./Assets/voiture2.png", 500, 500, 0.5, 0.5, {0, 0, 176, 125}); //voiture3
    this->create_drawable(reg, 26, "./Assets/voiture3.png", 800, 500, 0.3, 0.3, {0, 0, 329, 160}); //voiture4
    this->create_drawable(reg, 27, "./Assets/rick.png", 1100, 500, 0.5, 0.5, {0, 0, 192, 144}); //voiture5
    //END PLAYGAME
    this->create_text(reg, 16, "CHOOSE YOUR CAR", 500, 100, "./Assets/font.ttf", "White", 50, 0, "Regular"); //CHOOSE
    this->create_text(reg, 17, "ENDLESS", 200, 250, "./Assets/font.ttf", "Cyan", 50, 0, "Regular"); //ENDLESS
    this->create_text(reg, 18, "LEVEL", 1000, 250, "./Assets/font.ttf", "Green", 50, 0, "Regular"); //LEVEL
    this->create_text(reg, 19, "CHOOSE YOUR MODE", 500, 100, "./Assets/font.ttf", "White", 50, 0, "Regular"); //MODE
    this->create_text(reg, 20, "temps", 565, 260, "./Assets/timer.ttf", "White", 50, 1.4, "Regular"); //TEMPS

    auto &wind = reg.get_components<Components::Window>();
    std::string snn = std::to_string((int)(wind[0].value().framerate));
    this->create_text(reg, 21, "INVENTORY", 1000, 300, "./Assets/font.ttf", "Cyan", 50, 0, "Regular"); //INVENTORY
    this->create_text(reg, 22, "Full Screen", 651, 610, "./Assets/space_4.ttf", "White", 30, 0, "Regular"); //FULLDEFAULT
    this->create_text(reg, 23, "+", 873, 600, "./Assets/space_4.ttf", "Cyan", 50, 0, "Regular"); //FULLDEFAULTPL
    this->create_text(reg, 24, "-", 564, 600, "./Assets/space_4.ttf", "Cyan", 50, 0, "Regular"); //FULLDELFAUTMO
    this->create_text(reg, 25, "+", 550, 200, "./Assets/space_4.ttf", "Cyan", 50, 0, "Regular"); //PLUSFRAME
    this->create_text(reg, 26, "-", 380, 200, "./Assets/space_4.ttf", "Cyan", 50, 0, "Regular"); //MOINSFRAME
    this->create_text(reg, 27, snn, 450, 200, "./Assets/space_4.ttf", "White", 50, 0, "Regular"); //FRAME
    this->create_text(reg, 28, "+", 450, 400, "./Assets/space_4.ttf", "Cyan", 50, 0, "Regular"); //SOUNDPLUS
    this->create_text(reg, 29, "-", 250, 400, "./Assets/space_4.ttf", "Cyan", 50, 0, "Regular"); //SOUNDMOINS
    auto &sound = reg.get_components<Components::Sound>();
    std::string sn = std::to_string((int)(sound[0].value().volume));
   // auto &wind = reg.get_components<Components::Window>();
    //std::string snn = std::to_string((int)(wind[0].value().framerate));
    this->create_text(reg, 30, sn, 350, 400, "./Assets/space_4.ttf", "White", 50, 0, "Regular"); //SON

    this->create_drawable(reg, 7, "./Assets/cinematique_2/ezgif-frame1.jpg", 0, 0, 1, 1);
    this->create_drawable(reg, 8, "./Assets/cinematique_3/ezgif-frame1.jpg", 0, 0, 1, 1);

    this->create_text(reg, 31, "", 650, 310, "./Assets/space_4.ttf", "Black", 100, 0, "Regular"); //DECOMPTE

    // POWER UP
    this->create_power(reg, 0, "LIFE", "./Assets/heart.png", 1200, 100, 0.1, 0.1);
    this->create_power(reg, 1, "LIFE", "./Assets/heart.png", 250, -200, 0.1, 0.1);
    this->create_power(reg, 2, "SPEED", "./Assets/bolt.png", 1700, 250, 0.1, 0.1);
    this->create_power(reg, 3, "SPEED", "./Assets/bolt.png", 3000, 400, 0.1, 0.1);
    this->create_power(reg, 4, "LASER", "./Assets/x2.png", 800, 1000, 0.2, 0.2);
    this->create_power(reg, 5, "LASER", "./Assets/x2.png", 500, -100, 0.2, 0.2);
    // this->create_power(reg, 6, "SHOOT_SIZE", "./Assets/x2.png", 1200, 100, 0.2, 0.2);
    // this->create_power(reg, 7, "SHOOT_SIZE", "./Assets/x2.png", 1200, 100, 0.2, 0.2);
    // END POWER UP

    this->create_drawable(reg, 9, "./Assets/inv.png", 100, 300, 1, 1); //INVENTAIRE
    this->create_drawable(reg, 10, "./Assets/shield.png", 0, 0, 0.2, 0.2); //Shield
    this->create_drawable(reg, 11, "./Assets/shield.png", 0, 0, 0.2, 0.2); //Shield
    this->create_drawable(reg, 12, "./Assets/shield.png", 0, 0, 0.2, 0.2); //Shield
    this->create_drawable(reg, 13, "./Assets/shield.png", 0, 0, 0.2, 0.2); //Shield

    this->create_drawable(reg, 14, "./Assets/deadd.png", 0, 0, 1, 1); //DEAD
    this->create_drawable(reg, 15, "./Assets/vict.png", 0, 0, 1, 1); //VICTORY
}

void ISystem::load_lib(registry &reg)
{
    void *handle = dlopen("./build/lib/libsfml.so", RTLD_NOW);
    //void *handle = dlopen("./Game/librairies/sfml_lib.so", RTLD_NOW);
    std::shared_ptr<Sfml> create_t;
    this->se = reinterpret_cast<std::shared_ptr<Sfml>(*)(void)>(dlsym(handle, "entryPoint"));
    this->sec = this->se();
    if (!handle) std::cerr << dlerror() << std::endl;
    if (!this->sec) std::cerr << dlerror() << std::endl;
}

void ISystem::create_window(registry &reg, float height, float width, std::string name, std::string resolution)
{
    const entity to(0);
    Components::Window ok;
    ok.x = height, ok.y = width, ok.name = name, ok.resolution = resolution, ok.framerate = 60;
    reg.add_component<Components::Window>(to, ok);
}

void ISystem::create_drawable(registry &reg, int idx, std::string path, float posX, float posY, float scaleX, float scaleY)
{
    const entity to(idx);
    Components::drawable ok;
    ok.path = path, ok.posX = posX, ok.posY = posY, ok.scaleX = scaleX, ok.scaleY = scaleY;
    reg.add_component<Components::drawable>(to, ok);
}

void ISystem::create_drawable(registry &reg, int idx, std::string path, float posX, float posY, float scaleX, float scaleY, Components::Rect rect)
{
    const entity to(idx);
    Components::drawable_rect ok;
    ok.path = path, ok.posX = posX, ok.posY = posY, ok.scaleX = scaleX, ok.scaleY = scaleY, ok.rect = rect;
    reg.add_component<Components::drawable_rect>(to, ok);
}

void ISystem::create_player(registry &reg, int idx, std::string path, float posX, float posY, float scaleX, float scaleY, Components::Rect rect)
{
    const entity to(idx);
    Components::Player ok;
    ok.is_shield = false, ok.shield_time = 100, ok._sc = 5;
    ok.alive = false, ok.speed = 10, ok.power = 1, ok.score = 0, ok.life = 3, ok.rect.path = path, ok.rect.posX = posX, ok.rect.posY = posY, ok.rect.scaleX = scaleX, ok.rect.scaleY = scaleY, ok.rect.rect = rect;
    reg.add_component<Components::Player>(to, ok);
}

void ISystem::create_ennemy(registry &reg, int idx, std::string path, float posX, float posY, float scaleX, float scaleY, Components::Rect rect, std::string status, bool alive)
{
    const entity to(idx);
    Components::Ennemy ok;
    ok.up = 0, ok.forward = 0;
    if (status == "BOSS") ok.life = 3;
    else ok.life = 1;
    ok.status = status, ok.alive = alive, ok.speed = 10, ok.power = 1, ok.rect.path = path, ok.rect.posX = posX, ok.rect.posY = posY, ok.rect.scaleX = scaleX, ok.rect.scaleY = scaleY, ok.rect.rect = rect;
    reg.add_component<Components::Ennemy>(to, ok);
}

void ISystem::create_text(registry &reg, int idx, std::string txt, float posX, float posY, std::string font, std::string color, int size, int gras, std::string style)
{
    const entity to(idx);
    Components::Text ok;
    ok.txt = txt, ok.font = font, ok.color = color, ok.posX = posX, ok.posY = posY, ok.charactere_size = size, ok.gras = gras, ok.style = style;
    //reg.add_component<Components::Text>(to, ok);
    reg.add_component<Components::Text>(to, ok);
}

void ISystem::create_pos(registry &reg, int idx, float x, float y)
{
    const entity to(idx);
    Components::Position ok;
    ok.x = x, ok.y = y;
    reg.add_component<Components::Position>(to, ok);
}

void ISystem::create_fire(registry &reg, int idx, int id, std::string path, float posX, float posY, float scaleX, float scaleY, Components::Rect rect)
{
    const entity to(idx);
    Components::fire ok;
    ok.is_laser = false;
    ok.id = id, ok.idx = idx, ok.is_fire = false, ok.rect.path = path, ok.rect.posX = posX, ok.rect.posY = posY, ok.rect.scaleX = scaleX, ok.rect.scaleY = scaleY, ok.rect.rect = rect;
    reg.add_component<Components::fire>(to, ok);
}

void ISystem::create_sound(registry &reg, int idx, std::string path, bool inLoop, bool is_play, float volume)
{
    const entity to(idx);
    Components::Sound ok;
    ok.path = path, ok.inLoop = inLoop, ok.is_play = is_play, ok.volume = volume;
    reg.add_component<Components::Sound>(to, ok);
}

void ISystem::create_power(registry &reg, int idx, std::string action, std::string path, float posX, float posY, float scaleX, float scaleY)
{
    const entity to(idx);
    Components::Power_up ok;
    ok.action = action, ok.rect.path = path, ok.rect.posX = posX, ok.rect.posY = posY, ok.rect.scaleX = scaleX, ok.rect.scaleY = scaleY;
    reg.add_component<Components::Power_up>(to, ok);
}

void ISystem::set_sound(registry &reg, int idx, bool is_play)
{
    auto &sound = reg.get_components<Components::Sound>();

    sound[idx].value().is_play = is_play;
}

void ISystem::move_bg(registry &reg)
{
    auto &dra = reg.get_components<Components::drawable>();
    auto &dr = dra[0];
    auto &dr2 = dra[1];

    if (dr.value().posX > -1200)
        dr.value().posX -= 3;
    else if (dr.value().posX <= -1200)
        dr.value().posX = 0;

    if (dr2.value().posX > -1200)
        dr2.value().posX -= 3;
    else if (dr2.value().posX <= -1200)
        dr2.value().posX = 0;

    // if (dra[2].value().posX > 0) dra[2].value().posX -= 3;
    // else dra[2].value().posX = 1300;
}

void ISystem::set_speed(registry &reg, int id)
{
    auto &player = reg.get_components<Components::Player>();

    player[id].value().speed = 100;
}

void ISystem::move_car(registry &reg, int idx, Components::Inputs input)
{
    auto &dra = reg.get_components<Components::drawable_rect>();
    // auto &dr = dra[idx];

    for (int i = 0; i < dra.size(); ++i) {
        dra[i].value().posX -= 10;
    }
    // if (input == Components::LEFT_ARROW)
    //     dr.value().posX -= 35;
    // else if (input == Components::RIGHT_ARROW)
    //     dr.value().posX += 35;
    // else if (input == Components::UP_ARROW)
    //     dr.value().posY -= 35;
    // else if (input == Components::DOWN_ARROW)
    //     dr.value().posY += 35;
    // else if (input == Components::SPACE_BAR)
    // {
    //     dra[0].value().posX = dra[1].value().posX;
    //     dra[0].value().posY = dra[1].value().posY;
    //     this->check = true;
    // }
    // if (dra[2].value().posX > 0)
    //     dra[2].value().posX -= 3;
    // else
    //     dra[2].value().posX = 1300;
}

void ISystem::move_planete(registry &reg)
{
    auto &dra = reg.get_components<Components::drawable_rect>();

    for (int i = 0; i <= 2; i++) {
        if (dra[i].value().posX > -1000)
            dra[i].value().posX -= 5;
        else
            dra[i].value().posX = 1500;
    }

    if (dra[13].value().posY < 850) {
        dra[13].value().posX -= 5;
        dra[13].value().posY += 5;
    }
    else {
        dra[13].value().posX = 800;
        dra[13].value().posY = -1000;
    }

    if (dra[14].value().posY > -100) {
        dra[14].value().posX += 5;
        dra[14].value().posY -= 5;
    }
    else {
        dra[14].value().posX = 250;
        dra[14].value().posY = 1900;
    }

    if (dra[15].value().posX > -200) {
        dra[15].value().posX -= 5;
        //dra[15].value().posY -= 5;
    }
    else {
        dra[15].value().posX = 2200;
        //dra[15].value().posY = -200;
    }
}

bool ISystem::check_shield(registry &reg)
{
    auto &player = reg.get_components<Components::Player>();
    auto &ennemy = reg.get_components<Components::Ennemy>();
    auto &dra = reg.get_components<Components::drawable>();
    auto &fire = reg.get_components<Components::fire>();

    for (int i = 0; i < player.size(); i++) {
        if (player[i].value().is_shield == false && player[i].value().score % 25 == 0 && player[i].value().score != 0) {
            player[i].value().is_shield = true;
            player[i].value().score += 5;
        }
        if (player[i].value().is_shield == true) {
            for (int z = 0; z < fire.size(); z++) {
                if (fire[z].value().id == i) {
                    fire[z].value().rect.path = "./Assets/fire_2.png";
                }
            }
            dra[i + 10].value().posX = player[i].value().rect.posX;
            dra[i + 10].value().posY = player[i].value().rect.posY - 10;
            player[i].value().shield_time -= 1;
            if (player[i].value().shield_time == 0) {
                player[i].value().is_shield = false;
                player[i].value().shield_time = 100;
                fire[i].value().rect.path = "./Assets/fire.png";
            }
        }
        for (int j = 0; j < fire.size(); j++) {
            if (fire[j].value().id == i && player[i].value().is_shield == true) {
                fire[j].value().rect.scaleX = 1.5, fire[j].value().rect.scaleY = 1.5;
            }
            else if (fire[j].value().id == i && player[i].value().is_shield == false) {
                fire[j].value().rect.scaleX = 0.75, fire[j].value().rect.scaleY = 0.75;
            }
        }
    }
    return (true);
}

void ISystem::change_rect(registry &reg)
{
    auto &dra_rect = reg.get_components<Components::drawable_rect>();
    auto &dra_player = reg.get_components<Components::Player>();
    auto &dra_ennemy = reg.get_components<Components::Ennemy>();
    // auto &dr = dra[idx];

    for (int i = 0; i < dra_rect.size(); ++i) {
        if (i < 16) dra_rect[i].value().posX -= 3;
    }
    // if (dra_rect[0].value().rect.x < 256) dra_rect[0].value().rect.x += 64;
    // else dra_rect[0].value().rect.x = 0;

    // if (dra_rect[1].value().rect.x == 528 - 176) dra_rect[1].value().rect.x = 0;
    // else dra_rect[1].value().rect.x += 176;
    // //printf("left = %d\n", dr_rect.value().rect.x);
    // if (dra_rect[2].value().rect.x < 352) dra_rect[2].value().rect.x += 176;
    // else dra_rect[2].value().rect.x = 0;

    if (dra_rect[0].value().rect.x < 12000) dra_rect[0].value().rect.x += 250;
    else dra_rect[0].value().rect.x = 0;

    if (dra_rect[1].value().rect.x < 12000) dra_rect[1].value().rect.x += 250;
    else dra_rect[1].value().rect.x = 0;

    if (dra_rect[2].value().rect.x < 12000) dra_rect[2].value().rect.x += 250;
    else dra_rect[2].value().rect.x = 0;

    if (dra_rect[13].value().rect.x < 12000) dra_rect[13].value().rect.x += 250;
    else dra_rect[13].value().rect.x = 0;

    if (dra_rect[14].value().rect.x < 12000) dra_rect[14].value().rect.x += 250;
    else dra_rect[14].value().rect.x = 0;

    if (dra_rect[15].value().rect.x < 12000) dra_rect[15].value().rect.x += 250;
    else dra_rect[15].value().rect.x = 0;

    // if (dra_rect[3].value().posX > -1000) dra_rect[3].value().posX -= 35;
    // else dra_rect[3].value().posX = 1500;

    // if (dra_rect[4].value().posX > -1000) dra_rect[4].value().posX -= 35;
    // else dra_rect[4].value().posX = 1500;

    // if (dra_rect[5].value().posX > -1000) dra_rect[5].value().posX -= 35;
    // else dra_rect[5].value().posX = 1500;

    if (dra_player[0].value().rect.rect.x == 352) dra_player[0].value().rect.rect.x = 0;
    else dra_player[0].value().rect.rect.x += 176;
    if (dra_player[1].value().rect.rect.x == 352) dra_player[1].value().rect.rect.x = 0;
    else dra_player[1].value().rect.rect.x += 176;
    if (dra_player[2].value().rect.rect.x == 658) dra_player[2].value().rect.rect.x = 0;
    else dra_player[2].value().rect.rect.x += 329;
    if (dra_player[3].value().rect.rect.x == 1536) dra_player[3].value().rect.rect.x = 0;
    else dra_player[3].value().rect.rect.x += 192;

    if (dra_ennemy[0].value().rect.rect.x == 2800) dra_ennemy[0].value().rect.rect.x = 0;
    else dra_ennemy[0].value().rect.rect.x += 400;
    if (dra_ennemy[1].value().rect.rect.x == 6600) dra_ennemy[1].value().rect.rect.x = 0;
    else dra_ennemy[1].value().rect.rect.x += 550;
    if (dra_ennemy[2].value().rect.rect.x == 1959) dra_ennemy[2].value().rect.rect.x = 0;
    else dra_ennemy[2].value().rect.rect.x += 653;
    if (dra_ennemy[3].value().rect.rect.x == 2240) dra_ennemy[3].value().rect.rect.x = 0;
    else dra_ennemy[3].value().rect.rect.x += 560;
    if (dra_ennemy[4].value().rect.rect.x == 1050) dra_ennemy[4].value().rect.rect.x = 0;
    else dra_ennemy[4].value().rect.rect.x += 150;
    if (dra_ennemy[5].value().rect.rect.x == 945) dra_ennemy[5].value().rect.rect.x = 0;
    else dra_ennemy[5].value().rect.rect.x += 135;
}

void ISystem::move_power(registry &reg)
{
    auto &power = reg.get_components<Components::Power_up>();

    if (power[0].value().rect.posX > 0) power[0].value().rect.posX -= 5;
    else power[0].value().rect.posX = 1300;
    if (power[1].value().rect.posY < 800) power[1].value().rect.posY += 5;
    else power[1].value().rect.posY = -200;
    if (power[2].value().rect.posX > 0) power[2].value().rect.posX -= 5;
    else power[2].value().rect.posX = 1300;
    if (power[3].value().rect.posX > 0) power[3].value().rect.posX -= 5;
    else power[3].value().rect.posX = 1300;
    if (power[4].value().rect.posY > 0) power[4].value().rect.posY -= 5;
    else power[4].value().rect.posY = 1000;
    if (power[5].value().rect.posY < 800) power[5].value().rect.posY += 5;
    else power[5].value().rect.posY = -200;
}

void ISystem::change_fire_rect(registry &reg)
{
    auto &fire = reg.get_components<Components::fire>();

    for (int i = 0; i < fire.size(); i++) {
        if (i <= 19) {
            if (fire[i].value().is_laser == false) {
                if (fire[i].value().rect.rect.x < 256) fire[i].value().rect.rect.x += 64;
                else fire[i].value().rect.rect.x = 0;
            }
            else {
                if (fire[i].value().rect.rect.x < 3690) fire[i].value().rect.rect.x += 738;
                else fire[i].value().rect.rect.x = 0;
            }
        }
        else {
            if (fire[i].value().rect.rect.x < 65.5) fire[i].value().rect.rect.x += 65.5;
            else fire[i].value().rect.rect.x = 0;
        }
    }
}

// void ISystem::set_shoot(registry &reg)
// {
//     // auto &dra_rect = reg.get_components<Components::drawable_rect>();

//     // dra_rect[0].value().posX = dra_rec t[1].value().posX;
//     // dra_rect[0].value().posY = dra_rect[1].value().posY;
// }

void ISystem::shoot(registry &reg)
{
    // auto &dra_rect = reg.get_components<Components::drawable_rect>();

    // if (dra_rect[0].value().posX < 1350)
    //     dra_rect[0].value().posX += 10;
    // else
    // {
    //     dra_rect[0].value().posX = 0;
    //     this->check = false;
    // }
}

void ISystem::set_shoot(registry &reg)
{
    auto &fire = reg.get_components<Components::fire>();

    std::string to_send;
    for (int i = 0; i < fire.size(); i++) {
        if (fire[i].value().is_fire == true) {
            if (fire[i].value().rect.posX < 1350 && fire[i].value().rect.posX >= 0) {
                fire[i].value().rect.posX += 1;
                //to_send = std::to_string(fire[i].value().id) + " SHOOT_NEW_POS " + std::to_string(fire[i].value().rect.posX) + " " + std::to_string(fire[i].value().rect.posY);
            }
            if (fire[i].value().rect.posX >= 1350) fire[i].value().is_fire = false;
        }
    }
    //return (to_send);
}

std::string ISystem::set_shoot_pos(registry &reg, std::string message)
{
    auto &fire = reg.get_components<Components::fire>();
    auto &player = reg.get_components<Components::Player>();
    int id = this->get_id(message);
    std::string to_send;
    for (int i = 0; i < fire.size(); i++) {
        //if (fire[i].value().id == id && fire[i].value().is_fire == true && fire[i].value().rect.posX >= 1100) fire[i].value().is_fire = false;
        if (fire[i].value().id == id && fire[i].value().is_fire == false) {
            fire[i].value().is_fire = true;
            fire[i].value().rect.posX = player[id].value().rect.posX;
            fire[i].value().rect.posY = player[id].value().rect.posY + 15;
            to_send = std::to_string(fire[i].value().id) + " SHOOT_NEW_POS " + std::to_string(fire[i].value().rect.posX) + " " + std::to_string(fire[i].value().rect.posY);
            break;
        }
    }
    return(to_send);
}

std::vector<std::string> ISystem::check_shoot(registry &reg)
{
    auto &fire = reg.get_components<Components::fire>();
    std::vector<std::string> vect;
    for (int i = 0; i < fire.size(); i++) {
        if (fire[i].value().rect.posX >= 1250 && fire[i].value().id != 4) {
            std::string to_send = std::to_string(fire[i].value().idx);
            vect.push_back(to_send);
            fire[i].value().rect.posX = -100;
        }
    }
    return(vect);
}

int ISystem::get_pos(std::string message)
{
    int res = 0;
    int check = message.find(" ");
    std::stringstream stream(message.substr(check));
    stream >> res;
    return (res);
}

void ISystem::set_server_shoot(registry &reg, std::string message)
{
    auto &fire = reg.get_components<Components::fire>();
    int id = this->get_pos(message);
    fire[id].value().is_fire = false;
}

// ENNEMY

std::vector<std::string> ISystem::move_ennemy(registry &reg)
{
    std::vector<std::string> to_send;
    auto &ennemy = reg.get_components<Components::Ennemy>();

    for (int i = 0; i < ennemy.size(); i++) {
        if (ennemy[i].value().alive == true && ennemy[i].value().status == "simple" && i != 0) {
            if (ennemy[i].value().rect.posX > -15) ennemy[i].value().rect.posX -= ennemy[i].value().speed;
            if (ennemy[i].value().rect.posX <= -15) {
                ennemy[i].value().rect.posX = 1500;
                ennemy[i].value().rect.posY = rand() % 750;
            }
            std::string msg = std::to_string(i) + " NEW_ENNEMY_POS " + std::to_string(ennemy[i].value().rect.posX) + " " + std::to_string(ennemy[i].value().rect.posY);
            to_send.push_back(msg);
        }
        if (i == 0) {
            if (ennemy[i].value().rect.posX > -15 && ennemy[i].value().up == 0) ennemy[i].value().rect.posX -= ennemy[i].value().speed;
            if (ennemy[i].value().rect.posY < 800 && ennemy[i].value().up == 1) ennemy[i].value().rect.posY += ennemy[i].value().speed;
            if ((int)(ennemy[i].value().rect.posX) % 350 == 0) {
                ennemy[i].value().rect.posX -= ennemy[i].value().speed;
                ennemy[i].value().up = 1;
            }
            if ((int)(ennemy[i].value().rect.posY) % 100 == 0) {
                ennemy[i].value().rect.posY += ennemy[i].value().speed;
                ennemy[i].value().up = 0;
            }
            if (ennemy[i].value().rect.posX <= 0 || ennemy[i].value().rect.posY >= 780) {
                ennemy[i].value().rect.posX = 1500;
                ennemy[i].value().rect.posY = rand() % 200;
            }
        }
        if (ennemy[i].value().alive == true && i == 4) {
            if (ennemy[i].value().rect.posX > 400 && ennemy[i].value().forward == 0) ennemy[i].value().rect.posX -= ennemy[i].value().speed;
            if (ennemy[i].value().rect.posX < 1200 && ennemy[i].value().forward == 1) ennemy[i].value().rect.posX += ennemy[i].value().speed;
            //if (ennemy[i].value().rect.posX > -15) ennemy[i].value().rect.posX -= ennemy[i].value().speed;
            if (ennemy[i].value().rect.posY > -15 && ennemy[i].value().up == 0) ennemy[i].value().rect.posY -= ennemy[i].value().speed;
            if (ennemy[i].value().rect.posY <= 700 && ennemy[i].value().up == 1) ennemy[i].value().rect.posY += ennemy[i].value().speed;

            if (ennemy[i].value().rect.posY <= 30) ennemy[i].value().up = 1;
            if (ennemy[i].value().rect.posX <= 425) ennemy[i].value().forward = 1;
            
            if (ennemy[i].value().rect.posY >= 700) ennemy[i].value().up = 0;
            if (ennemy[i].value().rect.posX >= 1100) ennemy[i].value().forward = 0;

            if (ennemy[i].value().rect.posX <= -15) {
                ennemy[i].value().rect.posX = 1500;
                ennemy[i].value().rect.posY = rand() % 800;
            }
            std::string msg = std::to_string(i) + " NEW_ENNEMY_POS " + std::to_string(ennemy[i].value().rect.posX) + " " + std::to_string(ennemy[i].value().rect.posY);
            to_send.push_back(msg);
        }
        if (ennemy[i].value().alive == true && i == 5) {
            if (ennemy[i].value().rect.posX > 400 && ennemy[i].value().forward == 0) ennemy[i].value().rect.posX -= ennemy[i].value().speed;
            if (ennemy[i].value().rect.posX < 1200 && ennemy[i].value().forward == 1) ennemy[i].value().rect.posX += ennemy[i].value().speed;
            //if (ennemy[i].value().rect.posX > -15) ennemy[i].value().rect.posX -= ennemy[i].value().speed;
            if (ennemy[i].value().rect.posY > -15 && ennemy[i].value().up == 0) ennemy[i].value().rect.posY -= ennemy[i].value().speed;
            if (ennemy[i].value().rect.posY <= 700 && ennemy[i].value().up == 1) ennemy[i].value().rect.posY += ennemy[i].value().speed;

            if (ennemy[i].value().rect.posY <= 30) ennemy[i].value().up = 1;
            if (ennemy[i].value().rect.posX <= 425) ennemy[i].value().forward = 1;
            
            if (ennemy[i].value().rect.posY >= 700) ennemy[i].value().up = 0;
            if (ennemy[i].value().rect.posX >= 1100) ennemy[i].value().forward = 0;

            if (ennemy[i].value().rect.posX <= -15) {
                ennemy[i].value().rect.posX = 1500;
                ennemy[i].value().rect.posY = rand() % 800;
            }
        }
    }
    return (to_send);
}

void ISystem::move_IA(registry &reg)
{
    auto &player = reg.get_components<Components::Player>();

    //player[1].value().alive = true;
    if (player[1].value().rect.posY < 500 && player[1].value().up == 0) player[1].value().rect.posY += 5;
    if (player[1].value().rect.posY < 500 && player[1].value().up == 1) player[1].value().rect.posY -= 5;
    if (player[1].value().rect.posY < 20) player[1].value().up = 0;
    if (player[1].value().rect.posY > 480) player[1].value().up = 1;
    //else player[1].value().rect.posY -= 5;
}

void ISystem::check_boss(registry &reg, int score, int i)
{
    auto &ennemy = reg.get_components<Components::Ennemy>();
    auto &player = reg.get_components<Components::Player>();

    for (int i = 0; i < player.size(); i++) {
        if (player[i].value().score >= score) {
            if (i == 1 || i == 0) ennemy[4].value().alive = true;
            if (i == 2) ennemy[5].value().alive = true;
        }
    }
}

void ISystem::check_boss2(registry &reg, int score, int i)
{
    auto &ennemy = reg.get_components<Components::Ennemy>();
    auto &player = reg.get_components<Components::Player>();

    for (int i = 0; i < player.size(); i++) {
        if (player[i].value().score >= score) {
            if (i == 1) ennemy[4].value().alive = true;
            if (i == 2 || i == 0) ennemy[5].value().alive = true;
        }
    }
}

void ISystem::game_over(registry &reg, int score)
{
    auto &ennemy = reg.get_components<Components::Ennemy>();
    auto &player = reg.get_components<Components::Player>();

    for (int i = 0; i < player.size(); i++) {
        //if (player[i].value().life == 0) player[i].value().alive = false;
        if (player[i].value().score >= score && ennemy[4].value().alive == false &&
            ennemy[5].value().alive == false) {
                this->where = 14;
        }
    }
}

bool ISystem::is_over(registry &reg)
{
    auto &player = reg.get_components<Components::Player>();

    for (int i = 0; i < player.size(); i++) {
        if (player[i].value().life == 0) player[1].value().alive = false;
        if (player[i].value().life > 0 && player[i].value().alive == true) return (false);
    }
    return (true);
}

bool ISystem::change_stage(registry &reg, int score)
{
    auto &ennemy = reg.get_components<Components::Ennemy>();
    auto &player = reg.get_components<Components::Player>();
    auto &dra_rect = reg.get_components<Components::drawable_rect>();
    auto &fire = reg.get_components<Components::fire>();

    for (int i = 0; i < player.size(); i++) {
        if (player[i].value().score >= score && ennemy[4].value().alive == false) {
            // for (int j = 0; j <= 19; j++) {
            //     if (i <= 4) {
            //         fire[i].value().rect.path = "./Assets/lazer.png";
            //         fire[i].value().rect.rect = {0, 0, 738, 311};
            //         //this->create_fire(reg, i, 0, "./Assets/lazer.png", -100, -100, 0.75, 0.75, {0, 0, 738, 311});
            //         fire[i].value().is_laser = true;
            //     }
            //     if (i <= 9) {
            //         fire[i].value().rect.path = "./Assets/lazer.png";
            //         fire[i].value().rect.rect = {0, 0, 738, 311};
            //         fire[i].value().is_laser = true;
            //     }
            //     if (i <= 14) {
            //         fire[i].value().rect.path = "./Assets/lazer.png";
            //         fire[i].value().rect.rect = {0, 0, 738, 311};
            //         fire[i].value().is_laser = true;
            //     }
            //     if (i <= 19) {
            //         fire[i].value().rect.path = "./Assets/lazer.png";
            //         fire[i].value().rect.rect = {0, 0, 738, 311};
            //         fire[i].value().is_laser = true;
            //     }
            // }
            ennemy[0].value().alive = false;
            ennemy[1].value().alive = false;
            ennemy[2].value().alive = true;
            ennemy[3].value().alive = true;
            ennemy[0].value().rect.posX = 2000;
            ennemy[1].value().rect.posX = 2000;
            ennemy[2].value().rect.posX = 2000;
            ennemy[3].value().rect.posX = 2000;
            ennemy[4].value().rect.posX = 2000;
            ennemy[5].value().rect.posX = 2000;

            fire[20].value().rect.posX = 2000;
            fire[21].value().rect.posX = 2000;
            fire[22].value().rect.posX = 2000;
            fire[23].value().rect.posX = 2000;
            fire[24].value().rect.posX = 2000;
            fire[25].value().rect.posX = 2000;

            fire[26].value().rect.posX = 2000;
            fire[27].value().rect.posX = 2000;
            fire[28].value().rect.posX = 2000;
            fire[29].value().rect.posX = 2000;
            dra_rect[0].value().path = "./Assets/island_3.png";
            dra_rect[1].value().path = "./Assets/galaxy_3.png";
            dra_rect[2].value().path = "./Assets/lava_3.png";
            return (true);
        }
    }
    return (false);
}

void ISystem::set_ennemy_client(registry &reg, std::string message)
{
    auto &ennemy = reg.get_components<Components::Ennemy>();

    Components::player_new_pos new_pos = extract_new_pos(message);

    ennemy[new_pos.id].value().rect.posX = new_pos.posX;
    ennemy[new_pos.id].value().rect.posY = new_pos.posY;
}

void ISystem::set_ennemy_shoot(registry &reg)
{
    auto &ennemy = reg.get_components<Components::Ennemy>();
    auto &fire = reg.get_components<Components::fire>();

    if (ennemy[0].value().alive == true) {
        if (fire[20].value().rect.posX <= 0 && ennemy[0].value().rect.posX > 550) {
            fire[20].value().rect.posX = ennemy[0].value().rect.posX;
            fire[20].value().rect.posY = ennemy[0].value().rect.posY + 40;
        }
        else {
            fire[20].value().rect.posX -= 25;
            //fire[20].value().rect.posY -= 10;
        }
    }

    if (ennemy[1].value().alive == true) {
        if (fire[21].value().rect.posX <= 0 && ennemy[1].value().rect.posX > 550) {
            fire[21].value().rect.posX = ennemy[1].value().rect.posX;
            fire[21].value().rect.posY = ennemy[1].value().rect.posY + 45;
        }
        else {
            fire[21].value().rect.posX -= 15;
            //fire[21].value().rect.posY -= 10;
        }
    }

    if (ennemy[2].value().alive == true) {
        if (fire[22].value().rect.posX <= 0 && ennemy[2].value().rect.posX > 550) {
            fire[22].value().rect.posX = ennemy[2].value().rect.posX;
            fire[22].value().rect.posY = ennemy[2].value().rect.posY + 45;
        }
        else {
            fire[22].value().rect.posX -= 15;
            //fire[21].value().rect.posY -= 10;
        }
        if (fire[23].value().rect.posX <= 0 && ennemy[2].value().rect.posX > 550) {
            fire[23].value().rect.posX = ennemy[2].value().rect.posX;
            fire[23].value().rect.posY = ennemy[2].value().rect.posY + 65;
        }
        else {
            fire[23].value().rect.posX -= 15;
            //fire[21].value().rect.posY -= 10;
        }
    }
    if (ennemy[3].value().alive == true) {
        if (fire[24].value().rect.posX <= 0 && ennemy[3].value().rect.posX > 550) {
            fire[24].value().rect.posX = ennemy[3].value().rect.posX;
            fire[24].value().rect.posY = ennemy[3].value().rect.posY + 45;
        }
        else {
            fire[24].value().rect.posX -= 15;
            //fire[21].value().rect.posY -= 10;
        }
        if (fire[25].value().rect.posX <= 0 && ennemy[3].value().rect.posX > 550) {
            fire[25].value().rect.posX = ennemy[3].value().rect.posX;
            fire[25].value().rect.posY = ennemy[3].value().rect.posY + 65;
        }
        else {
            fire[25].value().rect.posX -= 15;
            //fire[21].value().rect.posY -= 10;
        }
    }

    if (ennemy[4].value().alive == true) {
        if (fire[26].value().rect.posX <= 0 && ennemy[4].value().rect.posX > 950 && ennemy[4].value().rect.posY < 150) {
                fire[26].value().rect.posX = ennemy[4].value().rect.posX;
                fire[26].value().rect.posY = ennemy[4].value().rect.posY + 45;
        }
        else {
            fire[26].value().rect.posX -= 15;
        }
        if (fire[27].value().rect.posX <= 0 && ennemy[4].value().rect.posX > 700 && ennemy[4].value().rect.posY < 300) {
                fire[27].value().rect.posX = ennemy[4].value().rect.posX;
                fire[27].value().rect.posY = ennemy[4].value().rect.posY + 45;
        }
        else {
            fire[27].value().rect.posX -= 15;
        }
        if (fire[28].value().rect.posX <= 0 && ennemy[4].value().rect.posX > 550 && ennemy[4].value().rect.posY < 450) {
                fire[28].value().rect.posX = ennemy[4].value().rect.posX;
                fire[28].value().rect.posY = ennemy[4].value().rect.posY + 45;
        }
        else {
            fire[28].value().rect.posX -= 15;
        }
        if (fire[29].value().rect.posX <= 0 && ennemy[4].value().rect.posX > 400 && ennemy[4].value().rect.posY > 600) {
                fire[29].value().rect.posX = ennemy[4].value().rect.posX;
                fire[29].value().rect.posY = ennemy[4].value().rect.posY + 45;
        }
        else {
            fire[29].value().rect.posX -= 15;
        }
    }

    if (ennemy[5].value().alive == true) {
        if (fire[26].value().rect.posX <= 0 && ennemy[5].value().rect.posX > 950 && ennemy[5].value().rect.posY < 150) {
                fire[26].value().rect.posX = ennemy[5].value().rect.posX;
                fire[26].value().rect.posY = ennemy[5].value().rect.posY + 45;
        }
        else {
            fire[26].value().rect.posX -= 15;
        }
        if (fire[27].value().rect.posX <= 0 && ennemy[5].value().rect.posX > 700 && ennemy[5].value().rect.posY < 300) {
                fire[27].value().rect.posX = ennemy[5].value().rect.posX;
                fire[27].value().rect.posY = ennemy[5].value().rect.posY + 45;
        }
        else {
            fire[27].value().rect.posX -= 15;
        }
        if (fire[28].value().rect.posX <= 0 && ennemy[5].value().rect.posX > 550 && ennemy[5].value().rect.posY < 450) {
                fire[28].value().rect.posX = ennemy[5].value().rect.posX;
                fire[28].value().rect.posY = ennemy[5].value().rect.posY + 45;
        }
        else {
            fire[28].value().rect.posX -= 15;
        }
        if (fire[29].value().rect.posX <= 0 && ennemy[5].value().rect.posX > 400 && ennemy[5].value().rect.posY > 600) {
                fire[29].value().rect.posX = ennemy[5].value().rect.posX;
                fire[29].value().rect.posY = ennemy[5].value().rect.posY + 45;
        }
        else {
            fire[29].value().rect.posX -= 15;
        }
    }
}

// END ENNEMY

// std::string ISystem::is_collision(registry &reg)
// {
//     auto &ennemy = reg.get_components<Components::Ennemy>();
//     auto &fire = reg.get_components<Components::fire>();

//     for (int i = 0; i < fire.size(); i++) {
//         for (int j = 0; j < ennemy.size(); j++) {
//             if (this->sec->check_collision(fire[i].value().rect.rect, ennemy[j].value().rect.rect)) {
//                 fire[i].value().rect.posX = -200;
//                 ennemy[j].value().rect.posX = 1500;
//             }
//         }
//     }
// }

std::string ISystem::update_server_pos(registry &reg, std::string message)
{
    // if (std::regex_match(message.c_str(), std::regex("[0-9]+ (DOWN|UP|LEFT|RIGHT)")))
    //     printf("ok");
    int id = this->get_id(message);
    auto &dra = reg.get_components<Components::Player>();
    auto &dr = dra[id];
    std::string move = message.substr((message.find(" ")) + 1);

    if (move.compare("LEFT") == 0 && dr.value().rect.posX >= 0)
        dr.value().rect.posX -= dr.value().speed;
    else if (move.compare("RIGHT") == 0 && dr.value().rect.posX <= 1270)
        dr.value().rect.posX += dr.value().speed;
    else if (move.compare("UP") == 0 && dr.value().rect.posY >= 0)
        dr.value().rect.posY -= dr.value().speed;
    else if (move.compare("DOWN") == 0 && dr.value().rect.posY <= 720)
        dr.value().rect.posY += dr.value().speed;

    std::string res = std::to_string(id) + " NEW_POSITION " + std::to_string(dr.value().rect.posX) + " " + std::to_string(dr.value().rect.posY);
    return (res);
}



void ISystem::update_client_pos(registry &reg, std::string message)
{
    int id = this->get_id(message);
    auto &dra = reg.get_components<Components::Player>();
    auto &dr = dra[id];

    Components::player_new_pos new_pos = extract_new_pos(message);

    dr.value().rect.posX = new_pos.posX;
    dr.value().rect.posY = new_pos.posY;
}

int ISystem::get_id(std::string message)
{
    int res = 0;
    int check = message.find(" ");
    std::stringstream stream(message.substr(0, check));
    stream >> res;
    return (res);
}

Components::player_new_pos ISystem::extract_new_pos(std::string message)
{
    Components::player_new_pos new_pos;
    int first = message.find(" ");
    std::stringstream stream(message.substr(0, first));
    stream >> new_pos.id;
    std::string temp = message.substr((message.find(" ")) + 1);
    temp = temp.substr((temp.find(" ")) + 1);
    first = temp.find(" ");
    std::stringstream stream2(temp.substr(0, first));
    stream2 >> new_pos.posX;
    temp = temp.substr((temp.find(" ")) + 1);
    std::stringstream stream3(temp);
    stream3 >> new_pos.posY;
    return (new_pos);
}

void ISystem::set_cine_vector(registry &reg)
{
    for (int i = 1; i <= 84; i++) {
        std::string str = "./Assets/cinematique/ezgif-frame" + std::to_string(i) + ".jpg";
        this->cine.push_back(str);
    }
}

void ISystem::set_cine(registry &reg, int idx)
{
    auto &dra = reg.get_components<Components::drawable>();

    dra[3].value().path = this->cine[idx];
}

void ISystem::set_cine_vector2(registry &reg)
{
    for (int i = 1; i <= 32; i++) {
        std::string str = "./Assets/final/ezgif-frame" + std::to_string(i) + ".jpg";
        this->cine2.push_back(str);
    }
}

void ISystem::set_cine2(registry &reg, int idx)
{
    auto &dra = reg.get_components<Components::drawable>();

    dra[4].value().path = this->cine2[idx];
}

void ISystem::set_cine_vector3(registry &reg)
{
    for (int i = 1; i <= 20; i++) {
        std::string str = "./Assets/cinematique_2/ezgif-frame" + std::to_string(i) + ".jpg";
        this->cine3.push_back(str);
    }
}

void ISystem::set_cine3(registry &reg, int idx)
{
    auto &dra = reg.get_components<Components::drawable>();

    dra[7].value().path = this->cine3[idx];
}

void ISystem::set_cine_vector4(registry &reg)
{
    for (int i = 1; i <= 10; i++) {
        std::string str = "./Assets/cinematique_3/ezgif-frame" + std::to_string(i) + ".jpg";
        this->cine4.push_back(str);
    }
}

void ISystem::set_cine4(registry &reg, int idx)
{
    auto &dra = reg.get_components<Components::drawable>();

    dra[8].value().path = this->cine4[idx];
}

void ISystem::change_menu_rect(registry &reg)
{
    auto &dra_rect = reg.get_components<Components::drawable_rect>();

    if (dra_rect[3].value().rect.x < 12000) dra_rect[3].value().rect.x += 250;
    else dra_rect[3].value().rect.x = 0;

    if (dra_rect[4].value().rect.x < 12500) dra_rect[4].value().rect.x += 250;
    else dra_rect[4].value().rect.x = 0;
}

void ISystem::play_rect(registry &reg)
{
    auto &dra_rect = reg.get_components<Components::drawable_rect>();

    if (dra_rect[23].value().rect.x < 10560) dra_rect[23].value().rect.x += 480;
    else dra_rect[23].value().rect.x = 0;

    if (dra_rect[24].value().rect.x < 352) dra_rect[24].value().rect.x += 176;
    else dra_rect[24].value().rect.x = 0;

    if (dra_rect[25].value().rect.x < 352) dra_rect[25].value().rect.x += 176;
    else dra_rect[25].value().rect.x = 0;

    if (dra_rect[26].value().rect.x < 658) dra_rect[26].value().rect.x += 329;
    else dra_rect[26].value().rect.x = 0;

    if (dra_rect[27].value().rect.x < 1440) dra_rect[27].value().rect.x += 192;
    else dra_rect[27].value().rect.x = 0;
}

void ISystem::update_mouse(registry &reg, Components::Position pos)
{
    auto &mouse = reg.get_components<Components::Position>();

    mouse[0].value().x = pos.x, mouse[0].value().y = pos.y;
}

void ISystem::event_mouse(registry &reg, Components::Inputs input)
{
    auto &wind = reg.get_components<Components::Window>();
    auto &position = reg.get_components<Components::Position>();
    auto &text = reg.get_components<Components::Text>();
    auto &sound = reg.get_components<Components::Sound>();
    auto &dra = reg.get_components<Components::drawable>();
    auto &dra_rect = reg.get_components<Components::drawable_rect>();

    if (this->where == 0) {
        if (position[0].value().x < 1200 && position[0].value().y < 271 && position[0].value().x > 1005 && position[0].value().y > 213) {
            if (input == Components::Inputs::BUTTON)
                where = 1;
            //text[1].value().color = "Green";
            text[1].value().gras = 2;
        }
        else
        {
            //text[1].value().color = "Cyan";
            text[1].value().gras = 0;
            text[1].value().style = "Regular";
        }

        if (position[0].value().x < 1200 && position[0].value().y < 368 && position[0].value().x > 1005 && position[0].value().y > 307) {
            if (input == Components::Inputs::BUTTON)
                where = 2;
            //text[3].value().color = "Green";
            text[3].value().gras = 2;
        }
        else
        {
            //text[3].value().color = "Cyan";
            text[3].value().gras = 0;
            text[3].value().style = "Regular";
        }

        if (position[0].value().x < 1200 && position[0].value().y < 463 && position[0].value().x > 1005 && position[0].value().y > 407) {
            if (input == Components::Inputs::BUTTON)
                where = 3;
            //text[2].value().color = "Green";
            text[2].value().gras = 2;
        }
        else
        {
            //text[2].value().color = "Cyan";
            text[2].value().gras = 0;
            text[2].value().style = "Regular";
        }

        if (position[0].value().x < 1154 && position[0].value().y < 565 && position[0].value().x > 1005 && position[0].value().y > 507) {
            if (input == Components::Inputs::BUTTON)
                where = 4;
            //text[4].value().color = "Green";
            text[4].value().gras = 2;
        }
        else
        {
            //text[4].value().color = "Cyan";
            text[4].value().gras = 0;
            text[4].value().style = "Regular";
        }

        if (position[0].value().x < 1092 && position[0].value().y < 661 && position[0].value().x > 1005 && position[0].value().y > 610) {
            if (input == Components::Inputs::BUTTON)
                where = 5;
            //text[5].value().color = "Green";
            text[5].value().gras = 2;
        }
        else
        {
            //text[5].value().color = "Cyan";
            text[5].value().gras = 0;
            text[5].value().style = "Regular";
        }
    }

    if (this->where == 3) {
        if (position[0].value().x < 900 && position[0].value().y < 654 && position[0].value().x > 873 && position[0].value().y > 600) {
            // if (input == Components::Inputs::BUTTON)
            //     //where = 1;
            text[23].value().gras = 2;
        }
        else
        {
            //text[7].value().color = "Cyan";
            text[23].value().gras = 0;
            text[23].value().style = "Regular";
        }

        if (position[0].value().x < 600 && position[0].value().y < 654 && position[0].value().x > 564 && position[0].value().y > 600) {
            // if (input == Components::Inputs::BUTTON)
            //     //where = 1;
            text[24].value().gras = 2;
        }
        else
        {
            //text[7].value().color = "Cyan";
            text[24].value().gras = 0;
            text[24].value().style = "Regular";
        }

        if (position[0].value().x < 600 && position[0].value().y < 260 && position[0].value().x > 550 && position[0].value().y > 200) {
            if (input == Components::Inputs::BUTTON) {
                if (wind[0].value().framerate < 100) wind[0].value().framerate +=10;
                text[27].value().txt = std::to_string(wind[0].value().framerate);
            }
            //     //where = 1;
            text[25].value().gras = 2;
        }
        else
        {
            //text[7].value().color = "Cyan";
            text[25].value().gras = 0;
            text[25].value().style = "Regular";
        }
        if (position[0].value().x < 400 && position[0].value().y < 260 && position[0].value().x > 380 && position[0].value().y > 200) {
            if (input == Components::Inputs::BUTTON) {
                if (wind[0].value().framerate > 0) wind[0].value().framerate -=10;
                text[27].value().txt = std::to_string(wind[0].value().framerate);
            }
            //     //where = 1;
            text[26].value().gras = 2;
        }
        else
        {
            //text[7].value().color = "Cyan";
            text[26].value().gras = 0;
            text[26].value().style = "Regular";
        }
        
        if (position[0].value().x < 351 && position[0].value().y < 230 && position[0].value().x > 55 && position[0].value().y > 200) {
            // if (input == Components::Inputs::BUTTON)
            //     //where = 1;
            text[27].value().gras = 2;
        }
        else
        {
            //text[7].value().color = "Cyan";
            text[27].value().gras = 0;
            text[27].value().style = "Regular";
        }
        if (position[0].value().x < 500 && position[0].value().y < 500 && position[0].value().x > 450 && position[0].value().y > 400) {
            if (input == Components::Inputs::BUTTON) {
                if (sound[0].value().volume < 100) sound[0].value().volume += 1;
                text[30].value().txt = std::to_string((int)(sound[0].value().volume));
            }
            text[28].value().gras = 2;
        }
        else
        {
            //text[7].value().color = "Cyan";
            text[28].value().gras = 0;
            text[28].value().style = "Regular";
        }
        if (position[0].value().x < 300 && position[0].value().y < 500 && position[0].value().x > 250 && position[0].value().y > 400) {
            if (input == Components::Inputs::BUTTON) {
                if (sound[0].value().volume > 0) sound[0].value().volume -= 1;
                text[30].value().txt = std::to_string((int)(sound[0].value().volume));
            }
            text[29].value().gras = 2;
        }
        else
        {
            //text[7].value().color = "Cyan";
            text[29].value().gras = 0;
            text[29].value().style = "Regular";
        }

        if (position[0].value().x < 220 && position[0].value().y < 500 && position[0].value().x > 57 && position[0].value().y > 400) {
            // if (input == Components::Inputs::BUTTON)
            //     //where = 1;
            text[30].value().gras = 2;
        }
        else
        {
            //text[7].value().color = "Cyan";
            text[30].value().gras = 0;
            text[30].value().style = "Regular";
        }

        if (position[0].value().x < 360 && position[0].value().y < 250 && position[0].value().x > 57 && position[0].value().y > 215) {
            if (input == Components::Inputs::BUTTON)
                //where = 1;
            //text[7].value().color = "Green";
            text[7].value().gras = 2;
        }
        else
        {
            //text[7].value().color = "Cyan";
            text[7].value().gras = 0;
            text[7].value().style = "Regular";
        }

        if (position[0].value().x < 220 && position[0].value().y < 449 && position[0].value().x > 57 && position[0].value().y > 419) {
            if (input == Components::Inputs::BUTTON)
                //where = 1;
            //text[8].value().color = "Green";
            text[8].value().gras = 2;
        }
        else
        {
            //text[8].value().color = "Cyan";
            text[8].value().gras = 0;
            text[8].value().style = "Regular";
        }

        if (position[0].value().x < 534 && position[0].value().y < 650 && position[0].value().x > 57 && position[0].value().y > 620) {
            if (input == Components::Inputs::BUTTON)
                this->change_screen(reg);
            //text[9].value().color = "Green";
            text[9].value().gras = 2;
        }
        else
        {
            //text[9].value().color = "Cyan";
            text[9].value().gras = 0;
            text[9].value().style = "Regular";
        }

        if (position[0].value().x < 117 && position[0].value().y < 67 && position[0].value().x > 56 && position[0].value().y > 25) {
            if (input == Components::Inputs::BUTTON)
                where = 0;
            //text[10].value().color = "Green";
            text[10].value().gras = 2;
        }
        else
        {
            //text[10].value().color = "Cyan";
            text[10].value().gras = 0;
            text[10].value().style = "Regular";
        }

        if (position[0].value().x < 1200 && position[0].value().y < 271 && position[0].value().x > 1005 && position[0].value().y > 213) {
            if (input == Components::Inputs::BUTTON)
                where = 1;
           // text[1].value().color = "Green";
            text[1].value().gras = 2;
        }
        else
        {
           // text[1].value().color = "Cyan";
            text[1].value().gras = 0;
            text[1].value().style = "Regular";
        }
    }

    if (this->where == 2) {
        if (position[0].value().x < 117 && position[0].value().y < 67 && position[0].value().x > 56 && position[0].value().y > 25) {
            if (input == Components::Inputs::BUTTON)
                where = 0;
            //text[10].value().color = "Green";
            text[10].value().gras = 2;
        }
        else
        {
            //text[10].value().color = "Cyan";
            text[10].value().gras = 0;
            text[10].value().style = "Regular";
        }
    }

    if (this->where == 5) {
        if (position[0].value().x < 410 && position[0].value().y < 450 && position[0].value().x > 353 && position[0].value().y > 416) {
            if (input == Components::Inputs::BUTTON)
                where = 0;
            //text[12].value().color = "Green";
            text[12].value().gras = 2;
        }
        else
        {
            //text[12].value().color = "Cyan";
            text[12].value().gras = 0;
            text[12].value().style = "Regular";
        }

        if (position[0].value().x < 983 && position[0].value().y < 448 && position[0].value().x > 900 && position[0].value().y > 417) {
            if (input == Components::Inputs::BUTTON)
                where = -2;
            //text[13].value().color = "Green";
            text[13].value().gras = 2;
        }
        else
        {
            //text[13].value().color = "Cyan";
            text[13].value().gras = 0;
            text[13].value().style = "Regular";
        }
    }

    if (this->where == 1) {
        if (position[0].value().x < 543 && position[0].value().y < 397 && position[0].value().x > 478 && position[0].value().y > 324) {
            if (input == Components::Inputs::BUTTON) {
                this->where = 8;
            }
            dra[5].value().scaleX = 0.35, dra[5].value().scaleY = 0.35;
        }
        else
        {
            dra[5].value().scaleX = 0.25, dra[5].value().scaleY = 0.25;
        }
        if (position[0].value().x < 893 && position[0].value().y < 405 && position[0].value().x > 835 && position[0].value().y > 322) {
            if (input == Components::Inputs::BUTTON) {
                this->where = 8;
            }
            dra[6].value().scaleX = 0.35, dra[6].value().scaleY = 0.35;
        }
        else
        {
            dra[6].value().scaleX = 0.25, dra[6].value().scaleY = 0.25;
        }
        if (position[0].value().x < 117 && position[0].value().y < 67 && position[0].value().x > 56 && position[0].value().y > 25) {
            if (input == Components::Inputs::BUTTON)
                where = 0;
            //text[10].value().color = "Green";
            text[10].value().gras = 2;
        }
        else
        {
            //text[10].value().color = "Cyan";
            text[10].value().gras = 0;
            text[10].value().style = "Regular";
        }
    }
    if (this->where == 8) {
        if (position[0].value().x < 117 && position[0].value().y < 67 && position[0].value().x > 56 && position[0].value().y > 25) {
            if (input == Components::Inputs::BUTTON)
                where = 0;
            text[10].value().gras = 2;
        }
        else
        {
            //text[10].value().color = "Cyan";
            text[10].value().gras = 0;
            text[10].value().style = "Regular";
        }

        if (position[0].value().x < 270 && position[0].value().y < 550 && position[0].value().x > 200 && position[0].value().y > 480) {
            if (input == Components::Inputs::BUTTON) {
                this->where = 9;
            }
            dra_rect[24].value().scaleX = 0.75, dra_rect[24].value().scaleY = 0.75;
        }
        else
        {
            dra_rect[24].value().scaleX = 0.50, dra_rect[24].value().scaleY = 0.50;
        }
        if (position[0].value().x < 570 && position[0].value().y < 550 && position[0].value().x > 500 && position[0].value().y > 480) {
            if (input == Components::Inputs::BUTTON) {
                this->where = 9;
            }
            dra_rect[25].value().scaleX = 0.75, dra_rect[25].value().scaleY = 0.75;
        }
        else
        {
            dra_rect[25].value().scaleX = 0.50, dra_rect[25].value().scaleY = 0.50;
        }
        if (position[0].value().x < 870 && position[0].value().y < 550 && position[0].value().x > 800 && position[0].value().y > 480) {
            if (input == Components::Inputs::BUTTON) {
                this->where = 9;
            }
            dra_rect[26].value().scaleX = 0.75, dra_rect[26].value().scaleY = 0.75;
        }
        else
        {
            dra_rect[26].value().scaleX = 0.50, dra_rect[26].value().scaleY = 0.50;
        }
        if (position[0].value().x < 1170 && position[0].value().y < 550 && position[0].value().x > 1100 && position[0].value().y > 480) {
            if (input == Components::Inputs::BUTTON) {
                this->where = 9;
            }
            dra_rect[27].value().scaleX = 0.75, dra_rect[27].value().scaleY = 0.75;
        }
        else
        {
            dra_rect[27].value().scaleX = 0.50, dra_rect[27].value().scaleY = 0.50;
        }
    }
    if (this->where == 9) {
        if (position[0].value().x < 117 && position[0].value().y < 67 && position[0].value().x > 56 && position[0].value().y > 25) {
            if (input == Components::Inputs::BUTTON)
                where = 0;
            //text[10].value().color = "Green";
            text[10].value().gras = 2;
        }
        else {
            //text[10].value().color = "Cyan";
            text[10].value().gras = 0;
            text[10].value().style = "Regular";
        }
        if (position[0].value().x < 374 && position[0].value().y < 304 && position[0].value().x > 202 && position[0].value().y > 271) {
            if (input == Components::Inputs::BUTTON) {
                this->where = 10;
                this->is_infini = true;
            }
            text[17].value().gras = 2;
        }
        else
        {
            text[17].value().gras = 0;
        }

        if (position[0].value().x < 1133 && position[0].value().y < 303 && position[0].value().x > 1005 && position[0].value().y > 261) {
            if (input == Components::Inputs::BUTTON) {
                this->where = 10;
                this->is_infini = false;
            }
            text[18].value().gras = 2;
        }
        else
        {
            text[18].value().gras = 0;
        }
    }

    if (this->where == 10) {

    }
}

void ISystem::update_credit(registry &reg)
{
    auto &dra_rect = reg.get_components<Components::drawable_rect>();

    if (dra_rect[12].value().rect.x < 12250) dra_rect[12].value().rect.x += 250;
    else dra_rect[12].value().rect.x = 0;

    if (dra_rect[11].value().rect.x < 14700) dra_rect[11].value().rect.x += 300;
    else dra_rect[11].value().rect.x = 0;
}

void ISystem::move_credit(registry &reg, Components::Inputs input)
{
    auto &dra = reg.get_components<Components::drawable>();
    auto &position = reg.get_components<Components::Position>();
    auto &text = reg.get_components<Components::Text>();

    if (dra[2].value().posY > -2200) dra[2].value().posY -= 10;
    else dra[2].value().posY = 1200;

    if (position[0].value().x < 117 && position[0].value().y < 67 && position[0].value().x > 56 && position[0].value().y > 25) {
        if (input == Components::Inputs::BUTTON) {
            where = 0;
            dra[2].value().posY = 0;
        }
        text[10].value().color = "Green";
        text[10].value().gras = 2;
    }
    else
    {
        text[10].value().color = "Cyan";
        text[10].value().gras = 0;
        text[10].value().style = "Regular";
    }
}

void ISystem::update_setting(registry &reg)
{
    auto &dra_rect = reg.get_components<Components::drawable_rect>();

    if (dra_rect[6].value().rect.x < 12250) dra_rect[6].value().rect.x += 250;
    else dra_rect[6].value().rect.x = 0;

    if (dra_rect[5].value().rect.x < 12000) dra_rect[5].value().rect.x += 250;
    else dra_rect[5].value().rect.x = 0;
}

// void ISystem::update_how(registry &reg)
// {
//     auto &dra_rect = reg.get_components<Components::drawable_rect>();
// }

void ISystem::update_inventory(registry &reg)
{
    auto &dra_rect = reg.get_components<Components::drawable_rect>();

    if (dra_rect[10].value().rect.x < 12250) dra_rect[10].value().rect.x += 250;
    else dra_rect[10].value().rect.x = 0;

    if (dra_rect[9].value().rect.x < 12000) dra_rect[9].value().rect.x += 250;
    else dra_rect[9].value().rect.x = 0;
}

void ISystem::update_quit(registry &reg)
{
    auto &dra_rect = reg.get_components<Components::drawable_rect>();

    if (dra_rect[7].value().rect.x < 12250) dra_rect[7].value().rect.x += 250;
    else dra_rect[7].value().rect.x = 0;

    if (dra_rect[8].value().rect.x < 12000) dra_rect[8].value().rect.x += 250;
    else dra_rect[8].value().rect.x = 0;
}

void ISystem::change_screen(registry &reg)
{
    auto &window = reg.get_components<Components::Window>();
    if (window[0].value().resolution.compare("Default")) window[0].value().resolution = "Full";
    if (window[0].value().resolution.compare("Full")) window[0].value().resolution = "Default";
}