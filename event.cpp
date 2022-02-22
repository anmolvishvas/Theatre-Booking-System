// calling the event class header file
#include "event.h"

// defining the Event class constructor
Event::Event(std::string event_type,std::string event_id, std::string event_name,std::string event_timing)
{
    this->event_type = event_type;
    this->event_id = event_id;
    this->event_name = event_name;
    this->event_timing = event_timing;
}

// Main Menu function
void Event::Main_Menu() {
    // to clear the screen
    system("clear");
    // outputing the main menu
    std::cout << "_____________________Theatre Booking System_____________________" << std::endl;
    std::cout << "------------------------------Menu-----------------------------" << std::endl;
    std::cout << "|                                                              |"<< std::endl;
    std::cout << "|         (1) Add booking for an event                         |" << std::endl;
    std::cout << "|         (2) Cancel / Refund a booking                        |" << std::endl;
    std::cout << "|         (3) List all events                                  |" << std::endl;
    std::cout << "|         (4) List details and availability of a given event   |" << std::endl;
    std::cout << "|         (5) Exit                                             |" << std::endl;
    std::cout << "_______________________________________________________________" << std::endl;
    std::cout << "\n"<< std::endl;
    std::cout << "\tWhich functionality would you like to use? \n \t\t\tEnter a number: ";
}

// Function to display all the events
void Event::Display() {
    std::cout <<"\t\tEvent Type: "<< event_type << "\n\t\tShow name: " << event_name << "\n\t\tShow time: " << event_timing << std::endl;
}

// Function to display the event type menu
void Event::ListEventMenu() {
    // outputing the menu
    std::cout << "*                  List of the type of event:                  *" << std::endl;
    std::cout << "|              (1) Live Music                                  |" << std::endl;
    std::cout << "|              (2) Stand Up Comedy                             |" << std::endl;
    std::cout << "|              (3) Film                                        |" << std::endl;
    std::cout << "|                                                              |"<< std::endl;
    std::cout << "*                  Other options:                              *" << std::endl;
    std::cout << "|              (4) Go back to menu                             |" << std::endl;
    std::cout << "|              (5) Exit                                        |" << std::endl;
    std::cout << "_______________________________________________________________" << std::endl;
    std::cout << "\n"<< std::endl;
}

// setter functions that will be used for the test cases
void Event::setEventType(std::string type){
    event_type = type;
}
void Event::setEventID(std::string id){
    event_id = id;
}
void Event::setEventName(std::string name){
    event_name = name;
}
void Event::setEventTiming(std::string timing){
    event_timing = timing;
}

// getter functions that will be used for the test cases
std::string Event::getEventType(){
    return event_type;
}
std::string Event::getEventID(){
    return event_id;
}
std::string Event::getEventName(){
    return event_name;
}
std::string Event::getEventTiming(){
    return event_timing;
}
