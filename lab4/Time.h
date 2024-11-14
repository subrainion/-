#ifndef TIME_H
#define TIME_H

#include <string>
using namespace std;

class Time
{
    short int hours;
    short int minutes;
public:
    //Конструкторы
    Time();
    Time(short int hours, short int minutes);
    Time(const Time& other);
    // Свойства
    short int getHours() const;
    short int getMinutes() const;
    //Методы
    Time subtraction(unsigned int mins);
    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Time& time);
    //Унарные операции

    //Операции приведения типа
    operator short int() const;
    explicit operator bool() const;
    //Бинарные операции
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
};
#endif //TIME_H