#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <bits/stdc++.h>

std::unordered_map<std::string, std::string> words;

void permute(std::string str, std::string out)
{
    // When size of str becomes 0, out has a permutation (length of out is n)
    if (str.size() == 0)
    {
        if (words.find(out) == words.end())
        {
            return;
        }
        else
        {
            std::cout << out << std::endl;
            return;
        }
    }
    // One be one move all characters at the beginning of out (or result)
    for (int i = 0; i < str.size(); i++)
    {
        // Remove first character from str and add it to out
        permute(str.substr(1), out + str[0]);
        // Rotate string in a way second character moves to the beginning.
        std::rotate(str.begin(), str.begin() + 1, str.end());
    }
}

void ssort(std::string &s)
{
    std::sort(s.begin(), s.end());
}

int main(int argc, char *argv[])
{
    std::ifstream file;
    std::string word;

    if (argc != 2) {
        std::cout << "usage:  ./jumble <filename>\n";
        std::cout << "goodbye\n";
        return 1;
    }

    file.open(argv[1], std::ios::in);

    if (!file.is_open()) {
        std::cout << "Error: could not open file '" << argv[1] << "'\n";
        std::cout << "goodbye\n";
        return 1;
    }

    std::cout << "reading input file...\n";

    while (file >> word)
        words[word] = word;

    std::cout << "start entering jumbled words (ctrl-d to terminate)" << std::endl;
    std::cout << "> ";

    while (std::cin >> word) {
        std::cout << "English Anagrams Found:" << std::endl;
        permute(word, "");
        std::cout << "> ";
    }
    std::cout << "REPORT:\n";
    printf("num_words\t\t: %d\n", words.size());

    return 0;
}