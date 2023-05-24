//
// Created by asaf7 on 5/9/2023.
//

#ifndef COWBOY_VS_NINJA_A_NINJA_HPP
#define COWBOY_VS_NINJA_A_NINJA_HPP

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
        // should be protected but tidy
        int speed;

    protected:
        Ninja(const string &name, const Point &location);
    public:

        void setSpeed(int speed);

        int getSpeed() const;

//        Ninja(const string &name, const Point &location);

        void move(const Character *other);

        void slash(Character *other);

        string print() const override;

        ~Ninja() override = default;

        Ninja(const Ninja &) = default;

        Ninja &operator=(const Ninja &) = default;

        Ninja(Ninja &&) = default;

        Ninja &operator=(Ninja &&) = default;

        void attack(Character *other) override;
    };


} // ariel

#endif //COWBOY_VS_NINJA_A_NINJA_HPP
