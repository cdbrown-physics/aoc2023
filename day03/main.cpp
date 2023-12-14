#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <regex>

using std::cout;
using std::endl;

std::map<std::string, int> findNumbersInLine(std::string input, int offSet) 
{
    std::vector<std::map<std::string, int>> mapEntrys;
    std::regex pattern("(\\d+)");   // matches numbers in a string

    std::sregex_token_iterator it (input.begin(), input.end(), pattern);
    std::sregex_token_iterator end;
    std::vector<std::string> foo(it, end);

    mapEntrys.reserve(foo.size());
    for (auto f: foo)
    {
        std::map<std::string, int> mapEntry;
        cout << f << endl;
        // Get the position of those sub string
        size_t pos = input.find(f);
        cout << "found at: " << pos << " - " << pos + f.size() -1 << endl;
        // Turn that possition into a string map key
        std::string mapKey = "";
        int posInt = static_cast<int>(pos);
        for(int i = pos; i < pos + f.size(); i++)
        {
            mapKey += std::to_string(i) + ",";
        }
        cout << "This is the mapKey: " << mapKey << endl;
        mapEntry[mapKey] = stoi(f);
        cout << "Trying to push back" << endl;
        mapEntrys.push_back(mapEntry);
    }

}

int main(int argc, char* argv[])
{
    std::string line_input = "";
    std::ifstream MyReadFile(argv[1]);
    int offSet = 0;
    while(std::getline (MyReadFile, line_input))
    {
        int size = line_input.size();
        cout << line_input << "size" << size << endl;
        findNumbersInLine(line_input, offSet);
        offSet += line_input.size();
    }
    return 0;
}