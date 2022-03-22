#include <iostream>
using namespace std;
template <typename T> void showArr(T arr[], int len);
void threeMax(int &a, int &b, int &c);
int& negativeEl(int array[], int len);
void zero(int arr1[], int len1, int arr2[], int len2);

int main() {
	setlocale(LC_ALL, "Russian");

	//Задача 1 . 
	/*Создайте функцию, которая принимает 3 переменные. Она находит среди них максимальную, после чего меняет
	значение двух оставшихся переменных на такое же значение, как и у максимальной.*/
	int a = 1, b = 8 , c = 15;
	cout << "Задача 1.\nИзначальные значения переменных: "<< a << " " << b << " " << c << endl;
	threeMax(a, b, c);
	cout << "Итоговые значения переменных: " << a << " " << b << " " << c << endl;
	cout << endl;

	//Задача 2
	/*Создайте функцию, которая принимает массив и его длину. Функция возвращает ссылку на первый
	отрицательный элемент массива. Если отрицательного элемента нет, то функция возвращает ссылку на первый
	элемент.*/
	cout << "Задача 2.\nИзначальный массив №1: ";
	int array[10] = { 1, 5, 9, -7, -3, 0, 17, -88, 64, 15 };
	showArr(array, 10);
	cout << negativeEl(array, 10) << endl;
	cout << "Изначальный массив №2: "; //без отрицательных значений
	int array2[10] = { 1, 5, 9, 7, 3, 0, 17, 88, 64, 15 };
	showArr(array2, 10);
	cout << negativeEl(array2, 10) << endl;
	cout << endl;

	//Задача 3
	/*Напишите функцию, которая принимает два массива и их длины. Функция должна обнулить все элементы
	второго массива, которые встречаются в первом. Для решения данной задачи используйте синтаксис
	указателей.*/
	cout << "Задача 3.\nМассив №1: ";
	int array31[7] = { 1, 15, 8, 57, 64, 20, 3 };
	int* pArr31 = array31;
	int array32[6] = { 8, 17, 81, 6, 1, 29 };
	int* pArr32 = array32;
	showArr(array31, 7);
	cout << "Массив №2: ";
	showArr(array32, 6);
	zero(pArr31, 7 , pArr32, 6);
	cout << "Итоговый массив: ";
	showArr(array32, 6);

	return 0;
}
//Задача 1.
void threeMax(int& a, int& b, int& c) {
	if (a > b && a > c) {
		b = a;
		c = a;
	}
	else
		if (b > a && b > c) {
			a = b;
			c = b;
		}
		else { 
			a = c;
			b = c;
		}
}

//Задача 2. 
int& negativeEl(int array[], int len) {
	for (int i = 0; i < len; i++)
		if (array[i] < 0)
			return array[i];
	return array[0];
}

//Задача 3.
void zero(int arr1[], int len1, int arr2[], int len2) {
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len1; j++) {
			if (*(arr1 + i) == *(arr2 + j))
				*(arr2 + j) = 0;
		}
	}
}

//Вывод массива: 
template <typename T> void showArr(T arr[], int len) {
	cout << "[";
	for (int i = 0; i < len; i++)
		cout << arr[i] <<", ";
	cout << "\b\b]\n";
}