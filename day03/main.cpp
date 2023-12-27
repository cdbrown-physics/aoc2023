#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <regex>

using std::cout;
using std::endl;

std::vector<std::string> findNumbersInLine(const std::string & input)
{
    std::regex pattern("(\\d+)");   // matches numbers in a string
    std::sregex_token_iterator it (input.begin(), input.end(), pattern);
    std::sregex_token_iterator end;
    std::vector<std::string> numbers(it, end);
    return numbers;
}

std::map<std::string, int> makeLineMap(std::string input, int offSet) 
{
    std::vector<std::string> numbers = findNumbersInLine(input);
    // mapEntrys.reserve(numbers.size());
    std::map<std::string, int> mapLine; // Map for this one line of the file
    for (auto n: numbers)
    {
        // std::map<std::string, int> mapEntry;
        cout << n << endl;
        // Get the position of those sub string
        size_t pos = input.find(n);
        cout << "found at: " << pos << " - " << pos + n.size() -1 << endl;
        // Turn that possition into a string map key
        std::string mapKey = "";
        int posInt = static_cast<int>(pos);
        for(int i = posInt; i < posInt + n.size(); i++)
        {
            mapKey += std::to_string(i + offSet) + ",";
        }
        cout << "This is the mapKey: " << mapKey << endl;
        mapLine[mapKey] = stoi(n);
    }
    // Now that I have the map entries, I want to add them to the master map
    return mapLine;
}

int main(int argc, char* argv[])
{
    std::string line_input = "";
    std::ifstream MyReadFile(argv[1]);
    int offSet = 0;
    while(std::getline (MyReadFile, line_input))
    {
        int size = line_input.size();
        cout << "size: " << size << endl;
        cout << line_input << endl;
        std::map<std::string, int> mapLine = makeLineMap(line_input, offSet);
        offSet += line_input.size();
        return 0;
    }
    return 0;
}