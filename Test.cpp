/**
 * Demo program for Coup exercise
 *
 * @author: Tal Zichlinsky
 * @since: 2022-02
 */

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include "doctest.h"
#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

TEST_CASE("one"){
    /**checking if game can be played with 1 or with more then 6 players - shood raise an error where there isn't enough players
     * or too many players
     **/
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    CHECK_THROWS(duke.income());
	Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    Ambassador ambassador2{game_1, "Meirav2"};
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    //checks new player with same name
    CHECK_THROWS(Contessa contessa(game_1, "Gilad"));
    CHECK_NOTHROW(contessa.income());
     //chek if can add more then 6 players
     for(int i = 0; i < 30; i++){
        CHECK_NOTHROW(Contessa contessa(game_1, "Gilad" + to_string(i)));
     }
    //check if game is still playable after decline the adding of new players
    CHECK_NOTHROW(ambassador2.income());
    //check if the turn loop closed after decline the adding new players
     CHECK_NOTHROW(duke.income());

}
TEST_CASE("two"){
    /**checking if you can add a player midd game - shood raise an error 
     **/
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    CHECK_THROWS(duke.income());
	Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    CHECK_NOTHROW(duke.income());
    CHECK_THROWS(Ambassador ambassador2(game_1, "Meirav2"));
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(duke.income());

}

TEST_CASE("three"){
    /** adding two players and check income works
     **/
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK(duke.coins() == 1);
    CHECK(assassin.coins() == 1);
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK(duke.coins() == 2);
    CHECK(assassin.coins() == 2);
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK(duke.coins() == 3);
    CHECK(assassin.coins() == 3);
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK(duke.coins() == 4);
    CHECK(assassin.coins() == 4);

}
TEST_CASE("four"){
    /** testing player type
     **/
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    CHECK(duke.get_player_type() == "Duke");
    Assassin assassin{game_1, "Yossi"};
    CHECK(assassin.get_player_type() == "Assassin");
    Ambassador ambassador{game_1, "Meirav"};
    CHECK(ambassador.get_player_type() == "Ambassador");
    Captain captain{game_1, "Reut"};
    CHECK(captain.get_player_type() == "Captain");
    Contessa contessa{game_1, "Gilad"};
    CHECK(contessa.get_player_type() == "Contessa");

}
TEST_CASE("five"){
    /** testing foreign_aid**/
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK(duke.coins() == 2);
    CHECK(assassin.coins() == 2);
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK(duke.coins() == 4);
    CHECK(assassin.coins() == 4);
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK(duke.coins() == 6);
    CHECK(assassin.coins() == 6);
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK(duke.coins() == 8);
    CHECK(assassin.coins() == 8);
}
TEST_CASE("five"){
    /** testing turn working**/
    Game game_1{};
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    CHECK(game_1.turn() == "Moshe");
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());
    CHECK(game_1.turn() == "Moshe");
    CHECK_NOTHROW(duke.income());
    CHECK(game_1.turn() == "Yossi");
    CHECK_NOTHROW(assassin.income());
    CHECK(game_1.turn() == "Reut");
    CHECK_NOTHROW(captain.income());
    CHECK(game_1.turn() == "Gilad");
    CHECK_NOTHROW(contessa.income());
    CHECK(game_1.turn() == "Moshe");
}
