#include <iostream>
#include <cstdlib>
#include <ctime>

const int ARRAY_SIZE = 31;

bool isDuplicate(const int arr[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return true;  // 중복된 값이 존재하면 true 반환
        }
    }
    return false;  // 중복된 값이 없으면 false 반환
}

int main() {
    int uniqueRandomNumbers[ARRAY_SIZE];
    int currentIndex = 0;

    // 랜덤 시드를 현재 시간으로 설정
    std::srand(static_cast<unsigned>(std::time(0)));

    while (currentIndex < ARRAY_SIZE) {
        // 중복되지 않게 랜덤한 정수 생성
        int randomNumber = std::rand() % 100 + 1;  // 1부터 100 사이의 숫자로 가정

        // 중복 체크 후 배열에 추가
        if (!isDuplicate(uniqueRandomNumbers, currentIndex, randomNumber)) {
            uniqueRandomNumbers[currentIndex] = randomNumber;
            ++currentIndex;
        }
    }

    // 결과 출력
    std::cout << "Unique random numbers: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << uniqueRandomNumbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}