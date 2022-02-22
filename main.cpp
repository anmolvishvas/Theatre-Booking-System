#include <iostream> //  Library for standard input / output streams
#include <stdlib.h> // library for built-in functions to clear the system
#include <fstream> // library to operate with files
#include <string> // library for strings
#include <list> // library for lists
#include <sstream> //library for string stream

#include "event.h" // including (calling) event base class
#include "event_music.h" // including (calling) live music derived class
#include "event_comedy.h" // including (calling) stand up comedy derived class
#include "event_film.h" // including (calling) film derived class

// calling all the functions
int update_seats(std::string show_name,int number_seats_booked);
void bookingConfirmation(std::string show_name);
void live_musicBooking();
void Display_LiveMusic() ;
void film_booking();
void Display_Film();
void updateAllocatedSeats(int reserved_seats, int event);
void bookingConfirmation_Comedy(std::string show_name);
void stand_up_booking();
void Display_StandUpComedy();
void type_EventSelection();
void addBooking();
void updateEventsfile(int temp, std::string show_name);
void updateBookingFile(std::string customer_name);
void cancelAllocatedSeats(int temp_comedy, int event);
void cancelBooking();
void functionality();
void readFile_DisplayDetails();
void listDetails();
void readFile_DisplayEvents();
void listEvents();
int main();

// ---------------------------------------Function for the add booking functionality---------------------------------------------------------------------------------------

// function to update seats when booking confirmed using the show name and number of seats booked
int update_seats(std::string show_name,int number_seats_booked) {
    // declaring variables
    int updated_seats;
    int temp;
    // declaration of list
    std::list<std::string> updatedList;

    // opening events.txt file in reading mode
    std::ifstream file;
    file.open("Events.txt", std::ios::in);
    // checking if file is open
    if (file.is_open()) {
        // declaring line as string
        std::string line;
        // looping through the file using while loop
        while(std::getline(file, line))
        {
            // converting line into string stream
            std::stringstream stream(line);
            // declaring variable for each data in file
            std::string e_id, e_type, e_name, time,availability;
            // assigning the 1st value to the e_type variable to distinguish type of event
            std::getline(stream, e_type, ',');
            // assigning the 2nd value to the e_if variable to distinguish event id
            std::getline(stream, e_id, ',');
            // assigning the 3rd value to the e_name variable to distinguish name of event
            std::getline(stream, e_name, ',');
            // assigning the 4th value to the time variable to distinguish time of event
            std::getline(stream, time, ',');
            // assigning the 5th value to the availability variable to distinguish the availability
            std::getline(stream, availability);
            // checking if show name exist in the file 
           if (std::string(e_name) == show_name)
           {                
               // converting availability into integer
                temp=stoi(availability);
           }

        }
        file.close();
    }
    // substracting the number of seats available in the file with the number of seats booked 
    updated_seats = temp-number_seats_booked;

    // opening events.txt file in reading mode
    std::ifstream updatedFile;
    updatedFile.open("Events.txt", std::ios::in);
    // checking if file is open
    if (updatedFile.is_open()) {
        // declaring line as string
        std::string line;
        // looping through the file using while loop
        while(std::getline(updatedFile, line))
        {
            // converting line into string stream
            std::stringstream stream(line);
            // declaring variable for each data in file
            std::string e_id, e_type, e_name, time,availability;
            // assigning the 1st value to the e_type variable to distinguish type of event
            std::getline(stream, e_type, ',');
            // assigning the 2nd value to the e_if variable to distinguish event id
            std::getline(stream, e_id, ',');
            // assigning the 3rd value to the e_name variable to distinguish name of event
            std::getline(stream, e_name, ',');
            // assigning the 4th value to the time variable to distinguish time of event
            std::getline(stream, time, ',');
            // assigning the 5th value to the availability variable to distinguish the availability
            std::getline(stream, availability);
            // checking if show name exist in the file 
           if (std::string(e_name) == show_name)
           {
               // pushing the updated data into the list for that specific show name
                updatedList.push_back(e_type+","+e_id+","+e_name+ ","+time+ ","+std::to_string(updated_seats));
                updatedList.push_back("\n");
                continue;
           }
            //  pushing the lines of file into the list for the other datas  
            updatedList.push_back(line);
            updatedList.push_back("\n");
        }
        updatedFile.close();
    }

    // opening the events.txt file in write mode
    std::fstream newFile;
    newFile.open("Events.txt",std::ios::out);
    // checking if the file is open
    if(newFile.is_open()){
        // looping throught the list
        for(std::string lines:updatedList){
            // pushing the new lines into the file using the list
            newFile<<lines;
        }
    }
    newFile.close();
    
    return number_seats_booked;
}

