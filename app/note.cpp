#include "note.h"
#include <iostream>

using namespace std;

namespace app
{
  namespace notepadd 
  {
    Note::Note(sqlite3* connection) 
    {
      Note::connection = connection;
    }

    bool Note::createNote(string noteTitle, string content)
    {
      sqlite3_stmt* stmt;
      const char* createNote;

      noteTitle = formateData(noteTitle);
      content = formateData(content);

      createNote = "INSERT INTO notepadd (title, content) VALUES (?, ?)";
      int result = sqlite3_prepare(connection, createNote, -1, &stmt, NULL);
      sqlite3_bind_text(stmt, 1, noteTitle.c_str(), -1, SQLITE_STATIC);
      sqlite3_bind_text(stmt, 2, content.c_str(), -1, SQLITE_STATIC);
      sqlite3_step(stmt);
      sqlite3_finalize(stmt);
      return true;
    }

    string Note::formateData(std::string value)
    {
      return string("'") + value + string("'");
    }
  }
}