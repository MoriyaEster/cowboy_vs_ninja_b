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

    class Team2
    {
    public:
        std::vector<Ninja *> team_ninja;
        std::vector<Cowboy *> team_cowboy;
        std::vector<int> order;
        Character *leader;
        int size;
        int size_ninja;
        int size_cowboy;

        Team2(Ninja *leader);
        Team2(Cowboy *leader);
        ~Team2();

        Team2 &operator=(const Team2 &other);
        bool operator==(const Team2 &other) const;

        void add(Ninja *player);
        void add(Cowboy *player);
        void attack(Team2 *enemy);
        int stillAlive();
        void print();
    };

}
