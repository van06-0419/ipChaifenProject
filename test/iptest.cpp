#include <gtest/gtest.h>
#include "../include/ipChaifen.h"
#include <sstream>
#include <vector>
#include <tuple>

TEST(IPUtilsTest, DuquAndJaingxuIpTest) {
    std::string input =
        "192.168.1.1\tother_data\n"
        "10.0.0.1\tmore_data\n"
        "255.255.255.255\tlast\n";

    std::istringstream iss(input);
    auto ips = duqu_and_jaingxu_ip(iss);

    ASSERT_EQ(ips.size(), 3);
    EXPECT_EQ(ips[0], std::make_tuple(255, 255, 255, 255));
    EXPECT_EQ(ips[1], std::make_tuple(192, 168, 1, 1));
    EXPECT_EQ(ips[2], std::make_tuple(10, 0, 0, 1));
}

TEST(IPUtilsTest, JaingxuTest) {
    std::string input =
        "1.1.1.1\n"
        "2.2.2.2\n"
        "1.1.1.2\n";

    std::istringstream iss(input);
    auto ips = duqu_and_jaingxu_ip(iss);

    ASSERT_EQ(ips.size(), 3);
    EXPECT_EQ(ips[0], std::make_tuple(2, 2, 2, 2));
    EXPECT_EQ(ips[1], std::make_tuple(1, 1, 1, 2));
    EXPECT_EQ(ips[2], std::make_tuple(1, 1, 1, 1));
}

TEST(IPUtilsTest, GuolvTest) {
    std::vector<std::tuple<int, int, int, int>> test_ips = {
        {1, 2, 3, 4},
        {1, 5, 6, 7},
        {46, 2, 3, 4},
        {46, 70, 8, 9},
        {10, 46, 3, 4},
        {11, 12, 46, 14},
        {15, 16, 17, 46}
    };

    auto diyiguolv = diyidyValue(test_ips, 1);
    EXPECT_EQ(diyiguolv.size(), 2);
    EXPECT_EQ(diyiguolv[0], std::make_tuple(1, 2, 3, 4));
    EXPECT_EQ(diyiguolv[1], std::make_tuple(1, 5, 6, 7));

    auto qianliangguolv = qianliadyValue(test_ips, 46, 70);
    EXPECT_EQ(qianliangguolv.size(), 1);
    EXPECT_EQ(qianliangguolv[0], std::make_tuple(46, 70, 8, 9));

    auto renyiguolv = renyidyValue(test_ips, 46);
    EXPECT_EQ(renyiguolv.size(), 5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
