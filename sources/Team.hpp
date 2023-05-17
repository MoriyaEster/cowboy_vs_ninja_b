#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <vector>

#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
namespace ariel
{

    class Team
    {
    public:
        std::vector <Character> team;
        Character *leader;

        Team(Character *leader);
        void add(Character *player);
        void attack(Team * enemy);
        int stillAlive();
        void print();
        

    };

}







        // Team &operator=(const Team &other);
        // bool operator==(const Team &other) const;