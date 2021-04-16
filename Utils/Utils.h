#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
using namespace std;
/**
* Converts the entered text to upper case
* @return the upper case form of the text entered
*/
const string toUpperCase(string text);

/**
* Splits the string value by a delimiter
* @returns a vector of the split string
*/
const vector<string> splitStr(string value, const string delimiter);

/**
* Gets the classification associated by number
* @return classification
*/
const string getClassification(int classification);
#endif // UTILS_H

