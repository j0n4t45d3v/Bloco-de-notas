#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <sqlite3.h>

namespace app
{
  namespace notepadd 
  {
    class Note 
    {
      private:
        sqlite3* connection;
        std::string formateData(std::string value);
      public:
        Note(sqlite3* connection);
        bool createNote(std::string noteTitle, std::string content); 
    };
  }  
}

#endif