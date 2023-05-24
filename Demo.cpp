/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <stdexcept>
#include <cassert>

using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/SmartTeam.h"

using namespace ariel;


int main() {
    Point a(32.3, 44), b(1.3, 3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() << endl;

    sushi->move(tom);
    sushi->slash(tom);

    Team team_A(tom);
    team_A.add(new YoungNinja("Yogi", Point(64, 57)));


    // Team b(tom); should throw tom is already in team a

    Team team_B(sushi);
    team_B.add(new TrainedNinja("Hikari", Point(12, 81)));


    while (team_A.stillAlive() > 0 && team_B.stillAlive() > 0) {
        team_A.attack(&team_B);
        team_B.attack(&team_A);
        cout << " team a"<< endl;
        team_A.print();
        cout << " team b"<< endl;
        team_B.print();
    }

    if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
    else cout << "winner is team_B" << endl;

//    Point c(0, 0), d(0, 2), f(0, 100);
//    Point e{c.moveTowards(d, 2)};

//
//    cout << e.print() << endl;
//    cout << d.print() << endl;
//    cout << c.print() << endl;
//    Point g{e.moveTowards(f, 55)};
//    cout << e.print() << endl;
//    cout << d.print() << endl;
//    cout<<&e<<endl;
//    cout<<&d<<endl;
//    e = g;
//    cout<<&e<<endl;
//    cout<<&d<<endl;
//    cout << &g << endl;
//    cout <<e.print() << endl;
//    cout << d.print() << endl;
//    cout << g.print() << endl;



//    // build SmartTeam and Team
//    SmartTeam smartTeam_A(new Cowboy("smartTom", Point(-1004, 1)));
//    smartTeam_A.add(new TrainedNinja("smartTom", Point(237, 543)));// should throw tom is already in team a
//    smartTeam_A.add(new YoungNinja("smartYogi", Point(413, 12)));
//    smartTeam_A.add(new TrainedNinja("smartHikari", Point(45, 16)));
//    smartTeam_A.add(new OldNinja("smartSushi", Point(184, 100)));
//    smartTeam_A.add(new Cowboy("smartSusdhi", Point(54, -100)));// should throw sushi is already in team a
//
//    Team team_A2(new Cowboy("Tom", Point(1004, 1)));
//    team_A2.add(new Cowboy("Tom", Point(-237, 543)));
//    team_A2.add(new TrainedNinja("Hikari", Point(45, 16)));// should throw tom is already in team a
//    team_A2.add(new YoungNinja("Yogi", Point(-413, 12)));
//    team_A2.add(new YoungNinja("Yogi", Point(-13, 12)));
//    team_A2.add(new TrainedNinja("Hikari", Point(-45, 16)));
//    team_A2.add(new OldNinja("Sushi", Point(-184, 100)));
//    team_A2.add(new OldNinja("Susdhi", Point(-184, 100)));// should throw sushi is already in team a
//    while (smartTeam_A.stillAlive() > 0 && team_A2.stillAlive() > 0) {
//        team_A2.attack(&smartTeam_A);
//        smartTeam_A.attack(&team_A2);
//
//
//        smartTeam_A.print();
//        team_A2.print();
//    }
//    if (smartTeam_A.stillAlive() > 0) cout << "winner is smartTeam_A" << endl;
//    else cout << "winner is team_A2" << endl;


    return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

}
