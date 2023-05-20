#include "Team2.hpp"
#include <climits>

using namespace ariel;

// Team2::Team2(Ninja *leader)
//     : Team(leader)
// {
//     team_ninja.push_back(leader);
//     order.push_back(1);
//     size_ninja++;
//     size++;
// }

// Team2::Team2(Cowboy *leader)
//     : Team(leader)
// {
//     team_cowboy.push_back(leader);
//     order.push_back(2);
//     size_cowboy++;
//     size++;
// }

Team2::Team2(Character *new_leader)
    : Team(new_leader)
{
    if (new_leader->play_now)
    {
        throw std::runtime_error("The player is playing now");
    }
    new_leader->play_now = true;
    if ((dynamic_cast<Cowboy *>(new_leader)) != NULL)
    {
        printf("the leader is coeboy\n");
        this->leader = new_leader;
        team_cowboy.push_back(dynamic_cast<Cowboy *>(new_leader));
        size_cowboy++;
        size++;
    }
    if ((dynamic_cast<Ninja *>(new_leader)) != NULL)
    {
        printf("the leader is ninja\n");
        this->leader = new_leader;
        team_ninja.push_back(dynamic_cast<Ninja *>(new_leader));
        size_ninja++;
        size++;
    }
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

// void Team2::add(Ninja *player)
// {
//     if (size <= 0)
//     {
//         throw std::runtime_error("There is no leader to the team");
//     }
//     if (size >= 10)
//     {
//         throw std::overflow_error("The team is full");
//     }
//     else
//     {
//         team_ninja.push_back(player);
//         order.push_back(1);
//         size_ninja++;
//         size++;
//     }
// }

// void Team2::add(Cowboy *player)
// {
//     if (size <= 0)
//     {
//         throw std::runtime_error("There is no leader to the team");
//     }
//     if (size >= 10)
//     {
//         throw std::overflow_error("The team is full");
//     }
//     else
//     {
//         team_cowboy.push_back(player);
//         order.push_back(2);
//         size_cowboy++;
//         size++;
//     }
// }

void Team2::add(Character *player)
{
    if (player->play_now)
    {
        throw std::runtime_error("The player is playing now");
    }
    player->play_now = true;
    if (size <= 0)
    {
        throw std::runtime_error("There is no leader to the team");
    }
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

void Team2::attack(Team *enemy)
{
    printf("attack");
    if (!enemy->stillAlive())
    {
        printf("the enemy died\n");
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

int Team2::stillAlive()
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

Character *Team2::close_player(Character *current_leader)
{
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