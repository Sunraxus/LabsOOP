#include <gtest/gtest.h>
#include <function/function.h>

using namespace vehicles;

TEST(VehicleListTests, CapacityCheck) {
    VehicleList vehicle;

    const auto v = Vehicle::Vehicle(RailWay, 0);
    for (int i = 0; i < VehicleList::CAPACITY; ++i) {
        vehicle.insert(i, v);
    }
    ASSERT_ANY_THROW(vehicle.insert(10, v));
}

TEST(IndexOfSequenceWithMinValue, MinChack1) {
    VehicleList vehicle;

    vehicle.insert(0, Vehicle::Vehicle(RailWay, 50));
    vehicle.insert(1, Vehicle::Vehicle(RailWay, 45));


    const auto index = index_of_min_price(vehicle, 5, 15);

    ASSERT_EQ(index, 1);
}

TEST(IndexOfSequenceWithMinValue, MinChack2) {
    VehicleList vehicle;

    vehicle.insert(0, Vehicle::Vehicle(RailWay, 50));
    vehicle.insert(1, Vehicle::Vehicle(RailWay, 45));
    vehicle.insert(2, Vehicle::Vehicle(WaterWay, 45, 0.95));

    const auto index = index_of_min_price(vehicle, 5, 25);

    ASSERT_EQ(index, 2);
}

TEST(IndexOfSequenceWithMinValue, MinChack3) {
    VehicleList vehicle;

    vehicle.insert(0, Vehicle::Vehicle(RailWay, 50));
    vehicle.insert(1, Vehicle::Vehicle(RailWay, 45));
    vehicle.insert(2, Vehicle::Vehicle(WaterWay, 45, 0.95));
    vehicle.insert(3, Vehicle::Vehicle(WaterWay, 24.5, 0.95));

    const auto index = index_of_min_price(vehicle, 65, 105);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, MinChack4) {
    VehicleList vehicle;

    vehicle.insert(0, Vehicle::Vehicle(RailWay, 50));
    vehicle.insert(1, Vehicle::Vehicle(RailWay, 45));
    vehicle.insert(2, Vehicle::Vehicle(WaterWay, 45, 0.95));
    vehicle.insert(3, Vehicle::Vehicle(WaterWay, 24.5, 0.925));
    vehicle.insert(4, Vehicle::Vehicle(AirWay, Turbo, 13.5));
    vehicle.insert(5, Vehicle::Vehicle(AirWay, React, 35));

    const auto index = index_of_min_price(vehicle, 125, 10005);

    ASSERT_EQ(index, 5);
}

