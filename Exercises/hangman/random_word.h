#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <random>

std::string get_random_word() {
    std::ifstream file("commonwords.txt");
    std::vector<std::string> words;

    std::string word;
    while (file >> word) {
        words.push_back(word);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, words.size() - 1);

    std::string random_word = words[distrib(gen)];

    return random_word;
}
