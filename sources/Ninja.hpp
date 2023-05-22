#pragma once

#include "Character.hpp"

namespace ariel
{

    class Ninja : public Character
    {
        int _speed;

    public:
        char type = 'N';
        Ninja(Point location, int self_Hit, std::string name, int speed);

        void move(Character *target);
        void slash(Character *target);

        Ninja(const Ninja &other);
        Ninja(Ninja &&other) noexcept;
        virtual ~Ninja();

        Ninja &operator=(const Ninja &other);
        Ninja &operator=(Ninja &&other) noexcept;
        bool operator==(const Ninja &other) const;

        virtual std::string print() override;
    };
}