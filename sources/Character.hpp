//
// Created by asaf7 on 5/9/2023.
//

#ifndef COWBOY_VS_NINJA_A_CHARACTER_HPP
#define COWBOY_VS_NINJA_A_CHARACTER_HPP

#include "Point.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <vector>

using namespace std;

namespace ariel {

    class Character {
        // should be protected but tidy
        Point location;
        int health_points;
        std::string name;
        bool alive;
        bool belong_to_team;
        bool is_cowboy;
    public:
        bool isCowboy() const;
        void setIsCowboy(bool isCowboy);

        Character(const std::string &name, const Point &location, int health_points);

        const Point &getLocation() const;

        bool getBelongToTeam() const;

        void setBelongToTeam(bool belongToTeam);

        bool isAlive() const;

        double distance(Character const *other ) ;

        void hit(int damage);

        const std::string &getName() const;

        virtual string print() const = 0;

        virtual ~Character() = default;

        int getHealthPoints() const;

        void setHealthPoints(int healthPoints);

        void setLocation(const Point &location);
        Character* getNearestCharacter(const std::vector<Character*>& characters) const;

        virtual void attack(Character* other) = 0;
        void setAlive(bool alive);

        Character(const Character&) = default;
        Character& operator=(const Character&) = default;

        Character(Character&&) = default;
        Character& operator=(Character&&) = default;

    };

} // ariel

#endif //COWBOY_VS_NINJA_A_CHARACTER_HPP
