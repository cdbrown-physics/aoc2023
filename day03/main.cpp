#include <iostream>
#include <string>
#include <fstream>
#include <regex>

using std::cout;
using std::endl;

int testing() 
{
    std::string s = "..467...114..";
    std::regex pattern("(\\d+)");   // matches numbers in a string
    std::smatch match;   // for returned details of the match
    std::sregex_token_iterator it (s.begin(), s.end(), pattern);
    std::sregex_token_iterator end;
    std::vector<std::string> foo(it, end);
    for (auto f: foo)
    {
        cout << f << endl;
        // Get the position of those sub string
        size_t pos = s.find(f);
        cout << "found at: " << pos << " - " << pos + f.size() -1 << endl;
    }
    return 0;
}


int main(int argc, char* argv[])
{
    std::string line_input = "";
    std::ifstream MyReadFile(argv[1]);
    while(std::getline (MyReadFile, line_input))
    {
        cout << line_input << endl;
    }
    testing();
    return 0;
}