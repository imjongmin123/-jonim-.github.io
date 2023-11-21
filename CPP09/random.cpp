#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> generateRandomNumbers(int min, int max, int count) {
    std::vector<int> numbers;
    
    // 초기화
    for (int i = min; i <= max; ++i) {
        numbers.push_back(i);
    }

    // 섞기
    std::random_shuffle(numbers.begin(), numbers.end());

    // 필요한 개수만큼 추출
    std::vector<int> result;
    for (int i = 0; i < count; ++i) {
        result.push_back(numbers[i]);
    }

    return result;
}

int main() {
    // 1부터 100까지 중복되지 않는 정수 10개 뽑기
    std::vector<int> randomNumbers = generateRandomNumbers(1, 100, 10);

    // 결과 출력
    std::cout << "Random Numbers: ";
    for (int i = 0; i < randomNumbers.size(); ++i) {
        std::cout << randomNumbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

