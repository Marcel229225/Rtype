/*
** EPITECH PROJECT, 2022
** R TYPE
** File description:
** lib sfml
*/

#include "iLib.hpp"

Sfml::Sfml()
{

}

Sfml::~Sfml()
{

}

void Sfml::createGameWindow(float height, float width, std::string name, std::string resolution)
{
    if (resolution.compare("Full") == 0)
        this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(height, width), name, sf::Style::Fullscreen);
    else if (resolution.compare("Default") == 0)
        this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(height, width), name, sf::Style::Default);
    // this->window->setVerticalSyncEnabled(false);
    this->window->setFramerateLimit(60);
    sf::Image icon;
    icon.loadFromFile("./Assets/icon.png");
    window->setIcon(512, 512, icon.getPixelsPtr());
    //this->window->useVerticalSync(false);
}

bool Sfml::is_open()
{
    return (this->window->isOpen());
}

void Sfml::createText(int idx, std::string txt, std::string font, std::string color, std::string style)
{
    // sf::Font ft;
    // ft.loadFromFile(font);
    text[idx] = std::make_shared<sf::Text>();
    all_font[idx] = std::make_shared<sf::Font>();
    all_font[idx]->loadFromFile(font);

    if (color.compare("Cyan") == 0) text[idx]->setFillColor(sf::Color::Cyan);
    if (color.compare("Green") == 0) text[idx]->setFillColor(sf::Color::Green);
    if (color.compare("White") == 0) text[idx]->setFillColor(sf::Color::White);
    if (color.compare("Black") == 0) text[idx]->setFillColor(sf::Color::Black);
    if (color.compare("Magenta") == 0) text[idx]->setFillColor(sf::Color::Magenta);
    if (style.compare("Regular") == 0) text[idx]->setStyle(sf::Text::Regular);
    //text[idx]->setString(txt);
    //text[idx]->setFont(*all_font[0]);
    //text[idx]->setOutlineColor(sf::Color::Green);
    //text[idx]->setOutlineThickness(gras);
    //text[idx]->setCharacterSize(size);
    //text[idx]->setPosition(posX, posY);
}

void Sfml::displayText(int idx, std::string txt, float posX, float posY, int size, int gras)
{
    text[idx]->setString(txt);
    text[idx]->setFont(*all_font[idx]);
    // if (!font.loadFromFile("Assets/font.ttf"))
    //     printf("Couldn't load font'");
    // sf::Text txt(text.txt, font, 24);
    // txt.setFillColor(sf::Color::White);
    // txt.setPosition(text.posY*7,text.posX*15);
    // this->window->draw(txt);
    // sf::Font ft;
    // ft.loadFromFile(font);
    // sf::Text text(txt, ft, size);
    // //text.setFont(ft);
    // //text.setString(txt);
    // text.setFillColor(sf::Color::Cyan);
    // if (color.compare("Cyan") == 0) text.setFillColor(sf::Color::Cyan);
    // if (color.compare("Green") == 0) text.setFillColor(sf::Color::Green);
    // if (color.compare("White") == 0) text.setFillColor(sf::Color::White);
    // if (color.compare("Magenta") == 0) text.setFillColor(sf::Color::Magenta);
    // if (style.compare("Regular") == 0) text.setStyle(sf::Text::Regular);
    text[idx]->setOutlineColor(sf::Color::Green);
    text[idx]->setOutlineThickness(gras);
    text[idx]->setCharacterSize(size);
    text[idx]->setPosition(posX, posY);
    this->window->draw(*text[idx]);
}

void Sfml::closeWindow()
{
    this->window->close();
}

void Sfml::updateWindow()
{
    this->window->display();
}

extern "C"
{
    std::shared_ptr<Sfml> entryPoint()
    {
        return std::make_shared<Sfml>();
    }
}

void Sfml::clearWindow()
{
    this->window->clear();
}

