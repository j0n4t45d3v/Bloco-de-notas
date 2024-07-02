#include "notepadd.h"
#include "../app/note.h"
#include <iostream>

using namespace std;
using namespace app::notepadd;

namespace view
{
  namespace notepadd 
  {
    Notepadd::Notepadd(sqlite3* connection) 
    {
      Notepadd::note = new Note(connection);
    }
    void Notepadd::create() 
    {
      cin.clear();
      cin.ignore(INT8_MAX, '\n');
      string noteTitle, content;
      cout << endl << "Titulo: ";
      getline(cin, noteTitle, '\n');
      cout << "Escreva o conteudo da anotação: ";
      getline(cin, content, '\n');
      
      Notepadd::note->createNote(noteTitle, content);
    }

    void Notepadd::list() 
    {
      Notepadd::note->listNotes();
    }
  }
}