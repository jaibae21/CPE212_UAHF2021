// ****************************************
// Program Title: Project 2
// Project File: club.cpp
// Name: Jaiden Gann
// Course Section: CPE-212-01
// Due Date: 10/2/21
// Program description: Function definitions
// of the blackcard sub class club. 
// Setting suit and appending description
// ****************************************

#include <string>
#include "club.h"

using namespace std;

Club::Club(int v):BlackCard(v)
{
    SetSuit('C');
}
string Club::Description() const
{
    string d = BlackCard::Description();    // temporary variable used to accumulate result   
    string e = ", Suit = ";
    e = e + GetSuit();
    d = d + e;
    return d;                 // Return string describing card value
}