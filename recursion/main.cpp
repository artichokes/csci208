#include <iostream>
#include <string>

int puzzle(int base, int limit);
int power(int base, int exponent);
int recursiveMinimum(int array[], int start, int end);
int recursiveMinimum(int array[], int start, int end, int minimum);
bool testPalidrome(std::string input);
std::string reverse(std::string input);
int binarySearch(int array[], int low, int high, int target);

int main() {
  std::cout << "Puzzle:" << std::endl;
  std::cout << puzzle(20, 5) << std::endl;
  std::cout << puzzle(3, 6) << std::endl;
  std::cout << puzzle(8, 8) << std::endl;

  std::cout << "Power:" << std::endl;
  std::cout << power(20, 5) << std::endl;
  std::cout << power(3, 6) << std::endl;
  std::cout << power(8, 8) << std::endl;

  std::cout << "Minimum:" << std::endl;
  int array1[] = {5, 1, 2, 10, 15, 4};
  std::cout << recursiveMinimum(array1, 0, 0) << std::endl;
  std::cout << recursiveMinimum(array1, 0, 2) << std::endl;
  std::cout << recursiveMinimum(array1, 2, 4) << std::endl;
  std::cout << recursiveMinimum(array1, 3, 5) << std::endl;

  std::cout << "Palindrome:" << std::endl;
  std::cout << testPalidrome("testing") << std::endl;
  std::cout << testPalidrome("racecar") << std::endl;
  std::cout << testPalidrome("madamimadam") << std::endl;
  std::cout << testPalidrome("acca") << std::endl;

  std::cout << "Binary search:" << std::endl;
  int array2[] = {1};
  int array3[] = {1, 3, 5};
  std::cout << binarySearch(array2, 0, 0, 1) << std::endl;
  std::cout << binarySearch(array2, 0, 0, 2) << std::endl;
  std::cout << binarySearch(array3, 0, 2, 3) << std::endl;
  std::cout << binarySearch(array3, 0, 2, 1) << std::endl;
  std::cout << binarySearch(array3, 0, 2, 5) << std::endl;
}

int puzzle(int base, int limit) {
  if (base > limit)
    return -1;
  else if (base == limit)
    return 1;
  else
    return base * puzzle(base + 1, limit);
}

int power(int base, int exponent) {
  if (exponent == 1) {
    return base;
  } else {
    return base * power(base, exponent - 1);
  }
}

int recursiveMinimum(int array[], int start, int end) {
  return recursiveMinimum(array, start + 1, end, array[start]);
}

int recursiveMinimum(int array[], int start, int end, int minimum) {
  if (start > end) {
    return minimum;
  } else {
    if (array[start] < minimum)
      return recursiveMinimum(array, start + 1, end, array[start]);
    else
      return recursiveMinimum(array, start + 1, end, minimum);
  }
}

bool testPalidrome(std::string input) {
  unsigned long length = input.length();
  std::string firstHalf;
  std::string secondHalf;

  if (length % 2 == 0) {
    firstHalf = input.substr(0, length / 2);
    secondHalf = input.substr(length / 2, length - 1);
  } else {
    firstHalf = input.substr(0, length / 2);
    secondHalf = input.substr((length / 2) + 1, length - 1);
  }

  return reverse(firstHalf) == secondHalf;
}

std::string reverse(std::string input) {
  if (input.length() == 0)
    return "";

  std::string last(1, input[input.length() - 1]);
  std::string reversed = reverse(input.substr(0, input.length() - 1));
  return last + reversed;
}

int binarySearch(int array[], int low, int high, int target) {
  int mid = (high + low) / 2;

  if (low > high)
    return -1;
  else if (array[mid] == target)
    return mid;
  else if (target < array[mid])
    return binarySearch(array, low, mid - 1, target);
  else
    return binarySearch(array, mid + 1, high, target);
}