// function to confirm booking using the show name as parameter
void bookingConfirmation(std::string show_name){
    // declaring variables
    std::string customer_name, input, type, id, name, timing;
    int no_ticket, select, temp;

    // opening the events.txt file in read mode
    std::ifstream file;
    file.open("Events.txt", std::ios::in);
    // checking if file is open
    if (file.is_open()) {
        // declaring line as string
        std::string line;
        // looping through the file using while loop
        while(std::getline(file, line))
        {
            // converting line into string stream
            std::stringstream stream(line);
            // declaring variable for each data in file
            std::string e_id, e_type, e_name, time,availability;
            // assigning the 1st value to the e_type variable to distinguish type of event
            std::getline(stream, e_type, ',');
            // assigning the 2nd value to the e_if variable to distinguish event id
            std::getline(stream, e_id, ',');
            // assigning the 3rd value to the e_name variable to distinguish name of event
            std::getline(stream, e_name, ',');
            // assigning the 4th value to the time variable to distinguish time of event
            std::getline(stream, time, ',');
            // assigning the 5th value to the availability variable to distinguish the availability
            std::getline(stream, availability);
            
            // checking if show name exist in the file 
            if (std::string(e_name) == show_name)
            {
                type = e_type;
                id = e_type;
                name = e_name;
                timing = time;
                // converting availability into integer
                temp=stoi(availability);
            }
        }
        file.close();
    }
    // to clear the console
    system("clear");
    std::cout << "_____________________Theatre Booking System_____________________" << std::endl;

    // checking if the show name corresponds to the one specified
    if (show_name == " John Mayer Show") {
        // calling Live music class
        Live_Music music(type,id,name,timing,temp);
        // calling the main function DisplayDetails() function from the live music class
        music.DisplayDetails();
    }
    // checking if the show name corresponds to the one specified
    if (show_name == " Christophe Mae Show") {
            // calling Live music class
        Live_Music music(type,id,name,timing,temp);
            // calling the main function DisplayDetails() function from the live music class
        music.DisplayDetails();
    }
    // checking if the show name corresponds to the one specified
    if (show_name == " King of Comedy Show") {
        // calling Stand Up comedy function class
        Stand_Up_Comedy comedy(type,id,name,timing,temp);
        // calling the main function DisplayDetails() function from the stand up comedy class
        comedy.DisplayDetails();
    }
    // checking if the show name corresponds to the one specified
    if (show_name == " Mr Bean show") {
        // calling Stand Up comedy function class
        Stand_Up_Comedy comedy(type,id,name,timing,temp);
        // calling the main function DisplayDetails() function from the stand up comedy class
        comedy.DisplayDetails();
    }
    // checking if the show name corresponds to the one specified
    if (show_name == " Spiderman 2D Show") {
        // calling film function class
        Film film(type,id,name,timing,temp);
        // calling the main function DisplayDetails() function from the film class
        film.DisplayDetails();
    }
    // checking if the show name corresponds to the one specified
    if (show_name == " Spiderman 3D Show") {
        // calling film function class
        Film film(type,id,name,timing,temp);
        // calling the main function DisplayDetails() function from the film class
        film.DisplayDetails();
    }

    std::cout << "Booking for " << show_name << std::endl;
    std::cout << "Enter your name: ";
    // taking inputs from the user
    std::cin >> customer_name;
    std::cout << "How many tickets would you like to book? ";
    // taking inputs from the user
    std::cin >> no_ticket;

    // Checking if ticket number requested is not greater than availability into the file
    while(no_ticket >= temp){
        // displaying an error message 
        std::cout << "Invalid! \nAvailability:"<<temp <<std::endl;
        std::cout << "\nHow many tickets would you like to book? \n(Number of ticket should be less than Availability):";
        std::cin >> no_ticket;
    } 
    std::cout << "_______________________________________________________________" << std::endl;

    // to clear the console
    system("clear");
    std::cout << "_____________________Theatre Booking System_____________________" << std::endl;
    // displaying the booking details
    std::cout << "\n";
    std::cout << "\tBooking details:\n\n\tCustomer Name: "<<customer_name<<"\n\tNumber of tickets booked: "<<no_ticket<<std::endl;
    std::cout << "\n";
    std::cout << "_______________________________________________________________" << std::endl;
    std::cout << "\n";

    std::cout << "Confirm Booking? y or n?";
    do {
        // taking input from user
        std::cin>>input;

        // if user input 'y'
        if (input == "y") {
            // opening the booking.txt file in writing and append mode
            std::fstream booking_file;
            booking_file.open("booking.txt", std::ios::out|std::ios::app);
            // checking if file is open
            if (booking_file.is_open()) {
                // writing into the file
                booking_file<<show_name<<","<<customer_name<<","<<no_ticket<<std::endl;
                booking_file.close();
            }
            // calling update seats function using the show name and number of tickets booked by the user
            update_seats(show_name,no_ticket);
            
            // checking if the shown name is the same as the 1st stand up comedy
            if (show_name == " King of Comedy Show"){
                // initializing event to 1
                int event = 1;
                // calling the update Allocated seats function with the number of ticket and event as parameters
                updateAllocatedSeats(no_ticket, event);

                std::cout << "Booking confirmed! Thank You!\n\n";
                std::cout << "Press (1) to go back to menu"<<std::endl;

                do {
                    // taking input from user
                    std::cin>>select;
                    // if user input 1
                    if (select == 1) {
                        // calling main function
                        main();
                        break;
                    }

                    // validation
                    while (std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        continue;
                    }
                    std::cout << "Invalid! press (1) to go back to menu: ";
                } while(select!=1);

            }
            // checking if the shown name is the same as the 2nd stand up comedy
            else if(show_name == " Mr Bean show"){
                // initializing event to 2
                int event = 2;
                // calling the update Allocated seats function with the number of ticket and event as parameters
                updateAllocatedSeats(no_ticket, event);

                std::cout << "Booking confirmed! Thank You!\n\n";
                std::cout << "Press (1) to go back to menu"<<std::endl;

                do {
                    // taking input from user
                    std::cin>>select;
                    // if user input 1
                    if (select == 1) {
                        // calling main function
                        main();
                        break;
                    }
                    // validation
                    while (std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        continue;
                    }
                    std::cout << "Invalid! press (1) to go back to menu: ";
                } while(select!=1);
            }
            else {

                std::cout << "Booking confirmed! Thank You!\n\n";
                std::cout << "Press (1) to go back to menu"<<std::endl;

                do {
                    // taking input from the user
                    std::cin>>select;
                    // if user press 1
                    if (select == 1) {
                        // calling main function
                        main();
                        break;
                    }

                    // validation
                    while (std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(256,'\n');
                        continue;
                    }
                    std::cout << "Invalid! press (1) to go back to menu: ";
                } while(select!=1);
            }  
        }
        // if user inputs n
        if (input == "n") {
            // calling main function
            main();
            break;
        }
        std::cout << "Invalid! Enter \'y'or \'n' :"; 
    } while (input != "y" && input != "n");
}

// function for film event type booking
void film_booking() {
    // declaring of variables
    int type_selection;

    // displaying the other options
    std::cout << "\n"<< std::endl;
    std::cout << "(3) go back to menu"<< std::endl;
    std::cout << "(4) exit"<< std::endl;
    std::cout << "For which one would you like to book?";

    do {
        // taking the input from the user
        std::cin >> type_selection;

        // if the user press 1
        if (type_selection == 1)
        {
            std::string show_name = " Spiderman 2D Show";
            // calling the booking confirmation function using the show name as parameter
            bookingConfirmation(show_name); 
            break;      
        }

        // if the user press 2
        if (type_selection == 2){
            std::string show_name = " Spiderman 3D Show";
            // calling the booking confirmation function using the show name as parameter
            bookingConfirmation(show_name);
            break;      
        }

        // if the user press 3
        if (type_selection == 3){
            // calling main function
            main();
            break;      
        }

        // if the user press 4
        if (type_selection == 4)
        {
            EXIT_SUCCESS;
            break;      
        }

        // validation
        while (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            continue;
        }
        std::cout << "\tInvalid!, Enter a number between 1 and 4: ";
    } while (type_selection != 1 && type_selection != 2 && type_selection != 3 && type_selection != 4);
}

