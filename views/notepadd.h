#ifndef NOTEPADD_H
#define NOTEPADD_H

#include <sqlite3.h>

namespace view
{
  namespace notepadd 
  {
    class Notepadd 
    {
      private:
        sqlite3* connection;
      public:
        Notepadd(sqlite3* connection);
        void create();
    };
  }
}

#endif