#include "views/menu.h"
#include "views/notepadd.h"
#include "database/database.h"
#include <sqlite3.h>
#include <iostream>

using namespace std;
using namespace view::notepadd;

int main()
{
  Menu menuNotpad;
  connection::Database *con = connection::Database::getInstance();
  short option;
  bool exitSystem = false;



  if (con != nullptr)
  {
    sqlite3 *db = con->getConnection();
    Notepadd* notepaddView = new Notepadd(db);
    menuNotpad.showTitle();
    do
    {
      menuNotpad.show();
      option = menuNotpad.getOption();

      switch (option)
      {
        case 1:
          notepaddView->create();
          break;
        case 0: 
          exitSystem = true;
        default:
          exitSystem = true;
      }

      if (option == 0)
      {
        exitSystem = true;
      }
    } while (!exitSystem);

    con->closeConnection();
  }
  return 0;
}