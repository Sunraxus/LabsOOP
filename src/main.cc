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
		cout << "������ ���������� ����";
	for (int i = 0; i < arr.get_size(); ++i) {
		cout << "[" << i + 1 << "]\t" << arr[i] << endl;
	}
	cout << endl;
	cout << "��� ����������� ������� ����� ������ ";
	get_key();
}

VehicleType InputTypeVeh() {
	string types[] = { "RailWay", "AirWay", "WaterWay" };
	VehicleType ctypes[] = { RailWay, AirWay, WaterWay, };
	int choose = 0;
	int flag = true;
	system("cls");
	while (flag) {
		cout << "<�������� ��� ����������>" << endl;
		cout << "1)" << "<���������������>" << endl;
		cout << "2)" << "<���������>" << endl;
		cout << "3)" << "<������>" << endl;
		int seq_type = get_key();
		if (seq_type == 49) { choose = 0; flag = false; }
		else if (seq_type == 50) { choose = 1; flag = false; }
		else if (seq_type == 51) { choose = 2; flag = false; }
		else { cout << "������� ������������ �����, ���������� ��� ���" << endl; }
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
		cout << "<�������� ��� ���������>" << endl;
		cout << "1)" << "<���������>" << endl;
		cout << "2)" << "<����������>" << endl;
		int seq_type = get_key();
		if (seq_type == 49) { choose = 0; flag1 = false; }
		else if (seq_type == 50) { choose = 1; flag1 = false; }
		else { cout << "������� ������������ �����, ���������� ��� ���" << endl; }
	}
	return ctypeseng[choose];
}

void InputA(Vehicle& veh) {
	int a = 0;
	cout << "������� ����������� �����������" << endl;
	cin >> a;
	veh.set_a(a);
}

void InputK(Vehicle& veh) {
	int k = 0;
	cout << "������� ������� ����� ���������" << endl;
	cin >> k;
	veh.set_k(k);
}

int InputIndex(int size) {
	bool flag = true;
	int index;
	while (flag) {
		cout << "������� ������ ��� 0, ���� ������ �����: ";
		cin >> index;
		index--;
		if (cin.fail() || index < -1 || index >= size) {
			std::cin.clear();
			system("cls");
			cout << "�������� ������ ��� ����!" << endl;
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
		cout << "������ ���������� ����";
		for (int i = 0; i < arr.get_size(); ++i) {
			cout << "[" << i + 1 << "]\t" << arr[i] << endl;
		}
		cout << endl;
		cout << "��� ����������� ������� ����� ������ ";
		get_key();
	}
	else {
		double m;
		double d;
		cout << "������� ����� ����� m: \n";
		cin >> m;
		cout << "������� ����� ���� d: \n";
		cin >> d;
		int index = index_of_min_price(arr, m, d);
		cout << "������ ����������� � ����������� ����� ��������������� ��� m=" << m << "��� d=" << d << " �������� - " << "[" << index << "]" << " " << arr[index] << endl;
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
	cout << "1)" << "�������� ��������� � ������" << endl;
	cout << "2)" << "�������� ��������� � ������ �� �������" << endl;
	cout << "3)" << "������� ��������� �� ������� �� �������" << endl;
	cout << "4)" << "������� ��������� �� �����" << endl;
	cout << "5)" << "������� ������ ��������� � ����������� ����� ���������������" << endl;
	cout << "6)" << "�������� ��������� �� ������� �� �������" << endl;
	cout << "7)" << "�����" << endl;

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
		printf("����:\n");
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