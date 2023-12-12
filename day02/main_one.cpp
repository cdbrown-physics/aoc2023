#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <regex>

using std::cout;
using std::endl;

int BLUE_TOTAL = 14;
int GREEN_TOTAL = 13;
int RED_TOTAL = 12;

int getGameId(const std::string & input)
{
    std::regex gameIdPattern("([^:]+)");
    std::regex gameIdNumber("(\\d+)");

    std::smatch gameMatch;
    std::smatch numMatch;
    
    std::regex_search(input, gameMatch, gameIdPattern);
    // Get the number in that string
    std::string gameSig = gameMatch[0].str();
    std::regex_search(gameSig, numMatch, gameIdNumber);
    return std::stoi(numMatch[0].str());
}

std::vector<std::string> getSets(const std::string & input)
{
    std::regex afterColon(": (.*)"); // Get everything after :
    std::smatch match;
    if (std::regex_search(input, match, afterColon))
    {
        std::string sAfterColon = match[1];
        std::regex splitPattern("; ");
        std::sregex_token_iterator it(sAfterColon.begin(), sAfterColon.end(), splitPattern, -1);
        std::sregex_token_iterator end;
        std::vector<std::string> vectorSets(it, end);
        return vectorSets;
    }
}

int getRedDraw(const std::string & set)
{
    std::regex pattern("(\\d+) red");
    std::smatch match;
    if (std::regex_search(set, match, pattern))
    {  
        return std::stoi(match[0].str());
    }
    return 0;
}
int getBlueDraw(const std::string & set)
{
    std::regex pattern("(\\d+) blue");
    std::smatch match;
    if (std::regex_search(set, match, pattern))
    {  
        return std::stoi(match[0].str());
    }
    return 0;
}
int getGreenDraw(const std::string & set)
{
    std::regex pattern("(\\d+) green");
    std::smatch match;
    if (std::regex_search(set, match, pattern))
    {  
        return std::stoi(match[0].str());
    }
    return 0;
}

bool gamePossible(const std::string &input)
{
    std::vector<std::string> vectorSets = getSets(input); 
    for (int i = 0; i < vectorSets.size(); i++)
    {
        // cout << "Looking at: " << vectorSets[i] << endl;
        // cout << "Red draw is: " << getRedDraw(vectorSets[i])<< endl;
        if (getRedDraw(vectorSets[i]) > RED_TOTAL ||
            getBlueDraw(vectorSets[i]) > BLUE_TOTAL ||
            getGreenDraw(vectorSets[i]) > GREEN_TOTAL)
        {
            cout << "Invalid Draw: " << input << endl;
            return false;
        }
    }
    cout << "Valid Draw" << input << endl;
    return true;
}
unsigned long int getPower(std::string line_input)
{
    std::vector<std::string> vectorSets = getSets(line_input);
    unsigned long int power = 0;
    unsigned long int maxRed = 0;
    unsigned long int maxBlue = 0;
    unsigned long int maxGreen = 0;
    for (int i = 0; i < vectorSets.size(); i++)
    {
        std::string set = vectorSets[i];
        unsigned long int tmpRed = getRedDraw(set);
        unsigned long int tmpBlue = getBlueDraw(set);
        unsigned long int tmpGreen = getGreenDraw(set);
        if (tmpRed > maxRed) {maxRed = tmpRed;}
        if (tmpBlue > maxBlue) {maxBlue = tmpBlue;}
        if (tmpGreen > maxGreen) { maxGreen = tmpGreen;}
    }
    power = maxRed * maxBlue * maxGreen;
    return power;
}

unsigned long int part_two(std::string dataFile)
{
    std::string line_input = "";
    std::ifstream MyReadFile(dataFile);
    unsigned long int answer = 0;
    while (std::getline(MyReadFile, line_input))
    {
        answer += getPower(line_input);
    }
    return answer;
}

int main(int argc, char* argv[])
{
    std::string line_input = "";
    std::ifstream MyReadFile(argv[1]);
    int gameId = 0;
    unsigned long int answer = 0;
    while(std::getline (MyReadFile, line_input))
    {
        gameId = getGameId(line_input);
        if (gamePossible(line_input))
        {
            answer += gameId;
        }
    }
    cout << "Answer to part 1 is: " << answer << endl;
    MyReadFile.close();
    unsigned long int part_two_answer = part_two(argv[1]);
    cout << "Answer to part 2 is: " << part_two_answer << endl;
    return 0;
}