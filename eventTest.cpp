#define CATCH_CONFIG_MAIN
// including catch file
#include "catch.hpp"

#include "event.h" // including (calling) event base class
#include "event_music.h" // including (calling) live music derived class
#include "event_comedy.h" // including (calling) stand up comedy derived class
#include "event_film.h" // including (calling) film derived class

// test case for the base class
TEST_CASE("Event Base Class Test", "[Event]")
{
    // calling the event class
    Event event("", "", "", "");

    // setting some values into each variables of the event class
    event.setEventType("Event Type");
    event.setEventID("Event ID");
    event.setEventName("Event Name");
    event.setEventTiming("Event Timing");

    // checking if the setter functions passed the values
    REQUIRE(event.getEventType() == "Event Type");
    REQUIRE(event.getEventID() == "Event ID");
    REQUIRE(event.getEventName() == "Event Name");
    REQUIRE(event.getEventTiming() == "Event Timing");
    REQUIRE_NOTHROW(event.Display());
}

// test case for the live music derived class
TEST_CASE("Live Music Derived Class Test", "[Live Music]")
{
    // calling the live music class
    Live_Music music("", "", "", "", 0);

    // setting some values into each variables of the live music class
    music.setEventType("Live Music");
    music.setEventID("L20");
    music.setEventName("John Mayer Show");
    music.setEventTiming("2h");
    music.setEventAvailability(300);
 
    // checking if the setter functions passed the values
    REQUIRE(music.getEventType() == "Live Music");
    REQUIRE(music.getEventID() == "L20");
    REQUIRE(music.getEventName() == "John Mayer Show");
    REQUIRE(music.getEventTiming() == "2h");
    REQUIRE(music.getEventAvailability() == 300);
    REQUIRE_NOTHROW(music.Display());
}

// test case for the film derived class
TEST_CASE("Film Derived Class Test", "[Film]")
{
    // calling the film class
    Film film("", "", "", "", 0);

    // setting some values into each variables of the film class
    film.setEventType("Film");
    film.setEventID("F10");
    film.setEventName("Spiderman 2D Show");
    film.setEventTiming("3h");
    film.setEventAvailability(200);
 
    // checking if the setter functions passed the values
    REQUIRE(film.getEventType() == "Film");
    REQUIRE(film.getEventID() == "F10");
    REQUIRE(film.getEventName() == "Spiderman 2D Show");
    REQUIRE(film.getEventTiming() == "3h");
    REQUIRE(film.getEventAvailability() == 200);
    REQUIRE_NOTHROW(film.Display());
}

// test case for the stand up comedy derived class
TEST_CASE("Stand Up Comedy Derived Class Test", "[Stand Up Comedy]")
{
    // calling the stand up comedy class
    Stand_Up_Comedy standupComedy("", "", "", "", 0);

    // setting some values into each variables of the stand up comedy class
    standupComedy.setEventType("Stand Up Comedy");
    standupComedy.setEventID("C08");
    standupComedy.setEventName("Mr Bean show");
    standupComedy.setEventTiming("1h");
    standupComedy.setEventAvailability(200);
 
    // checking if the setter functions passed the values
    REQUIRE(standupComedy.getEventType() == "Stand Up Comedy");
    REQUIRE(standupComedy.getEventID() == "C08");
    REQUIRE(standupComedy.getEventName() == "Mr Bean show");
    REQUIRE(standupComedy.getEventTiming() == "1h");
    REQUIRE(standupComedy.getEventAvailability() == 200);
    REQUIRE_NOTHROW(standupComedy.Display());
}