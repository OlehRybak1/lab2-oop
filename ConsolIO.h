#pragma once
#include <iostream>
#include <string>
#include <limits>

// Статичний клас для роботи з консоллю (зчитування чисел і тексту з перевіркою)
class ConsolIO
{
public:
    // Зчитує дійсне число, якщо введено не число - просить повторити
    static double GetValue(std::istream& is)
    {
        double value;
        while (true)
        {
            if (is >> value)
            {
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            std::cout << "\n\tНЕКОРЕКТНИЙ ВВІД! Очікується число. Повторіть: ";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return value;
    }

    // Зчитує непорожній рядок тексту з консолі
    static std::string GetText(std::istream& is)
    {
        std::string line;
        while (true)
        {
            std::getline(is, line);
            bool onlySpaces = true;
            for (char c : line)
                if (c != ' ') { onlySpaces = false; break; }

            if (!line.empty() && !onlySpaces)
                break;

            std::cout << "\n\tНЕКОРЕКТНИЙ ВВІД! Очікується текст. Повторіть: ";
        }
        return line;
    }
};
