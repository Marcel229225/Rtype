/*
** EPITECH PROJECT, 2022
** B-CPP-500-COT-5-1-rtype-marcel.yobo
** File description:
** client
*/

#include "../include/client.hpp"

Client::Client(int ac, int nbr, char **av)
{
    this->client = client;
    this->address = address;
    this->event = event;
    this->peer = peer;
    client = enet_host_create(NULL, 1, 1, 0, 0);
    enet_address_set_host(&address, av[2]);
    address.port = ac;
    peer = enet_host_connect(client, &address, 1, 0);
    if (nbr == 4) this->game.set_config(std::string(av[3]));
}

Client::~Client()
{
}

void Client::SendPacket(ENetPeer *peer, const char *data)
{
    ENetPacket *packet = enet_packet_create(data, strlen(data) + 1, ENET_PACKET_FLAG_RELIABLE);
    enet_peer_send(peer, 0, packet);
}
int Client::verifyerror(void)
{
    if (enet_initialize() != 0)
    {
        fprintf(stderr, "An error occured while initializing Enet.\n");
        return EXIT_FAILURE;
    }
    atexit(enet_deinitialize);
    if (client == NULL)
    {
        fprintf(stderr, "An error occurred while creating Enet client.\n");
        return EXIT_FAILURE;
    }

    if (peer == NULL)
    {
        fprintf(stderr, "Couldn't connect to server\n");
        return EXIT_FAILURE;
    }
    return 0;
}

// void ClientData::ParseData(char *data)
// {
//     std::cout << "PRASE:" << data << "\n";

//     int data_type;
//     int id;
//     sscanf(data, "%d|%d", &data_type, &id);

//     switch (data_type)
//     {
//     case 1:
//         if(id != CLIENT_ID)
// 			{
// 				std::string msg;
// 				sscanf(data, "%*d|%d|%[^|]", &msg);
// 				std::getline(std::cin, msg);
// 			}
//         break;
//     case 2:
//         if (id != CLIENT_ID)
//         {
//             char username[80];
//             sscanf(data, "%d|%d|%*[^|]", &username);
//             client_map[id] = new ClientData(id);
//             client_map[id]->SetUsername(username);
//         }
//         break;
//     case 3:
//         CLIENT_ID = id;
//         break;
//     }
// }


void *Client::MsgLoop(ENetHost *client)
{
    while (true)
    {
        ENetEvent event;
        while (enet_host_service(client, &event, 0) > 0)
        {
            switch (event.type)
            {
            case ENET_EVENT_TYPE_RECEIVE:
                if (std::regex_match((std::string((char *)(event.packet->data))), std::regex("[0-9]+ NEW_POSITION (-)?[0-9]+.[0-9]+ (-)?[0-9]+.[0-9]+"))) {
                    client_system.update_client_pos(client_reg, (std::string((char *)(event.packet->data))));
                }
                if (std::regex_match((std::string((char *)(event.packet->data))), std::regex("[0-9]+ SHOOT_NEW_POS (-)?[0-9]+.[0-9]+ (-)?[0-9]+.[0-9]+"))) {
                    client_system.set_shoot_pos(client_reg, (std::string((char *)(event.packet->data))));
                    //std::string to_send = this->client_system.set_shoot(client_reg, (std::string((char *)(event.packet->data))));
                }
                if (std::regex_match((std::string((char *)(event.packet->data))), std::regex("[0-9]+"))) {
                    this->id = atoi((char *)(event.packet->data));
                    //client_system.set_shoot_pos(client_reg, (std::string((char *)(event.packet->data))));
                    //std::string to_send = this->client_system.set_shoot(client_reg, (std::string((char *)(event.packet->data))));
                }

                if (std::regex_match((std::string((char *)(event.packet->data))), std::regex("[0-9]+ TIME"))) {
                    this->time = this->client_system.get_id((std::string((char *)(event.packet->data))));
                }

                if (std::regex_match((std::string((char *)(event.packet->data))), std::regex("[0-9] Number of clients"))) {
                    game.nbr_client = this->client_system.get_id((std::string((char *)(event.packet->data))));
                    if (game.nbr_client == 1) this->game.set_life(this->client_reg, game.nbr_client, true);
                    else this->game.set_life(this->client_reg, game.nbr_client, false);
                }

                // if (std::regex_match((std::string((char *)(event.packet->data))), std::regex("[0-9]+ NEW_ENNEMY_POS (-)?[0-9]+.[0-9]+ (-)?[0-9]+.[0-9]+"))) {
                //     client_system.set_ennemy_client(client_reg, (std::string((char *)(event.packet->data))));
                //     //std::string to_send = this->client_system.set_shoot(client_reg, (std::string((char *)(event.packet->data))));
                // }
                printf("%s\n", event.packet->data);
                enet_packet_destroy(event.packet);
                break;
            }
        }
    }
}

