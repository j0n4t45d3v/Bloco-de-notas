#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>

namespace connection
{
  class Database
  {
    private:
      sqlite3 *DB;
      int statusDb;
      static Database* instance;
      Database();
      void initDatabase();
    
    public:
      static Database* getInstance();
      sqlite3* getConnection() const;
      void closeConnection() const;
  };
}

#endif