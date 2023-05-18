#include "Team.hpp"

using namespace ariel;

Team::Team(Character *leader)
    : leader(leader)
{
}

Team::~Team()
{
    if (size > 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            team[i]->~Character();
        }
    }
}

Team &Team::operator=(const Team &other)
{
    printf("HAVE TO CHANGE");
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

bool Team::operator==(const Team &other) const
{
    if (leader->getName() != other.leader->getName() || team.size() != other.team.size())
    {
        return false;
    }

    for (size_t i = 0; i < team.size(); i++)
    {
        if (*team[i] != *other.team[i])
        {
            return false;
        }
    }
    return true;
}

void Team::add(Character *player)
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
        team.push_back(player);
        size++;
    }
}

void Team::attack(Team *enemy)
{
}

int Team::stillAlive()
{
    if (size == 0)
    {
        return false;
    }
    return true;
}

void Team::print()
{
    for (size_t i = 0; i < size; i++)
    {
        team[i]->print();
    }
}