Components::Inputs Sfml::getInput()
{
    sf::Event ev{};
    Components::Inputs input = Components::NO_TYPE;

    while (this->window->pollEvent(ev)) {
        // if (ev.type == sf::Event::Resized) {
        //     sf::FloatRect visibleArea(0, 0, ev.size.width, ev.size.height);
        //     this->window->setView(sf::View(visibleArea));
        // }
        if (ev.type == sf::Event::Closed)
            input = Components::QUIT;
        else if (ev.type == sf::Event::KeyPressed) {
            if (ev.key.code == sf::Keyboard::Up)
                input = Components::UP_ARROW;
            else if (ev.key.code == sf::Keyboard::Down)
                input = Components::DOWN_ARROW;
            else if (ev.key.code == sf::Keyboard::Left)
                input = Components::LEFT_ARROW;
            else if (ev.key.code == sf::Keyboard::Right)
                input = Components::RIGHT_ARROW;
            else if (ev.key.code == sf::Keyboard::Enter)
                input = Components::ENTER_KEY;
            else if (ev.key.code == sf::Keyboard::Space)
                input = Components::SPACE_BAR;
            else if (ev.key.code == sf::Keyboard::C)
                input = Components::C;
            else if (ev.key.code == sf::Keyboard::R)
                input = Components::R;
            else if (ev.key.code == sf::Keyboard::N)
                input = Components::N;
        }
        else if (ev.type == sf::Event::MouseButtonPressed)
            input = Components::BUTTON;
    }
    return input;
}

void Sfml::createdraw(int idx, std::string path)
{
    //sf::Texture txt;
    //sf::Sprite spt;
    texture[idx] = std::make_shared<sf::Texture>();
    sprite[idx] = std::make_shared<sf::Sprite>();
    texture[idx]->loadFromFile(path);
    sprite[idx]->setTexture(*texture[idx]);
    //this->window->draw(*sprite[idx]);
}

void Sfml::createdrawrect(int idx, std::string path)
{
    //sf::Texture txt;
    //sf::Sprite spt;
    texture_rect[idx] = std::make_shared<sf::Texture>();
    sprite_rect[idx] = std::make_shared<sf::Sprite>();
    texture_rect[idx]->loadFromFile(path);
    sprite_rect[idx]->setTexture(*texture_rect[idx]);
    //this->window->draw(*sprite[idx]);
}

Components::Frame Sfml::displaydraw(int idx, float posX, float posY, float scaleX, float scaleY)
{
    Components::Frame frame;
    sprite[idx]->setPosition(posX, posY);
    sprite[idx]->setScale(scaleX, scaleY);
    sf::FloatRect rect2 = sprite[idx]->getGlobalBounds();
    frame.x = rect2.left, frame.y = rect2.top, frame.width = rect2.width, frame.height = rect2.height;
    this->window->draw(*sprite[idx]);
    return(frame);
}


void Sfml::createdrawplayer(int idx, std::string path)
{
    texture_player[idx] = std::make_shared<sf::Texture>();
    sprite_player[idx] = std::make_shared<sf::Sprite>();
    texture_player[idx]->loadFromFile(path);
    sprite_player[idx]->setTexture(*texture_player[idx]);
}

void Sfml::createdrawennemy(int idx, std::string path)
{
    texture_ennemy[idx] = std::make_shared<sf::Texture>();
    sprite_ennemy[idx] = std::make_shared<sf::Sprite>();
    texture_ennemy[idx]->loadFromFile(path);
    sprite_ennemy[idx]->setTexture(*texture_ennemy[idx]);
}

void Sfml::createdrawfire(int idx, std::string path)
{
    texture_fire[idx] = std::make_shared<sf::Texture>();
    sprite_fire[idx] = std::make_shared<sf::Sprite>();
    texture_fire[idx]->loadFromFile(path);
    sprite_fire[idx]->setTexture(*texture_fire[idx]);
}

void Sfml::createdrawpower(int idx, std::string path)
{
    texture_power[idx] = std::make_shared<sf::Texture>();
    sprite_power[idx] = std::make_shared<sf::Sprite>();
    texture_power[idx]->loadFromFile(path);
    sprite_power[idx]->setTexture(*texture_power[idx]);
}

Components::Frame Sfml::displaydraw(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect)
{
    Components::Frame frame;
    sf::IntRect rec{rect.x, rect.y, rect.x2, rect.y2};
    sprite_rect[idx]->setTextureRect(rec);
    sprite_rect[idx]->setPosition(posX, posY);
    sprite_rect[idx]->setScale(scaleX, scaleY);
    this->window->draw(*sprite_rect[idx]);
    sf::FloatRect rect2 = sprite_rect[idx]->getGlobalBounds();
    frame.x = rect2.left, frame.y = rect2.top, frame.width = rect2.width, frame.height = rect2.height;
    return (frame);
}

