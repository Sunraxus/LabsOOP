#include <cstdio>
#include <stdexcept>
#include <function/function.h>

using namespace vehicles;

Vehicle::Vehicle() : _type(VehicleType::RailWay), _k(1) {} 

Vehicle::Vehicle(VehicleType type, double k) {
	this->_type = type;
	this->_k = k;
}

Vehicle::Vehicle(VehicleType type, EngineType eng, double k) {
	this->_type = type;
	this->_eng = eng;
	this->_k = k;
}

Vehicle::Vehicle(VehicleType type, double k, double a) {
	this->_type = type;
	this->_k = k;
	this->_a = a;
}

VehicleType Vehicle::get_vehicle_type() const {
	return _type;
}

EngineType Vehicle::get_engine_type() const {
	return _eng;
}

void Vehicle::set_k(double k) {
	_k = k;
}

double Vehicle::get_k() const {
	return _k;
}

void Vehicle::set_a(double a) {
	_a = a;
}

double Vehicle::get_a() const {
	return _a;
}

double Vehicle::calc_price(double m, double d) {
	switch (_type) {
	case RailWay:
		return _k * m * d;
	case WaterWay:
		return _k * m * d * pow(_a, d / 5000);
	case AirWay:
		switch (_eng) {
		case Turbo:
			if (d < 1000) return _k * m * d * 0.5;
			else return _k * m * d * 1.5;
		case React:
			if (d < 1000) return _k * m * d * 1.5;
			else return _k * m * d * 0.5;
		}
	}
}

std::ostream& vehicles::operator<<(std::ostream& out1, const VehicleType& type) {
	switch (type) {
	case RailWay:
		out1 << "RailWay";
		return out1;
	case AirWay:
		out1 << "AirWay";
		return out1;
	case WaterWay:
		out1 << "WaterWay";
		return out1;
	}
}

std::ostream& vehicles::operator<<(std::ostream& out2, EngineType& eng) {
	switch (eng) {
	case Turbo:
		out2 << "Turbo";
		return out2;
	case React:
		out2 << "React";
		return out2;
	}
}

std::ostream& vehicles::operator<<(std::ostream& out, const Vehicle& vehicle) {
	double a = vehicle._a;
	double k = vehicle._k;
	if (vehicle.get_vehicle_type() == RailWay) { out << "Type: " << vehicle.get_vehicle_type() << "|" << "Basic Rate: " << k << "\n"; }
	else if (vehicle.get_vehicle_type() == WaterWay) { out << "Type: " << vehicle.get_vehicle_type() << "|" << "Basic Rate: " << k << "|" << "Encouraging Coefficient : " << a << "\n"; }
	else if (vehicle.get_vehicle_type() == AirWay) { out << "Type: " << vehicle.get_vehicle_type() << "|" << "Basic Rate: " << k << "|" << "Engine Type : " << vehicle.get_engine_type() << "\n"; }
	return out;
}