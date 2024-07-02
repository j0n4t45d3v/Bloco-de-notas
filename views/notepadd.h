#ifndef NOTEPADD_H
#define NOTEPADD_H

#include <sqlite3.h>
#include "../app/note.h"

using namespace app::notepadd;

namespace view
{
  namespace notepadd 
  {
    class Notepadd 
    {
      private:
        Note* note;
      public:
        Notepadd(sqlite3* connection);
        void create();
        void list();
    };
  }
}

#endif