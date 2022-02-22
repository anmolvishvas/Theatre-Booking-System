// including the header files
#include "event.h"
#include "event_comedy.h"

// library for string
#include <string>


// defining the Stand Up Comedyclass constructor
Stand_Up_Comedy::Stand_Up_Comedy(std::string event_type, std::string event_id, std::string event_name,std::string event_timing, int available_seats) : Event(event_type, event_id, event_name, event_timing)
{
    this->available_seats = available_seats;
}

// function to display details of the event
void Stand_Up_Comedy::DisplayDetails(){
    std::cout <<"\t\tEvent Type: " << event_type<< "\n\t\tShow name: " << event_name << "\n\t\tTiming:" << event_timing << "\n\t\tAvailability (seating):" << available_seats << std::endl;
}

// function to display the event detail
void Stand_Up_Comedy::Display(){
    // outputing the event type and event name
    std::cout <<"|\t\tEvent Type: "<< event_type << "\t\t       |\n|\t\tShow name: " << event_name << "\t\t       |" << std::endl;
}

// setter functions that will be used for the test cases
void Stand_Up_Comedy::setEventType(std::string type){
    event_type = type;
}
void Stand_Up_Comedy::setEventID(std::string id){
    event_id = id;
}
void Stand_Up_Comedy::setEventName(std::string name){
    event_name = name;
}
void Stand_Up_Comedy::setEventTiming(std::string timing){
    event_timing = timing;
}
void Stand_Up_Comedy::setEventAvailability(int seatings){
    available_seats = seatings;
}

// getter functions that will be used for the test cases
std::string Stand_Up_Comedy::getEventType(){
    return event_type;
}
std::string Stand_Up_Comedy::getEventID(){
    return event_id;
}
std::string Stand_Up_Comedy::getEventName(){
    return event_name;
}
std::string Stand_Up_Comedy::getEventTiming(){
    return event_timing;
}
int Stand_Up_Comedy::getEventAvailability(){
    return available_seats;
}



