#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Game.hpp"
#include "Player.hpp"
#include "Duke.hpp"

namespace coup{
        Duke::Duke(Game& game, std::string name): Player(game, std::move(name)){}        
        void Duke::block(Player& player){
            std::cout << "Duke " << this->player_name << " blocks " << player.name() << " from foreign_aid." << std::endl;
        }
        void Duke::tax(){
            std::cout << "Duke " << this->player_name << " gets tax." << std::endl;
        }
        void Duke::coup(Player& player) {
            std::cout << "Duke " << this->player_name << " coup " << player.name() << "." << std::endl;
        }
};