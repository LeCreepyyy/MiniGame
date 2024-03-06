/**
 * Creator :
 * Axoux & Creepy
*/

#include "algoLib.hpp"

int main(void) {
    t_data data;
    if (data.bld.setValueInDeck() == false)
        return (EXIT_FAILURE);
    while (data.game.winner != 1) {
        data.game.duel(&data);
    }
    return (EXIT_SUCCESS);
}
