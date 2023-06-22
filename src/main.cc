#include <iostream>
#include <stdlib.h>
#include <function/function.h>
#include <string>
#include <conio.h>
#include <locale.h>
using namespace std;
using namespace vehicles;


int get_key() {
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

void PrintList(VehicleList& arr) {
	system("cls");
	if (arr.get_size() == 0)
		cout << "Массив транспорта пуст";
	for (int i = 0; i < arr.get_size(); ++i) {
		cout << "[" << i + 1 << "]\t" << arr[i] << endl;
	}
	cout << endl;
	cout << "Для продолжения нажмите любую кнопку ";
	get_key();
}

VehicleType InputTypeVeh() {
	string types[] = { "RailWay", "AirWay", "WaterWay" };
	VehicleType ctypes[] = { RailWay, AirWay, WaterWay, };
	int choose = 0;
	int flag = true;
	system("cls");
	while (flag) {
		cout << "<Выберите тип трансопрта>" << endl;
		cout << "1)" << "<Железнодорожный>" << endl;
		cout << "2)" << "<Воздушный>" << endl;
		cout << "3)" << "<Водный>" << endl;
		int seq_type = get_key();
		if (seq_type == 49) { choose = 0; flag = false; }
		else if (seq_type == 50) { choose = 1; flag = false; }
		else if (seq_type == 51) { choose = 2; flag = false; }
		else { cout << "Введено неправильное число, попробуйте ещё раз" << endl; }
	}
	return ctypes[choose];
}

EngineType InputTypeEng(Vehicle& veh) {
	string typeseng[] = { "Turbo", "React" };
	EngineType ctypeseng[] = { Turbo, React };
	int choose = 0;
	int flag1 = true;
	system("cls");
	while (flag1) {
		cout << "<Выберите тип двигателя>" << endl;
		cout << "1)" << "<Турбинный>" << endl;
		cout << "2)" << "<Реактивный>" << endl;
		int seq_type = get_key();
		if (seq_type == 49) { choose = 0; flag1 = false; }
		else if (seq_type == 50) { choose = 1; flag1 = false; }
		else { cout << "Введено неправильное число, попробуйте ещё раз" << endl; }
	}
	return ctypeseng[choose];
}

void InputA(Vehicle& veh) {
	int a = 0;
	cout << "Введите поощаряющий коэффициент" << endl;
	cin >> a;
	veh.set_a(a);
}

void InputK(Vehicle& veh) {
	int k = 0;
	cout << "Введите базовый тариф перевозки" << endl;
	cin >> k;
	veh.set_k(k);
}

int InputIndex(int size) {
	bool flag = true;
	int index;
	while (flag) {
		cout << "Введите индекс или 0, если хотите выйти: ";
		cin >> index;
		index--;
		if (cin.fail() || index < -1 || index >= size) {
			std::cin.clear();
			system("cls");
			cout << "Неверный индекс или ввод!" << endl;
		}
		else {
			flag = false;
		}
	}
	return index;
}

void AddVehicleForIndex(VehicleList& arr) {
	system("cls");
	int index = InputIndex(arr.get_size() + 1);
	if (index != -1) {
		Vehicle veh(InputTypeVeh(), 0);
		InputK(veh);
		VehicleType type = veh.get_vehicle_type();
		if (type == AirWay) { InputTypeEng(veh); }
		if (type == WaterWay) { InputA(veh); }
		arr.insert(index, veh);
	}
}

void AddVehicle(VehicleList& arr) {
	system("cls");
	Vehicle veh(InputTypeVeh(), 0);
	InputK(veh);
	VehicleType type = veh.get_vehicle_type();
	if (type == AirWay) { InputTypeEng(veh); }
	if (type == WaterWay) { InputA(veh); }
	arr.add(veh);
}

void DeleteCharacter(VehicleList& arr) {
	int index = InputIndex(arr.get_size());
	if (index != -1) { arr.remove(index); }
}

void FindMinPrice(VehicleList& arr) {
	system("cls");
	if (arr.get_size() == 0) {
		cout << "Массив транспорта пуст";
		for (int i = 0; i < arr.get_size(); ++i) {
			cout << "[" << i + 1 << "]\t" << arr[i] << endl;
		}
		cout << endl;
		cout << "Для продолжения нажмите любую кнопку ";
		get_key();
	}
	else {
		double m;
		double d;
		cout << "Введите массу груза m: \n";
		cin >> m;
		cout << "Введите длину пути d: \n";
		cin >> d;
		int index = index_of_min_price(arr, m, d);
		cout << "Первым транспортом с минимальной ценой транспортировки при m=" << m << "при d=" << d << " является - " << "[" << index << "]" << " " << arr[index] << endl;
		get_key();
	}
}

void ChangeVehicle(VehicleList& arr) {
	system("cls");
	int index = InputIndex(arr.get_size());
	if (index != -1) {
		Vehicle veh(InputTypeVeh(), 0);
		InputK(veh);
		VehicleType type = veh.get_vehicle_type();
		if (type == AirWay) { InputTypeEng(veh); }
		if (type == WaterWay) { InputA(veh); }
		arr[index] = veh;
	}
}

int menu1() {
	cout << "1)" << "Добавить транспорт в массив" << endl;
	cout << "2)" << "Вставить транспорт в массив по индексу" << endl;
	cout << "3)" << "Удалить транспорт из массива по индексу" << endl;
	cout << "4)" << "Вывести транспорт на экран" << endl;
	cout << "5)" << "Вывести первый транспорт с минимальной ценой транспортировки" << endl;
	cout << "6)" << "Заменить транспорт из массива по индексу" << endl;
	cout << "7)" << "Выйти" << endl;

	while (true) {
		int key = get_key();
		if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55)) return key;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	VehicleList array;
	while (true) {
		system("cls");
		printf("Меню:\n");
		int m1 = menu1();
		if (m1 == 50) { system("cls"); AddVehicleForIndex(array); };
		if (m1 == 51) { DeleteCharacter(array); };
		if (m1 == 52) { PrintList(array); };
		if (m1 == 53) { FindMinPrice(array); };
		if (m1 == 54) { ChangeVehicle(array); };
		if (m1 == 49) { system("cls"); AddVehicle(array); };
		if (m1 == 55) break;
	}
	return 0;
}