#include <iostream>
#include "menu.h"

using namespace std;

namespace view
{
  namespace notepadd
  {
    void Menu::showTitle() const
    {
      cout << endl;
      cout << "============ Bloco de Nota ============" << endl;
      cout << endl;
    }

    void Menu::show()
    {
      cout << "x--------------------------------x" << endl;
      cout << "|                                |" << endl;
      cout << "|  0 - Sair do bloco de notas;   |" << endl;
      cout << "|                                |" << endl;
      cout << "|  1 - Criar uma nova nota;      |" << endl;
      cout << "|                                |" << endl;
      cout << "|  2 - Listar as notas;          |" << endl;
      cout << "|                                |" << endl;
      cout << "x--------------------------------x" << endl
           << endl;
      cout << "Selecione a opção desejada: ";
      cin >> option;
      cout << endl;
    }

    short Menu::getOption() const
    {
      return option;
    }
  }
}