#pragma once
#include <string>
#include <iostream>

namespace vehicles {
	enum VehicleType {
		RailWay,
		WaterWay,
		AirWay
	};

	enum EngineType {
		Turbo,
		React
	};

	class Vehicle {
	private:
		VehicleType _type;
		EngineType _eng;
		double _k, _a;
	public:
		Vehicle();
		Vehicle(VehicleType _type, double k);
		Vehicle(VehicleType _type, EngineType _eng, double k);
		Vehicle(VehicleType _type, double k, double a);
		VehicleType get_vehicle_type() const; 
		EngineType get_engine_type() const;
		double get_k() const;
		double get_a() const;
		void set_a(double a);
		void set_k(double k);
		double calc_price(double m, double d);
	};

	class VehicleList {
	public:
		static const int CAPACITY = 20;
	private:
		Vehicle _vehicles[CAPACITY];
		int _size; 
	public:
		VehicleList();
		int get_size() const;
		Vehicle operator[](int index) const;
		void insert(int index, Vehicle v);
		void remove(int index);
	};
	int index_of_min_price(const VehicleList& vehicle, double m, double d);
}