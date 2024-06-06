/*
** EPITECH PROJECT, 2022
** R-type
** File description:
** regitry file   
*/

#include "registry.hpp"

// namespace component {
//     struct position
//     {
//         float x;
//         float y;
//     };

//     struct velocity
//     {
//         float vx;
//         float vy;
//     };
// }

// void logging_system(registry &r)
// {
//     auto const &positions = r.get_components<component::position >();
//     auto const &velocities = r.get_components<component::velocity>();
//     for (size_t i = 0; i < positions.size() && i < velocities.size(); ++i) {
//         auto const &pos = positions[i];
//         auto const &vel = velocities[i];
//         if (pos && vel) {
//             std::cerr << i << ": Position = { " << pos.value().x << ", " << pos.value().y << " } , Velocity = { " << vel.value().vx << ", " << vel.value().vy << " }" << std::endl;
//         }
//     }
// }

// int main()
// {
//     registry r;
//     r.register_component<component::position>();
//     r.register_component<component::velocity>();
//     const entity to(1);
//     r.add_component<component::position>(to, component::position({41, 54}));
//     r.add_component<component::velocity>(to, component::velocity({10, 20}));
//     logging_system(r);
//     return(0);
// }