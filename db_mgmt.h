#include "mysql_connection.h"
//#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <string>
#include <stdio.h>


class db_handle{
private:
	sql::Driver *driver;
	sql::Connection *conn;
	sql::ResultSet* res;
	//sql::Statement *stmt;
	//sql::ResultSet *res;
	//MYSQL* conn;
	
	sql::ResultSet* mysql_query(const std::string& query);
	bool mysql_exec(const std::string& request);
	
public:
	db_handle(){};
	int mysql_init();
	
	sql::Connection* mysql_connection(std::string host, std::string username, std::string password);
	
	void mysqL_killconnection();
	
	int mysql_get_rows(std::string** items, const std::string& tablename, const std::string& condition, const std::string& columns, const int& col_num);
	
	void mysql_createtable();
	
	int mysql_insert_row(const std::string& tablename, std::string* const fields, const int len, std::map<std::string, std::string> fieldvals);
	
};