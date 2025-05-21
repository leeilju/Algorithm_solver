//  AC라는 새로운 프로그래밍 언어 제작
//  정수 배열에 연산을 하기 위해 만든 언어
//  R(뒤집기): 배열의 순서를 뒤집어 버리는거
//  D(버리기) : 첫 번째 수를 버리는 함수가 있음

//  문제풀이의 핵심 : R함수를 사용할때 배열을 뒤집는게 아닌 bool 플래그 등을
//  사용해서 뒤집어진 상태냐 아니냐를 체크하는 것

#include <deque>  //double-ended-queue 앞과 뒤에서 모두 삽입 및 삭제가 가능한 queue
#include <iostream>
#include <string>

void executeCommand(const std::string &command, std::deque<int> &parsed_array) {
  bool reverse = false;

  for (char cmd : command) {
    if (cmd == 'R') {
      reverse = !reverse;
    } else if (cmd == 'D') {
      if (parsed_array.empty()) {
        std::cout << "error\n";
        return;
      }
      if (!reverse) {
        parsed_array.pop_front();
      } else {
        parsed_array.pop_back();
      }
    }
  }

  std::cout << "[";

  if (!parsed_array.empty()) {
    if (!reverse) {
      for (auto it = parsed_array.begin(); it != parsed_array.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != parsed_array.end()) {
          std::cout << ",";
        }
      }
    } else {
      for (auto it = parsed_array.rbegin(); it != parsed_array.rend(); ++it) {
        std::cout << *it;
        if (std::next(it) != parsed_array.rend()) {
          std::cout << ",";
        }
      }
    }
  }

  std::cout << "]\n";
}

std::deque<int> parseIntArray(const std::string &array) {
  std::deque<int> result;
  std::string number;
  for (char ch : array) {
    if (isdigit(ch)) {
      number += ch;
    } else {
      if (!number.empty()) {
        result.push_back(std::stoi(number));
        number.clear();
      }
    }
  }
  return result;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int test_cases;
  std::cin >> test_cases;

  for (int i = 0; i < test_cases; ++i) {
    std::string command;
    std::cin >> command;

    int n;
    std::cin >> n;

    std::string array;
    std::cin >> array;

    std::deque<int> parsed_array = parseIntArray(array);
    executeCommand(command, parsed_array);
  }

  return 0;
}
