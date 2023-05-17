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
        Cowboy(Cowboy &other);          // Copy constructor
        Cowboy(Cowboy &&other) noexcept;      // Move constructor
        ~Cowboy();                            // Destructor

        Cowboy &operator=(const Cowboy &other);    // Copy assignment operator
        Cowboy &operator=(Cowboy &&other) noexcept; // Move assignment operator

        void shoot(Character *target);
        bool hasboolets();
        void reload();

        int getNum_Of_bolls();
        char getType();

        bool operator==(const Cowboy &other); // Equality operator
    };
}
