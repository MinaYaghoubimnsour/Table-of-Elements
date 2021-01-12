#include <iostream>
using namespace std;
#ifndef ELEMENT_H //Start include guard
#define ELEMENT_H
void menu();

struct element //this struct is about element's Property
{
    char elementName[20]; //Element name
    char symbol[3];       //Element symbol
    double weight;        //Element weight
    char nature[10];      //The natural state of the element
    char otherProp[50];   //Element attribute
    int atomicNumber;     //Atomic number of the element
};
//These are the functions we used in the program
void addElement();
void showAll();
void print(int);
void searchSynbol();
void searchName();
void searchAtomicNumber();
void sortByWeight();
void addProp();
void swap1(element *, element *);
void intiolize();

#endif //Ended include gurd