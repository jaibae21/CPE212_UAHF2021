// ****************************************
// Program Title: Project 2
// Project File: spade.cpp
// Name: Jaiden Gann
// Course Section: CPE-212-01
// Due Date: 10/2/21
// Program description: Function definitions
// of the blackcard sub class spade. 
// Setting suit and appending description
// ****************************************

#include <string>
#include "spade.h"

using namespace std;

Spade::Spade(int v):BlackCard(v)
{
    SetSuit('S');
}
string Spade::Description() const
{
    string d = BlackCard::Description();    // temporary variable used to accumulate result
    string e = ", Suit = ";
    e = e + GetSuit();
    d = d + e;
    return d;                 // Return string describing card value
}