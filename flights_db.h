#include "db_mgmt.h"

class flights_db{
private:
	db_handle dbase;
public:
	flights_db (std::string host, std::string uname, std::string passw);	
	void ReserveSeats();
	void UserTicket();	
	void FlightsSchedule();
	void DisplayPassanger();
	void AddNewFlight();
};