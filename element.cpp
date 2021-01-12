#include <iostream>
#include "element.hpp"
#include <windows.h>
using namespace std;           //To use namespace std
element *E = new element[118]; //Provide structures
static int count = 16;         //counter for Provide structures
void addElement()              //This function is used to add elements
{
    cout << ">>----Welcome to the Addelement function----<<" << endl;
    cout << "Please enter the element name -> ";
    fflush(stdin);
    cin.getline(E[count].elementName, 20);
    int flag = 0;
    for (size_t i = 0; i < count; i++)
    {
        if (strcmp(E[count].elementName, E[i].elementName) == 0)
        {
            cout << "This element exists. Please press enter key to return to the original menu " << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "Please enter the element symbol -> ";
        fflush(stdin);
        cin.getline(E[count].symbol, 3);
        int flag1 = 0;
        for (size_t g = 0; g < count; g++)
        {
            if (strcmp(E[count].symbol, E[g].symbol) == 0)
            {
                cout << "There is an element with this symbol. Please press enter key to return to the main menu" << endl;
                flag1 = 1;
                break;
            }
        }
        if (flag1 == 0)
        {
            cout << "Please enter the element weight -> ";
            cin >> E[count].weight;
            if (E[count].weight <= 0)
            {
                while (E[count].weight <= 0)
                {
                    cout << "The entered weight is not valid. Please try again" << endl;
                    cout << "Please enter the element weight -> ";
                    cin >> E[count].weight;
                }
            }
            //fflush(stdin);
            cout << "Please enter the element nature -> ";
            fflush(stdin);
            cin.getline(E[count].nature, 10);
            cout << "Please enter the element atomic numner -> ";
            cin >> E[count].atomicNumber;
            if (E[count].atomicNumber < 1 || E[count].atomicNumber > 118)
            {
                while (!(E[count].atomicNumber >= 1 && E[count].atomicNumber <= 118))
                {
                    cout << "The entered atomic number is invalid. Please try again" << endl;
                    cout << "Please enter the element atomic numner -> ";
                    cin >> E[count].atomicNumber;
                }
            }

            int flag2 = 0;
            for (size_t p = 0; p < count; p++)
            {
                if (E[count].atomicNumber == E[p].atomicNumber)
                {
                    cout << "There is an element with this atomic number. Please press enter key to return to the main menu " << endl;
                    flag2 = 1;
                    getchar();
                    break;
                }
            }
            if (flag2 == 0)
            {
                ++count;
            }
        }
    }
    getchar();       //This command waits for the user to press a button on the keyboard
    system("clear"); //This command is in the "windows.h" file and is used to clear the page
}
void print(int i) //This function is called by the "showAll" function and prints the information of the elements in the console
{
    cout << "Element " << (i + 1) << " :";
    int j = 0;
    cout << "Element's name is "; //Print element name
    cout<<E[i].elementName;
    cout << ":) " << endl;
    j = 0;
    cout << "Element's symbol is "; //Print element symbol
    cout<<E[i].symbol;
    cout << ":) " << endl;
    cout << "Element's weight is " << E[i].weight << ":) " << endl; //Print element weight
    j = 0;
    cout << "Element's nature is "; //Print the natural state of the element
    cout<<E[i].nature;
    cout << ":) " << endl;
    j = 0;
    cout << "Element's atomic number is " << E[i].atomicNumber << ":) " << endl;
    if (E[i].otherProp[j] != '\0') //If the user has added a feature -> Print another feature of the element
    {
        cout << "Element's other properties is ";
        cout<<E[i].otherProp;
        cout << ":) " << endl;
    }
}
void showAll() //print all of information about element's
{
    cout << ">>----Welcome to the Showall function----<<" << endl;
    for (size_t i = 0; i < count; ++i)
    {
        print(i); //Calling the print function
        cout << "-------------------------" << endl;
    }
}
void searchSynbol() //To search and display the desired element by symbol
{
    cout << ">>----Welcome to the Searchsymbol function----<<" << endl;
    char sym[3];
    int flag = 0;
    cout << "Please enter the icon of the desired element -> ";
    cin >> sym;
    for (size_t i = 0; i < count; i++) //Search in E array of element
    {
        if (strcmp(E[i].symbol, sym) == 0) //compare
        {
            cout << "The desired element was found" << endl;
            char num;
            cout << "Do you want the element information to be printed?(y/n) ->";
            cin >> num;
            switch (num)
            {
            case 'y':
            case 'Y':
                print(i);
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
        cout << "The requested item was not found :(" << endl;
}

void searchName() //
{
    cout << ">>----Welcome to the Searchname function----<<" << endl;
    char name[50];
    int flag = 0;
    cout << "Please enter the name of the desired element -> ";
    fflush(stdin);
    cin.getline(name, 50);
    for (size_t i = 0; i < count; i++)
    {
        if (strcmp(E[i].elementName, name) == 0) //compare
        {
            print(i); //Call the print function
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "The requested item was not found :(" << endl;
}

void searchAtomicNumber()
{
    cout << ">>----Welcome to the Searchatomicnumber function----<<" << endl;
    int num, flag = 0;
    cout << "Please enter the atomic number of the desired element -> ";
    cin >> num;
    for (size_t i = 0; i < count; i++)
    {
        if (num == E[i].atomicNumber)
        {
            print(i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "The requested item was not found :(" << endl;
}
void swap(element *a, element *b) //To swap two houses of array
{
    double w;
    w = a->weight;
    a->weight = b->weight;
    b->weight = w;
    //================
    int an;
    an = a->atomicNumber;
    a->atomicNumber = b->atomicNumber;
    b->atomicNumber = an;
    //===========
    char name[20];
    strcpy(name, a->elementName);
    strcpy(a->elementName, b->elementName);
    strcpy(b->elementName, name);
    //==========
    char sym[3];
    strcpy(sym, a->symbol);
    strcpy(a->symbol, b->symbol);
    strcpy(b->symbol, sym);
    //=============
    char natu[10];
    strcpy(natu, a->nature);
    strcpy(a->nature, b->nature);
    strcpy(b->nature, natu);
    //==============
    char otherp[50];
    strcpy(otherp, a->otherProp);
    strcpy(a->otherProp, b->otherProp);
    strcpy(b->otherProp, otherp);
}
void sortByWeight()
{
    cout << ">>----Welcome to the SortbyWeight function----<<" << endl;
    float *t;
    for (size_t i = 0; i < (count - 1); i++)
    {
        for (size_t j = 0; j < (count - 1); j++)
        {
            //int k = ++j;
            if (E[j].weight > E[j + 1].weight)
            {
                swap(&E[j], &E[j + 1]);
            }
        }
    }
    char ch;
    cout << "Do you want the information to be printed?(Y/N) ";
    cin >> ch;
    switch (ch)
    {
    case 'y':
    case 'Y':
        showAll();
        break;
    }
}

void addProp()
{
    cout << ">>----Welcome to the Addprop function----<<" << endl;
    char sym[3];
    int flag = 0;
    cout << "Please enter the icon of the desired element -> ";
    cin >> sym;
    for (size_t i = 0; i < count; i++)
    {
        if (strcmp(E[i].symbol, sym) == 0)
        {
            cout << "Please enter your prop -> ";
            fflush(stdin);
            cin.getline(E[i].otherProp, 50);
            flag = 1;
            cout<<"Do you want element information to be displayed?(y/n) ";
            char n;
            cin>>n;
            switch (n)
            {
            case 'Y':
            case 'y':
            print(i);
                break;
            }
            break;
        }
    }
    if (flag == 0)
        cout << "The requested item was not found :(" << endl;
}
void exit()
{
    delete[] E;
    cout << "I hope you enjoyed my program :D " << endl;
}
void intiolize()//Initialization of the first 16 cells element array
{
        E[0].atomicNumber = 1;
    strcpy(E[0].nature, "Gass");
    strcpy(E[0].symbol, "H");
    strcpy(E[0].elementName, "Hydrogen");
    E[0].weight = 1.008;
    //-------------------
    E[1].atomicNumber = 3;
    strcpy(E[1].nature, "Solid");
    strcpy(E[1].symbol, "Li");
    strcpy(E[1].elementName, "Lithium");
    E[1].weight = 6.941;
    //-------------
    E[2].atomicNumber = 19;
    strcpy(E[2].nature, "Solid");
    strcpy(E[2].symbol, "K");
    strcpy(E[2].elementName, "potassium");
    E[2].weight = 39.098;
    //------------------------
    E[3].atomicNumber = 118;
    strcpy(E[3].nature, "Gass");
    strcpy(E[3].symbol, "Og");
    strcpy(E[3].elementName, "Oganson");
    E[3].weight = 294;
    //-------------------
    E[3].atomicNumber = 118;
    strcpy(E[3].nature, "Gass");
    strcpy(E[3].symbol, "Og");
    strcpy(E[3].elementName, "Oganson");
    E[3].weight = 294;
    //---------
    E[4].atomicNumber = 32;
    strcpy(E[4].nature, "Solid");
    strcpy(E[4].symbol, "Ge");
    strcpy(E[4].elementName, "Germanium");
    E[4].weight = 72.61;
    //----------
    E[5].atomicNumber = 17;
    strcpy(E[5].nature, "Gass");
    strcpy(E[5].symbol, "Cl");
    strcpy(E[5].elementName, "Chlorine");
    E[5].weight = 35.453;
    //-------------
    E[6].atomicNumber = 33;
    strcpy(E[6].nature, "Solid");
    strcpy(E[6].symbol, "As");
    strcpy(E[6].elementName, "Arsenic");
    E[6].weight = 74.922;
    //--------------
    E[7].atomicNumber = 74;
    strcpy(E[7].nature, "Solid");
    strcpy(E[7].symbol, "W");
    strcpy(E[7].elementName, "Tungsten");
    E[7].weight = 183.84;
    //---------------
    E[8].atomicNumber = 42;
    strcpy(E[8].nature, "Solid");
    strcpy(E[8].symbol, "Mo");
    strcpy(E[8].elementName, "Molybdenum");
    E[8].weight = 95.94;
    //-----------
    E[9].atomicNumber = 55;
    strcpy(E[9].nature, "Solid");
    strcpy(E[9].symbol, "Cs");
    strcpy(E[9].elementName, "Cesium");
    E[9].weight = 132.905;
    //-----------
    E[10].atomicNumber = 46;
    strcpy(E[10].nature, "Solid");
    strcpy(E[10].symbol, "Pd");
    strcpy(E[10].elementName, "Palladium");
    E[10].weight = 106.42;
    //-------------
    E[11].atomicNumber = 26;
    strcpy(E[11].nature, "Solid");
    strcpy(E[11].symbol, "Fe");
    strcpy(E[11].elementName, "Iron");
    E[11].weight = 55.845;
    //-------------
    E[12].atomicNumber = 20;
    strcpy(E[12].nature, "Solid");
    strcpy(E[12].symbol, "Ca");
    strcpy(E[12].elementName, "Calcium");
    E[12].weight = 40.078;
    //----------------
    E[13].atomicNumber = 82;
    strcpy(E[13].nature, "Solid");
    strcpy(E[13].symbol, "Pb");
    strcpy(E[13].elementName, "Lead");
    E[13].weight = 207.2;
    //----------------
    E[14].atomicNumber = 30;
    strcpy(E[14].nature, "Solid");
    strcpy(E[14].symbol, "Zn");
    strcpy(E[14].elementName, "Zinc");
    E[14].weight = 65.39;
    //-----------------
    E[15].atomicNumber = 87;
    strcpy(E[15].nature, "Liquid");
    strcpy(E[15].symbol, "Fr");
    strcpy(E[15].elementName, "Francium");
    E[15].weight = 223;

}

void menu()
{
    for (;;)
    {
        int select;
        cout << ">>----Please enter your desired option----<<" << endl
             << "1) Add element" << endl
             << "2) Display properties of all elements" << endl
             //<< "3) Display the properties of the selected element" << endl
             << "3) Ability to search for an element by name" << endl
             << "4) Ability to search for an item by number" << endl
             << "5) Ability to search for an element by symbol" << endl
             << "6) Sort and display elements based on their weight" << endl
             << "7) Add property" << endl
             << "8)Exit" << endl
             << "Select an element and add a property to it -> ";
        cin >> select;
        system("clear");
        if (select == 8)
        {
            exit();
            break;
        }

        switch (select)
        {
        case 1:
            addElement();
            break;
        case 2:
            showAll();
            break;
        case 3:
            searchName();
            break;
        case 4:
            searchAtomicNumber();
            break;
        case 5:
            searchSynbol();
            break;
        case 6:
            sortByWeight();
            break;
        case 7:
            addProp();
            break;
        }
    }
}