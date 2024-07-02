#include "database.h"
#include <sqlite3.h>
#include <iostream>

using namespace std;

namespace connection
{
  Database* Database::instance = nullptr;

  Database::Database()
  {
    statusDb = sqlite3_open("./example.db", &DB);
    initDatabase();
  };

  void Database::initDatabase() 
  {
    const char* sql = 
      " CREATE TABLE IF NOT EXISTS notepadd ( " 
        " id INTEGER PRIMARY KEY AUTOINCREMENT, " 
        " title VARCHAR(100) DEFAULT '*Sem titulo' NOT NULL, " 
        " content VARCHAR(225) " 
      " )";

    char* messageError;
    int result = sqlite3_exec(DB, sql, NULL, 0, &messageError);

    if(result != SQLITE_OK)
    {
      cerr << "Error in creating table: " << messageError << endl;
      sqlite3_free(messageError);
      exit(1);
    }else {
      cout << "Table created.." << endl;
    }
  }

  Database *Database::getInstance()
  {
    if (instance == nullptr)
    {
      instance = new Database();
    }
    return instance;
  }

  sqlite3* Database::getConnection() const
  {
    if(statusDb) 
    {
      cout << "Error in connect database" << endl;
      exit(1);
    }

    return DB;
  }

  void Database::closeConnection() const
  {
    sqlite3_close(DB);
  }
}