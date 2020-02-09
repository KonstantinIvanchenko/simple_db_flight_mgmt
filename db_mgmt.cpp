#include "db_mgmt.h"


sql::ResultSet* db_handle::mysql_query(const std::string& query){
	try{
		sql::Statement* stmt = conn->createStatement();
		sql::ResultSet* result = stmt->executeQuery(query);
		//TODO: implement this
		delete stmt;
		//TODO: implement this
		return result;
		
	}catch (sql::SQLException &e){
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
}

bool db_handle::mysql_exec(const std::string& request){
	try{
		sql::Statement* stmt = conn->createStatement();
		bool result = stmt->execute(request);
		//TODO: implement this
		delete stmt;
		//TODO: implement this
		return result;
		
	}catch (sql::SQLException &e){
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
}
		
sql::Connection* db_handle::mysql_connection(std::string host, std::string username, std::string password){
	try{
		this->driver = get_driver_instance();
		
		this->conn = this->driver->connect(host+":3306", username, password);
		this->conn->setSchema("cpp_airlinereservation_db");  //TODO: apply name general
		
		return this->conn;
		
	}catch (sql::SQLException &e){
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
	}
}
	
void db_handle::mysqL_killconnection(){
	delete this->conn;
}
	
int db_handle::mysql_get_rows(std::string** items, const std::string& tablename, const std::string& condition, const std::string& columns, const int& col_num){
	
	std::string columns_stmt = "";
	
	if (std::string("*").compare(columns)){
		for(int i = 0; i < col_num; i++){
			columns_stmt += columns[i];
		}
	}
	else{
		//columns_stmt = "*";
		columns_stmt.assign("*");
	}
	
	if (std::string("").compare(condition)){
		this->res = mysql_query("select "+columns_stmt+" from "+tablename+" where "+condition);
	}
	else{
		this->res = mysql_query("select "+columns_stmt+" from "+tablename);
	}
	
	int row = 0;
	int row_count = this->res->rowsCount();
	
	for (int i = 0; i < col_num; i++){
		items[i] = new std::string[row_count];
	}
	
	//get amount of rows and allocate row here
	//access after that
	
	while(this->res->next()){
		/*
		items[row] = new std::string[col_num];
		
		for(int i = 0; i < col_num; i++){
			items[row][i] = this->res->getString(i+1);//this->res->getString(columns[i]);
		*/
		for(int i = 0; i < col_num; i++){
			//std::string t = this->res->getString(i+1);
			items[i][row] = std::string(this->res->getString(i+1));
			//items[row][i] = this->res->getString(i+1);//this->res->getString(columns[i]);
		}
		row++;
		//return number of fetched rows;
	}
	
	delete this->res;
	
	return row;
}

void db_handle::mysql_createtable(){
	
}

int db_handle::mysql_insert_row(const std::string& tablename, std::string* const fields, const int len, 
									std::map<std::string, std::string> fieldvals){
	
	std::string query = "insert into " + tablename + " (";
	
	if (len <= 0)
		return 0;
	
	for (int i = 0; i < len-1; i++){
		query += fields[i] +", ";
	}
	
	query += fields[len-1] + ") values ('";
	
	for(int i = 0; i < len-1; i++){
		query += fieldvals[fields[i]] + "','";
	}
	
	query += fieldvals[fields[len-1]] + "')";
	
	return this->mysql_exec(query);
}
