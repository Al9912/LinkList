// This program is created by Alan Colon.
// COSC-2436
// Professor: Ali Nikzad
// Finsh Date: March 25, 2023
// The basics of using Linked List.

#include <iostream>
#include "linkLists.h"

using namespace std;

void dashN(int times);
void dashesChar (int times);
void TitleCard(int month, int date, int year, string title);

int main()
{
    TitleCard(3,25,2023,"The basics of using Linked List.");
    linkLists list;
    int numberOfDashesChar = 75, numberOfDashN = 6;

    list.displayList();

    // Adding New Nodes
    cout << "Adding the New Nodes in order." << endl;;
    dashesChar(numberOfDashesChar);
    list.appendNode(2.5);
    list.appendNode(5.98);
    list.appendNode(30.60);
    list.appendNode(40.69);
    // Display
    list.displayList();

    // Checking the number is inside the list.
    dashN(numberOfDashN);
    double checkingNumber = 40.69;
    cout << "Checking the number " << checkingNumber << " is inside." << endl;
    if (true == list.isMember(checkingNumber))
    {
        cout << "Yes the number " << checkingNumber << " is inside the list.\t|" << endl;
    }
    else
    {
        cout << "ERROR: The number " << checkingNumber << " is not on the list.\t|" << endl;
    }
    dashN(numberOfDashN);
    

    // Insert New Nodes
    cout << "Insertig an New Node." << endl;
    list.insertNode(10.69);
    dashesChar(numberOfDashesChar);
    list.displayList();
    dashN(numberOfDashN);

    // Reverse List Nodes
    list.reverse();
    // Display
    cout << "Reverse List:" << endl;
    dashesChar(numberOfDashesChar);
    list.displayList();
    dashN(numberOfDashN);
    
    // Delete Nodes
    cout << "Deleting Nodes:\n";
    dashesChar(numberOfDashesChar);
    list.deleteNode(40.69);
    list.displayList();

    list.deleteNode(30.60);
    list.displayList();
    
    list.deleteNode(10.69);
    list.displayList();
    
    list.deleteNode(5.98);
    list.displayList();

    // Distroy
    dashN(numberOfDashN);
    cout << "Distroying Nodes..." << endl;
    dashesChar(numberOfDashesChar);
    list.~linkLists();
    list.displayList();

    cout << "Press Enter to continue." << endl;
    std::cin.ignore();
    
    return 0;
}

void dashN(int times)
{
    for (int i = 0; i < times; i++)
    {
        cout << "\n";
    }
}

void dashesChar (int times)
{
    for (int i = 0; i < times; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void TitleCard(int month, int date, int year, string title)
{
    string monthName = "";
    switch (month)
    {
    case 1:
        monthName = "January";
        break;
    case 2:
        monthName = "February";
        break;
    case 3:
        monthName = "March";
        break;
    case 4:
        monthName = "April";
        break;
    case 5:
        monthName = "May";
        break;
    case 6:
        monthName = "June";
        break;
    case 7:
        monthName = "July";
        break;
    case 8:
        monthName = "August";
        break;
    case 9:
        monthName = "September";
        break;
    case 10:
        monthName = "October";
        break;
    case 11:
        monthName = "November ";
        break;
    case 12:
        monthName = "December";
        break;
    default:
        cout << "Error: There is an error on the function titleCard() in the swith function monthName." << endl;
        break;
    }
    cout << "This program is created by Alan Colon.\nCOSC-2436\nProfessor: Ali Nikzad\nFinsh Date: "<< monthName << " " << date << ", " << year << endl;
    cout << title << "\n\n" << endl;
}