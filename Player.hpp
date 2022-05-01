#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#pragma once

namespace coup{
    class Player{
        protected:
            Game& player_game;
            std::string player_name;
            int player_coins;
            bool is_alive;
            std::string player_type;

        public:
            explicit Player(Game& game_to_set, std::string name_to_set): player_game(game_to_set), player_name(name_to_set){}
            void income();//done
            void foreign_aid();//done
            virtual void coup(Player& player);//done
            int coins () const;
            std::string name() const;//done

            bool get_is_alive() const;
            void set_is_alive(bool is_alive_to_set);
            std::string get_player_type() const;
            void set_player_type(std::string player_type_to_set);
    };
};