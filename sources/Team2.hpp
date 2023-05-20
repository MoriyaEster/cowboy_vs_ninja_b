#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <vector>

#include "Team.hpp"
namespace ariel
{

    class Team2 : public Team
    {
    public:
        std::vector<Ninja *> team_ninja;
        std::vector<Cowboy *> team_cowboy;
        std::vector<int> order;
        Character *leader;
        int size;
        int size_ninja;
        int size_cowboy;

        // Team2(Ninja *leader);
        // Team2(Cowboy *leader);
        Team2(Character *new_leader);
        virtual ~Team2();

        virtual Team2 &operator=(const Team2 &other);
        virtual bool operator==(const Team2 &other) const;

        // virtual void add(Ninja *player);
        // virtual void add(Cowboy *player);
        virtual void add(Character *player) override;
        virtual void attack(Team *enemy) override;
        virtual int stillAlive() override;
        virtual void print() override;

        virtual Character *close_player(Character *current_leader) override;
    };

}
