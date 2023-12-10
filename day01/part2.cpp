#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <regex>
#include <vector>
#include <map>

using std::cout;
using std::endl;

std::vector<std::string> loopOverString(const std::string & input)
{
    std::vector<std::string> vsNumbers;
    char last_char_number;
    std::vector<std::string> result;
    std::smatch match;
    std::regex r("(one|two|three|four|five|six|seven|eight|nine|1|2|3|4|5|6|7|8|9)");
    
    std::string::const_iterator searchStart(input.cbegin());
    while (std::regex_search( searchStart, input.cend(), match, r))
    {
        result.push_back(match[0]);
        searchStart = match.suffix().first;
    }
    // result will be a vector of string found in the input string now I need 
    // to trun those into the two digit number
    vsNumbers.push_back(result[0]);
    vsNumbers.push_back(result.back());
    if (vsNumbers.size() > 2)
    {
        cout << vsNumbers.size() << endl;
        throw std::range_error("Too many values returned");
    }
    for (int i = 0; i < vsNumbers.size(); i++)
    {
        
    }
    return vsNumbers;
}

char spelledNumberToChar(const std::string & spelledNumber)
{
    std::map<std::string, char> numberMap = {{"one", '1'},
                                            {"two", '2'},
                                            {"three", '3'},
                                            {"four", '4'},
                                            {"five", '5'},
                                            {"six", '6'},
                                            {"seven", '7'},
                                            {"eight", '8'},
                                            {"nine", '9'}};
    auto it = numberMap.find(spelledNumber);
    if (it != numberMap.end())
    {
        return it->second;
    }
    else if (spelledNumber.size() > 1) // spelledNumber is just the number char
    {
        return (char)spelledNumber[0];
    }
    else // Something went wrong, throw exception
    {  
        cout << spelledNumber << endl;
        throw std::runtime_error("Bad value for spelledNumber");
    }

}

int main()
{
    std::string line_input = "";
    std::ifstream MyReadFile("test_input_two.txt");
    std::vector<std::string> vsNumbers;
    int iLineNumber = 0;
    unsigned long int answer = 0;

    while(std::getline (MyReadFile, line_input))
    {
        cout << "Looking at the line " << line_input << endl;
        vsNumbers = loopOverString(line_input);
        // vsNumbers should be the single char characters now
        iLineNumber = atoi(line_number_chars);
    }
    MyReadFile.close();

    return 0;
}