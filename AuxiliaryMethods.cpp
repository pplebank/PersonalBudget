#include "AuxiliaryMethods.h"

string AuxiliaryMethods::IntIntoString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::LoadLine() {
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::LoadNumber(string text, int CharPosition) {
    string number = "";
    while(isdigit(text[CharPosition]) == true) {
        number += text[CharPosition];
        CharPosition ++;
    }
    return number;
}

string AuxiliaryMethods::ChangeFirstLetterIntoCapitalRestLowercases(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethods::StringIntoInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

float AuxiliaryMethods::StringIntoFloat(string text)
{
    float numberFloat;
    istringstream iss(text);
    iss >> numberFloat;

    return numberFloat;
}

string AuxiliaryMethods::FloatIntoString(float number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
