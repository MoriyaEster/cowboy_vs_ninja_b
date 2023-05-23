#include "Team2.hpp"
#include <climits>

using namespace ariel;

Team2::Team2(Character *new_leader)
    : Team(new_leader)
{
}

Team2::~Team2()
{
}

void Team2::add(Character *player)
{
    if (player == nullptr)
    {
        throw std::runtime_error("3The player is null");
    }
    if (player->play_now)
    {
        throw std::runtime_error("The player is playing now");
    }
    if (size >= 10)
    {
        throw std::overflow_error("The team is full");
    }

    player->play_now = true;
    Ninja *ninja = dynamic_cast<Ninja *>(player);
    Cowboy *cowboy = dynamic_cast<Cowboy *>(player);

    if (ninja != nullptr)
    {
        team_ninja.push_back(ninja);
        order.push_back(1);
        size_ninja++;
        size++;
    }
    else if (cowboy != nullptr)
    {
        team_cowboy.push_back(cowboy);
        order.push_back(0);
        size_cowboy++;
        size++;
    }
    else if (cowboy == nullptr && ninja == nullptr)
    {
        throw std::runtime_error("The player is null");
    }
}

void Team2::attack(Team *enemy)
{
    if (enemy == nullptr)
    {
        throw std::invalid_argument("The team is null");
    }

    if (enemy->leader == nullptr)
    {
        throw std::runtime_error("The team is null");
    }

    if (enemy->stillAlive() <= 0)
    {
        throw std::runtime_error("the enemy died");
    }

    if (this->stillAlive() <= 0)
    {
        throw std::runtime_error("the team died");
    }

    if (!this->leader->isAlive())
    {
        this->leader = close_player(this);
        if (this->leader == nullptr)
        {
            throw std::runtime_error("the leade is null");
        }
    }

    Character *target = close_player(enemy);

    if (target == nullptr)
    {
        throw std::runtime_error("target is null");
    }

    int who_attack_now;
    size_t j = 0;
    size_t k = 0;

    for (size_t i = 0; i < order.size(); i++)
    {
        who_attack_now = order[i];
        if (who_attack_now == 1)
        {
            if (enemy->stillAlive() <= 0)
            {
                return;
            }
            if (!target->isAlive())
            {
                target = close_player(enemy);
                if (target == nullptr)
                {
                    throw std::runtime_error("target is null");
                }
            }
            if (!team_ninja[j]->isAlive())
            {
                throw std::runtime_error("the ninja is dead");
            }

            else
            {
                target = close_player(enemy);
                if (target == nullptr)
                {
                    throw std::runtime_error("target is null");
                }
                if ((team_ninja[j]->distance(target)) < 1)
                {
                    team_ninja[j]->slash(target);
                }
                else
                {
                    team_ninja[j]->move(target);
                }
            }
            j++;
        }

        if (who_attack_now == 0)
        {
            if (enemy->stillAlive() <= 0)
            {
                return;
            }
            if (!target->isAlive())
            {
                target = close_player(enemy);

                if (target == nullptr)
                {
                    throw std::runtime_error("target is null");
                }
            }
            if (!team_cowboy[k]->isAlive())
            {
                throw std::runtime_error("the cowboy is dead");
            }

            else
            {
                target = close_player(enemy);
                if (target == nullptr)
                {
                    throw std::runtime_error("target is null");
                }
                if (!team_cowboy[k]->hasboolets())
                    team_cowboy[k]->reload();
                else if (team_cowboy[k] != target)
                {
                    team_cowboy[k]->shoot(target);
                }
            }
            k++;
        }
    }
}

// void Team2::print()
// {
// int size_to_print = size;
// while (size_to_print > 0)
// {
//     if (order.size())
//     {
//         int order_num = order[0];
//         order.erase(order.begin());
//         size_to_print--;
//         size_t i = 0;
//         size_t j = 0;
//         if ((order_num == 1) && (i < size_cowboy))
//         {
//             team_cowboy[i]->print();
//             i++;
//         }
//         if ((order_num == 2) && (j < size_ninja))
//         {
//             team_ninja[j]->print();
//             j++;
//         }
//     }
// }
// }

Character *Team2::close_player(Team *team)
{
    if (team == nullptr)
    {
        throw std::runtime_error("The team is null");
    }
    int min = INT_MAX;
    Character *closet_target = this->leader;

    int who_now;
    size_t j = 0;
    size_t k = 0;
    for (size_t i = 0; i < order.size(); i++)
    {
        who_now = order[i];
        if (who_now == 0)
        {
            if ((this->leader->distance(team->team_cowboy[j])) < min)
            {
                if ((team->team_cowboy[j])->isAlive())
                {
                    min = this->leader->distance(team->team_cowboy[j]);
                    closet_target = team->team_cowboy[j];
                }
            }
            j++;
        }
        if (who_now == 1)
        {
            if ((this->leader->distance(team->team_ninja[k])) < min)
            {
                if ((team->team_ninja[k])->isAlive())
                {
                    min = this->leader->distance(team->team_ninja[k]);
                    closet_target = team->team_ninja[k];
                }
            }
            k++;
        }
    }
    return closet_target;
}