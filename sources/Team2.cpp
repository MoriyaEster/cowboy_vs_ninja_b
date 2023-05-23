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
            if (team_ninja[j]->isAlive())
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
            if (team_cowboy[k]->isAlive())
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

int Team2::stillAlive()
{
    int size_of_the_team = 0;
    int size_of_the_cowboys = 0;
    int size_of_the_ninjas = 0;

    int who_now;
    size_t j = 0;
    size_t k = 0;

    for (size_t i = 0; i < order.size(); i++)
    {
        who_now = order[i];
        if (who_now == 0)
        {
            if (team_cowboy[j]->isAlive())
            {
                size_of_the_cowboys++;
                size_of_the_team++;
            }
            j++;
        }
        if (who_now == 1)
        {
            if (team_ninja[k]->isAlive())
            {
                size_of_the_ninjas++;
                size_of_the_team++;
            }
            k++;
        }
    }

    return size_of_the_team;
}

void Team2::print()
{
    int who_now;
    size_t j = 0;
    size_t k = 0;
    for (size_t i = 0; i < order.size(); i++)
    {
        who_now = order[i];
        if (who_now == 0)
        {
            team_cowboy[j]->print();
        }
        else if (who_now == 1)
        {
            team_ninja[k]->print();
        }
    }
}

    Character *Team2::close_player(Team * team)
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

        for (size_t i = 0; i < team->order.size(); i++)
        {
            who_now = team->order[i];
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