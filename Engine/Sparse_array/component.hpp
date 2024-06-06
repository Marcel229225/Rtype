/*
** EPITECH PROJECT, 2022
** R type
** File description:
** Component hpp
*/

#ifndef Component
#define Component

namespace Components {
    struct Position
    {
        float x;
        float y;
    };

    struct Velocity
    {
        float vx;
        float vy;
    };
    struct Window {
        size_t x;
        size_t y;
        std::string name;
        std::string resolution;
        int framerate;
    };
    enum Inputs{
        NO_TYPE = -1,
        ENTER_KEY,
        LEFT_ARROW,
        RIGHT_ARROW,
        UP_ARROW,
        DOWN_ARROW,
        QUIT,
        SPACE_BAR,
        NO_SPACE_BAR,
        BUTTON,
        C,
        R,
        N
    };
    struct Text {
        float posX;
        float posY;
        int charactere_size;
        int gras;
        std::string txt;
        std::string font;
        std::string color;
        std::string style;
    };

    struct Frame {
        float x;
        float y;
        float height;
        float width;
    };

    struct drawable {
        std::string path;
        float posX;
        float posY;
        float scaleX;
        float scaleY;
        Frame frame;
    };

    struct Rect {
        int x;
        int y;
        int x2;
        int y2;
    };


    struct drawable_rect {
        std::string path;
        float posX;
        float posY;
        float scaleX;
        float scaleY;
        Rect rect;
        Frame frame;
    };

    struct player_new_pos {
        int id;
        float posX;
        float posY;
    };

    struct Player {
        int id;
        int life;
        int score;
        int power;
        int speed;
        bool alive;
        bool is_shield;
        int shield_time;
        int _sc;
        int up = 0;
        drawable_rect rect;
    };

    struct Ennemy {
        int id;
        int life;
        int speed;
        int power;
        bool alive;
        int up;
        int forward;
        std::string status;
        drawable_rect rect;
    };

    struct Power_up {
        std::string action;
        drawable rect;
    };
    
    struct fire {
        int id;
        int idx;
        int degat;
        bool is_fire;
        bool is_laser;
        drawable_rect rect;
    };

    struct Sound {
        std::string path;
        bool inLoop;
        float volume;
        bool is_play;        
    };

    struct level {
    int first_score;
    int enm1;
    int enm2;
    int boss1;
    int second_score;
    int enm3;
    int enm4;
    int boss2;
};
}

#endif /* !Component */