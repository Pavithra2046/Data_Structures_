// Round-robin scheduling algorithm using a circular linked list

#include <iostream>
#include "roundrobin.h"
using namespace std;

int main(){

    int choice=0;                       
    int stop=0;
    int time=0;
    int fixed=0;

    roundrobinschedule r;

    cout << "Enter fixed time slot: ";
    cin >> fixed;
    r.settime(fixed);

    while(stop==0){
        
        cout << "The Menu\n"
             << "1. Insert Process\n"
             << "2. Execute\n"
             << "3. Exit\n";
        cout << "Enter user choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            cout << "Enter the process time: ";
            cin >> time;
            r.insertend(time);
            cout << endl;
            break;

            case 2:
            r.execute();
            cout << endl;
            break;

            case 3:
            stop=1;
            cout << "Exiting program!" << endl;
            cout << endl;
            break;
        }

    }

}

