#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Ambassador.hpp"

namespace coup{
        Ambassador::Ambassador(Game& game, std::string name): Player(game, std::move(name)){}
        void Ambassador::block(Player& player){
            std::cout << "Ambassador " << this->player_name << " blocks " << player.name() << " from stealing." << std::endl;
        }
        void Ambassador::transfer(Player& player, Player& target){
            std::cout << "Ambassador " << this->player_name << " transfers money from " << player.name() << " to " << target.name() << "." << std::endl;
        }

        void Ambassador::coup(Player& player){
            std::cout << "Ambassador " << this->player_name << " coup " << player.name() << "." << std::endl;
        }

};