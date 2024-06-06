/*
** EPITECH PROJECT, 2022
** R TYPE
** File description:
** ILib
*/

#ifndef ILib_HPP
#define ILib_HPP

#include <iostream>
#include <ostream>
#include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

#include "../../Engine/Sparse_array/component.hpp"

class ILib {
    public:
        virtual ~ILib() = default;
        virtual void createGameWindow(float height, float width, std::string name, std::string resolution) = 0;
        virtual void createText(int idx, std::string txt, std::string font, std::string color, std::string style) = 0;
        virtual void displayText(int idx, std::string txt, float posX, float posY, int size, int gras) = 0;
        virtual void closeWindow() = 0;
        virtual void updateWindow() = 0;
        virtual void clearWindow() = 0;
        virtual Components::Inputs getInput() = 0;
        virtual void createdraw(int idx, std::string path) = 0;
        virtual Components::Frame displaydraw(int idx, float posX, float posY, float scaleX, float scaleY) = 0;
        virtual void createdrawrect(int idx, std::string path) = 0;
        virtual void createdrawplayer(int idx, std::string path) = 0;
        virtual void createdrawennemy(int idx, std::string path) = 0;
        virtual void createdrawfire(int idx, std::string path) = 0;
        virtual void createdrawpower(int idx, std::string path) = 0;
        virtual Components::Frame displaydraw(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect) = 0;
        virtual Components::Frame displaydrawplayer(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect) = 0;
        virtual Components::Frame displaydrawennemy(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect) = 0;
        virtual Components::Frame displaydrawfire(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect) = 0;
        virtual Components::Frame displaydrawpower(int idx, float posX, float posY, float scaleX, float scaleY) = 0;
        virtual Components::Position getMouse() = 0;
        virtual bool check_collision(Components::Frame Frame1, Components::Frame Frame2) = 0;
        virtual bool is_open() = 0;
        virtual void show() = 0;
        virtual float get_clock() = 0;
        virtual void restart_clock() = 0;
        virtual void play_song(std::string path, int idx,  bool inLoop, bool is_play, float volume) = 0;
        virtual void set_song_vol(float vol, int idx) = 0;
        virtual void set_framerate(int frame) = 0;
    private:
};

class Sfml : public ILib
{
    public:
        Sfml();
        ~Sfml();
        void createGameWindow(float height, float width, std::string name, std::string resolution);
        void createText(int idx, std::string txt, std::string font, std::string color, std::string style);
        void displayText(int idx, std::string txt, float posX, float posY, int size, int gras);
        void closeWindow();
        void updateWindow();
        void clearWindow();
        Components::Inputs getInput();
        //void createdraw(int idx, std::string path, float posX, float posY, float scaleX, float scaleY);
        Components::Frame displaydraw(int idx, float posX, float posY, float scaleX, float scaleY);
        void createdraw(int idx, std::string path);
        void createdrawrect(int idx, std::string path);
        void createdrawplayer(int idx, std::string path);
        void createdrawennemy(int idx, std::string path);
        void createdrawfire(int idx, std::string path);
        void createdrawpower(int idx, std::string path);
        Components::Frame displaydraw(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect);
        Components::Frame displaydrawplayer(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect);
        Components::Frame displaydrawennemy(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect);
        Components::Frame displaydrawfire(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect);
        Components::Frame displaydrawpower(int idx, float posX, float posY, float scaleX, float scaleY);
        Components::Position getMouse();
        bool is_open();
        void show();
        float get_clock();
        void restart_clock();
        bool check_collision(Components::Frame frame1, Components::Frame Frame2);
        std::shared_ptr<sf::RenderWindow> (window);
        std::shared_ptr<sf::Sound> (sound)[10];
        std::shared_ptr<sf::SoundBuffer> (buffer)[10];
        std::shared_ptr<sf::Texture> (texture)[50];
        std::shared_ptr<sf::Sprite> (sprite)[50];
        std::shared_ptr<sf::Texture> (texture_rect)[50];
        std::shared_ptr<sf::Sprite> (sprite_rect)[50];
        std::shared_ptr<sf::Texture> (texture_player)[50];
        std::shared_ptr<sf::Sprite> (sprite_player)[50];
        std::shared_ptr<sf::Texture> (texture_ennemy)[50];
        std::shared_ptr<sf::Sprite> (sprite_ennemy)[50];
        std::shared_ptr<sf::Texture> (texture_fire)[50];
        std::shared_ptr<sf::Sprite> (sprite_fire)[50];
        std::shared_ptr<sf::Texture> (texture_power)[50];
        std::shared_ptr<sf::Sprite> (sprite_power)[50];
        std::shared_ptr<sf::Text> (text)[50];
        std::shared_ptr<sf::Font> (all_font)[50];
        void play_song(std::string path, int idx, bool inLoop, bool is_play, float volume);
        void set_song_vol(float vol, int idx);
        void set_framerate(int frame);
    private:
        std::shared_ptr<sf::Event> (event);
        //sf::Font (font);
        sf::Clock clock;
};

#endif /* !ILib */