#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class AuxiliaryMethods
{
    public:
static string IntIntoString(int number);
static string LoadLine();
static string LoadNumber (string text, int CharPosition);
static string ChangeFirstLetterIntoCapitalRestLowercases (string text);
static int StringIntoInt (string text);
static float StringIntoFloat(string text);
static string FloatIntoString(float number);

};

#endif
