/*
** EPITECH PROJECT, 2022
** B-CPP-500-COT-5-1-rtype-marcel.yobo
** File description:
** server
*/

#include <iomanip>
#include <iostream>
#include <ostream>
#include <enet/enet.h>
#include <string>
#include <cstring>
#include <thread>
#include <map>
#include <iterator>
#include <algorithm>
#include "../../sfml/sfml.hpp"
#include "../../../Engine/System/system.hpp"

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

class Server
{
public:
    int new_player_id = 0;
    Server(int ac);
    ~Server();
    int verifyerror(void);
    int initializeserver(void);
    void BroadcastPacket(ENetHost* server, const char* data);
    void sendpacket(ENetPeer *peer, const char *data);
    std::map<int, int> clientmap;
    ENetEvent event;
    ENetAddress address;
    ENetHost *server;
    ISystem server_system;
    registry serve_reg;
    bool is_start;
    int time = 25;
};

class DataClient
{
public:
    int id;
    std::string name;
    DataClient(int id) : id(id){};
    void SetUsername(std::string name) { name = name; };
    int GetId() const { return id; };
    std::string GetName() const { return name; };
    void ParseData(ENetHost *server, int id, char *data);
    void sendpacket(ENetPeer *peer, const char *data);
    void BroadcastPacket(ENetHost* server, const char* data);
    void ReceivedPacket(ENetEvent event, ENetHost *server);
};

typedef struct serialization
{
    int data;
    char *data_str = new char[1024];
    float *tab = new float[8];

    std::ostream &serialize(std::ostream &os) const
    {
        char null = '\0';
        os.write((char *)&data, sizeof(data));
        os.write(data_str, 1024);
        for (int i = 0; i < 8; i++)
        {
            os.write((char *)&(tab[i]), sizeof(tab));
        }
        os.write(&null, 1);
        return os;
    }
    std::istream &deserialize(std::istream &is)
    {
        char null = '\0';
        is.read((char *)&data, sizeof(data));
        is.read(data_str, 1024);
        for (int i = 0; i < 8; i++)
        {
            is.read((char *)&(tab[i]), sizeof(tab));
        }
        is.read(&null, 1);
        return is;
    }
} serialise;

std::map<int, DataClient *> client_map;
static int CLIENT_ID = -1;

#endif /* !CLIENT_HPP_ */