// function to display film show details
void Display_Film() {
    // declaring variables
    int available;
    int count = 1;

    std::cout << "_____________________Theatre Booking System_____________________" << std::endl;
    std::cout << "*                  List of Films                               *"<< std::endl;

    // opening the events.txt files in a reading mode
    std::ifstream file;
    file.open("Events.txt", std::ios::in);
    // checking if file is open
    if (file.is_open()) {
        // declaring line as string
        std::string line;
        // looping through the file using a while loop
        while(std::getline(file, line))
        {
            // converting the line into string stream
            std::stringstream stream(line);
            // declaring variable for each data in file 
            std::string e_id, e_type, e_name, time,availability;
            // assigning the 1st value to the e_type variable to distinguish type of event
            std::getline(stream, e_type, ',');
            // assigning the 2nd value to the e_if variable to distinguish event id
            std::getline(stream, e_id, ',');
            // assigning the 3rd value to the e_name variable to distinguish name of event
            std::getline(stream, e_name, ',');
            // assigning the 4th value to the e_time variable to distinguish time of event
            std::getline(stream, time, ',');
            // assigning the 5th value to the availability variable to distinguish the availability
            std::getline(stream, availability);

            // checking if there is a film type of event into the file  
            if (std::string (e_type) == "Film")
            {
                std::cout << "|                                                              |"<< std::endl;   
                std::cout << "+               (" << count++ << ")                                            +" << std::endl;
                // converting string into integer
                available = stoi(availability);
                // calling the film derived class
                Film film(e_type,e_id,e_name,time,available);
                // calling the Display() function from the film class
                film.Display();
            }
        }
        std::cout << "________________________________________________________________" << std::endl;
    }
    file.close();
}

// function to update the allocated seats for the stand up comedy
void updateAllocatedSeats(int reserved_seats, int event) {
    // declaring variables
    int target, no_reserved_seat, seatState, line_file=0;

    std::cout << "Which seat would you like to book? Enter a number from 1 to 200:\n" ;

    // for loop to ask the user the seat number for each ticket
    for (int i = 1; i <= reserved_seats; i++ ) {
        while(true){
            std::cout<<"Ticket "<<i<<":";
            std::cin>>no_reserved_seat;

            // if its the 1st stand up comedy event
            if (event==1){
                // target line will start from line 12
                target = 12+no_reserved_seat;
            }
            else{
                // else target line will start from line 219
                target = 219+no_reserved_seat;
            }
            
            // opening events.txt file in read mode
            std::ifstream file;
            file.open("Events.txt", std::ios::in);
            // checking if file is open
            if (file.is_open()){
                // declaring line as string
                std::string line;
                // setting line_file to 0
                line_file = 0;
                while (getline(file,line)){
                    // incremeting line_file each time it will loop through the file
                    line_file++;
                    if (line_file==target){
                        // converting string to integer
                        seatState = stoi(line);
                    }
                }
            }
            file.close();

            // if seat state is 9, means its already booked, an error message will be displayed
            if (seatState==9){
                std::cout<<"Sorry this seat number is already booked. Choose another number for:\n";   
                continue;

            }
            // if seat state is 0, means is available
            else if(seatState == 0){
                // declaring a list
                std::list<std::string> updatedList;
                // declaring a variable
                int file_line;
                
                // opening events.txt file in reading mode
                std::fstream file1;
                file1.open("Events.txt", std::ios::in);

                // checking if file is open
                if (file1.is_open()){
                    // declaring line as string
                    std::string line;
                    // setting file_line to 0
                    file_line = 0;
                    while(getline(file1, line)){
                        file_line++;
                        if (file_line == target){
                            // updating the list for that specific line
                            updatedList.push_back("9");
                            updatedList.push_back("\n");
                            continue;
                        }
                        // pushing the other lines into the list
                        updatedList.push_back(line);
                        updatedList.push_back("\n");
                    }
                    file1.close();
                }
                // opening the events.txt file is write mode
                std::fstream file2;
                file2.open("Events.txt", std::ios::out);
                // checking if file is open
                if (file2.is_open()){
                    for (std::string lines:updatedList) {
                        // writing the file using the data in the list
                        file2<<lines;
                    }
                    break;
                }
            }
        }
    }
}

// function for stand-up comedy event type booking
void stand_up_booking() {
    // declaring of variables
    int type_selection;    

    // displaying the other options
    std::cout << "\n"<< std::endl;    
    std::cout << "(3) go back to menu"<< std::endl;
    std::cout << "(4) exit"<< std::endl;
    std::cout << "For which one would you like to book?";

    do {
        // taking the input from the user
        std::cin >> type_selection;

        // if the user press 1
        if (type_selection == 1)
        {
            std::string show_name = " King of Comedy Show";
            // calling the booking confirmation function using the show name as parameter
            bookingConfirmation(show_name);
            break; 
        }

        // if the user press 2
        if (type_selection == 2){
            std::string show_name = " Mr Bean show";
            // calling the booking confirmation function using the show name as parameter
            bookingConfirmation(show_name);
            break;
        }

        // if the user press 3
        if (type_selection == 3){
            // calling main function
            main();
            break;
        }

        // if the user press 4 
        if (type_selection == 4)
        {
            EXIT_SUCCESS;
            break;
        }

        // validation
        while (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            continue;
        }

        std::cout << "\tInvalid!, Enter a number between 1 and 4: ";
    } while (type_selection != 1 && type_selection != 2 && type_selection != 3 && type_selection != 4);
}

