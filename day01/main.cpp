#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>

using std::cout;
using std::endl;

bool isNumber( char c)
{
    return std::isdigit(c);
}

char* loopOverString(const std::string & string)
{
    char* number_chars = new char[2];
    number_chars[0] = 'X'; // Don't want to check garbage value
    char last_char_number;
    for ( char c: string)
    {
        if ( isNumber(c))
        {
            if (number_chars[0] == 'X')
            {
                number_chars[0] = c;
            }
            last_char_number = c;
        }
    }
    number_chars[1] = last_char_number;
    return number_chars;
}

int main()
{
    std::string line_input = "";
    std::ifstream MyReadFile("data.txt");
    char* line_number_chars;
    int iLineNumber = 0;
    unsigned long int answer = 0;

    while(std::getline (MyReadFile, line_input))
    {
        line_number_chars = loopOverString(line_input);
        cout << " the number string is: " << line_number_chars << endl;
        iLineNumber = atoi(line_number_chars);
        answer += iLineNumber;
        delete[] line_number_chars;
    }
    cout << "The answer to part one is: " << answer << endl;
    MyReadFile.close();
}