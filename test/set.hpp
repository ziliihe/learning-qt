#include <iostream>
using std::cout;
using std::endl;
namespace my
{
    class v1 {
    public:
        v1() {
            std::cout << "class v1" << endl;
        }
    };

    inline namespace current {
        class A{
        public:
            A() { std::cout << "class A inline" << endl; }
        };
    }
} // namespace my
