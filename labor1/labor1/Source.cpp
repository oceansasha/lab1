#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int length = 0, length2 = 0, a, b, k, temp, i;
	int deust;
	ifstream file;
	string str;

	{
		cout << "1. ������������ ������������ ���������� ������; " << endl;
		cout << "2. ��������� ������������ ������; " << endl;
		cout << "3. �����; \n\n" << endl;

		cout << "�������� ��������: ";

		cin >> deust;
	}

	while ((deust > 3) || (deust < 0)) {
		cout << "\n������� �������� ��������." << endl;
		cout << "�������� ��������: ";
		cin >> deust;
	}

	if (deust == 3) {
		cout << "�����." << endl;
		exit(0);
	}

	file.open("massiv.txt");

	if (!file) {
		cout << "���� �� ������\n\n";
		return -1;
	}

	while (!file.eof()) {
		file >> str;
		length++;
	}
	file.close();

	int* arr = new int[length];
	file.open("massiv.txt");
	length = 0;

	while (!file.eof())
	{
		file >> a;
		arr[length] = a;
		length++;
	}
	file.close();

	while ((deust == 1) || (deust == 2)) {
		switch (deust) {

		case 1:

			cout << "��������� �������� �� �����: " << endl;
			for (int i = 0; i < length; i++)
				cout << arr[i] << " ";
				
			cout << endl;
			cout << "���������� ������: " << endl;
			for (int i = 0; i < length - 1; i++) {
				for (int j = 0; j < length - i - 1; j++) {
						if (arr[j] > arr[j + 1]) {
							temp = arr[j];
							arr[j] = arr[j + 1];
							arr[j + 1] = temp;
						}
					}
				}

				for (int i = 0; i < length; i++) {
					if (arr[i] < 0)
						cout << arr[i] << " ";
				}

				break;

		case 2:
			int randomD;
			int* arr2 = new int[10];
			int length2;
			cout << "\n������� ������� ��������� a � b: ";
			cin >> a; cin >> b;

			srand(time(NULL));

			for (length2 = 0; length2 < 10; length2++) {
				arr2[length2] = rand() % (b - a + 1) + a;
				cout << arr2[length2] << " ";
			}

			cout << "\n\n������� ����� k ��� �������� �����: ";
			cin >> k;
			cout << endl;
			cout << "���������� ������: " << endl;

			for (length2 = 0; length2 < 10; length2++) {
				if (((arr2[length2]) % 2) == 1)
					cout << k << " ";
				cout << arr2[length2] << " ";
			}
			break;
		}
	cout << endl;
	cout << "\n\n�������� ��������: ";
	cin >> deust;
		while ((deust < 1) || (deust > 3)) {
			cout << "������� �������� ��������. ���������� �����: ";
			cin >> deust;
		}
	}
}