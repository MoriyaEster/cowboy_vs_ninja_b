#include "Team.hpp"
#include <climits>

using namespace ariel;

Team::Team(Character *new_leader)
{
    if (new_leader == nullptr)
    {
        throw std::runtime_error("1The player is null");
    }

    if (new_leader->play_now)
    {
        throw std::runtime_error("The player is playing now");
    }

    new_leader->play_now = true;

    if ((dynamic_cast<Cowboy *>(new_leader)) != NULL)
    {
        this->leader = new_leader;
        team_cowboy.push_back(dynamic_cast<Cowboy *>(new_leader));
        this->size_cowboy = 1;
        this->size = 1;
    }
    if ((dynamic_cast<Ninja *>(new_leader)) != NULL)
    {
        this->leader = new_leader;
        team_ninja.push_back(dynamic_cast<Ninja *>(new_leader));
        this->size_ninja = 1;
        this->size = 1;
    }
    else
    {
        throw std::runtime_error("2The player is null");
    }
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

    for (size_t i = 0; i < size_ninja; i++)
    {
        team_ninja[i]->~Ninja();
    }
    team_ninja.clear();
    for (size_t j = 0; j < size_cowboy; j++)
    {
        team_cowboy[j]->~Cowboy();
    }
    team_cowboy.clear();
}

// Team &Team::operator=(const Team &other)
// {
//     printf("HAVE TO CHANGE: operator=(const Team &other)");
//     if (this != &other)
//     {
//         // delete leader;
//         // for (auto &player : team)
//         // {
//         //     delete player;
//         // }

//         // leader = other.leader->clone();
//         // team.clear();
//         // for (const auto &player : other.team)
//         // {
//         //     if (player != other.leader)
//         //     {
//         //         team.push_back(player->clone());
//         //     }
//         // }
//     }
//     return *this;
// }

// bool Team::operator==(const Team &other) const
// {
//     printf("HAVE TO CHANGE: operator==(const Team &other)");
//     // if (leader->getName() != other.leader->getName() || team.size() != other.team.size())
//     // {
//     //     return false;
//     // }

//     // for (size_t i = 0; i < team.size(); i++)
//     // {
//     //     if (*team[i] != *other.team[i])
//     //     {
//     //         return false;
//     //     }
//     // }
//     return true;
// }

void Team::add(Character *player)
{
    if (player == nullptr)
    {
        throw std::runtime_error("3The player is null");
    }
    if (player->play_now)
    {
        throw std::runtime_error("The player is playing now");
    }

    player->play_now = true;

    if (size >= 10)
    {
        throw std::overflow_error("The team is full");
    }
    if ((dynamic_cast<Cowboy *>(player)) != NULL)
    {
        team_cowboy.push_back((dynamic_cast<Cowboy *>(player)));
        size_cowboy++;
        size++;
    }
    if ((dynamic_cast<Ninja *>(player)) != NULL)
    {
        team_ninja.push_back((dynamic_cast<Ninja *>(player)));
        size_ninja++;
        size++;
    }
}

void Team::attack(Team *enemy)
{
    if (enemy == nullptr)
    {
        throw std::runtime_error("The team is null");
    }

    if (enemy->leader == nullptr)
    {
        throw std::runtime_error("The team is null");
    }

    if (!enemy->stillAlive())
    {
        throw std::runtime_error("the enemy died");
    }

    if (!enemy->leader->isAlive())
    {
        if ((dynamic_cast<Cowboy *>(enemy->leader)) != NULL)
        {
            enemy->size--;
            enemy->size_cowboy--;
        }
        if ((dynamic_cast<Ninja *>(enemy->leader)) != NULL)
        {
            enemy->size--;
            enemy->size_ninja--;
        }
        enemy->leader = close_player(enemy->leader);
    }

    Character *target = close_player(this->leader);
    if (target == nullptr)
    {
        throw std::runtime_error("the target");
    }

    for (size_t i = 0; i < size_cowboy; i++)
    {
        if (!target->isAlive())
        {
            if ((dynamic_cast<Cowboy *>(target)) != NULL)
            {
                enemy->size--;
                enemy->size_cowboy--;
            }
            if ((dynamic_cast<Ninja *>(target)) != NULL)
            {
                enemy->size--;
                enemy->size_ninja--;
            }
            target = close_player(this->leader);
        }

        if (team_cowboy[i]->isAlive())
        {
            if (!team_cowboy[i]->hasboolets())
                team_cowboy[i]->reload();
            team_cowboy[i]->shoot(target);
        }
    }
    for (size_t j = 0; j < size_ninja; j++)
    {
        if (!target->isAlive())
        {
            if ((dynamic_cast<Cowboy *>(target)) != NULL)
            {
                enemy->size--;
                enemy->size_cowboy--;
            }
            if ((dynamic_cast<Ninja *>(target)) != NULL)
            {
                enemy->size--;
                enemy->size_ninja--;
            }
            target = close_player(this->leader);
        }
        if (team_ninja[j]->isAlive())
        {
            if ((team_ninja[j]->distance(target)) < 1)
            {
                team_ninja[j]->slash(target);
            }
            team_ninja[j]->move(target);
        }
    }
}

int Team::stillAlive()
{
    int size_of_the_team = 0;
    int size_of_the_cowboys = 0;
    int size_of_the_ninjas = 0;
    for (size_t i = 0; i < team_cowboy.size(); i++)
    {
        if (team_cowboy[i]->isAlive())
        {
            size_of_the_cowboys++;
            size_of_the_team++;
        }
    }
    for (size_t j = 0; j < team_ninja.size(); j++)
    {
        if (team_ninja[j]->isAlive())
        {
            size_of_the_ninjas++;
            size_of_the_team++;
        }
    }
    return size_of_the_team;
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

Character *Team::close_player(Character *current_leader)
{
    if (current_leader == nullptr)
    {
        throw std::runtime_error("The team is null");
    }
    int min = INT_MAX;
    if (size_cowboy)
    {
        for (size_t i = 0; i < size_cowboy; i++)
        {
            if ((current_leader->distance(team_cowboy[i])) < min)
            {
                if ((team_cowboy[i])->isAlive())
                {
                    min = current_leader->distance(team_cowboy[i]);
                    return team_cowboy[i];
                }
            }
        }
    }
    if (size_ninja)
    {
        for (size_t j = 0; j < size_ninja; j++)
        {
            if ((current_leader->distance(team_ninja[j])) < min)
            {
                if ((team_ninja[j])->isAlive())
                {
                    min = current_leader->distance(team_ninja[j]);
                    return team_ninja[j];
                }
            }
        }
    }
    return NULL;
}