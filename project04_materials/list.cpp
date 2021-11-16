// ****************************************
// Program Title: Project 4
// Project File: list.cpp
// Name: Jaiden Gann
// Course Section: CPE-212-01
// Due Date: 10/30/2021
// Program description: The .cpp file that 
// defines the basic functions from the
// list.h file
// ****************************************

#include <iostream>
#include <new>
#include "list.h"
List::List() {  // list constructor  initializes num =0 and points head to null
    num = 0;
    head = NULL;
}
List:: ~List() { // destructor which delete s all memory locations ...
    Node* ptr1 = head;
    Node* ptr2 = NULL;
    while (ptr1 != NULL) {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
        delete ptr2;
    }
    delete ptr1;
}
void List::Append(string newword) {
    Node* ptr = head;
    Node* newNode = new Node; // create new node 
    newNode->next = NULL;  // as we are appending it will be the end of list hence next is null
    newNode->word = newword;
    if (head == NULL) {  // if head is null set head to newnode
        head = newNode;
        num++;
        return;
    }
    while (ptr->next != NULL) {  // if head not null iteration until last node will continue
        ptr = ptr->next;
    }
    ptr->next = newNode;
    num++;
}
void List::InsertAt(int pos, string newword) {
    Node* ptr1 = head;
    Node* ptr2 = NULL;
    try {
        if (pos > num - 1) {
            throw ListBadPosition();
        }
        else {
            for (int i = 0; i < pos; i++) { 
                ptr2 = ptr1;    //ptr2 points where ptr1 was
                ptr1 = ptr1->next;  //ptr1 points to next node
            }
            Node* newNode = new Node;
            newNode->word = newword;
            newNode->next = ptr1;
            if (ptr2 == NULL) {   //if ptr2 points to Null
                head = newNode; //head is now newnode
            }
            else {    // else set ptr2's node point to newnode
                ptr2->next = newNode;
            }
            num++;
        }
    }
    catch (ListBadPosition) {
        //cout << " list bad exception " << endl;
    }
}
void List::Delete(string someword) {
    Node* ptr1 = head;
    Node* ptr2 = NULL;
    while (ptr1 != NULL) 
    {
        if (ptr1->word == someword)
        {  //if word is there in list
            if (ptr2 == NULL) 
            {
                head = ptr1->next;

            }
            else 
            {
                ptr2->next = ptr1->next;
            }
            delete ptr1;    // delete  that word and set num to num-1
            num--;
            return;
        }
        ptr2 = ptr1;
        ptr1 = ptr1->next;

    }
    try
    {          // if no word is found throw exception
        throw ListNotFound();
    }
    catch (ListNotFound)
    {
       // cout << " List not found exception thrown " << endl;
    }
}
void List::Replace(string oldword, string newword) {
    Node* ptr = head;
    while (ptr != NULL)
    {
        if (ptr->word == oldword)
        {
            ptr->word = newword;
            return;
        }
        ptr = ptr->next;
    }
    try 
    {
            throw ListNotFound();
    }
    catch (ListNotFound) {
        //cout << " List not found exception thrown " << endl;
    }
}
/***** Observer Methods *****/
int List::Length() const {
    return num;
}
bool List::Find(string someword) const {
    Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->word == someword) {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}