// ****************************************
// Program Title: Project 2
// Project File: blackcard.cpp
// Name: Jaiden Gann
// Course Section: CPE-212-01
// Due Date: 10/2/21
// Program description: Function definitions
// of the blackcard class. Setting color and 
// appending description
// ****************************************


#include <string>
#include "blackcard.h"

using namespace std;

BlackCard::BlackCard(int v):Card(v)
{
    SetColor("black");
}
string BlackCard::Description() const
{

    string d = Card::Description();    // temporary variable used to accumulate result
    string c = ", Color = ";
    c = c + GetColor();
    d = d + c;
    return d;                 // Return string describing card value
}