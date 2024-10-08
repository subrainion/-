#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int sumLastNums(int x)
{
	return (x % 10) + ((x % 100) / 10);
}
bool isPositive(int x)
{
	if (x > 0)
		return true;
	else
		return false;
}
bool isUpperCase(char x)
{
	if (isupper(x))
		return true;
	else
		return false;

}
bool isDivisor(int a, int b)
{
	if ((a % b == 0) || (b % a == 0))
		return true;
	else
		return false;
}
int lastNumSum(int a, int b)
{
	return 0;
}
double safeDiv(int x, int y)
{
	if (y > 0)
		return (x / y);
	else
		return 0;
}
string makeDecision(int x, int y)
{
	if (x > y)
		return to_string(x) + ">" + to_string(y);
	if (x < y)
		return to_string(x) + "<" + to_string(y);
	else
		return to_string(x) + "==" + to_string(y);
}
bool sum3(int x, int y, int z)
{
	if ((x + y == z) || (x + z == y) || (y + z == x))
		return true;
	else
		return false;
}
string age(int x)
{
	if ((x % 10 == 1) && (x != 11))
		return to_string(x) + " ���";
	if (((x % 10 == 2) || (x % 10 == 3) || (x % 10 == 4)) && (x != 12) && (x != 13) && (x != 14))
		return to_string(x) + " ����";
	else
		return to_string(x) + " ���";
}
void printDays(string x)
{
	return;
}
string reverseListNums(int x)
{
	stringstream ss;
	for (int i = x; i >= 0; i--) 
	{
		ss << i << " ";
	}
	return ss.str();
}
int pow(int x, int y)
{
	int a = 1;
	for (int i = 0; i < y; i++)
	{
		a = a * x;
	}
	return a;
}
bool equalNum(int x)
{
	if (x < 10) {
		return true;
	}
	int lastDigit = x % 10;
	x /= 10;
	while (x > 0) {
		if (x % 10 != lastDigit) {
			return false;
		}
		x /= 10;
	}
	return true;
}
void leftTriangle(int x)
{
	string s;
	for (int i = 1; i <= x; i++)
	{
		s.append("*");
		cout << s << endl;
	}
}
void guessGame()
{
	int guess, answ, k;
	srand(time(0));
	answ = rand() % 10;
	cin >> guess;
	k = 1;
	if (guess == answ)
		cout << "�� �������!" << endl << "�� �������� ����� �� " << k << " �������";
	while (guess != answ)
	{
		cout << "�� �� �������, ������� ����� �� 0 �� 9:";
		k += 1;
		cin >> guess;
		if (guess == answ)
			cout << "�� �������!" << endl << "�� �������� ����� �� " << k << " �������";
	}
}
int findLast(int arr[], int x)
{
	int lastIndex = -1;
	for (int i = 0; i < sizeof(arr); i++) {
		if (arr[i] == x) {
			lastIndex = i;
		}
	}
	return lastIndex;
}
int* add(int arr[], int x, int pos)
{
	int* newArr = new int[sizeof(arr) + 1];
	for (int i = 0; i < pos; ++i)
		newArr[i] = arr[i];
	newArr[pos] = x;
	for (int i = pos; i < sizeof(arr); ++i)
		newArr[i + 1] = arr[i];
	return newArr;
	delete[] newArr;
}
void reverse(int arr[])
{
	int right = sizeof(arr) - 1;
	int a;
	for (int left = 0; left < right; ++left)
	{
		a = arr[left];
		arr[left] = arr[right];
		arr[right] = a;
		right--;
	}
	cout << "��������������� ������: ";
	for (int i = 0; i < sizeof(arr); ++i)
	{
		cout << arr[i] << " ";
	}
}
int* concat(int arr1[], int arr2[])
{
	return 0;
}
int* deleteNegative(int arr[])
{
	return 0;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice, a,b,c;
	char x;
	string s;
	cout << "������� ����� ��������� �������:\n 1.�������� ���� ��������� ������ �����\n 2.�������� �� ����� �������������\n 3.������� �����\n 4.��������\n 5.������������ �����\n 6.���������� �������\n 7.������ ���������\n 8.������� �����\n 9.�������\n 10.����� ���� ������\n 11.����� ��������\n 12.������� �����\n 13.������������\n 14.����� �����������\n 15.��������\n 16.����� ���������� ��������\n 17.���������� � ������\n 18.������\n 19.�����������\n 20.������� �������\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "������� �����(�� ����� ���� ������):";
		cin >> a;
		if (a / 100 <= 0)
			cout << "����� ����� ����� ���� ������"; break;
		cout << "��������� �������� ���� ��������� ������ �����:" << sumLastNums(a); break;
	case 2:
		cout << "������� �����:";
		cin >> a;
		cout << isPositive(a); break;
	case 3:
		cout << "������� ������:";
		cin >> x;
		cout << isUpperCase(x); break;
	case 4:
		cout << "������� ��� �����:";
		cin >> a >> b;
		cout << isDivisor(a, b); break;
	case 5:
		cout << "������� ��� �����:";
		cin >> a >> b;
		cout << lastNumSum(a, b); break;
	case 6:
		cout << "������� ��� �����:";
		cin >> a >> b;
		cout << safeDiv(a, b); break;
	case 7:
		cout << "������� ��� �����:";
		cin >> a >> b;
		cout << makeDecision(a, b); break;
	case 8:
		cout << "������� ��� �����:";
		cin >> a >> b >> c;
		cout << sum3(a, b, c); break;
	case 9:
		cout << "������� �������:";
		cin >> a;
		cout << age(a); break;
	case 10:
		cout << "������� �������� ��� ������:";
		cin >> s;
		printDays(s); break;
	case 11:
		cout << "������� �����:";
		cin >> a;
		cout << reverseListNums(a); break;
	case 12:
		cout << "������� ����� � �������:";
		cin >> a >> b;
		cout << pow(a, b); break;
	case 13:
		cout << "������� �����:";
		cin >> a;
		cout << equalNum(a); break;
	case 14:
		cout << "������� ������ ������������:";
		cin >> a;
		leftTriangle(a); break;
	case 15:
		cout << "������� ����� �� 0 �� 9:";
		guessGame(); break;
	case 16:
	{
		cout << "������� ����� �������: ";
		cin >> a;
		int* arr = new int[a];
		cout << "������� �������� �������: ";
		for (int i = 0; i < a; i++)
			cin >> arr[i];
		cout << "������� ����� x: ";
		cin >> b;
		cout << findLast(arr, b);
		delete[] arr;
		break;
	}
	case 17:
	{
		cout << "������� ����� �������:";
		cin >> a;
		int* arr = new int[a];
		cout << "������� �������� �������:";
		for (int i = 0; i < a; i++)
			cin >> arr[i];
		cout << "������� ����� ��� ����������:";
		cin >> b;
		cout << "������� ������� ��� ����������:";
		cin >> c;
		arr = add(arr, b, c);
		for (int i = 0; i < a + 1; ++i)
		{
			cout << arr[i] << " ";
		}
		delete[] arr;
		break;
	}
	case 18:
	{
		cout << "������� ����� �������:";
		cin >> a;
		int* arr = new int[a];
		cout << "������� �������� �������:";
		for (int i = 0; i < a; i++)
			cin >> arr[i];
		reverse(arr);
		delete[] arr; 
		break;
	}
	case 19:
		cout << "������� ������ ������, � ����� ������:";
		concat;
		break;
	case 20:
		cout << "������� ������:";
		deleteNegative;
		break;
	default:
		cout << "������ � �����"; break;
	}
}