#include <iostream>

//매크로 함수 작성
#define SQUARE_M(x) (x*x)

//인라인 함수 작성
inline int square_i(int x) {
    return x * x;
}

int main() {

    std::cout << "2의 제곱: " << SQUARE_M(2) << std::endl;
    std::cout << "1.1의 제곱: " << SQUARE_M(1.1) << std::endl;

    std::cout << "2의 제곱: " << square_i(2) << std::endl;
    std::cout << "1.1의 제곱: " << square_i(1.1) << std::endl;

    return 0;
}
