/*  차량이 터널을 통과하는동안 추월이 있었는지 확인하는 문제.
    입구에서 차량이 들어온 순서와 출구에서 차량들이 나간 순서를 비교해서
    입구에서 더 늦게 들어온 차량이 출구에서 먼저 나갔다면 추월한 것으로 간주*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void getInOrder(std::unordered_map<std::string, int> &in_order, const int n) {
  for (int i = 0; i < n; ++i) {
    std::string car;
    std::cin >> car;
    in_order[car] = i;
  }
}

void getOutOrder(std::vector<std::string> &out_order, const int n) {
  for (int i = 0; i < n; ++i) {
    std::cin >> out_order[i];
  }
}

int checkOverTaking(const std::unordered_map<std::string, int> &in_order,
                    const std::vector<std::string> &out_order, const int n) {
  int count = 0, cur_idx = 0, out_index = 0;
  std::vector<bool> visited(n, false);

  for (int i = 0; i < n; ++i) {
    out_index = in_order.at(out_order[i]);  // i번째로 나간차가 입구에 몇번째로
                                            // 들어왔는지 확인

    for (; cur_idx < n; ++cur_idx) {
      if (!visited[cur_idx]) {
        if (cur_idx != out_index) {
          ++count;
        }
        visited[out_index] = true;
        break;
      }
    }
  }
  return count;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::unordered_map<std::string, int> in_order;
  getInOrder(in_order, n);
  std::vector<std::string> out_order(n);
  getOutOrder(out_order, n);
  std::cout << checkOverTaking(in_order, out_order, n) << std::endl;
  return 0;
}
