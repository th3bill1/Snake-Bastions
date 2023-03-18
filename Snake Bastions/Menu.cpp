#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* This part of the code is made to ensure you read correct file. You can create variable for any file source in file() as below and change possible input numbers in the array.
    Later on we can use it for testing different inputs from the site.
*/

const int input_numbers[] = { 1,2 };

int User_choice();

const char* file() 
{
    const char* input1 = "/Users/serhatseval/Developer/Xcode Files/SnakesandHoles/SnakesandHoles/00-example-2.txt";
    const char* input2 = "00-example-2.txt";
    int choice = User_choice();
    if (choice == 1) return input1;
    if (choice == 2)
    {
        return input2;
    }
    return "";
}

bool isok(int choice)
{
    for (int i = 0; i < (sizeof(input_numbers) / sizeof(int)); i++)
    {
        if (find(begin(input_numbers), end(input_numbers), choice)) return true;  
    }
    return false;
}

int User_choice()
{

    int choice;
    string asking = "Put user (1-Ser 2-Wowo): ";
    cout << asking;
    cin >> choice;
    if (!isok(choice))
    {
        while (true)
        {
            cout << "Wrong input try again!";
            cout << asking;
            cin >> choice;
            if (!isok(choice)) return choice;
        }
    }
    else return choice;
}



