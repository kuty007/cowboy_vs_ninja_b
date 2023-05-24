//
// Created by asaf7 on 5/9/2023.
//

#ifndef COWBOY_VS_NINJA_A_COWBOY_HPP
#define COWBOY_VS_NINJA_A_COWBOY_HPP

#include "Character.hpp"

namespace ariel {

    class Cowboy : public Character {
        //this class is inherited from Character
    private:
        int ammo;
    public:
        Cowboy(const std::string &name, const Point &location);

        Cowboy(const Cowboy &) = default;

        Cowboy &operator=(const Cowboy &) = default;

        Cowboy(Cowboy &&) = default;

        Cowboy &operator=(Cowboy &&) = default;

        // shoot get a pointer to a Character and hit him with 10 damage
        void shoot(Character *enemy);

        void reload();

        string print() const override;



        ~Cowboy() override = default;

        void attack(Character *other) override;

        bool hasboolets() const;

    }; // ariel

} // namespace ariel

#endif //COWBOY_VS_NINJA_A_COWBOY_HPP
