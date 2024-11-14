#ifndef TIME_H
#define TIME_H

#include <string>
using namespace std;

class Time
{
    short int hours;
    short int minutes;
public:
    //������������
    Time();
    Time(short int hours, short int minutes);
    Time(const Time& other);
    // ��������
    short int getHours() const;
    short int getMinutes() const;
    //������
    Time subtraction(unsigned int mins);
    // ���������� ��������� ������
    friend ostream& operator<<(ostream& os, const Time& time);
    //������� ��������

    //�������� ���������� ����
    operator short int() const;
    explicit operator bool() const;
    //�������� ��������
    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
};
#endif //TIME_H