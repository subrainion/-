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
		return to_string(x) + " год";
	if (((x % 10 == 2) || (x % 10 == 3) || (x % 10 == 4)) && (x != 12) && (x != 13) && (x != 14))
		return to_string(x) + " года";
	else
		return to_string(x) + " лет";
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
		cout << "Вы угадали!" << endl << "Вы отгадали число за " << k << " попытки";
	while (guess != answ)
	{
		cout << "Вы не угадали, введите число от 0 до 9:";
		k += 1;
		cin >> guess;
		if (guess == answ)
			cout << "Вы угадали!" << endl << "Вы отгадали число за " << k << " попытки";
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
	cout << "Реверсированный массив: ";
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
	cout << "Введите номер выбранной функции:\n 1.Сложение двух последних знаков числа\n 2.Является ли число положительным\n 3.Большая буква\n 4.Делитель\n 5.Многократный вызов\n 6.Безопасное деление\n 7.Строка сравнения\n 8.Тройная сумма\n 9.Возраст\n 10.Вывод дней недели\n 11.Числа наоборот\n 12.Степень числа\n 13.Одинаковость\n 14.Левый треугольник\n 15.Угадайка\n 16.Поиск последнего значения\n 17.Добавление в массив\n 18.Реверс\n 19.Объединение\n 20.Удалить негатив\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Введите число(не менее двух знаков):";
		cin >> a;
		if (a / 100 <= 0)
			cout << "Число имеет менее двух знаков"; break;
		cout << "Результат сложения двух последних знаков числа:" << sumLastNums(a); break;
	case 2:
		cout << "Введите число:";
		cin >> a;
		cout << isPositive(a); break;
	case 3:
		cout << "Введите символ:";
		cin >> x;
		cout << isUpperCase(x); break;
	case 4:
		cout << "Введите два числа:";
		cin >> a >> b;
		cout << isDivisor(a, b); break;
	case 5:
		cout << "Введите два числа:";
		cin >> a >> b;
		cout << lastNumSum(a, b); break;
	case 6:
		cout << "Введите два числа:";
		cin >> a >> b;
		cout << safeDiv(a, b); break;
	case 7:
		cout << "Введите два числа:";
		cin >> a >> b;
		cout << makeDecision(a, b); break;
	case 8:
		cout << "Введите три числа:";
		cin >> a >> b >> c;
		cout << sum3(a, b, c); break;
	case 9:
		cout << "Введите возраст:";
		cin >> a;
		cout << age(a); break;
	case 10:
		cout << "Введите название дня недели:";
		cin >> s;
		printDays(s); break;
	case 11:
		cout << "Введите число:";
		cin >> a;
		cout << reverseListNums(a); break;
	case 12:
		cout << "Введите число и степень:";
		cin >> a >> b;
		cout << pow(a, b); break;
	case 13:
		cout << "Введите число:";
		cin >> a;
		cout << equalNum(a); break;
	case 14:
		cout << "Введите высоту треугольника:";
		cin >> a;
		leftTriangle(a); break;
	case 15:
		cout << "Введите число от 0 до 9:";
		guessGame(); break;
	case 16:
	{
		cout << "Введите длину массива: ";
		cin >> a;
		int* arr = new int[a];
		cout << "Введите элементы массива: ";
		for (int i = 0; i < a; i++)
			cin >> arr[i];
		cout << "Введите число x: ";
		cin >> b;
		cout << findLast(arr, b);
		delete[] arr;
		break;
	}
	case 17:
	{
		cout << "Введите длину массива:";
		cin >> a;
		int* arr = new int[a];
		cout << "Введите элементы массива:";
		for (int i = 0; i < a; i++)
			cin >> arr[i];
		cout << "Введите число для добавления:";
		cin >> b;
		cout << "Введите позицию для добавления:";
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
		cout << "Введите длину массива:";
		cin >> a;
		int* arr = new int[a];
		cout << "Введите элементы массива:";
		for (int i = 0; i < a; i++)
			cin >> arr[i];
		reverse(arr);
		delete[] arr; 
		break;
	}
	case 19:
		cout << "Введите первый массив, а затем второй:";
		concat;
		break;
	case 20:
		cout << "Введите массив:";
		deleteNegative;
		break;
	default:
		cout << "Ошибка в вводе"; break;
	}
}