// function to display stand up comedy show details
void Display_StandUpComedy() {
    // declaring variables
    int available;
    int count = 1;

    std::cout << "_____________________Theatre Booking System_____________________ " << std::endl;
    std::cout << "*                  List of Stand Up Comedies                   *"<< std::endl;
    
    // opening the events.txt files in a reading mode
    std::ifstream file;
    file.open("Events.txt", std::ios::in);
    
    // checking if file is open
    if (file.is_open()) {
        // declaring line as string
        std::string line;
        // looping through the file using a while loop
        while(std::getline(file, line))
        {            
            // converting the line into string stream
            std::stringstream stream(line);
            // declaring variable for each data in file
            std::string e_id, e_type, e_name, id, availability;
            // assigning the 1st value to the e_type variable to distinguish type of event
            std::getline(stream, e_type, ',');
            // assigning the 2nd value to the e_if variable to distinguish event id
            std::getline(stream, e_id, ',');
            // assigning the 3rd value to the e_name variable to distinguish name of event
            std::getline(stream, e_name, ',');
            // assigning the 4th value to the e_time variable to distinguish time of event
            std::getline(stream, id, ',');
            // assigning the 5th value to the availability variable to distinguish the availability
            std::getline(stream, availability);

            // checking if there is a stand up comedy type of event into the file
            if (std::string (e_type) == "Stand Up Comedy")
            {
                std::cout << "|                                                              |"<< std::endl;
                std::cout << "+               (" << count++ << ")                                            +" << std::endl;
                // converting string into integer
                available = stoi(availability);
                // calling the stand up comedy derived class
                Stand_Up_Comedy stand_up_comedy(e_type,e_id,e_name,id,available);
                // calling the Display() function from the stand up comedy class
                stand_up_comedy.Display();
            }
        }
        std::cout << "________________________________________________________________" << std::endl;
    }
    file.close();
}

// function for live music event type booking
void live_musicBooking() {
    // declaring of variables
    int type_selection;

    // displaying the other options
    std::cout << "\n"<< std::endl;
    std::cout << "(3) go back to menu"<< std::endl;
    std::cout << "(4) exit"<< std::endl;
    std::cout << "For which one would you like to book?";

    do {
        // taking the input from the user
        std::cin >> type_selection;

        // if the user press 1
        if (type_selection == 1)
        {
            std::string show_name = " John Mayer Show";
            // calling the booking confirmation function using the show name as parameter
            bookingConfirmation(show_name);   
            break;
        }

        // if the user press 2
        if (type_selection == 2){
            std::string show_name = " Christophe Mae Show";
            // calling the booking confirmation function using the show name as parameter
            bookingConfirmation(show_name);
            break;
        }

        // if the user press 3
        if (type_selection == 3){
            // calling main function
            main();
            break;
        }

        // if the user press 1
        if (type_selection == 4)
        {
            EXIT_SUCCESS;
            break;
        }

        // validation
        while (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            continue;
        }

        std::cout << "\tInvalid!, Enter a number between 1 and 4: ";
    } while(type_selection != 1 && type_selection != 2 && type_selection != 3 && type_selection != 4);
}

// function to display live music show details
void Display_LiveMusic() {
    // declaring variables
    int count = 1;
    int available;

    std::cout << "_____________________Theatre Booking System_____________________" << std::endl;
    std::cout << "*                  List of Live Music Shows                    *"<< std::endl;

    // opening the events.txt files in a reading mode
    std::ifstream file;
    file.open("Events.txt", std::ios::in);
    // checking if file is open
    if (file.is_open()) {
        // declaring line as string
        std::string line;
        // looping through the file using a while loop
        while(std::getline(file, line))
        {
            // converting the line into string stream
            std::stringstream stream(line);
            // declaring variable for each data in file
            std::string e_id, e_type, e_name, time, availability;
            // assigning the 1st value to the e_type variable to distinguish type of event
            std::getline(stream, e_type, ',');
            // assigning the 2nd value to the e_if variable to distinguish event id
            std::getline(stream, e_id, ',');
            // assigning the 3rd value to the e_name variable to distinguish name of event
            std::getline(stream, e_name, ',');
            // assigning the 4th value to the e_time variable to distinguish time of event
            std::getline(stream, time, ',');
            // assigning the 5th value to the availability variable to distinguish the availability
            std::getline(stream, availability);
           
            // checking if there is a live music type of event into the file
            if (std::string (e_type) == "Live Music")
            {
                std::cout << "|                                                              |"<< std::endl;
                std::cout << "+               (" << count++ << ")                                            +" << std::endl;
                // converting string into integer
                available = stoi(availability);
                // calling the Live music derived class
                Live_Music live_music(e_type,e_id,e_name,time,available);
                // calling the Display() function from the live_music class
                live_music.Display();
            }
        }
        std::cout << "________________________________________________________________" << std::endl;
    }
    file.close();
}

// function that will be used for the add booking part 
void type_EventSelection(){
    // declaring variable
    int type_selection;

    // Calling the event class
    Event event("","","","");
    // calling the list event menu from the base class
    event.ListEventMenu();

    std::cout << "Choose for which type of event would you like to book? >> ";

    do {
        // taking inputs from the user
        std::cin >> type_selection;

        // if the user press 1
        if (type_selection == 1)
        {
            // to clear the console
            system("clear");
            // calling the display live music function to display list of live music event
            Display_LiveMusic();
            // calling live_musicBooking function 
            live_musicBooking();
            break;
        
        }
        // if the user press 2
        if (type_selection == 2)
        {
            // to clear the console
            system("clear"); 
            // calling the display standup comedy function to display list of standup comedy event
            Display_StandUpComedy();
            // calling stand_up_comedy Booking function 
            stand_up_booking();    
            break;

        }
        // if the user press 3
        if (type_selection == 3)
        {
            // to clear the console
            system("clear"); 
            // calling the 
            Display_Film();
            film_booking();
            break;

        }
        // if the user press 4
        if (type_selection == 4)
        {
            // to clear the console
            system("clear"); 
            main();
            break;

        }
        // if the user press 5
        if (type_selection == 5)
        {
            // to clear the console
            system("clear"); 
            EXIT_SUCCESS;
            break;
        }

        // validation
        while (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            continue;
        }

        // displaying an error message if the user inputs another value than a number between 1 to 5
        std::cout << "\tInvalid!, Enter a number between 1 and 5: ";
    } while(type_selection != 1 && type_selection != 2 && type_selection != 3 && type_selection != 4 && type_selection != 5);
}

// function to add bookings
void addBooking() {
    // displaying the add booking part
    std::cout << "_____________________Theatre Booking System_____________________" << std::endl;
    std::cout << "---------------------------Add Booking--------------------------" << std::endl;
    std::cout << "|                                                              |"<< std::endl;

    // calling the type event selection function
    type_EventSelection();
}

