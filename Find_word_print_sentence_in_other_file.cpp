
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <fstream>


void readSearchWriteInFile()
{
    std::fstream fin;
    std::vector<std::string> word;
    fin.open("input.txt");
    std::string sentence;

    std::ofstream fout("output.txt");

    if (fin.is_open()) 
    {
        while (getline(fin, sentence))
        {
            word.push_back(sentence);
        }
        fin.close();
    }

    /*
    for (int i = 0; i < word.size(); i++)
    {
        std::cout << word[i] << std::endl;
    }*/

    std::regex country(R"(\bArmenia\b)");
    std::smatch sm;

    for (std::string& s : word)
    {
        if (std::regex_search(s, sm, country))
        {
            fout << s << std::endl;
        }
    }
}

int main()
{
    readSearchWriteInFile();

    return 0;

}