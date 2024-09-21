#include <iostream>
#include <limits>

using namespace std;

void validateInput(int &subject)
{
    while(!cin)
    {
        cout<< "Please, enter only an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin>> subject;
    }
}

void validateInput(int &subject1, int &subject2)
{
    while(!cin)
    {
        cout<< "Please, enter only integers: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin>> subject1 >> subject2;
    }
}