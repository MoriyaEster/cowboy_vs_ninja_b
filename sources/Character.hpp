#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <stdio.h>
#include <cmath>
#include "Point.hpp"

namespace ariel
{

    class Character
    {

        Point _location;
        int _self_Hit;
        std::string _name;

    public:
        Character(Point location, int self_Hit, std::string name);
        Character();
        Character(const Character &other);
        Character(Character &&other) noexcept;
        virtual ~Character();

        Character &operator=(const Character &other);
        Character &operator=(Character &&other) noexcept;
        bool operator==(const Character &other) const;

        void setLocation(Point location);
        int getself_Hit();
        void setself_Hit(int self_Hit);

        bool isAlive();
        double distance(Character &other);
        void hit(int value);
        std::string getName();
        Point getLocation();
        virtual std::string print();
    };
}