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

std::map<std::string, int> addNumberToMap(std::vector<std::string> & numVector, const int offSet) 
{
    std::vector<std::map<std::string, int>> mapEntrys;
    mapEntrys.reserve(numVector.size());
    // for (int i = 0; i < numVector.size(); i++)
    // {
    //     std::map<std::string, int> mapEntry;
    //     std::string mapKey = "";
    //     std::string number = 
    // }
    // for (auto n: numVector)
    // {
        
    //     cout << n << endl;
    //     // Get the position of those sub string
    //     size_t pos = numVector.find(n);
    //     cout << "found at: " << pos << " - " << pos + f.size() -1 << endl;
    //     // Turn that possition into a string map key
        
    //     int posInt = static_cast<int>(pos);
    //     for(int i = pos; i < pos + f.size(); i++)
    //     {
    //         mapKey += std::to_string(i) + ",";
    //     }
    //     // cout << "This is the mapKey: " << mapKey << endl;
    //     mapEntry[mapKey] = stoi(f);
    //     // cout << "Trying to push back" << endl;
    //     mapEntrys.push_back(mapEntry);
    // }
    // return mapEntrys;

}

int main(int argc, char* argv[])
{
    std::string line_input = "";
    std::ifstream MyReadFile(argv[1]);
    int offSet = 0;
    while(std::getline (MyReadFile, line_input))
    {
        line_input.erase(std::remove(line_input.begin(), line_input.end(), '\n'), line_input.end());
        int size = line_input.size();
        // cout << line_input << endl;
        // cout << "Size: " << size << endl;
        std::vector<std::string> numbers = findNumbersInLine(line_input);
        for (auto n: numbers)
        {
            cout << n << endl;
            findPosition(n, line_input)
        }
        offSet += line_input.size();
    }
    return 0;
}