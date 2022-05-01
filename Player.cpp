#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{

        void Player::income(){
            this->player_coins += 1;
            std::cout << "Income" << std::endl;
        }

        void Player::foreign_aid(){
            this->player_coins += 2;
            std::cout << "Foreign Aid" << std::endl;
        }

        int  Player::coins() const{return this->player_coins;}

        std::string Player::name() const{return this->player_name;}

        bool Player::get_is_alive() const{return this->is_alive;}
        
        void Player::set_is_alive (bool is_alive_to_set){this->is_alive = is_alive_to_set;}

        void Player::coup(Player& player){
            std::cout<< this->player_name << "Coup" << player.name() << std::endl;
        }

        std::string Player::get_player_type() const{return this->player_type;}

        void Player::set_player_type(std::string player_type_to_set){this->player_type = std::move(player_type_to_set);}


};