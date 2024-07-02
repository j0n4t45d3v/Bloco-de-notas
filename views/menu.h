#ifndef MENU_H
#define MENU_H

namespace view
{
  namespace notepadd
  {
    class Menu
    {
    public:
      void showTitle() const;
      void show();
      short getOption() const;

    private:
      short option;
    };
  }
}

#endif