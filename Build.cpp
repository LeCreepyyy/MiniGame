#include "algoLib.hpp"

Build::Build(void) {
    int i = -1;
    while (++i <= 52) {
        deck1[i] = 0;
        deck2[i] = 0;
    }
    stepD1 = 26;
    stepD2 = 26;
}

Build::~Build(void) {
    std::cout << "End of program..." << std::endl;
}

void    Build::cardUp(int isd1ord2) {
    int i = -1;
    if (isd1ord2 == 1)
        while (++i < stepD1)
            deck1[i] = deck1[i + 1];
    else if (isd1ord2 == 2)
        while (++i < stepD2)
            deck2[i] = deck2[i + 1];
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

void    Build::setCard(int card1, int card2, int dest) {
    if (dest == 1) {
        deck1[stepD1] = card1;
        stepD1++;
        deck1[stepD1] = card2;
        stepD1++;
        cardUp(1);
        stepD1--;
        cardUp(2);
        stepD2--;
    }
    if (dest == 2) {
        deck2[stepD2] = card1;
        stepD2++;
        deck2[stepD2] = card2;
        stepD2++;
        cardUp(1);
        stepD2--;
        cardUp(2);
        stepD1--;
    }
}
