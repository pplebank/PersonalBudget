#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class XMLFile {
public:
    const string NAME_OF_FILE;
    const string NAME_OF_FILE_WiTH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;
    bool IfFileExists();
    XMLFile(string NameOfFile) : NAME_OF_FILE(NameOfFile) {
    }
    XMLFile(string nameOfFileWithIncomes, string nameOfFileWithExpenses) : NAME_OF_FILE_WiTH_INCOMES(nameOfFileWithIncomes),
    NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)  {
    }
};

#endif
