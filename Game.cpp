#include "algoLib.hpp"

Game::Game(void) {
    winner = 0;
    countDuel = 0;
    countBattle = 0;
    countRound = 0;
}

Game::~Game(void) {
    std::cout << "End of game" << std::endl;
}

void    Game::duel(t_data *data) {
    countDuel++;
    if (data->bld.deck1[0] < data->bld.deck2[0])
        data->bld.setCard(data->bld.deck1[0], data->bld.deck2[0], 1);
    else if (data->bld.deck1[0] > data->bld.deck2[0])
        data->bld.setCard(data->bld.deck2[0], data->bld.deck1[0], 2);
    else
        /*battle*/;
}

void    Game::battle(t_data *data) {
    countBattle++;
    
}
