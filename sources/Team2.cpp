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

// Team2 &Team2::operator=(const Team2 &other)
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

// bool Team2::operator==(const Team2 &other) const
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

// void Team2::add(Character *player)
// {
    // if (player->play_now)
    // {
    //     throw std::runtime_error("The player is playing now");
    // }
    // if (player == nullptr)
    // {
    //     throw std::runtime_error("The player is null");
    // }
    
    // player->play_now = true;

    // if (size >= 10)
    // {
    //     throw std::overflow_error("The team is full");
    // }
    // if ((dynamic_cast<Cowboy *>(player)) != NULL)
    // {
    //     team_cowboy.push_back((dynamic_cast<Cowboy *>(player)));
    //     size_cowboy++;
    //     size++;
    // }
    // if ((dynamic_cast<Ninja *>(player)) != NULL)
    // {
    //     team_ninja.push_back((dynamic_cast<Ninja *>(player)));
    //     size_ninja++;
    //     size++;
    // }
// }

// void Team2::attack(Team *enemy)
// {
    // printf("attack");
    // if (!enemy->stillAlive())
    // {
    //     printf("the enemy died\n");
    // }
    // if (!enemy->leader->isAlive())
    // {
    //     if ((dynamic_cast<Cowboy *>(enemy->leader)) != NULL)
    //     {
    //         enemy->size--;
    //         enemy->size_cowboy--;
    //     }
    //     if ((dynamic_cast<Ninja *>(enemy->leader)) != NULL)
    //     {
    //         enemy->size--;
    //         enemy->size_ninja--;
    //     }
    //     enemy->leader = close_player(enemy->leader);
    // }

    // Character *target = close_player(this->leader);

    // for (size_t i = 0; i < size_cowboy; i++)
    // {
    //     if (!target->isAlive())
    //     {
    //         if ((dynamic_cast<Cowboy *>(target)) != NULL)
    //         {
    //             enemy->size--;
    //             enemy->size_cowboy--;
    //         }
    //         if ((dynamic_cast<Ninja *>(target)) != NULL)
    //         {
    //             enemy->size--;
    //             enemy->size_ninja--;
    //         }
    //         target = close_player(this->leader);
    //     }

    //     if (team_cowboy[i]->isAlive())
    //     {
    //         if (!team_cowboy[i]->hasboolets())
    //             team_cowboy[i]->reload();
    //         team_cowboy[i]->shoot(target);
    //     }
    // }
    // for (size_t j = 0; j < size_ninja; j++)
    // {
    //     if (!target->isAlive())
    //     {
    //         if ((dynamic_cast<Cowboy *>(target)) != NULL)
    //         {
    //             enemy->size--;
    //             enemy->size_cowboy--;
    //         }
    //         if ((dynamic_cast<Ninja *>(target)) != NULL)
    //         {
    //             enemy->size--;
    //             enemy->size_ninja--;
    //         }
    //         target = close_player(this->leader);
    //     }
    //     if (team_ninja[j]->isAlive())
    //     {
    //         if ((team_ninja[j]->distance(target)) < 1)
    //         {
    //             team_ninja[j]->slash(target);
    //         }
    //         team_ninja[j]->move(target);
    //     }
    // }
// }

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

// Character *Team2::close_player(Character *current_leader)
// {
    // int min = INT_MAX;
    // if (size_cowboy)
    // {
    //     for (size_t i = 0; i < size_cowboy; i++)
    //     {
    //         if ((current_leader->distance(team_cowboy[i])) < min)
    //         {
    //             if ((team_cowboy[i])->isAlive())
    //             {
    //                 min = current_leader->distance(team_cowboy[i]);
    //                 return team_cowboy[i];
    //             }
    //         }
    //     }
    // }
    // if (size_ninja)
    // {
    //     for (size_t j = 0; j < size_ninja; j++)
    //     {
    //         if ((current_leader->distance(team_ninja[j])) < min)
    //         {
    //             if ((team_ninja[j])->isAlive())
    //             {
    //                 min = current_leader->distance(team_ninja[j]);
    //                 return team_ninja[j];
    //             }
    //         }
    //     }
    // }
    // return NULL;
// }