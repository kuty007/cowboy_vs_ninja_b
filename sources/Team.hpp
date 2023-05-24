//
// Created by asaf7 on 5/9/2023.
//

#ifndef COWBOY_VS_NINJA_A_TEAM_HPP
#define COWBOY_VS_NINJA_A_TEAM_HPP

#include <algorithm>
#include <vector>
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

namespace ariel {

    class Team {
        int capacity;
        Character *leader;
        std::vector<Character *> team;
//    protected:
//
//        int capcity;
//        Character *leader;
//        std::vector<Character *> team;
    public:


        int getCapacity() const;

        void setCapacity(int capacity);

        vector<Character *> &getTeam();

        Character *getLeader() const;

        void setLeader(Character *leader);

        Team(Character *leader);

        virtual void add(Character *character);

        virtual void attack(Team *other);

        static bool compare(Character *a_c, Character *b_c);

        void print();

        static void sortVector(std::vector<Character *> &characters, bool (*compare)(Character *, Character *));

        int stillAlive();

        virtual ~Team();

        Team(const Team &) = default;

        Team &operator=(const Team &) = default;

        Team(Team &&) = default;

        Team &operator=(Team &&) = default;

    };

} // ariel

#endif //COWBOY_VS_NINJA_A_TEAM_HPP
