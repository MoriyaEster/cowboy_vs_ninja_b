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
        std::vector<int> order;

        Team2(Character *new_leader);
        virtual ~Team2();

        // virtual Team2 &operator=(const Team2 &other);
        // virtual bool operator==(const Team2 &other) const;

        virtual void add(Character *player) override;
        virtual void attack(Team *enemy) override;
        // virtual void print() override;

        virtual Character *close_player(Team *enemy) override;
    };

}
