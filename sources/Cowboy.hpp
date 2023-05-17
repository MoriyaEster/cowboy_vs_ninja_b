#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
        int _num_Of_bolls;
        char _type = 'C';

    public:
        Cowboy(std::string name, Point location);
        // Cowboy(const Cowboy &other); // copy constructor
        ~Cowboy(); // destructor

        void shoot(Character *target);
        bool hasboolets();
        void reload();

        int getNum_Of_bolls();
        char getType();

        bool operator==(const Cowboy &other); // equality operator
    };
}