// ---------------------------------------Function for the cancel booking functionality---------------------------------------------------------------------------------------

// function to update event.txt file
void updateEventsfile(int temp, std::string show_name){
    // declaring variable and list
    int temp2;
    int updated_seats;
    std::ifstream file1;
    std::list<std::string> updatedList;

    // opening events.txt file in reading mode
    file1.open("Events.txt", std::ios::in);
    // checking if file is open
    if (file1.is_open()) {
        // declaring line as string
        std::string line;
        // looping through the file using while loop
        while(std::getline(file1, line))
        {
            // converting line into string stream
            std::stringstream stream(line);
            // declaring variable for each data in file
            std::string e_id, e_type, e_name, time,availability;
            // assigning the 1st value to the e_type variable to distinguish type of event
            std::getline(stream, e_type, ',');
            // assigning the 2nd value to the e_if variable to distinguish event id
            std::getline(stream, e_id, ',');
            // assigning the 3rd value to the e_name variable to distinguish name of event
            std::getline(stream, e_name, ',');
            // assigning the 4th value to the time variable to distinguish time of event
            std::getline(stream, time, ',');
            // assigning the 5th value to the availability variable to distinguish the availability
            std::getline(stream, availability);
            // checking if show name exist in the file 
            if (std::string(e_name) == show_name)
            {
                // converting availability into integer
                temp2=stoi(availability);

            }
        }
        file1.close();
    }
    // adding the number of seats available in the file with the number of seats booked
    updated_seats = temp+temp2;

    // opening events.txt file in reading mode
    std::ifstream updatedFile;
    updatedFile.open("Events.txt", std::ios::in);
    // checking if file is open
    if (updatedFile.is_open()) {
        // declaring line as string
        std::string line;
        // looping through the file using while loop
        while(std::getline(updatedFile, line))
        {
            // converting line into string stream
            std::stringstream stream(line);
            // declaring variable for each data in file
            std::string e_id, e_type, e_name, time,availability;
            // assigning the 1st value to the e_type variable to distinguish type of event
            std::getline(stream, e_type, ',');
            // assigning the 2nd value to the e_if variable to distinguish event id
            std::getline(stream, e_id, ',');
            // assigning the 3rd value to the e_name variable to distinguish name of event
            std::getline(stream, e_name, ',');
            // assigning the 4th value to the time variable to distinguish time of event
            std::getline(stream, time, ',');
            // assigning the 5th value to the availability variable to distinguish the availability
            std::getline(stream, availability);
            // checking if show name exist in the file 
           if (std::string(e_name) == show_name)
           {
               // pushing the updated data into the list for that specific show name
                updatedList.push_back(e_type+","+e_id+","+e_name+ ","+time+ ","+std::to_string(updated_seats));
                updatedList.push_back("\n");
                continue;
           }
            //  pushing the lines of file into the list for the other datas  
            updatedList.push_back(line);
            updatedList.push_back("\n");
        }
        updatedFile.close();
    }

    // opening the events.txt file in write mode
    std::fstream newFile;
    newFile.open("Events.txt",std::ios::out);
    // checking if the file is open
    if(newFile.is_open()){
        // looping throught the list
        for(std::string lines:updatedList){
            // pushing the new lines into the file using the list
            newFile<<lines;
        }
    }
    newFile.close();
}

// function to update the booking.txt file
void updateBookingFile(std::string customer_name){
    std::ifstream file;
    // declaring the list
    std::list<std::string> updatedList;
    // opening te booking.txt file in read mode
    file.open("booking.txt", std::ios::in);

    // checking if file is open
    if (file.is_open()) {
        // declaring line as string
        std::string line;
        // looping through the file using while loop
        while(std::getline(file, line))
        {
            // converting line into string stream
            std::stringstream stream(line);
            // declaring variables
            std::string event_type, name, reserved_seats;
            // assigning the 1st value to the event_type variable to distinguish type of event
            std::getline(stream, event_type, ',');
            // assigning the 2nd value to the name variable to distinguish name of user
            std::getline(stream, name, ',');
            // assigning the 3rd value to the reserved_Seats variable to distinguish number of seats booked
            std::getline(stream, reserved_seats);
        
            // if the name exist in the file
            if (std::string (name) == customer_name)
            {
                // it will continue looping and skiping that line
                continue;
            }
            else {
                // it will copy the other lines into the list
                updatedList.push_back(line);
                updatedList.push_back("\n");
            }
        }
    }

    file.close();

    // opening the booking.txt file in write mode
    std::fstream newFile;
    newFile.open("booking.txt",std::ios::out);
    if(newFile.is_open()){
        for(std::string lines:updatedList){
            // writing the data in the list into the booking.txt file
            newFile<<lines;
        }
    }
    newFile.close();
}

// function to cancel Allocated seats
void cancelAllocatedSeats(int temp_comedy, int event){
    // declaring variables
    int target, no_reserved_seat, seatState, line_file=0;

    std::cout << "For which seat would you cancel the booking? Enter a number from 1 to 200:\n" ;

    // for loop to ask the user the seat number for each ticket
    for (int i = 1; i <= temp_comedy; i++ ) {
        while(true){
            std::cout<<"Ticket "<<i<<":";
            std::cin>>no_reserved_seat;

            // if its the 1st stand up comedy event
            if (event==1){
                // target line will start from line 12
                target = 12+no_reserved_seat;
            }
            else{
                // else target line will start from line 219
                target = 219+no_reserved_seat;
            }
            
            // opening events.txt file in read mode
            std::ifstream file;
            file.open("Events.txt", std::ios::in);
            // checking if file is open
            if (file.is_open()){
                // declaring line as string
                std::string line;
                // setting line_file to 0
                line_file = 0;
                while (getline(file,line)){
                    // incremeting line_file each time it will loop through the file
                    line_file++;
                    if (line_file==target){
                        // converting string to integer
                        seatState = stoi(line);
                    }
                }
            }
            file.close();

            // if seat state is 0, means its available, an error message will be displayed
            if (seatState==0){
                std::cout<<"Sorry this seat number was not booked. Choose another number for:\n";   
                continue;

            }
            // if seat state is 9, means is booked
            else if(seatState == 9){
                // declaring a list
                std::list<std::string> updatedList;
                // declaring a variable
                int file_line;

                // opening events.txt file in reading mode
                std::fstream file1;
                file1.open("Events.txt", std::ios::in);

                // checking if file is open
                if (file1.is_open()){
                    // declaring line as string
                    std::string line;
                    // setting file_line to 0
                    file_line = 0;
                    while(getline(file1, line)){
                        file_line++;
                        if (file_line == target){
                            // updating the list for that specific line
                            updatedList.push_back("0");
                            updatedList.push_back("\n");
                            continue;
                        }
                        // pushing the other lines into the list
                        updatedList.push_back(line);
                        updatedList.push_back("\n");
                    }
                    file1.close();
                }
                // opening the events.txt file is write mode
                std::fstream file2;
                file2.open("Events.txt", std::ios::out);
                // checking if file is open
                if (file2.is_open()){
                    for (std::string lines:updatedList) {
                        // writing the file using the data in the list
                        file2<<lines;
                    }
                    break;
                }
            }
        }
    }

}

