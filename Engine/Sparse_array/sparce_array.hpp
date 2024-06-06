/*
** EPITECH PROJECT, 2022
** R-type 
** File description:
** Game 
*/

#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <optional>
#include <map>
#include <any>
#include <typeindex>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#ifndef Sparce_array
#define Sparce_array

class entity {
    public:
        explicit entity(std::size_t x)
        {
            this->id = x;
        }
        ~entity() {}
        operator std::size_t() const{ return id;}
        std::size_t id;
    private:
    protected:
};

template <typename Component> // You can also mirror the definition of std :: vector , that takes an additional allocator .
class sparse_array
{
public:
    using value_type = std::optional<Component>; // optional component type
    using reference_type = value_type &;
    using const_reference_type = value_type const &;
    using container_t = std ::vector<value_type>; // optionally add your allocator template here.
    using size_type = typename container_t ::size_type;
    using iterator = typename container_t ::iterator;
    using const_iterator = typename container_t ::const_iterator;

public:
    sparse_array() {}; // You can add more constructors .
    sparse_array(sparse_array const &space)
    {
        this->_data = space._data;
    }; // copy constructor
    sparse_array(sparse_array &&space) noexcept
    {
        this->_data = std::move(space._data);
    }; // move constructor
    ~sparse_array() {};
    sparse_array &operator=(sparse_array const &space)
    {
        this->_data = space->_data;
        return (*this);
    }; // copy assignment operator
    sparse_array &operator=(sparse_array &&space) noexcept
    {
        this->_data = std::move(space->_data);
        return (*this);
    }; // move assignment operator
    reference_type operator[](size_t idx)
    {
        if (idx <= this->_data.size())
            return this->_data[idx];
        else 
            return this->_data[idx];
    };
    const_reference_type operator[](size_t idx) const
    {
        if (idx <= this->_data.size())
            return this->_data[idx];
        return this->_data[idx];
    };
    iterator begin()
    {
        return this->_data.begin();
    };
    const_iterator begin() const
    {
        return this->_data.begin();
    };
    const_iterator cbegin() const
    {
        return this->_data.begin();
    };
    iterator end()
    {
        return this->_data.end();
    };
    const_iterator end() const
    {
        return this->_data.end();
    };
    const_iterator cend() const
    {
        return this->_data.end();
    };
    size_type size() const
    {
        return this->_data.size();
    };
    reference_type insert_at(size_type pos, Component const &space)
    {
        int index = 0;
        int i = 0;
        auto it = this->_data.begin();
        if (pos > this->_data.size())
        {
            index = this->_data.size();
            while (index < pos)
            {
                this->_data.push_back(std::nullopt);
                index++;
            }
            this->_data.push_back(space);
        }
        else {
            for (; it != this->_data.end(); it++, i++)
            {
                if (i == pos)
                    break;
            }
            this->_data.insert(it, space);
        }
        return this->_data.at(pos);

    };
    reference_type insert_at(size_type pos, Component &&space)
    {
        int index = 0;
        int i = 0;
        auto it = this->_data.begin();
        if (pos > this->_data.size())
        {
            index = this->_data.size();
            while (index < pos)
            {
                this->_data.push_back(std::nullopt);
                index++;
            }
            this->_data.push_back(std::move(space));
        }
        for (; it != this->_data.end(); it++, i++)
        {
            if (i == pos) {
                this->_data.erase(it);
                break;
            }
        }
        this->_data.insert(it, std::move(space));
        return this->_data.at(pos);
    };
    template <class... Params>
    reference_type emplace_at(size_type pos, Params &&...); // optional
    void erase(size_type pos)
    {
        iterator it;
        for (int i = 0; i < this->_data.size(); i++)
        {
            if (i == pos)
                break;
        }
        this->_data.erase(pos);
    };
    size_type get_index(value_type const &v) const
    {
        for (int i = 0; i < this->_data.size(); i++)
        {
            if (std::addressof(this->_data[i]) == std::addressof(v))
                return i;
        }
    };

private:
    container_t _data;
};
#endif /* !Sparce_array */
