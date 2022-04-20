#include <iostream>
#include <string>

using namespace std;

/* Define the traffic sign enum as a type. This is the same way
   we can create an enum in C */
typedef enum {
    red,
    yellow,
    green,
} trafficSignState;

/* Overloading the prefix ++ operator for the trafficSignState enum */
trafficSignState &operator++(trafficSignState& orig) {
    /* Enum can be implicitally converted to integers, integers needs
       to be explicitally converted to enums */
    orig = static_cast<trafficSignState>(orig + 1);

    if(orig > green) {
        orig = red;
    }

    return(orig);
}

/* We can determine the base type of the enum. This is new to C++.
   We can't use red, yellow and green as they are already used */
typedef enum : int {
    red_t,
    yellow_t,
    green_t,
} trafficSignState_t;

/* Override the stream operator */
ostream &operator<<(ostream &output, const trafficSignState_t &state) {
    string stateStr;

    switch(state) {
        case red:
            stateStr = "red"; 
            break;
        case yellow:
            stateStr = "yellow"; 
            break;
        case green:
            stateStr = "green"; 
            break;
        default:
            stateStr = "invalid"; 
    }

    output << stateStr;

    return output;            
}

/* A function to print the name of the traffic sign state */
void printTrafficSignState(trafficSignState tsColor) {
    switch(tsColor) {
        case red:
            cout << "Traffic sign red state" << endl; 
            break;
        case yellow:
            cout << "Traffic sign yellow state" << endl; 
            break;
        case green:
            cout << "Traffic sign green state" << endl; 
            break;
        default:
            cout << "Traffic sign unknown state" << endl; 
    }
}

int main()
{
    /* Create a variable to hold the traffic sign state */
    trafficSignState tsState = green;

    /* Pass the value to be printed */
    printTrafficSignState(tsState);

    /* Unscoped enums can be implicitily converted to integer types */
    cout << "Traffic sign state value: " << tsState << endl;
    int stateAsInteger = ++tsState;
    cout << "Traffic sign state value again: " << stateAsInteger << endl;

    /* Using stream overloaded operator */
    trafficSignState_t tsState_2 = green_t;
    cout << "Final traffic sign state: " << tsState_2 << endl;

    return 0;
}