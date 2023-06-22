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
		friend std::ostream& operator<<(std::ostream& out, const VehicleType& type);
		friend std::ostream& operator<<(std::ostream& out, EngineType& eng);
		friend std::ostream& operator<<(std::ostream& out, const Vehicle& veh);
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
		int _size;
		Vehicle** _array;
	public:
		VehicleList(const VehicleList& arr);
		VehicleList() : _size(0), _array(nullptr) {};
		VehicleList(int size);
		int get_size() const;
		void insert(int index, Vehicle& v);
		void remove(int index);
		void add(Vehicle v);
		void clear();

		Vehicle& operator[](int index);
		Vehicle operator[](int index) const;

		void swap(VehicleList& arr);
		~VehicleList();
		VehicleList& operator=(VehicleList arr);
	};
	int index_of_min_price(const VehicleList& vehicle, double m, double d);
}