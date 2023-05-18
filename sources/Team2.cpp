#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Ninja *leader)
    : Team(leader)
{
    team_ninja.push_back(leader);
    order.push_back(1);
    size_ninja++;
    size++;
}

Team2::Team2(Cowboy *leader)
    : Team(leader)
{
    team_cowboy.push_back(leader);
    order.push_back(2);
    size_cowboy++;
    size++;
}

Team2::~Team2()
{
    if (size > 0)
    {
        for (size_t i = 0; i < size_ninja; i++)
        {
            team_ninja[i]->~Ninja();
            size--;
        }
        for (size_t i = 0; i < size_cowboy; i++)
        {
            team_cowboy[i]->~Cowboy();
            size--;
        }
    }
}

Team2 &Team2::operator=(const Team2 &other)
{
    printf("HAVE TO CHANGE: operator=(const Team &other)");
    if (this != &other)
    {
        // delete leader;
        // for (auto &player : team)
        // {
        //     delete player;
        // }

        // leader = other.leader->clone();
        // team.clear();
        // for (const auto &player : other.team)
        // {
        //     if (player != other.leader)
        //     {
        //         team.push_back(player->clone());
        //     }
        // }
    }
    return *this;
}

bool Team2::operator==(const Team2 &other) const
{
    printf("HAVE TO CHANGE: operator==(const Team &other)");
    // if (leader->getName() != other.leader->getName() || team.size() != other.team.size())
    // {
    //     return false;
    // }

    // for (size_t i = 0; i < team.size(); i++)
    // {
    //     if (*team[i] != *other.team[i])
    //     {
    //         return false;
    //     }
    // }
    return true;
}

void Team2::add(Ninja *player)
{
    if (size <= 0)
    {
        throw std::runtime_error("There is no leader to the team");
    }
    if (size >= 10)
    {
        throw std::overflow_error("The team is full");
    }
    else
    {
        team_ninja.push_back(player);
        order.push_back(1);
        size_ninja++;
        size++;
    }
}

void Team2::add(Cowboy *player)
{
    if (size <= 0)
    {
        throw std::runtime_error("There is no leader to the team");
    }
    if (size >= 10)
    {
        throw std::overflow_error("The team is full");
    }
    else
    {
        team_cowboy.push_back(player);
        order.push_back(2);
        size_cowboy++;
        size++;
    }
}

void Team2::attack(Team *enemy)
{
    // if (size_cowboy)
    // {
    //     team_cowboy.pop_back();
    //     size_cowboy--;
    //     size--;
    // }
    // if (size_ninja)
    // {
    //     team_ninja.pop_back();
    //     size_ninja--;
    //     size--;
    // }
}

int Team2::stillAlive()
{
    if (size == 0)
    {
        return false;
    }
    return true;
}

void Team2::print()
{
    int size_to_print = size;
    while (size_to_print > 0)
    {
        if (order.size())
        {
            int order_num = order[0];
            order.erase(order.begin());
            size_to_print--;
            size_t i = 0;
            size_t j = 0;
            if ((order_num == 1) && (i < size_cowboy))
            {
                team_cowboy[i]->print();
                i++;
            }
            if ((order_num == 2) && (j < size_ninja))
            {
                team_ninja[j]->print();
                j++;
            }
        }
    }
}