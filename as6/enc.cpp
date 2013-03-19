#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    string name = "David";
    string nameb = "Alex";

    for(int i = 0; i <name.size(); i++)
        name[i] ^= 5;

    cout << name << endl;

    for(int i = 0; i < name.size(); i++)
        name[i] ^= 5;

    cout << name << endl;

    char message[100], pass[100], ch;
    int i = 0;

    cout << "Input message:" << endl;
    while((ch = getchar()) != '\n')
        message[i++] = ch;

    i = 0;
    cout << "input password:" << endl;
    while((ch = getchar()) != '\n')
        pass[i++] = ch;

    cout << message << endl;

    for(int j = 0; j < strlen(message); j++)
        message[j] ^= pass[j % strlen(pass)];

    cout << message << endl;

    for(int j = 0; j < strlen(message); j++)
        message[j] ^= pass[j % strlen(pass)];

    cout << message << endl;

}
