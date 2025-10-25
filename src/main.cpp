#include "../include/ipChaifen.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>

int main() {
    std::vector<std::tuple<int, int, int, int>> test_ips = {
        std::make_tuple(192, 168, 1, 1),
        std::make_tuple(10, 0, 0, 1),
        std::make_tuple(172, 16, 0, 1),
        std::make_tuple(192, 168, 1, 2),
        std::make_tuple(1, 1, 1, 1),
        std::make_tuple(46, 70, 0, 1),
        std::make_tuple(70, 46, 0, 1),
    };

    auto ips = test_ips;

    std::cout << "Все IP-адреса:\n";
    print_ips(ips);

    std::stringstream ss;
    for (const auto& ip : ips) {
    ss << std::get<0>(ip) << "."
        << std::get<1>(ip) << "."
        << std::get<2>(ip) << "."
        << std::get<3>(ip) << "\n";
    }
    auto sorted_ips = duqu_and_jaingxu_ip(ss);
    std::cout << "\nВсе IP-адреса после сортировки (по убыванию):\n";
    print_ips(sorted_ips);

    std::cout << "\nIP-адреса, где первый байт равен 1:\n";
    print_ips(diyidyValue(ips, 1));

    std::cout << "\nIP-адреса, где первый байт равен 46 и второй равен 70:\n";
    print_ips(qianliadyValue(ips, 46, 70));

    std::cout << "\nIP-адреса, где любой байт равен 46:\n";
    print_ips(renyidyValue(ips, 46));

    return 0;
}


