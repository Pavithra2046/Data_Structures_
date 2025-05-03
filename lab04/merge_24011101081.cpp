// Merging list
#include <iostream>
#include "mergesll.h"
using namespace std;

int main(){

    int choice=0;                       
    int stop=0;                         
    int num=0;                                                 
    int target=0;
    int dispchoice=0;
    list l1;
    list l2;
    list l3;

    while(stop==0){
        cout << "The Menu\n"
             << "1. Insert list 1\n"
             << "2. Insert list 2\n"
             << "3. Merge\n"
             << "4. Display\n"
             << "5. Exit\n";
        cout << "Enter user choice: ";
        cin >> choice;

        switch(choice){

            case 1:
            cout << "Enter the element to be inserted in list 1: ";
            cin >> num;
            l1.insertasc(num);

            break;

            case 2:
            cout << "Enter the element to be inserted in list 2: ";
            cin >> num;
            l2.insertasc(num);
            break;

            case 3:
            l3.mergelist(l1,l2,l3);
            cout << "The list has been merged!" << endl;
            break;

            case 4:
            cout << "Enter list number to be displayed: ";
            cin >> dispchoice;
            if (dispchoice==1){
                l1.display();
            }
            else if (dispchoice==2){
                l2.display();
            }
            else{
                l3.display();
            }
            break;

            case 5:
            stop=1;
            cout << "You have exited the program!" << endl;
        }}}