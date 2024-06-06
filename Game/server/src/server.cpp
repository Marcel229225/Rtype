/*
** EPITECH PROJECT, 2022
** B-CPP-500-COT-5-1-rtype-marcel.yobo
** File description:
** server
*/

#include "../include/server.hpp"

// void DataClient::BroadcastPacket(ENetHost *server, const char *data)
// {
//     ENetPacket *packet = enet_packet_create(data, strlen(data) + 1, ENET_PACKET_FLAG_RELIABLE);
//     enet_host_broadcast(server, 0, packet);
// }

void Server::BroadcastPacket(ENetHost *server, const char *data)
{
    ENetPacket *packet = enet_packet_create(data, strlen(data) + 1, ENET_PACKET_FLAG_RELIABLE);
    enet_host_broadcast(server, 0, packet);
}


void Server::sendpacket(ENetPeer *peer, const char *data)
{
    ENetPacket *packet = enet_packet_create(data, strlen(data) + 1, ENET_PACKET_FLAG_RELIABLE);
    enet_peer_send(peer, 0, packet);
}

Server::Server(int ac)
{
    this->event = event;
    this->address = address;
    this->server = server;
    this->new_player_id = new_player_id;
    address.host = ENET_HOST_ANY;
    address.port = 8080;
    new_player_id = -1;
    server = enet_host_create(&address, 32, 1, 0, 0);
}

Server::~Server()
{
}

int Server::verifyerror(void)
{
    if (enet_initialize() != 0)
    {
        fprintf(stderr, "An error occured while initializing Enet.\n");
        return EXIT_FAILURE;
    }
    if (server == NULL)
    {
        fprintf(stderr, "An error occurred while creating Enet Server.\n");
        return EXIT_FAILURE;
    }
    return 0;
}

void DataClient::ReceivedPacket(ENetEvent event, ENetHost *server)
{
    while (enet_host_service(server, &event, 1000) > 0)
    {
        switch (event.type)
        {
        case ENET_EVENT_TYPE_RECEIVE:
            printf("A packet of length %lu containing %s was received from %x %u on channel %u.\n",
                   event.packet->dataLength,
                   event.packet->data,
                   event.peer->address.host,
                   event.peer->address.port,
                   event.channelID);
        }
    }
}

int Server::initializeserver(void)
{
    // DataClient dataclient(new_player_id);
    verifyerror();
    // Début du  jeux
    this->server_system.init_sparse(this->serve_reg);
    while (true)
    {
        // auto &dra = serve_reg.get_components<Components::fire>();
        // for (int idx = 0; idx < dra.size(); idx++) {
        //     this->server_system.set_shoot(serve_reg);
        // }
        //std::vector<std::string> vect_ennemy = this->server_system.move_ennemy(this->serve_reg);
        // for (int v = 0; v < vect_ennemy.size(); v++) BroadcastPacket(this->server, vect_ennemy[v].c_str());
        while (enet_host_service(server, &event, 1000) > 0)
        {
            std::map<int, int>::iterator it = clientmap.begin();
            std::string data;
            std::stringstream os;
            serialise os_seral, os_deseral;
            switch (event.type)
            {
            case ENET_EVENT_TYPE_CONNECT:
                new_player_id++;
                printf("New client connected from %x:%u.\n",
                       event.peer->address.host,
                       event.peer->address.port);
                clientmap.insert({event.peer->connectID, new_player_id});
                sendpacket(event.peer, std::to_string(new_player_id).c_str());
                break;
            case ENET_EVENT_TYPE_RECEIVE:
                
                for (clientmap.begin(); it != clientmap.end(); it++)
                {
                    if (it->first == event.peer->connectID)
                    {
                        std::string okk = " ";
                        data = (std::to_string(it->second)) + okk + (std::string((char *)(event.packet->data)));
                    }
                }
                strcpy(os_seral.data_str, data.c_str());
                os_seral.serialize(os);
                os_deseral.deserialize(os);
                // data --> OS (castre OS with .str())
                if (std::regex_match((data.c_str()), std::regex("[0-9]+ (DOWN|UP|LEFT|RIGHT)"))) {
                    std::string to_send = this->server_system.update_server_pos(serve_reg, data);
                    BroadcastPacket(this->server, to_send.c_str());
                }
                if (std::regex_match((data.c_str()), std::regex("[0-9]+ (SHOOT)"))) {
                    std::string to_send = this->server_system.set_shoot_pos(serve_reg, data);
                    //this->server_system.set_shoot(serve_reg);
                    BroadcastPacket(this->server, to_send.c_str());
                }

                if (std::regex_match((data.c_str()), std::regex("[0-9]+ [0-9]+"))) {
                    //this->server_system.set_shoot(serve_reg);
                    this->server_system.set_server_shoot(serve_reg, data);
                    //BroadcastPacket(this->server, to_send.c_str());
                }

                if (std::regex_match((data.c_str()), std::regex("0 WILL START"))) {
                    this->is_start = true;
                }
                if (this->is_start == true) {
                    if(time >= 1) {
                        std::string sd = std::to_string(this->time) + " TIME";
                        BroadcastPacket(this->server, sd.c_str());
                        //std::this_thread::sleep_for(std::chrono::microseconds{100000});
                        time --;
                        std::string send_to = std::to_string(new_player_id + 1) + " Number of clients";
                        if (time == 10) BroadcastPacket(this->server, send_to.c_str());
                    }
                    else if (time == 1) is_start = false;
                }
                std::cout << data << std::endl;
                // printf("A packet of length %lu containing %s by %d was received from %x %u on channel %u.\n",
                //        event.packet->dataLength,
                //        event.packet->data,
                //        event.peer->address.host,
                //        event.peer->address.port,
                //        event.channelID);
                // dataclient.ParseData(server, static_cast<DataClient *>(event.peer->data)->GetId(), reinterpret_cast<char *>(event.packet->data));
                enet_packet_destroy(event.packet);
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                printf(("%x:%u disconnected\n"), event.peer->host, event.peer->address.port);
                event.peer->data = NULL;

                // char disconnected_data[126];
                // disconnected_data[0] = '\0';

                // dataclient.BroadcastPacket(server, disconnected_data);
                break;
            default:
                break;
            }
        }
    }
    // Fin du jeux
    enet_host_destroy(server);
    return EXIT_SUCCESS;
}

int main(int ac, char **av)
{
    if (ac != 2) return 84;
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (std::isdigit(av[1][i] == 0)) return 84;
    }
    Server serv(atoi(av[1]));
    serv.initializeserver();
}
