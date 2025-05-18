#include <iostream>
#include <vector>

const int kMaxStudents = 50000 + 1;
int parent[kMaxStudents];

inline int findParent(int student) {
  if (parent[student] != student) {
    parent[student] = findParent(parent[student]);
  }
  return parent[student];
}

void unionSet(int a, int b) {
  int root_a = findParent(a);
  int root_b = findParent(b);
  if (root_a != root_b) {
    parent[root_b] = root_a;
  }
}

int countDistinctReligions(int num_students) {
  std::vector<bool> visited(num_students + 1, false);
  int count = 0;
  for (int i = 1; i <= num_students; ++i) {
    int root = findParent(i);
    if (!visited[root]) {
      visited[root] = true;
      ++count;
    }
  }
  return count;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, m;
  int case_number = 1;

  while (true) {
    std::cin >> n >> m;
    if (n == 0 && m == 0) {
      break;
    }

    for (int i = 1; i <= n; ++i) {
      parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
      int a, b;
      std::cin >> a >> b;
      unionSet(a, b);
    }

    int religion_count = countDistinctReligions(n);
    std::cout << "Case " << case_number++ << ": " << religion_count << '\n';
  }

  return 0;
}
