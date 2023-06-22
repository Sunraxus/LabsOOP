#include <gtest/gtest.h>
#include <function/function.h>

using namespace vehicles;

TEST(VehicleTests, RailWay1) {
    Vehicle v(RailWay, 40);

    double res1 = v.calc_price(10, 30);
    double res2 = v.calc_price(56, 250);
    double res3 = v.calc_price(79, 600);

    EXPECT_EQ(res1, 12000);
    EXPECT_EQ(res2, 560000);
    EXPECT_EQ(res3, 1896000);
}

TEST(VehicleTests, RailWay2) {
    Vehicle v(RailWay, 15.5);

    double res1 = v.calc_price(5, 30);
    double res2 = v.calc_price(13, 55);
    double res3 = v.calc_price(20, 605);

    EXPECT_EQ(res1, 2325);
    EXPECT_EQ(res2, 11082.5);
    EXPECT_EQ(res3, 187550);
}

TEST(VehicleTests, RailWay3) {
    Vehicle v(RailWay, 20.6);

    double res1 = v.calc_price(10, 25);
    double res2 = v.calc_price(20, 140);
    double res3 = v.calc_price(15, 100);

    EXPECT_EQ(res1, 5150);
    EXPECT_EQ(res2, 57680);
    EXPECT_EQ(res3, 30900);
}

TEST(VehicleTests, WaterWay1) {
    Vehicle v(WaterWay, 20, 0.95);

    double res1 = v.calc_price(10, 25);
    double res2 = v.calc_price(20, 140);
    double res3 = v.calc_price(15, 100);

    EXPECT_EQ(res1, 4998.7178320638823);
    EXPECT_EQ(res2, 55919.629842517388);
    EXPECT_EQ(res3, 29969.239803983037);
}

TEST(VehicleTests, WaterWay2) {
    Vehicle v(WaterWay, 35, 0.97);

    double res1 = v.calc_price(5, 50);
    double res2 = v.calc_price(23, 130);
    double res3 = v.calc_price(30, 104.5);

    EXPECT_EQ(res1, 8747.3352252003333);
    EXPECT_EQ(res2, 104567.15635025951);
    EXPECT_EQ(res3, 109655.17157494406);
}

TEST(VehicleTests, AirWay1) {
    Vehicle v(AirWay, Turbo, 35);

    double res1 = v.calc_price(5, 50);
    double res2 = v.calc_price(23, 130);
    double res3 = v.calc_price(30, 104.5);

    EXPECT_EQ(res1, 4375);
    EXPECT_EQ(res2, 52325);
    EXPECT_EQ(res3, 54862.5);
}

TEST(VehicleTests, AirWay2) {
    Vehicle v(AirWay, Turbo, 55);

    double res1 = v.calc_price(5, 1550);
    double res2 = v.calc_price(3, 130);
    double res3 = v.calc_price(3.5, 10000);

    EXPECT_EQ(res1, 639375);
    EXPECT_EQ(res2, 10725);
    EXPECT_EQ(res3, 2887500);
}

TEST(VehicleTests, AirWay3) {
    Vehicle v(AirWay, React, 0.1);

    double res1 = v.calc_price(5, 1560);
    double res2 = v.calc_price(32, 130);
    double res3 = v.calc_price(3.55, 10000);

    EXPECT_EQ(res1, 390);
    EXPECT_EQ(res2, 624);
    EXPECT_EQ(res3, 1775);
}

TEST(VehicleTests, AirWay4) {
    Vehicle v(AirWay, React, 105);

    double res1 = v.calc_price(5.66, 256);
    double res2 = v.calc_price(32, 130);
    double res3 = v.calc_price(45, 345.678);

    EXPECT_EQ(res1, 228211.20000000001);
    EXPECT_EQ(res2, 655200);
    EXPECT_EQ(res3, 2449992.8250000002);
}

TEST(VehicleTests, SetKTest1) {

    Vehicle s(VehicleType::RailWay, 6);
    s.set_k(8);

    double res1 = s.get_k();

    EXPECT_EQ(res1, 8);
}

TEST(VehicleTests, SetKTest2) {

    Vehicle s(VehicleType::RailWay, 1);
    s.set_k(4);

    double  res1 = s.get_k();

    EXPECT_EQ(res1, 4);
}

TEST(VehicleTests, SetATest1) {

    Vehicle s(VehicleType::RailWay, 9);
    s.set_a(14);

    double  res1 = s.get_a();

    EXPECT_EQ(res1, 14);
}

TEST(VehicleTests, SetATest2) {

    Vehicle s(VehicleType::RailWay, 2);
    s.set_a(46);

    double  res1 = s.get_a();

    EXPECT_EQ(res1, 46);
}