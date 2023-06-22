#include <gtest/gtest.h>
#include <function/function.h>

using namespace vehicles;

TEST(VehicleListTests, CapacityCheck) {
	VehicleList vehicle(3);
	Vehicle v = Vehicle(RailWay, 50);
	vehicle[0] = Vehicle(RailWay, 190);
	vehicle[1] = Vehicle(RailWay, 70);
	vehicle[2] = Vehicle(RailWay, 501);
	ASSERT_ANY_THROW(vehicle.insert(4, v););

}

TEST(IndexOfVehicleWithMinPrice, MinCheck1) {
	VehicleList vehicle;
	Vehicle v0 = Vehicle(RailWay, 10);
	Vehicle v1 = Vehicle(RailWay, 15);
	vehicle.insert(0, v0);
	vehicle.insert(1, v1);
	vehicle.insert(2, v1);
	vehicle.insert(3, v0);
	const auto index = index_of_min_price(vehicle, 10, 9);
	ASSERT_EQ(index, 0);
}

TEST(IndexOfSequenceWithMinPrice, MinCheck2) {
	VehicleList vehicle;
	Vehicle v1 = Vehicle(RailWay, 10);
	Vehicle v2 = Vehicle(AirWay, Turbo, 13);
	Vehicle v3 = Vehicle(AirWay, React, 17);
	Vehicle v4 = Vehicle(AirWay, Turbo, 25);
	vehicle.insert(0, v1);
	vehicle.insert(1, v2);
	vehicle.insert(2, v3);
	vehicle.insert(3, v4);
	const auto index = index_of_min_price(vehicle, 5, 55);
	ASSERT_EQ(index, 1);
}


TEST(IndexOfVehicleWithMinPrice, MinCheck3) {
	VehicleList vehicle;
	Vehicle v0 = Vehicle(RailWay, 18);
	Vehicle v1 = Vehicle(AirWay, React, 24);
	Vehicle v3 = Vehicle(WaterWay, 24, 0.95);
	vehicle.insert(0, v0);
	vehicle.insert(1, v3);
	vehicle.insert(2, v0);
	vehicle.insert(3, v1);
	const auto index = index_of_min_price(vehicle, 52, 10);
	ASSERT_EQ(index, 0);
}

TEST(IndexOfVehicleWithMinPrice, MinCheck4) {
	VehicleList vehicle;
	Vehicle v0 = Vehicle(RailWay, 6);
	Vehicle v1 = Vehicle(WaterWay, 33, 0.95);
	Vehicle v2 = Vehicle(WaterWay, 5, 0.92);
	Vehicle v3 = Vehicle(WaterWay, 100, 0.91);
	vehicle.insert(0, v0);
	vehicle.insert(1, v1);
	vehicle.insert(2, v2);
	vehicle.insert(3, v3);
	const auto index = index_of_min_price(vehicle, 10, 40);
	ASSERT_EQ(index, 2);
}

TEST(IndexOfVehicleWithMinPrice, MinCheck5) {
	VehicleList vehicle;
	Vehicle v0 = Vehicle(RailWay, 16);
	Vehicle v1 = Vehicle(RailWay, 19);
	Vehicle v2 = Vehicle(AirWay, React, 15);
	Vehicle v3 = Vehicle(AirWay, Turbo, 30);
	Vehicle v4 = Vehicle(AirWay, Turbo, 5);
	Vehicle v5 = Vehicle(WaterWay, 200, 0.91);
	Vehicle v6 = Vehicle(WaterWay, 70, 0.99);
	Vehicle v7 = Vehicle(WaterWay, 40, 0.98);
	vehicle.insert(0, v0);
	vehicle.insert(1, v1);
	vehicle.insert(2, v2);
	vehicle.insert(3, v3);
	vehicle.insert(3, v4);
	vehicle.insert(3, v5);
	vehicle.insert(3, v6);
	vehicle.insert(3, v7);
	const auto index = index_of_min_price(vehicle, 50, 16);
	ASSERT_EQ(index, 6);
}



