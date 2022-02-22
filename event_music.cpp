// including the header files
#include "event.h"
#include "event_music.h"

// library for string
#include <string>

// defining the Live music class constructor
Live_Music::Live_Music(std::string event_type, std::string event_id, std::string event_name,std::string event_timing, int available_standings) : Event(event_type, event_id, event_name, event_timing)
{
    this->available_standings = available_standings;
}

// function to display details of the event
void Live_Music::DisplayDetails(){
    std::cout <<"\t\tEvent Type: " << event_type<< "\n\t\tShow name: " << event_name << "\n\t\tTiming:" << event_timing << "\n\t\tAvailability (standings):" << available_standings << std::endl;
}

// function to display the event detail
void Live_Music::Display(){
    // outputing the event type and event name
    std::cout <<"|\t\tEvent Type: "<< event_type << "\t\t\t       |\n|\t\tShow name: " << event_name << "\t\t       |" << std::endl;
}

// setter functions that will be used for the test cases
void Live_Music::setEventType(std::string type){
    event_type = type;
}
void Live_Music::setEventID(std::string id){
    event_id = id;
}
void Live_Music::setEventName(std::string name){
    event_name = name;
}
void Live_Music::setEventTiming(std::string timing){
    event_timing = timing;
}
void Live_Music::setEventAvailability(int standings){
    available_standings = standings;
}

// getter functions that will be used for the test cases
std::string Live_Music::getEventType(){
    return event_type;
}
std::string Live_Music::getEventID(){
    return event_id;
}
std::string Live_Music::getEventName(){
    return event_name;
}
std::string Live_Music::getEventTiming(){
    return event_timing;
}
int Live_Music::getEventAvailability(){
    return available_standings;
}