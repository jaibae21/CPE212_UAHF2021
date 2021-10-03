// ****************************************
// Program Title: Project 2
// Project File: redcard.cpp
// Name: Jaiden Gann
// Course Section: CPE-212-01
// Due Date: 10/2/21
// Program description: Function definitions
// of the redcard class. Setting color and 
// appending description
// ****************************************


#include <string>
#include "redcard.h"

using namespace std;

RedCard::RedCard(int v):Card(v)
{
	SetColor("red");
}
string RedCard::Description() const
{
    string a,b;
    string d = Card::Description();    // temporary variable used to accumulate result
    string c = ", Color = ";
    c = c + GetColor();
    d = d + c;
    return d;                 // Return string describing card value
}
