#include <iostream>


namespace outer {
    namespace my {
        class set {
        public:
            set() {
                std::cout << "class set" << std::endl;
            }
        };
    }
}