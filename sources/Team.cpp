#include "Team.hpp"

using namespace ariel;

Team::Team(Ninja *leader)
    : leader(leader)
{
    team_ninja.push_back(leader);
    size_ninja++;
    size++;
}

Team::Team(Cowboy *leader)
    : leader(leader)
{
    team_cowboy.push_back(leader);
    size_cowboy++;
    size++;
}

// Team::Team(const Team &other)
// {
//     // Copy the leader
//     if (dynamic_cast<Ninja *>(other.leader))
//     {
//         Ninja *ninjaLeader = dynamic_cast<Ninja *>(other.leader);
//         leader = new Ninja(*ninjaLeader);
//     }
//     else if (dynamic_cast<Cowboy *>(other.leader))
//     {
//         Cowboy *cowboyLeader = dynamic_cast<Cowboy *>(other.leader);
//         leader = new Cowboy(*cowboyLeader);
//     }

//     // Copy the ninja team
//     for (Ninja *ninja : other.team_ninja)
//     {
//         team_ninja.push_back(new Ninja(*ninja));
//     }

//     // Copy the cowboy team
//     for (Cowboy *cowboy : other.team_cowboy)
//     {
//         team_cowboy.push_back(new Cowboy(*cowboy));
//     }

//     size = other.size;
//     size_ninja = other.size_ninja;
//     size_cowboy = other.size_cowboy;
// }

// Team::Team(Team &&other) noexcept
//     : leader(other.leader), team_ninja(std::move(other.team_ninja)),
//       team_cowboy(std::move(other.team_cowboy)), size(other.size),
//       size_ninja(other.size_ninja), size_cowboy(other.size_cowboy)
// {
//     other.leader = nullptr;
//     other.size = 0;
//     other.size_ninja = 0;
//     other.size_cowboy = 0;
// }

Team::~Team()
{
    if (size > 0)
    {
        for (size_t i = 0; i < size_ninja; i++)
        {
            team_ninja[i]->~Ninja();
        }
        for (size_t i = 0; i < size_cowboy; i++)
        {
            team_cowboy[i]->~Cowboy();
        }
    }
}

Team &Team::operator=(const Team &other)
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

bool Team::operator==(const Team &other) const
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

void Team::add(Ninja *player)
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
        size_ninja++;
        size++;
    }
}

void Team::add(Cowboy *player)
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
        size_cowboy++;
        size++;
    }
}

void Team::attack(Team *enemy)
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
    for (size_t i = 0; i < size_cowboy; i++)
    {
        team_cowboy[i]->print();
    }

    for (size_t i = 0; i < size_ninja; i++)
    {
        team_ninja[i]->print();
    }
}