#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

void define_list(std::vector<std::string>& list, std::string file_name);
void shuffle(std::vector<std::string>& list);
std::string random_get(std::vector<std::string> list);
void fight(std::string choice, std::vector<std::string> list);

int main(int ac, char** av) {

    if (ac != 2) {
        std::cout << "Select file" << std::endl;
        return (0);
    }

    std::string file_name = av[1];

    std::vector<std::string> list;
    define_list(list, file_name);
    std::string choice = random_get(list);
    shuffle(list);


    fight(choice, list);

    return (EXIT_SUCCESS);
}


void fight(std::string choice, std::vector<std::string> list) {
    int score = 0;

    std::cout << "Choice is " << choice << " :" << std::endl;
    std::cout << std::endl;
    for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); it++) {
        if (*it == choice)
            continue;
        std::string answer;
        std::cout << choice << " vs " << *it << "      (tap no) : ";
        std::getline(std::cin, answer);

        std::cout << "\033[F\033[K";
        if (answer == "no")
            break;
        else
            score++;
        
        if (score == 20) {
            std::cout << choice << " win !" << std::endl;
            break;
        }
    }
    std::cout << "Score : " << score << std::endl;
}

void shuffle(std::vector<std::string>& list) {
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(list.begin(), list.end(), g);
}

std::string random_get(std::vector<std::string> list) {
    shuffle(list);
    return (list[0]);
}

void define_list(std::vector<std::string>& list, std::string file_name) {
    std::ifstream file(file_name);

    std::string line;
    while (std::getline(file, line)) {
        list.push_back(line);
    }

    file.close();
}
