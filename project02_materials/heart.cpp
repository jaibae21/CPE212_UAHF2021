// ****************************************
// Program Title: Project 2
// Project File: heart.cpp
// Name: Jaiden Gann
// Course Section: CPE-212-01
// Due Date: 10/2/21
// Program description: Function definitions
// of the redcard sub class heart. 
// Setting suit and appending description
// ****************************************

#include <string>
#include "heart.h"

using namespace std;

Heart::Heart(int v):RedCard(v)
{
    SetSuit('H');
}
string Heart::Description() const
{
    string d = RedCard::Description();    // temporary variable used to accumulate result
    //string c = "Color = red";
    string e = ", Suit = ";
    e = e + GetSuit();
    d = d + e;
    return d;                 // Return string describing card value
}