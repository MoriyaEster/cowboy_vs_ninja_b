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
        std::vector<Ninja *> team_ninja;
        std::vector<Cowboy *> team_cowboy;
        Character *leader;
        int size;
        int size_ninja;
        int size_cowboy;

        Team(Ninja *leader);
        Team(Cowboy *leader);
        // Team(const Team &other);
        // Team(Team &&other) noexcept;
        ~Team();

        Team &operator=(const Team &other);
        bool operator==(const Team &other) const;

        void add(Ninja *player);
        void add(Cowboy *player);
        virtual void attack(Team *enemy);
        int stillAlive();
        void print();
    };

}
