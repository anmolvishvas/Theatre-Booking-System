#ifndef _EVENT_H_
#define _EVENT_H_

#include <string> // library for strings
#include <iostream> //  Library for standard input / output streams
#include <fstream> // library to operate with files
#include <stdlib.h> // library for built-in functions to clear the system

class Event {
  // protected variables that can be used into the derived classes
  protected:
    // declaring variables
    std::string event_type;
    std::string event_id;
    std::string event_name;
    std::string event_timing;

  public:
    //event constructor 
    Event(std::string event_type, std::string event_id, std::string event_name,std::string event_timing);
    // declaring functions
    void Main_Menu();
    void Display();
    void ListEventMenu();
    // declaring setter functions
    void setEventType(std::string event_type);
    void setEventID(std::string event_id);
    void setEventName(std::string event_name);
    void setEventTiming(std::string event_timing);
    // declaring getter functions
    std::string getEventType();
    std::string getEventID();
    std::string getEventName();
    std::string getEventTiming();
};


#endif