// function to cancel booking
void cancelBooking() {
    // declaring variables
    std::string input, input2, show_name, customer_name, option;
    int temp, temp_comedy, select;

    std::cout << "_____________________Theatre Booking System_____________________" << std::endl;
    std::cout << "------------------------Cancel Booking--------------------------" << std::endl;
    std::cout << "|                                                              |"<< std::endl;

    std::cout << " Have you already booked a session? y or n?";

    do {
        // taking inputs from the user
        std::cin >> input;

        // if user inputs y
        if (input == "y") {
            std::cout << "Enter your name: " << std::endl;
            // taking inputs from the user
            std::cin >> input2;

            // opening the booking.txt file in reading mode
            std::ifstream file;
            file.open("booking.txt", std::ios::in);

            // checking if file is open
            if (file.is_open()) {
                // declaring line as string
                std::string line;
                // declaring variable for each data in file 
                std::string event_type, name, reserved_seats;
                // looping through the file using a while loop
                while(std::getline(file, line))
                {
                    // converting the line into string stream
                    std::stringstream stream(line);
                    // assigning the 1st value to the event_type variable to distinguish type of event
                    std::getline(stream, event_type, ',');
                    // assigning the 2nd value to the name variable to distinguish name of the user
                    std::getline(stream, name, ',');
                    // assigning the 3rd value to the reserved_seats variable to distinguish number of seats booked
                    std::getline(stream, reserved_seats);
                    // checking if there is a booking on the name entered by the user 
                    if (std::string (name) == input2)
                    {
                        // if the event type correspond to the 1st event of comedy show
                        if (std::string (event_type) == " King of Comedy Show"){
                            int event = 1;
                            // converting the number for reserved seats into integer
                            temp_comedy=stoi(reserved_seats);
                            std::cout <<reserved_seats<< " seats booked."<< std::endl;
                            show_name = std::string(event_type);
                            customer_name = std::string(name);
                            std::cout <<"Are you sure that you want to cancel your booking? (y or n)"<< std::endl;

                            do {
                                // taking inputs from the user
                                std::cin >> option;
                                // if user inputs y
                                if (option == "y") {
                                    // calling the cancelAllocatedSeats() function with temp_comedy and event number as parameters
                                    cancelAllocatedSeats(temp_comedy, event);
                                    // calling the updateBooking File() function with customer_name as parameters
                                    updateBookingFile(customer_name);
                                    // calling the updateEventFile() function with temp_comedy and show name as parameters
                                    updateEventsfile(temp_comedy,show_name);
                                    std::cout <<"Booking successfully canceled. Thank You!. "<< std::endl;
                                    std::cout << "Press (1) to go back to menu"<<std::endl;

                                    do {
                                        // taking inputs from the user
                                        std::cin>>select;
                                        // if user inputs 1
                                        if (select == 1) {
                                            // calling the main function
                                            main();
                                            break;
                                        }
                                        
                                        // validation
                                        while (std::cin.fail()){
                                            std::cin.clear();
                                            std::cin.ignore(256,'\n');
                                            continue;
                                        }
                                        std::cout << "Invalid! press (1) to go back to menu: ";
                                    } while(select!=1);
                                    break;
                                }
                                // if user inputs n
                                if (option == "n") {
                                    // calling main function
                                    main();
                                    break;
                                }
                                std::cout << "Invalid! Enter \'y'or \'n' :"; 
                            } while (option != "y" && option != "n");
                        }
                        // if the event type correspond to the 2nd event of comedy show
                        else if (std::string (event_type) == " Mr Bean show"){
                            int event = 2;
                            // converting the number for reserved seats into integer
                            temp_comedy=stoi(reserved_seats);
                            std::cout <<reserved_seats<< " seats booked."<< std::endl;
                            show_name = std::string(event_type);
                            customer_name = std::string(name);

                            std::cout <<"Are you sure that you want to cancel your booking? (y or n)"<< std::endl;
                            do {
                                // taking inputs from the user
                                std::cin >> option;
                                // if user inputs y
                                if (option == "y") {
                                    // calling the cancelAllocatedSeats() function with temp_comedy and event number as parameters
                                    cancelAllocatedSeats(temp_comedy, event);
                                    // calling the updateBooking File() function with customer_name as parameters
                                    updateBookingFile(customer_name);
                                    // calling the updateEventFile() function with temp_comedy and show name as parameters
                                    updateEventsfile(temp_comedy,show_name);
                                    std::cout <<"Booking successfully canceled. Thank You!. "<< std::endl;
                                    std::cout << "Press (1) to go back to menu"<<std::endl;

                                    do {
                                        // taking inputs from the user
                                        std::cin>>select;
                                        // if user inputs 1
                                        if (select == 1) {
                                            // calling the main function
                                            main();
                                            break;
                                        }

                                        // validation
                                        while (std::cin.fail()){
                                            std::cin.clear();
                                            std::cin.ignore(256,'\n');
                                            continue;
                                        }

                                        std::cout << "Invalid! press (1) to go back to menu: ";
                                    } while(select!=1);

                                    break;
                                }
                                // if user inputs n
                                if (option == "n") {
                                    // calling main function
                                    main();
                                    break;
                                }
                                std::cout << "Invalid! Enter \'y'or \'n' :"; 
                            } while (option != "y" && option != "n");
                        }
                        else {
                            temp = stoi(reserved_seats);
                            show_name = std::string(event_type);
                            customer_name = std::string(name);
                            std::cout <<"Are you sure that you want to cancel your booking? (y or n)"<< std::endl;

                            do {
                                // taking inputs from the user
                                std::cin >> option;
                                // if user inputs y
                                if (option == "y") {
                                    // calling the updateBooking File() function with customer_name as parameters
                                    updateBookingFile(customer_name);
                                    // calling the updateEventFile() function with temp_comedy and show name as parameters
                                    updateEventsfile(temp,show_name);
                                    std::cout <<"Booking successfully canceled. Thank You!. "<< std::endl;
                                    std::cout << "Press (1) to go back to menu"<<std::endl;

                                    do {
                                        // taking inputs from the user
                                        std::cin>>select;
                                        // if user inputs 1
                                        if (select == 1) {
                                            // calling the main function
                                            main();
                                            break;
                                        }

                                        // validation
                                        while (std::cin.fail()){
                                            std::cin.clear();
                                            std::cin.ignore(256,'\n');
                                            continue;
                                        }
                                        std::cout << "Invalid! press (1) to go back to menu: ";
                                    } while(select!=1);
                                    break;
                                }
                                // if user inputs n
                                if (option == "n") {
                                    // calling main function
                                    main();
                                    break;
                                }
                                std::cout << "Invalid! Enter \'y'or \'n' :"; 
                            } while (option != "y" && option != "n");
                            break;
                        }
                    }
                }
                // if name entered by the user doesn't exit in the booking.txt file
                if (std::string (name) != input2){
                    // declaring variable
                        int select;
                        
                        std::cout << "No booking available on this name. Thank You!"<<std::endl;
                        std::cout << "Press (1) to go back to menu"<<std::endl;

                        do {
                            // taking inputs from the user
                            std::cin>>select;
                            // if user inputs 1
                            if (select == 1) {
                                // calling the main function
                                main();
                            }
                            std::cout << "Invalid! press (1) to go back to menu: ";
                            // validation
                            while (std::cin.fail()){
                                std::cin.clear();
                                std::cin.ignore(256,'\n');
                                continue;
                            }
                        } while(select!=1);
                        break;                        
                    }
            }
            file.close();
        }
        // if user inputs n
        if (input == "n") {
            // calling main function
            main();
            break;
        }
        std::cout << "Invalid! Enter \'y'or \'n' :"; 
        // std::cin >> input;
    } while (input != "y" && input != "n");
}

