#include <iostream>
#include <cstdlib> // rand 함수를 사용하기 위한 헤더
#include <ctime>   // 시드(seed)를 설정하기 위한 헤더

int main() {
    // 현재 시간을 이용하여 시드를 설정
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 1부터 100 사이의 랜덤한 정수 20개 생성
    for (int i = 0; i < 8; ++i) {
        int randomNum = std::rand() % 100 + 1; // 1부터 100까지의 난수 생성
        std::cout << randomNum << " ";
    }

    std::cout << std::endl;

    return 0;
}

(element) [93 46 98 9 63 49 44 76 35 26]
---------------분할-----------
(1.mainchain) [93, 98, 63, 76, 35]			(1.pending)	[46, 9, 49, 44, 26]
(2.mainchain) [98, 76]						(2.pending)	[93, 63, 35]
(3.mainchain) [98]							(3.pending)	[76]

---------------병합------------
[76, 98]									(2.pending)	[63, 93, 35]
[35, 63, 76, 93, 98]						(1.pending)	[26, 49, 44, 46, 9]