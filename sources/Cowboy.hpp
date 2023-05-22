#pragma once

#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
        int _num_Of_bolls;

    public:
        char type = 'C';
        Cowboy(std::string name, Point location);
        Cowboy(Cowboy &other);
        Cowboy(Cowboy &&other) noexcept;
        virtual ~Cowboy();

        Cowboy &operator=(const Cowboy &other);
        Cowboy &operator=(Cowboy &&other) noexcept;

        void shoot(Character *target);
        bool hasboolets();
        void reload();

        int getNum_Of_bolls();
        char getType();

        bool operator==(const Cowboy &other);

        virtual std::string print() override;
    };
}
