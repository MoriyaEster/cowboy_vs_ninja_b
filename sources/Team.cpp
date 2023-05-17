#include "Team.hpp"

using namespace ariel;

Team::Team(Character *leader)
    : leader(leader)
{
}

// Team::Team(const Team &other)
// {
//     leader = other.leader->clone();
//     for (const auto &player : other.team)
//     {
//         if (player != other.leader)
//         {
//             team.push_back(player->clone());
//         }
//     }
// }

// Team::~Team()
// {
// }

// Team &Team::operator=(const Team &other)
// {
//     if (this != &other)
//     {
//         delete leader;
//         for (auto &player : team)
//         {
//             delete player;
//         }

//         leader = other.leader->clone();
//         team.clear();
//         for (const auto &player : other.team)
//         {
//             if (player != other.leader)
//             {
//                 team.push_back(player->clone());
//             }
//         }
//     }
//     return *this;
// }

// bool Team::operator==(const Team &other) const
// {
//     if (leader->getName() != other.leader->getName() || team.size() != other.team.size())
//     {
//         return false;
//     }

//     for (size_t i = 0; i < team.size(); i++)
//     {
//         if (*team[i] != *other.team[i])
//         {
//             return false;
//         }
//     }

//     return true;
// }

void Team::add(Character *player)
{
}

void Team::attack(Team *enemy)
{
}

int Team::stillAlive()
{
    return 0;
}

void Team::print()
{
}