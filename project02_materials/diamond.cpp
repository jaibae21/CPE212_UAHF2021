// ****************************************
// Program Title: Project 2
// Project File: diamond.cpp
// Name: Jaiden Gann
// Course Section: CPE-212-01
// Due Date: 10/2/21
// Program description: Function definitions
// of the redcard sub class diamond. 
// Setting suit and appending description
// ****************************************

#include <string>
#include "diamond.h"

using namespace std;

Diamond::Diamond(int v):RedCard(v)
{
    SetSuit('D');
}
string Diamond::Description() const
{
    string d = RedCard::Description();    // temporary variable used to accumulate result
    string e = ", Suit = ";
    e = e + GetSuit();
    d = d + e;
    return d;                 // Return string describing card value
}