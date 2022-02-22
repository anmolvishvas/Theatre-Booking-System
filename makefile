# calling c++ compiler
CXX = g++
# compiler flags: 
# -g to add debugging informations to the executable files
# -Wall to turn on the most compiler warning
CXXFLAGS = -g -Wall -Wextra

# the build target
.PHONY: all

# naming the target as theater
all: theatre

# targets needed to bring the executable up to date
theatre: main.cpp event.o event_music.o event_film.o event_comedy.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# target for the event_comedy.o
event_comedy.o: event_comedy.cpp event.o
	$(CXX) $(CXXFLAGS) -c $^

# target for the event_film.o
event_film.o: event_film.cpp event.o
	$(CXX) $(CXXFLAGS) -c $^

# target for the event_music.o
event_music.o: event_music.cpp event.o
	$(CXX) $(CXXFLAGS) -c $^

# target for the event.o
event.o: event.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
# removing all the files with the name theatre.exe
clean:
	rm *~ *.o theatre.exe
