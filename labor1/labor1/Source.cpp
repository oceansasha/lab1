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
		cout << "1. Сформировать динамический одномерный массив; " << endl;
		cout << "2. Заполнить динамический массив; " << endl;
		cout << "3. Выход; \n\n" << endl;

		cout << "Выберите действие: ";

		cin >> deust;
	}

	while ((deust > 3) || (deust < 0)) {
		cout << "\nВведено неверное значение." << endl;
		cout << "Выберите действие: ";
		cin >> deust;
	}

	if (deust == 3) {
		cout << "Выход." << endl;
		exit(0);
	}

	file.open("massiv.txt");

	if (!file) {
		cout << "Файл не открыт\n\n";
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

			cout << "Считанные значения из файла: " << endl;
			for (int i = 0; i < length; i++)
				cout << arr[i] << " ";
				
			cout << endl;
			cout << "Измененный массив: " << endl;
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
			cout << "\nВведите границы интервала a и b: ";
			cin >> a; cin >> b;

			srand(time(NULL));

			for (length2 = 0; length2 < 10; length2++) {
				arr2[length2] = rand() % (b - a + 1) + a;
				cout << arr2[length2] << " ";
			}

			cout << "\n\nВведите число k для нечётных чисел: ";
			cin >> k;
			cout << endl;
			cout << "Полученный массив: " << endl;

			for (length2 = 0; length2 < 10; length2++) {
				if (((arr2[length2]) % 2) == 1)
					cout << k << " ";
				cout << arr2[length2] << " ";
			}
			break;
		}
	cout << endl;
	cout << "\n\nВыберите действие: ";
	cin >> deust;
		while ((deust < 1) || (deust > 3)) {
			cout << "Введено неверное значение. Попробуйте снова: ";
			cin >> deust;
		}
	}
}