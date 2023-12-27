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

std::map<std::vector<int>, int> makeLineMap(std::string input, int offSet) 
{
    std::vector<std::string> numbers = findNumbersInLine(input);
    // mapEntrys.reserve(numbers.size());
    std::map<std::vector<int>, int> mapLine; // Map for this one line of the file
    for (auto n: numbers)
    {
        // Get the position of those sub string
        size_t pos = input.find(n);
        int posInt = static_cast<int>(pos);
        std::vector<int> mapKey;
        for(int i = posInt; i < posInt + n.size(); i++)
        {
            mapKey.push_back(i + offSet);
        }
        mapLine[mapKey] = stoi(n);
    }
    // Now that I have the map entries, I want to add them to the master map
    return mapLine;
}

int main(int argc, char* argv[])
{
    std::string line_input = "";
    std::map<std::vector<int>, int> mainMap;
    std::ifstream MyReadFile(argv[1]);
    int offSet = 0;
    while(std::getline (MyReadFile, line_input))
    {
        line_input.erase(std::remove(line_input.begin(), line_input.end(), '\n'), line_input.end());
        int size = line_input.size();
        std::map<std::vector<int>, int> mapLine = makeLineMap(line_input, offSet);
        offSet += line_input.size();
        mainMap.insert(mapLine.begin(), mapLine.end());

        // Now I have a map of all of the numbers in the data file. I need to do the same for the 
    }   
    for (const auto &pair: mainMap)
    {
        cout << "Key: " ;
        for (int i: pair.first)
        {
            cout << i << ',';
        }
        cout <<  " Value: " << pair.second << endl;
    }
    return 0;
}