// ---------------------------------------Function for the list event functionality---------------------------------------------------------------------------------------

// function to display of the events by reading the file
void readFile_DisplayEvents() {
    // declaring variables
    int count = 1;

    // opening the events.txt file in read mode
    std::ifstream file;
    file.open("Events.txt", std::ios::in);
    // checking if file is open
    if (file.is_open()) {
        // declaring line as string
        std::string line;
        // looping through the file using while loop
        while(std::getline(file, line))
        {
            // converting line into string stream
            std::stringstream stream(line);
            // declaring variable for each data in file
            std::string e_id, e_type, e_name, time,availability;
            // assigning the 1st value to the e_type variable to distinguish type of event
            std::getline(stream, e_type, ',');
            // assigning the 2nd value to the e_if variable to distinguish event id
            std::getline(stream, e_id, ',');
            // assigning the 3rd value to the e_name variable to distinguish name of event
            std::getline(stream, e_name, ',');
            // assigning the 4th value to the time variable to distinguish time of event
            std::getline(stream, time, ',');
            // assigning the 5th value to the availability variable to distinguish the availability
            std::getline(stream, availability);

            if (std::string (e_type) == "Live Music" || std::string (e_type) == "Stand Up Comedy" || std::string (e_type) == "Film"){
                std::cout << "\n"<< std::endl;
                std::cout << "\t\t(" << count++ << ")" << std::endl;
                Event event(e_type,e_id,e_name,time);
                event.Display();
            }
        }
    }
    file.close();
}

// function to list all Events
void listEvents() {
    std::cout << "_____________________Theatre Booking System_____________________" << std::endl;
    std::cout << "---------------------List of all events------------------------- " << std::endl;

    // calling readFile_DisplayEvents() function
    readFile_DisplayEvents();
    // calling the functionality function
    functionality();
}


// ---------------------------------------Function for the list details and availability of a given event functionality---------------------------------------------------------------------------------------

// function for functionalities
void functionality() {
    // declaring variables
    int type_selection;

    std::cout << " (1) Go back to menu" << std::endl;
    std::cout << " (2) Exit" << std::endl;
    std::cout << "Go back or exit?: ";

    do
    {
        // taking inputs from user
        std::cin >> type_selection;
        // if user inputs 1
        if (type_selection ==1)
        {
            system("clear"); 
            // calling main function
            main();
            break;
        }
        // if user inputs 2
        if (type_selection == 2)
        {
            system("clear"); 
            EXIT_SUCCESS;
            break;
        }
        // validation
        while (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            continue;
        }
        std::cout << "\tInvalid!, Enter a number between 1 and 2: ";
    } while (type_selection != 1 && type_selection != 2);
}

