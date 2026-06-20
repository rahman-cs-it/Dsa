#include <iostream> // Required for cout and endl
using namespace std; // To use cout and endl directly

class Solution {
public:
    void whichWeekDay(int day) {
        switch(day){
            case 1: cout<<"Monday"<<endl;
            break;
            case 2: cout<<"Tuesday"<<endl;
            break;
            case 3: cout<<"Wednesday"<<endl;
            break;
            case 4: cout<<"Thursday"<<endl;
            break;
            case 5: cout<<"Friday"<<endl;
            break;
            case 6: cout<<"Saturday"<<endl;
            break;
            case 7: cout <<"Sunday"<<endl;
            break;
            default: cout <<"Invalid"<<endl; // Handles any day value not covered by cases 1-7
            break;
        }
    }
};