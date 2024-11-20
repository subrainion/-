#include "Time.h"
#include <iostream>
#include <limits>
using namespace std;

//Конструкторы
Time::Time() : hours(0), minutes(0) {}
Time::Time(short int hours, short int minutes) : hours(hours), minutes(minutes) {}
Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

// Свойства
short int Time::getHours() const { return hours; }
short int Time::getMinutes() const { return minutes; }

//Метод вычитания минут
Time Time::subtraction(unsigned int mins) {
    minutes -= mins;
    if (minutes < 0) 
    {
        hours += (minutes / 60) - 1;
        minutes = (minutes % 60) + 60; 
        hours = (hours + 24) % 24;
    }
    return Time(hours, minutes);
}

// Перегрузка оператора вывода
ostream& operator<<(ostream& os, const Time& time) {
    os << time.hours << ":" << time.minutes;
    return os;
}
//Унарные операции 
Time& Time::operator-() {
    Time temp(hours = 0, minutes = 0);
    *this = temp;
    return *this;
}

Time Time::operator--(int) {
    Time temp = *this;  
    *this = Time(hours, minutes = 0);
    return temp;  
}
//Операции приведения типа
Time::operator short int() const {
    return hours;
}
Time::operator bool() const {
    return (hours != 0 || minutes != 0);
}
//Бинарные операции
bool Time::operator==(const Time& other) const {
    return (hours == other.hours && minutes == other.minutes);
}
bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}