// function to display the details of the events by ready the file
void readFile_DisplayDetails() {
    // declaring variables
    int count = 1, type_selection, available;

    // Calling the Event base class
    Event event("","","","");
    // calling the listEventMenu() function from the base class
    event.ListEventMenu();
    std::cout << "Choose for which type of event would you like to more details? ";

    // opening the events.txt files in a reading mode
    std::ifstream file;
    file.open("Events.txt", std::ios::in);

    do {
        // taking input from user
        std::cin >> type_selection;
        // if user inputs 
        if (type_selection == 1)
        {
            // checking if file is open
            if (file.is_open()) {
                // declaring line as string
                std::string line;
                // looping through the file using a while loop
                std::cout << "________________________________________________________________" << std::endl;
                while(std::getline(file, line))
                {
                    // converting the line into string stream
                    std::stringstream stream(line);
                    // declaring variable for each data in file
                    std::string e_id, e_type, e_name, time, availability;
                    // assigning the 1st value to the e_type variable to distinguish type of event
                    std::getline(stream, e_type, ',');
                    // assigning the 2nd value to the e_if variable to distinguish event id
                    std::getline(stream, e_id, ',');
                    // assigning the 3rd value to the e_name variable to distinguish name of event
                    std::getline(stream, e_name, ',');
                    // assigning the 4th value to the e_time variable to distinguish time of event
                    std::getline(stream, time, ',');
                    // assigning the 5th value to the availability variable to distinguish the availability
                    std::getline(stream, availability);
                
                    // checking if there is a live music type of event into the file
                    if (std::string (e_type) == "Live Music")
                    {
                        std::cout << "\t\t(" << count++ << ")" << std::endl;
                        // converting string into integer
                        available = stoi(availability);
                        // calling the Live music derived class
                        Live_Music live_music(e_type,e_id,e_name,time,available);
                        // calling the Display() function from the live_music class
                        live_music.DisplayDetails();
                    }
                }
                std::cout << "________________________________________________________________" << std::endl;
            }
            file.close();
            // calling functionality function
            functionality();
            break;

        }
        // if user inputs 2
        if (type_selection == 2)
        {
            // checking if file is open
            if (file.is_open()) {
                // declaring line as string
                std::string line;
                // looping through the file using a while loop
                std::cout << "________________________________________________________________" << std::endl;
                while(std::getline(file, line))
                {
                    // converting the line into string stream
                    std::stringstream stream(line);
                    // declaring variable for each data in file
                    std::string e_id, e_type, e_name, time, availability;
                    // assigning the 1st value to the e_type variable to distinguish type of event
                    std::getline(stream, e_type, ',');
                    // assigning the 2nd value to the e_if variable to distinguish event id
                    std::getline(stream, e_id, ',');
                    // assigning the 3rd value to the e_name variable to distinguish name of event
                    std::getline(stream, e_name, ',');
                    // assigning the 4th value to the e_time variable to distinguish time of event
                    std::getline(stream, time, ',');
                    // assigning the 5th value to the availability variable to distinguish the availability
                    std::getline(stream, availability);
                
                    // checking if there is a stand up comedy type of event into the file
                    if (std::string (e_type) == "Stand Up Comedy")
                    {
                        std::cout << "\t\t(" << count++ << ")" << std::endl;
                        // converting string into integer
                        available = stoi(availability);
                        // calling the stand up comedy derived class
                        Stand_Up_Comedy stand_up_comedy(e_type,e_id,e_name,time,available);
                        // calling the Display() function from the stand up comedy class
                        stand_up_comedy.DisplayDetails();
                    }
                }
                std::cout << "________________________________________________________________" << std::endl;
            }
            file.close();
            // calling functionality function
            functionality();
            break;                     
        }
        if (type_selection == 3)
        {
            // checking if file is open
            if (file.is_open()) {
                // declaring line as string
                std::string line;
                // looping through the file using a while loop
                std::cout << "________________________________________________________________" << std::endl;
                while(std::getline(file, line))
                {
                    // converting the line into string stream
                    std::stringstream stream(line);
                    // declaring variable for each data in file
                    std::string e_id, e_type, e_name, time, availability;
                    // assigning the 1st value to the e_type variable to distinguish type of event
                    std::getline(stream, e_type, ',');
                    // assigning the 2nd value to the e_if variable to distinguish event id
                    std::getline(stream, e_id, ',');
                    // assigning the 3rd value to the e_name variable to distinguish name of event
                    std::getline(stream, e_name, ',');
                    // assigning the 4th value to the e_time variable to distinguish time of event
                    std::getline(stream, time, ',');
                    // assigning the 5th value to the availability variable to distinguish the availability
                    std::getline(stream, availability);
                
                    // checking if there is a film type of event into the file
                    if (std::string(e_type) == "Film")
                    {
                        std::cout << "\t\t(" << count++ << ")" << std::endl;
                        // converting string into integer
                        available = stoi(availability);
                        // calling the film derived class
                        Film film(e_type,e_id,e_name,time,available);
                        // calling the Display() function from the film class
                        film.DisplayDetails();
                    }
                }
            }
            file.close();
            // calling functionality function
            functionality();
            break;

        }
        // if user inputs 4
        if (type_selection == 4)
        {
            system("clear"); 
            // calling main function
            main();
            break;

        }
        // if user inputs 5
        if (type_selection == 5)
        {
            system("clear"); 
            EXIT_SUCCESS;
            break;
        }
        // validation
        while (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            continue;
        }
        std::cout << "\tInvalid!, Enter a number between 1 and 5: ";
    } while (type_selection != 1 && type_selection != 2 && type_selection != 3 && type_selection != 4 && type_selection != 5);
}

// function to list details
void listDetails() {
    std::cout << "_____________________Theatre Booking System_____________________" << std::endl;
    std::cout << "-------------------List of event details------------------------ " << std::endl;

    // calling readFile_DisplayDetails() function
    readFile_DisplayDetails();
}


// ---------------------------------------Function for the cancel booking functionality---------------------------------------------------------------------------------------

int main() {
    // declaring variables
    int select;
    std::string type, id, name, timing;

    // calling Event class
    Event event(type,id,name,timing);
    // displaying main menu
    event.Main_Menu();

    do {
        // taking input from the user
        std::cin >> select;

        // if user will press 1
        if (select == 1) {
            // removing everything from the console
            system("clear");
            // calling add booking function
            addBooking();
            break;
        }

        // if user will press 2
        if (select == 2) {
            // removing everything from the console
            system("clear");
            // calling cancel booking function
            cancelBooking();
            break;
        }

        // if user will press 3
        if (select == 3) {
            // removing everything from the console
            system("clear");
            // calling the listEvent() function
            listEvents();
            break;
        }
        
        // if user will press 4
        if (select == 4) {
            // removing everything from the console
            system("clear"); 
            // calling the list details function
            listDetails();
            break;
        }

        // if user will press 5
        if (select == 5) {
            // removing everything from the console
            system("clear"); 
            EXIT_SUCCESS;
            break;
        }

        // validation
        while (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(256,'\n');
            continue;
        }

        // outputing an error message if the user enters another value than numbers between 1 to 5
        std::cout << "\tInvalid!, Enter a number between 1 and 5: ";
    } while (select != 1 && select != 2 && select != 3 && select != 4 && select != 5);

    return 0;
}