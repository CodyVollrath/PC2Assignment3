#include "Utils.h"
#include <algorithm>

//
// Converts and returns string in uppercase
//
// @precondition none
// @postcondition none
//
// @return Uppercase version of the string
//
const string toUpperCase(string text)
{
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    text.erase(std::remove(text.begin(), text.end(), '-'), text.end());

    return text;
}

const vector<string> splitStr(string value, const string delimiter)
{
    size_t pos = 0;
    string token;
    vector<string> elements;
    while ((pos = value.find(delimiter)) != string::npos) {
            token = value.substr(0, pos);
            elements.push_back(token);
            token = value.erase(0, pos + delimiter.length());
    }
    elements.push_back(token);
    return elements;
}
