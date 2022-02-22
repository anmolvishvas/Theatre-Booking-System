// including the header files
#include "event.h"
#include "event_film.h"

// library for string
#include <string>

// defining the Film class constructor
Film::Film(std::string event_type, std::string event_id, std::string event_name,std::string event_timing, int available_seats) : Event(event_type, event_id, event_name, event_timing)
{
    this->available_seats = available_seats;
}

// function to display details of the event
void Film::DisplayDetails(){
    std::cout <<"\t\tEvent Type: "<<" " << event_type<< "\n\t\tShow name:" << " " << event_name<< "\n\t\tTiming:" << " " << event_timing<< "\n\t\tAvailability (seats):" << " " << available_seats<< std::endl;
    std::cout << "_______________________________________________________" << std::endl;
    std::cout << "\n" << std::endl;
}

// function to display the event detail
void Film::Display() {
    std::cout <<"|\t\tEvent Type: "<< event_type << "\t\t\t       |\n|\t\tShow name: " << event_name << "\t\t       |" << std::endl;
}

// setter functions that will be used for the test cases
void Film::setEventType(std::string type){
    event_type = type;
}
void Film::setEventID(std::string id){
    event_id = id;
}
void Film::setEventName(std::string name){
    event_name = name;
}
void Film::setEventTiming(std::string timing){
    event_timing = timing;
}
void Film::setEventAvailability(int seatings){
    available_seats = seatings;
}

// getter functions that will be used for the test cases
std::string Film::getEventType(){
    return event_type;
}
std::string Film::getEventID(){
    return event_id;
}
std::string Film::getEventName(){
    return event_name;
}
std::string Film::getEventTiming(){
    return event_timing;
}
int Film::getEventAvailability(){
    return available_seats;
}