int Client::is_connect(ENetPeer *peer)
{
    if (peer != NULL)
        return 1;
    else 
        return 2;
}

int Client::initializeclient()
{
    printf("Entrer votre nom d'utilisateur\n");
    char username[80];
    scanf("%s", &username);
    verifyerror();
    if (enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT)
    {
        puts("Connecting to 10.50.11.79:8080 succeeded");
    }
    else
    {
        enet_peer_reset(peer);
        puts("Connection to 10.50.11.79:8080 failed");
        return EXIT_SUCCESS;
    }
    char str_data[80] = "2|";
    strcat(str_data, username);
    SendPacket(peer, username);
    std::thread thread(&Client::MsgLoop, this, client);
    //  while (true)
    // {
    //     std::string messages;
    //     std::getline(std::cin, messages);
    //     char message_data[80] = "1|";
    //     strcat(message_data, messages.c_str());
    //     SendPacket(peer,message_data);
    // }
    this->client_system.init_sparse(this->client_reg);
    //game.system.init_sparse(this->client_reg);
    game.init_game(this->client_reg);
    //this->client_system.create_window(this->client_reg, 1200, 800, "window", "Full");
    Components::Inputs input;
    while (true) {
        input = game.sec->getInput();
        //this->game.nbr_client = 2;
        int wh = game.main_menu(this->client_reg, input, this->id, this->time, std::string(username));
        if (input == Components::ENTER_KEY) exit(0);
        if (input == Components::DOWN_ARROW) SendPacket(peer, "DOWN");
        if (input == Components::UP_ARROW) SendPacket(peer, "UP");
        if (input == Components::LEFT_ARROW) SendPacket(peer, "LEFT");
        if (input == Components::RIGHT_ARROW) SendPacket(peer, "RIGHT");
        if (input == Components::SPACE_BAR) SendPacket(peer, "SHOOT");
        if (wh == 11) {
            SendPacket(peer, "WILL START");
            //is_send = true;
        }
        if (input == Components::BUTTON) {
            this->client_system.set_sound(this->client_reg, 1, true);
            game.create_sound(this->client_reg, 1);
            this->client_system.set_sound(this->client_reg, 1, false);
        }
        std::vector to_s = this->client_system.check_shoot(client_reg);
        if (to_s.size() > 0) {
            for (auto &it : to_s)
                SendPacket(peer, it.c_str());
        }
        to_s.clear();
        //if (this->client_system.where == 1) {
            // game.display_player_score(this->client_reg, this->id);
            // game.create_draw_rect(this->client_reg, this->id + 16);
        //}
    }
    thread.join();
    // Fin du jeux
    enet_peer_disconnect(peer, 0);
    while (enet_host_service(client, &event, 3000) > 0)
    {
        switch (event.type)
        {
        case ENET_EVENT_TYPE_RECEIVE:
            enet_packet_destroy(event.packet);
        case ENET_EVENT_TYPE_DISCONNECT:
            puts("Disconnectionn succeeded");
            break;
        }
    }
    return EXIT_SUCCESS;
}

int main(int ac, char **av)
{
    if (ac > 4 || ac == 1 || ac == 2) return 84;
    Client cli(atoi(av[1]), ac, av);
    cli.initializeclient();
}