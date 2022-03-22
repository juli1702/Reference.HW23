#include <iostream>
using namespace std;
template <typename T> void showArr(T arr[], int len);
void threeMax(int &a, int &b, int &c);
int& negativeEl(int array[], int len);
void zero(int arr1[], int len1, int arr2[], int len2);

int main() {
	setlocale(LC_ALL, "Russian");

	//������ 1 . 
	/*�������� �������, ������� ��������� 3 ����������. ��� ������� ����� ��� ������������, ����� ���� ������
	�������� ���� ���������� ���������� �� ����� �� ��������, ��� � � ������������.*/
	int a = 1, b = 8 , c = 15;
	cout << "������ 1.\n����������� �������� ����������: "<< a << " " << b << " " << c << endl;
	threeMax(a, b, c);
	cout << "�������� �������� ����������: " << a << " " << b << " " << c << endl;
	cout << endl;

	//������ 2
	/*�������� �������, ������� ��������� ������ � ��� �����. ������� ���������� ������ �� ������
	������������� ������� �������. ���� �������������� �������� ���, �� ������� ���������� ������ �� ������
	�������.*/
	cout << "������ 2.\n����������� ������ �1: ";
	int array[10] = { 1, 5, 9, -7, -3, 0, 17, -88, 64, 15 };
	showArr(array, 10);
	cout << negativeEl(array, 10) << endl;
	cout << "����������� ������ �2: "; //��� ������������� ��������
	int array2[10] = { 1, 5, 9, 7, 3, 0, 17, 88, 64, 15 };
	showArr(array2, 10);
	cout << negativeEl(array2, 10) << endl;
	cout << endl;

	//������ 3
	/*�������� �������, ������� ��������� ��� ������� � �� �����. ������� ������ �������� ��� ��������
	������� �������, ������� ����������� � ������. ��� ������� ������ ������ ����������� ���������
	����������.*/
	cout << "������ 3.\n������ �1: ";
	int array31[7] = { 1, 15, 8, 57, 64, 20, 3 };
	int* pArr31 = array31;
	int array32[6] = { 8, 17, 81, 6, 1, 29 };
	int* pArr32 = array32;
	showArr(array31, 7);
	cout << "������ �2: ";
	showArr(array32, 6);
	zero(pArr31, 7 , pArr32, 6);
	cout << "�������� ������: ";
	showArr(array32, 6);

	return 0;
}
//������ 1.
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

//������ 2. 
int& negativeEl(int array[], int len) {
	for (int i = 0; i < len; i++)
		if (array[i] < 0)
			return array[i];
	return array[0];
}

//������ 3.
void zero(int arr1[], int len1, int arr2[], int len2) {
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len1; j++) {
			if (*(arr1 + i) == *(arr2 + j))
				*(arr2 + j) = 0;
		}
	}
}

//����� �������: 
template <typename T> void showArr(T arr[], int len) {
	cout << "[";
	for (int i = 0; i < len; i++)
		cout << arr[i] <<", ";
	cout << "\b\b]\n";
}