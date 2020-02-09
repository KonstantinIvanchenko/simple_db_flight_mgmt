#include "flights_db.h"
#include <stdlib.h>
#include <iostream>


	flights_db::flights_db(std::string host, std::string uname, std::string passw){
		//implement here db mgmt
		//dbase();
		dbase.mysql_connection(host, uname, passw);
	}
	
	void flights_db::ReserveSeats(){
		
		int table_cols = 5;
		int row_count = 0;
		int user_fieldnames_length = 6;
		std::string dummy = "";
		
		std::string** table = new std::string* [table_cols];
		//std::string* inputs = new std::string[5];
		
		std::string user_fieldnames[user_fieldnames_length] = {"u_name", "u_phone", "u_passportno", "u_ticket", "u_flightno", "u_address"};
		
		//std::pair<std::string, std::string>* userParams = new std::pair<std::string, std::string>[user_fieldnames->length()];
		std::map<std::string, std::string> userParams;
		
		std::system("clear");
		//std::cout << std::flush;
		
		std::cout << "Welcome to Flight Reservation System" << std::endl << std::endl;
		std::cout << "Reserve Seat Menu" << std::endl << std::endl;
		
		std::cin.ignore(1, '\n');
		for (int i = 0; i < user_fieldnames_length; i++){
			std::cout << "Enter " +  user_fieldnames[i] + ": ";
			std::getline(std::cin, userParams[user_fieldnames[i]]);
		}

		std::string flight_table = "flightdetails_tb";
		std::string condition = "f_available = 'A'";
		std::string columns = "*";
		
		//FIXME: fetch field names with MYSQL_FIELD *mysql_fetch_field(MYSQL_RES *result)
		row_count = dbase.mysql_get_rows(table, flight_table, condition, columns, table_cols);
		
		std::cout << std::endl;
		
		std::string table_line = "";
		
		//output flight variants
		for(int i = 0; i < row_count; i++){
			for(int j = 0; j < table_cols; j++){
				table_line += table[j][i]+" ";
			}
			std::cout << table_line;
			table_line.assign("");
		}
		
		std::cout << std::endl;
		
		std::string user_reser_table = "userreservation_tb";
		
		if (!dbase.mysql_insert_row(user_reser_table, user_fieldnames, user_fieldnames_length, userParams)){
			std::cout << "User reservation details added." << std::endl;
		}
		else{
			std::cout << "DB query error." << std::endl;
		}
		
		std::cout << std::endl;
		std::cout << "Press enter.." << std::endl;
		std::cin >> dummy;//dummy
		std::system("clear");
		
		//clean memory
		for (int i = 0; i < table_cols; i++)
			delete [] table[i];
		
		delete [] table;
		
	}
	
	void flights_db::UserTicket(){
		
		int table_cols = 6;
		int row_count = 0;
		int user_fieldnames_length = 1;
		std::string dummy = "";
		
		std::string** table = new std::string* [table_cols];
		
		std::system("clear");
		
		std::cout << "Welcome to Flight Reservation System" << std::endl << std::endl;
		std::cout << "User Ticket Menu" << std::endl << std::endl;
		
		std::cin.ignore(1, '\n');
		
		std::string user_fieldnames[user_fieldnames_length] = {"u_name"};
		
		//std::pair<std::string, std::string>* userParams = new std::pair<std::string, std::string>[user_fieldnames->length()];
		std::map<std::string, std::string> userParams;
		//std::cout << std::flush;
		for (int i = 0; i < user_fieldnames_length; i++){
			std::cout << "Enter " +  user_fieldnames[i] + ": ";
			std::getline(std::cin, userParams[user_fieldnames[i]]);
		}
		
		////////
		
		std::string flight_table = "userreservation_tb";
		std::string condition = user_fieldnames[0] + " like '%" + userParams[user_fieldnames[0]] + "%'";
		std::string columns = "*";
		
		//FIXME: fetch field names with MYSQL_FIELD *mysql_fetch_field(MYSQL_RES *result)
		row_count = dbase.mysql_get_rows(table, flight_table, condition, columns, table_cols);
		
		std::cout << std::endl;
		
		std::string table_line = "";
		
		//output flight variants
		for(int i = 0; i < row_count; i++){
			for(int j = 0; j < table_cols; j++){
				table_line += table[j][i]+" ";
			}
			std::cout << table_line << std::endl;
			table_line.assign("");
		}
		
		std::cout << std::endl;
		std::cout << "Press enter.." << std::endl;
		std::cin >> dummy;//dummy
		std::system("clear");
		
		//clean memory
		for (int i = 0; i < table_cols; i++)
			delete [] table[i];
		
		delete [] table;
	}
	
	void flights_db::FlightsSchedule(){
		int table_cols = 9;
		int row_count = 0;
		std::string dummy = "";
		
		std::string** table = new std::string* [table_cols];
		std::array<int, 5> table_idx = {1, 3, 4, 7, 8};
		
		std::system("clear");
		
		std::cout << "Welcome to Flight Reservation System" << std::endl << std::endl;
		std::cout << "Flight Schedule" << std::endl << std::endl;
		
		std::cin.ignore(1, '\n');
		
		std::string flight_table = "flightdetails_tb";
		std::string condition = "";
		std::string columns = "*";
		
		//FIXME: fetch field names with MYSQL_FIELD *mysql_fetch_field(MYSQL_RES *result)
		row_count = dbase.mysql_get_rows(table, flight_table, condition, columns, table_cols);
		
		std::string table_line = "";
		
		for(int i = 0; i < row_count; i++){
			for(int j = 0; j < (int)table_idx.size(); j++){
				table_line += table[table_idx[j]][i]+" ";
			}
			std::cout << table_line << std::endl;
			table_line.assign("");
		}
		
		std::cout << std::endl;
		std::cout << "Press enter.." << std::endl;
		std::cin >> dummy;//dummy
		std::system("clear");
		
		//clean memory
		for (int i = 0; i < table_cols; i++)
			delete [] table[i];
		
		delete [] table;
	}
	
	void flights_db::DisplayPassanger(){
		int table_cols = 7;
		int row_count = 0;
		std::string dummy = "";
		
		std::string** table = new std::string* [table_cols];
		std::array<int, 6> table_idx = {1, 2, 3, 4, 5, 6};
		
		std::system("clear");
		
		std::cout << "Welcome to Flight Reservation System" << std::endl << std::endl;
		std::cout << "Display Passenger Menu" << std::endl << std::endl;
		
		std::cin.ignore(1, '\n');
		
		std::string flight_table = "userreservation_tb";
		std::string condition = "";
		std::string columns = "*";
		
		//FIXME: fetch field names with MYSQL_FIELD *mysql_fetch_field(MYSQL_RES *result)
		row_count = dbase.mysql_get_rows(table, flight_table, condition, columns, table_cols);
		
		std::string table_line = "";
		
		for(int i = 0; i < row_count; i++){
			for(int j = 0; j < (int)table_idx.size(); j++){
				table_line += table[table_idx[j]][i]+" ";
			}
			std::cout << table_line << std::endl;
			table_line.assign("");
		}
		
		std::cout << std::endl;
		std::cout << "Press enter.." << std::endl;
		std::cin >> dummy;//dummy
		std::system("clear");
		
		//clean memory
		for (int i = 0; i < table_cols; i++)
			delete [] table[i];
		
		delete [] table;
	}
	
	void flights_db::AddNewFlight(){
		int row_count = 0;
		int flight_fieldnames_length = 7;
		std::string dummy = "";
		//std::string* inputs = new std::string[5];
		
		std::string flight_fieldnames[flight_fieldnames_length] = {"f_no", "f_name", "f_from", "f_destination",
																"f_time", "f_amount", "f_available"};
		
		//std::pair<std::string, std::string>* userParams = new std::pair<std::string, std::string>[user_fieldnames->length()];
		std::map<std::string, std::string> flightParams;
		
		std::system("clear");
		//std::cout << std::flush;
		
		std::cout << "Welcome to Flight Reservation System" << std::endl << std::endl;
		std::cout << "Reserve Seat Menu" << std::endl << std::endl;
		
		std::cin.ignore(1, '\n');
		for (int i = 0; i < flight_fieldnames_length; i++){
			std::cout << "Enter " +  flight_fieldnames[i] + ": ";
			std::getline(std::cin, flightParams[flight_fieldnames[i]]);
		}

		std::cout << std::endl;
		
		std::string fl_det_table = "flightdetails_tb";
		
		if (!dbase.mysql_insert_row(fl_det_table, flight_fieldnames, flight_fieldnames_length, flightParams)){
			std::cout << "Flight details added." << std::endl;
		}
		else{
			std::cout << "DB query error." << std::endl;
		}
		
		std::cout << std::endl;
		std::cout << "Press enter.." << std::endl;
		std::cin >> dummy;//dummy
		std::system("clear");
	}