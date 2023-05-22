#include "Team.hpp"
#include <climits>

using namespace ariel;

Team::Team(Character *new_leader)
    : leader(new_leader)
{
    if (new_leader == nullptr)
    {
        throw std::runtime_error("1The new_leader is null");
    }

    if (new_leader->play_now)
    {
        throw std::runtime_error("The new_leader is playing now");
    }

    new_leader->play_now = true;
    Ninja *ninjaptr = dynamic_cast<Ninja *>(new_leader);
    Cowboy *cowboyptr = dynamic_cast<Cowboy *>(new_leader);

    if (ninjaptr != nullptr)
    {
        if (ninjaptr != nullptr)
        {
            team_ninja.push_back(ninjaptr);
            this->size_ninja = 1;
            this->size = 1;
        }
    }

    else if (cowboyptr != nullptr)
    {
        if (cowboyptr != nullptr)
        {
            team_cowboy.push_back(cowboyptr);
            this->size_cowboy = 1;
            this->size = 1;
        }
    }
    else if (ninjaptr == nullptr && cowboyptr == nullptr)
    {
        throw std::runtime_error("The new_leader is null");
    }
}

Team::~Team()
{

    for (size_t i = 0; i < team_ninja.size(); i++)
    {
        team_ninja[i]->~Ninja();
    }
    team_ninja.clear();
    for (size_t j = 0; j < team_cowboy.size(); j++)
    {
        team_cowboy[j]->~Cowboy();
    }
    team_cowboy.clear();
}

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
        size_ninja++;
        size++;
    }
    else if (cowboy != nullptr)
    {
        team_cowboy.push_back(cowboy);
        size_cowboy++;
        size++;
    }
    else if (cowboy == nullptr && ninja == nullptr)
    {
        throw std::runtime_error("The player is null");
    }
}

void Team::attack(Team *enemy)
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

    if (!enemy->leader->isAlive())
    {
        enemy->leader = close_player(enemy->leader);
        if (enemy->leader == nullptr)
        {
            throw std::runtime_error("the leade is null");
        }
    }

    Character *target = close_player(this->leader);

    if (target == nullptr)
    {
        throw std::runtime_error("target is null");
    }

    for (size_t i = 0; i < team_cowboy.size(); i++)
    {
        if (enemy->stillAlive() <= 0)
        {
            return;
        }
        if (!target->isAlive())
        {
            target = close_player(this->leader);

            if (target == nullptr)
            {
                throw std::runtime_error("target is null");
            }
        }
        if (!team_cowboy[i]->isAlive())
        {
            throw std::runtime_error("the cowboy is dead");
        }

        else
        {
            if (!team_cowboy[i]->hasboolets())
                team_cowboy[i]->reload();
            team_cowboy[i]->shoot(target);
        }
    }

    for (size_t j = 0; j < team_ninja.size(); j++)
    {
        if (enemy->stillAlive() <= 0)
        {
            return;
        }
        if (!target->isAlive())
        {
            target = close_player(this->leader);
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
    // for (size_t i = 0; i < size_cowboy; i++)
    // {
    //     team_cowboy[i]->print();
    // }

    // for (size_t i = 0; i < size_ninja; i++)
    // {
    //     team_ninja[i]->print();
    // }
}

Character *Team::close_player(Character *current_leader)
{
    if (current_leader == nullptr)
    {
        throw std::runtime_error("The team is null");
    }
    int min = INT_MAX;
    Character *closet_target = current_leader;

    for (size_t i = 0; i < team_cowboy.size(); i++)
    {
        if ((current_leader->distance(team_cowboy[i])) < min)
        {
            if ((team_cowboy[i])->isAlive())
            {
                min = current_leader->distance(team_cowboy[i]);
                closet_target = team_cowboy[i];
            }
        }
    }
    
    for (size_t j = 0; j < team_ninja.size(); j++)
    {
        if ((current_leader->distance(team_ninja[j])) < min)
        {
            if ((team_ninja[j])->isAlive())
            {
                min = current_leader->distance(team_ninja[j]);
                closet_target = team_ninja[j];
            }
        }
    }

    return closet_target;
}