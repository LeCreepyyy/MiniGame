#include "algoLib.hpp"

Game::Game(void) {
    winner = 0;
    countBattle = 0;
    countRound = 0;
}

Game::~Game(void) {
    std::cout << "End of game" << std::endl;
}

void    Game::duel(t_data *data) {
    if (data->bld.deck1[0] > data->bld.deck2[0])
        ;
    else if (data->bld.deck1[0] < data->bld.deck2[0])
        ;
    else
        /*battle*/;
}
