#include "views/menu.h"
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
    con->getConnection() ? 1 : 0;
    menuNotpad.showTitle();
    do
    {
      menuNotpad.show();
      option = menuNotpad.getOption();
      if (option == 0)
      {
        exitSystem = true;
      }
    } while (!exitSystem);

    con->closeConnection();
  }
  return 0;
}