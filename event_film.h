#ifndef _EVENT_FILM_H_
#define _EVENT_FILM_H_

// including the base class header file
#include "event.h"

#include <string> // library for strings
#include <iostream> //  Library for standard input / output streams
#include <fstream> // library to operate with files
#include <stdlib.h> // library for built-in functions to clear the system

class Film : public Event {
 private:
    // declaring variables
    int available_seats ;
 public:
 //film constructor
  Film(std::string event_type, std::string event_id, std::string event_name,std::string event_timing, int available_seats);
  // declaring functions
  void DisplayDetails();
  void Display();
  // declaring setter functions
  void setEventType(std::string event_type);
  void setEventID(std::string event_id);
  void setEventName(std::string event_name);
  void setEventTiming(std::string event_timing);
  void setEventAvailability(int available_seats);
  // declaring getter functions
  std::string getEventType();
  std::string getEventID();
  std::string getEventName();
  std::string getEventTiming();
  int getEventAvailability();
};

#endif