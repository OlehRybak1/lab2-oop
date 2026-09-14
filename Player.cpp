#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    cout << "Введіть кількість відеофайлів у бібліотеці: ";
    videoCount = static_cast<int>(ConsolIO::GetValue(cin));
    videos = new Video[videoCount];
    ioWorker = new VideoIO();
}

Player::~Player()
{
    delete[] videos;
    delete ioWorker;
}

void Player::Fill()
{
    for (int i = 0; i < videoCount; i++)
    {
        cout << "\n--- Відео #" << (i + 1) << " ---";
        ioWorker->Input(videos[i]);
    }
}

void Player::ShowAll()
{
    cout << "\nСписок усіх фільмів у бібліотеці:\n";
    for (int i = 0; i < videoCount; i++)
        ioWorker->Output(videos[i]);
}

void Player::SearchByActor()
{
    cout << "\nПошук фільмів за актором. Введіть ім'я актора: ";
    string actor = ConsolIO::GetText(cin);

    bool found = false;
    cout << "\nФільми за участю \"" << actor << "\":\n";
    for (int i = 0; i < videoCount; i++)
    {
        if (videos[i].hasActor(actor))
        {
            ioWorker->Output(videos[i]);
            found = true;
        }
    }
    if (!found)
        cout << "\tНічого не знайдено.\n";
}

void Player::SearchByTitle()
{
    cout << "\nПошук фільмів за назвою. Введіть назву: ";
    string title = ConsolIO::GetText(cin);

    bool found = false;
    cout << "\nФільми з назвою \"" << title << "\":\n";
    for (int i = 0; i < videoCount; i++)
    {
        if (videos[i].getTitle() == title)
        {
            ioWorker->Output(videos[i]);
            found = true;
        }
    }
    if (!found)
        cout << "\tНічого не знайдено.\n";
}

void Player::SearchByTheme()
{
    cout << "\nПошук фільмів за темою. Введіть тему: ";
    string theme = ConsolIO::GetText(cin);

    bool found = false;
    cout << "\nФільми теми \"" << theme << "\":\n";
    for (int i = 0; i < videoCount; i++)
    {
        if (videos[i].getTheme() == theme)
        {
            ioWorker->Output(videos[i]);
            found = true;
        }
    }
    if (!found)
        cout << "\tНічого не знайдено.\n";
}
