#include <iostream>
#include <string>

constexpr int kMaxStackSize = 10000;
int stack[kMaxStackSize];
int top = -1;

void StackPush(int value) { stack[++top] = value; }

int StackPop() {
  if (top == -1) return -1;
  return stack[top--];
}

int StackSize() { return top + 1; }

int StackEmpty() { return top == -1 ? 1 : 0; }

int StackTop() {
  if (top == -1) return -1;
  return stack[top];
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  while (n--) {
    std::string input;
    std::cin >> input;

    if (input == "push") {
      int value;
      std::cin >> value;
      StackPush(value);
    } else if (input == "pop") {
      std::cout << StackPop() << '\n';
    } else if (input == "size") {
      std::cout << StackSize() << '\n';
    } else if (input == "empty") {
      std::cout << StackEmpty() << '\n';
    } else if (input == "top") {
      std::cout << StackTop() << '\n';
    }
  }

  return 0;
}
