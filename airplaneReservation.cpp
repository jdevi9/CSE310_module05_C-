// airplaneReservation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main(); // foward declaration
void readFlightFile(); // foward declaration
int manifestMenu(); // foward declaration
int readManifest(); // foward declaration
void writeToManifest(); // foward declaration

// amenities list 
string amenities[4] = { "soda", "towel", "candy", "free movies" };


bool mainMenu() {
    // welcome screen and option selection
    printf("Welcome to the Cali Airlines!\n");
    printf("Choose from the following options by typing in the number for your selection:\n");
    printf("\n");
    printf("1. See Available Flights\n");
    printf("2. Flight Manifest Menu\n");
    printf("3. See currrent flight amenities\n");
    printf("4. Exit\n");

    // input from user on selection
    int userChoice;
    printf("\nEnter number here: ");
    cin >> userChoice;


    if (userChoice == 1) {
        // pulls up list of flights
        readFlightFile();
    }
    else if (userChoice == 2) {
        // brings up manifest menu where people can be added 
        // or just to see one
        manifestMenu();
    }
    else if (userChoice == 3) {
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ": " << amenities[i] << "\n";
        }
    }
    else {
        exit(3);
        
    }
    return true;
}

static void readFlightFile()
{
    ifstream file("tripsInfo.txt", ios::in);
    string origin, oShrtCode, destination, dShrtCode, date;
    int departureTime, arrivalTime, cost;

    if (!file)
        cerr << "Cant open " << endl;

    while (file >> origin >> oShrtCode >> destination >> dShrtCode >> date >> departureTime >> arrivalTime >> cost)
    {
        cout << origin << " " << oShrtCode << " " << destination << " " << dShrtCode << " " << date << " " << departureTime << " " << arrivalTime << " " << cost << endl;
    }

    file.close();
    
    // return to the main menu
    int option;
    int pp = 0;
    int numTickets;
    int total;
    printf("\nMenu Options: ");
    printf("\n1. Sell Ticket");
    printf("\n2. Return to main menu\n");
    printf("Enter a number: ");
    cin >> option;
    if (option == 1) {
        string originCode;
        printf("Enter Origin Code: ");
        cin >> originCode;
        if (originCode == "SMF") {
            pp = 1000;
        }
        else if (originCode == "DFW") {
            pp = 750;
        }
        printf("How many tickets? (Enter number 1-10)");
        cin >> numTickets;
        total = numTickets * pp;
        printf("The total due by the customer now is: ");
        cout << total;
    }
    else if (option == 2) {
        mainMenu();
    }


}

int manifestMenu() 
{
    printf("\nWelcome to the Manifest Menu. Enter the number to what you would like to do:\n");
    printf("\n1. See a manifest\n"); // takes player to choose a manifest that will then print
    printf("2. Edit a manifest\n"); // takes user to choose a manifest that they can add people to.
    printf("3. return to main menu"); // returns to the main menu

    // user enters option 
    int userChoice;
    printf("\nEnter a number here: ");
    cin >> userChoice;

    if (userChoice == 1) {
        readManifest();
    }
    else if (userChoice == 2) {
        writeToManifest();
    }
    else if (userChoice == 3) {
        mainMenu();
    }
    else {
        manifestMenu();
    }

    return 0;
}

void writeToManifest()
{   
    string filename;
    ofstream foutput;
    ifstream finput;
    string newPerson;

    cout << "Which file do you want to edit? ";
    cin >> filename;
    
    finput.open(filename.c_str());
    foutput.open(filename.c_str(), ios::app);

    printf("Add new person to manifest below [last name] [first name] [date of birth].\n ");
    if (finput.is_open())
        std::getline(std::cin >> std::ws, newPerson);
        foutput << "\n" + newPerson;
    
    cout << "\n Name has been added";

    finput.close();
    foutput.close();
 

}

int readManifest()
{
    string filename;
    string myText;
    ofstream fileC;

    cout << "which file do you want to open?";
    cin >> filename;

    ifstream file(filename.c_str(), ios::in);
    string lastName, firstName, dob;

    if (!file)
        cerr << "Cant open " << endl;

    while (file >> lastName >> firstName >> dob)
    {
        cout << lastName << " " << firstName << " " << dob << endl;
    }
    
    return 0;
}


int main()
{
    mainMenu();
    

}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
