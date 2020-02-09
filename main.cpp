#include <stdio.h>
#include <string>
#include <iostream>

#include "flights_db.h"

void askForString(std::string aPrompt, std::string &aValue) {
    std::cout << aPrompt << " ";
    std::cin >> aValue;
}

void askForInt(std::string aPrompt, int &aValue) {
    std::string tString;
    char *endptr;
    while (1) {
        std::cout << aPrompt << " ";
        std::cin >> tString;
        errno = 0;
        aValue = strtol(tString.c_str(), &endptr, 10);
        if (errno || tString.c_str() == endptr || (endptr != NULL && *endptr != 0)) {
            std::cout << "Repeat, please?" << std::endl;
        } else {
            break;
        }
    }
}

int main(int argc, char **argv)
{
	//std::cout << "Select your option: ";
	
	int option = 0;
	int fl_option = 0;
	
	flights_db flights_db_handle (/*TODO: Insert argument here: host, uname, password*/);
	
	while (true){
		
		if (option == 0){
			std::cout << "Welcome to Online Airway Booking System" << std::endl;
			std::cout << "1. Reserve Seat" << std::endl;
			std::cout << "2. UserTicket" << std::endl;
			std::cout << "3. Flights Schdule" << std::endl;
			std::cout << "4. Display Passenger" << std::endl;
			std::cout << "5. Flight Details" << std::endl;
			std::cout << "6. Exit Program" << std::endl;
			
			std::cout << std::endl;
			
			askForInt("Select your option: ", option);
			
			if ((1 > (int)option) || ((int)option > 7)){
				option = 0;
				
				std::cout << "Wrong input..";
				std::cout << "Select your option: ";
			}
			
		}
		else{
			
			switch (option){
				case 1:
					flights_db_handle.ReserveSeats();
					option = 0; // TODO: change to proper option
					break;
				case 2:
					flights_db_handle.UserTicket();
					option = 0;
					break;
				case 3:
					flights_db_handle.FlightsSchedule();
					option = 0;
					break;
				case 4:
					flights_db_handle.DisplayPassanger();
					option = 0;
					break;
				case 5:
					std::cout << "Welcome To Airlines Reservation System" << std::endl;
					std::cout << "Airlines Reservation System Menu" << std::endl;
					std::cout << "1. Add Flight." << std::endl;
					std::cout << "2. Edit Flight." << std::endl;
					std::cout << "3. Delete Flight." << std::endl;
					std::cout << "4. Flight Leave And Arrive." << std::endl;
					std::cout << "5. Back To Menu." << std::endl;
				
					if (fl_option == 0){
						std::cout << std::endl;
						
						askForInt("Select your option: ", fl_option);
						
						if ((1 > (int)fl_option) || ((int)fl_option > 7)){
							fl_option = 0;
							
							std::cout << "Wrong input..";
							std::cout << "Select your option: ";
						}
				
						switch(fl_option){
							case 1:
								flights_db_handle.AddNewFlight();
								fl_option = 0;
								break;
							default:
								break;
						}
					}
				default:
					std::cout << "Option reserved.." << std::endl;
					break;
			}
		}
		
		
	}
	
	return 0;
}
