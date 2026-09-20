#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdint>

int main(int argc, char* argv[]) {
  uint32_t N;
  if (argc == 1) {
    N = 1000000;
  } else {
    N = atoi(argv[1]);
  }

  uint32_t count {0};

  auto start = std::chrono::high_resolution_clock::now();
  for (uint32_t i {0}; i < N; i++) {
    count++;
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> elapsedDuration = (end - start);

  std::cout << "=== LOOP BENCHMARK ===\n";
  std::cout << "N = " << N << std::endl;
  std::cout << "Increment: " << count << std::endl;
  std::cout << "Loop Start: " << start << std::endl;
  std::cout << "Loop Ends: " << end << std::endl;

  std::cout << std::fixed << std::setprecision(6);
  std::cout << "Elapse duration: " << elapsedDuration << std::endl;

  return 0;
}
