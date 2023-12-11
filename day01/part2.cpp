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
    std::vector<std::string> result;
    std::smatch match;
    std::regex pattern("(one|two|three|four|five|six|seven|eight|nine|1|2|3|4|5|6|7|8|9)");
    // std::regex pattern(R"((one|two|three|four|five|six|seven|eight|nine|\d))");
    std::string::const_iterator searchStart(input.cbegin());
    int i = 0;
    std::string searchString = input;
    while (std::regex_search( searchStart, input.cend(), match, pattern))
    {  
        result.push_back(match[0]);
        cout << "The match was: " << match[0] << endl;
        cout << "Match suffix: " << match.suffix().str() << endl;
        cout << "Match suffix size: " << match.suffix().str().size() << endl;
        searchStart = match.suffix().first;
        if (searchStart == input.cend())
        {
            break;
        }
        else
        {
            searchStart -= 1;
        }
        cout << "I'm looking at: " << *searchStart << endl;
        i++;
        if (i > 4)
        {
            break;
        }
    }
    throw std::runtime_error("Fuck this");
    // result will be a vector of string found in the input string now I need 
    // to trun those into the two digit number
    vsNumbers.push_back(result[0]);
    vsNumbers.push_back(result.back());
    if (vsNumbers.size() > 2)
    {
        cout << vsNumbers.size() << endl;
        throw std::range_error("Too many values returned");
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
    else if (spelledNumber.size() == 1) // spelledNumber is just the number char
    {
        return (char)spelledNumber[0];
    }
    else // Something went wrong, throw exception
    {  
        cout << "This is the spelledNumber: " << spelledNumber << endl;
        cout << spelledNumber.size() << endl;
        throw std::runtime_error("Bad value for spelledNumber");
    }

}

int main(int argc, char* argv[])
{
    std::string line_input = "";
    std::ifstream MyReadFile(argv[1]);
    std::vector<std::string> vsNumbers;
    char* line_number_chars = new char[2];
    int iLineNumber = 0;
    unsigned long int answer = 0;

    while(std::getline (MyReadFile, line_input))
    {
        cout << "Looking at the line " << line_input << endl;
        vsNumbers = loopOverString(line_input);
        for (int i = 0; i < vsNumbers.size(); i++)
        {
            line_number_chars[i] = spelledNumberToChar(vsNumbers[i]);
        }
        // vsNumbers should be the single char characters now
        iLineNumber = atoi(line_number_chars);
        cout << "The numbers in that line are " << iLineNumber << endl;
        answer += iLineNumber;
        cout << "Running total " << answer << endl;
    }
    cout << "Answer to part two is: " << answer << endl;
    MyReadFile.close();

    return 0;
}