Components::Frame Sfml::displaydrawplayer(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect)
{
    Components::Frame frame;
    sf::IntRect rec{rect.x, rect.y, rect.x2, rect.y2};
    sprite_player[idx]->setTextureRect(rec);
    sprite_player[idx]->setPosition(posX, posY);
    sprite_player[idx]->setScale(scaleX, scaleY);
    this->window->draw(*sprite_player[idx]);
    sf::FloatRect rect2 = sprite_player[idx]->getGlobalBounds();
    frame.x = rect2.left, frame.y = rect2.top, frame.width = rect2.width, frame.height = rect2.height;
    return (frame);
}

Components::Frame Sfml::displaydrawennemy(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect)
{
    Components::Frame frame;
    sf::IntRect rec{rect.x, rect.y, rect.x2, rect.y2};
    sprite_ennemy[idx]->setTextureRect(rec);
    sprite_ennemy[idx]->setPosition(posX, posY);
    sprite_ennemy[idx]->setScale(scaleX, scaleY);
    this->window->draw(*sprite_ennemy[idx]);
    sf::FloatRect rect2 = sprite_ennemy[idx]->getGlobalBounds();
    frame.x = rect2.left, frame.y = rect2.top, frame.width = rect2.width, frame.height = rect2.height;
    return (frame);
}

Components::Frame Sfml::displaydrawfire(int idx, float posX, float posY, float scaleX, float scaleY, Components::Rect rect)
{
    Components::Frame frame;
    sf::IntRect rec{rect.x, rect.y, rect.x2, rect.y2};
    sprite_fire[idx]->setTextureRect(rec);
    sprite_fire[idx]->setPosition(posX, posY);
    sprite_fire[idx]->setScale(scaleX, scaleY);
    this->window->draw(*sprite_fire[idx]);
    sf::FloatRect rect2 = sprite_fire[idx]->getGlobalBounds();
    frame.x = rect2.left, frame.y = rect2.top, frame.width = rect2.width, frame.height = rect2.height;
    return (frame);
}

Components::Frame Sfml::displaydrawpower(int idx, float posX, float posY, float scaleX, float scaleY)
{
    Components::Frame frame;
    //sf::IntRect rec{rect.x, rect.y, rect.x2, rect.y2};
    //sprite_power[idx]->setTextureRect(rec);
    sprite_power[idx]->setPosition(posX, posY);
    sprite_power[idx]->setScale(scaleX, scaleY);
    this->window->draw(*sprite_power[idx]);
    sf::FloatRect rect2 = sprite_power[idx]->getGlobalBounds();
    frame.x = rect2.left, frame.y = rect2.top, frame.width = rect2.width, frame.height = rect2.height;
    return (frame);
}

void Sfml::show()
{
    this->window->display();
}

float Sfml::get_clock()
{
    return (this->clock.getElapsedTime().asSeconds());
}

void Sfml::restart_clock()
{
    this->clock.restart();
}

Components::Position Sfml::getMouse()
{
    Components::Position pos;
    sf::Vector2i position = sf::Mouse::getPosition();
    pos.x = position.x, pos.y = position.y;
    return(pos);
}

bool Sfml::check_collision(Components::Frame r1, Components::Frame r2)
{
    sf::FloatRect rect1 = {r1.x, r1.y, r1.width, r1.height};
    sf::FloatRect rect2 = {r2.x, r2.y, r2.width, r2.height};

    return (rect1.intersects(rect2));
}

void Sfml::play_song(std::string path, int idx, bool inLoop, bool is_play, float volume)
{
    //sf::SoundBuffer buffer;
    //sf::Sound sound;
    //buffer->loadFromFile(path);
    // sound->setBuffer(std::make_shared<sf::Sound>buffer);
    // //if(is_play) sound.play();
    // //if (!is_play) sound.stop();
    // sound->play();
    // sound->setLoop(true);
    // sound->setVolume(100.f);
    if(is_play) {
        buffer[idx] = std::make_shared<sf::SoundBuffer>();
        buffer[idx]->loadFromFile(path);
        sound[idx] = std::make_shared<sf::Sound>();
        sound[idx]->setBuffer(*buffer[idx]);
        if (is_play) sound[idx]->play();
        //else sound[idx]->stop();
        if(inLoop) sound[idx]->setLoop(true);
        sound[idx]->setVolume(volume);
    }
}

void Sfml::set_song_vol(float vol, int idx)
{
    //sound[idx] = std::make_shared<sf::Sound>();
    sound[idx]->setVolume(vol);
}

void Sfml::set_framerate(int frame)
{
    window->setFramerateLimit(frame);
}