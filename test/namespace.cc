#include <iostream>
#include <vector>
#include "set.hpp"
#include "vec.hpp"

namespace my {
    class vector {
    public:
        vector() {
            std::cout << "my vector" << std::endl;
        }
        vector(int n) {
            std::cout << "my vector size = " << n << std::endl;
        }
    };
}

namespace atest = outer::my;

int main() {
    std::vector<int> v1{1, 2, 3, 4, 5, 6};
    std::cout << "v1.size = " << v1.size() << std::endl;

    my::vector v2(2);
    my::v1 v3;
    outer::my::set v4;
    atest::set v5;

    std::cout << "inline namespace: " << std::endl;
    my::A a1;
    my::current::A a2;
    return 0;
}
