/*
** EPITECH PROJECT, 2022
** R-type
** File description:
** Registry
*/

#include "../Sparse_array/sparce_array.hpp"

#ifndef Registry
#define Registry

class registry {
    public :
        template <class Component>
            void register_component ()
            {
                sparse_array <Component> some;
                this->_components_arrays.insert({typeid (Component), std::any_cast<sparse_array <Component>>(some)});
            }

        template <class Component>
            sparse_array <Component> &get_components()
            {
                return (std::any_cast<sparse_array<Component>&>(this->_components_arrays[typeid(Component)]));
            }
        template <class Component>
            sparse_array < Component > const & get_components () const ;
        
            entity spawn_entity()
            {
                size_t a;
                entity some(a);
                return(some);
            }

            entity entity_from_index(std::size_t idx)
            {
                entity some(idx);
                return(some);
            }

            void kill_entity (entity const &e);
        template <typename Component>
            void add_component (entity const &to ,Component &&c)
            {
                sparse_array<Component> &some = get_components<Component>();
                some.insert_at(to, c);
                //return (some);
            }
        template <typename Component>
            void add_component (entity const &to ,Component &c)
            {
                sparse_array<Component> &some = get_components<Component>();
                some.insert_at(to, c);
                //return (some);
            }
        template <typename Component , typename Params>
            typename sparse_array < Component >::reference_type emplace_component (entity const &to, Params &&p) ;
        template <typename Component>
            void remove_component (entity const &from);
    private :
        std::map<std::type_index, std::any> _components_arrays;
};
#endif /* !Registry */
