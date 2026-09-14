#include "Player.h"
#include <windows.h>

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Player library;
    library.Fill();

    library.ShowAll();
    library.SearchByActor();
    library.SearchByTitle();
    library.SearchByTheme();

    return 0;
}