/*
** EPITECH PROJECT, 2022
** B-CPP-500-COT-5-1-rtype-marcel.yobo
** File description:
** client
*/

#include <iomanip>
#include <iostream>
#include <ostream>
#include <enet/enet.h>
#include <string>
#include <cstring>
#include <thread>
#include <map>

using namespace std;

#include "../../../Engine/System/system.hpp"
#include "../../sfml/sfml.hpp"
#ifndef CLIENT_HPP_
#define CLIENT_HPP_


class Client {
    public:
        char *client_username;
        Client(int ac, int nbr, char **av);
        ~Client();
        int verifyerror(void);
        int initializeclient();
        void sendpacket(ENetPeer *peer, const char *data);
        void *MsgLoop(ENetHost *client);
        static int is_connect(ENetPeer *peer);
        ENetHost *client;
        ENetAddress address;
        ENetEvent event; 
        Game_SFML game;
        void SendPacket(ENetPeer *peer, const char *data);
        ENetPeer *peer;
        std::string msg;
        int id;
        int time;
        int is_send = false;
        registry client_reg;
        ISystem client_system;
};

class ClientData
{
public:
    int id;
    std::string name;
    ClientData(int id) : id(id){};
    void SetUsername(std::string name) { name = name; };
    int GetId() const { return id; };
    std::string GetName() const { return name; };
    void ParseData(char *data);
};

std::map<int, ClientData *> client_map;
static int CLIENT_ID = -1;


#endif /* !CLIENT_HPP_ */