#include "algoLib.hpp"

Build::Build(void) {
    int i = -1;
    while (++i <= 52) {
        deck1[i] = 0;
        deck2[i] = 0;
    }
    stepD1 = 26;
    stepD2 = 26;
    stepS1 = 0;
    stepS2 = 0;
}

Build::~Build(void) {
    std::cout << "End of program..." << std::endl;
}

bool Build::setValueInDeck(void) {
    std::cout << "Give 26 card for first deck (1rst is top of stack):" << std::endl;
    int count = 1;
    std::string outUser;
    while (count < 27) {
        std::cout << count << " : ";
        std::cin >> outUser;
        // Parsing on "outUser" here
        deck1[count - 1] = std::stoi(outUser);
        count++;
    }
    count = 1;
    std::cout << "Give 26 card for second deck (1rst is top of stack):" << std::endl;
    while (count < 27) {
        std::cout << count << " : ";
        std::cin >> outUser;
        // Parsing on "outUser" here
        deck2[count - 1] = std::stoi(outUser);
        std::cout << std::stoi(outUser) << std::endl;
        count++;
    }
    return (true);
}

/**
 * Monte de +1 toutes les cartes des deux deck et -1 le step des deux deck
*/
void    Build::cardUp(void) {
    int i = -1;
    while (++i < stepD1)
        deck1[i] = deck1[i + 1];
    int i = -1;
    while (++i < stepD2)
        deck2[i] = deck2[i + 1];
    stepD1--;
    stepD2--;
}

/**
 * @param card1 premiere carte a etre placer dans le deck (carte perdante)
 * @param card2 deuxieme carte a etre placer dans le deck (carte gagnante)
 * @param dest dans quel deck les cartes vont
*/
void    Build::setCard(t_data *data) {
    ;
}
