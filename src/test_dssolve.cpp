#include <gtest/gtest.h>
#include "dssolve.h"

// Demonstrate some basic assertions.
TEST(Basic, BasicAssertions)
{
  // Create the A matrix:
  // | (1 + j1)     0     |
  // |    0      (1 + j1) |
  cmplx values[] = {{1, 1}, {1, 1}};
  unsigned int rows[] = {0, 1};
  unsigned int cols[] = {0, 1};
  unsigned int n_value = 2; // number of non-zero values

  // Create the b vector:
  // | (1 + j0) |
  // | (1 + j0) |
  cmplx b[] = {{1, 0}, {0, 1}};
  unsigned int size = 2; // Size of the system

  // Expected solution (x):
  // | (0.5 - j0.5) |
  // | (0.5 + j0.5) |
  cmplx expected[] = {{0.5, -0.5}, {0.5, 0.5}};

  // Solve the system Ax = b and salve the result in b.
  solve(values, rows, cols, n_value, b, size);

  // Check that the solution is correct.
  for (unsigned int i = 0; i < size; i++)
  {
    EXPECT_NEAR(expected[i].real, b[i].real, 1e-6);
    EXPECT_NEAR(expected[i].imag, b[i].imag, 1e-6);
  }

  // Print the solution.
  for (unsigned int i = 0; i < size; i++)
  {
    std::cout << "x[" << i << "] = "
              << b[i].real << " + j(" << b[i].imag << ")" << std::endl;
  }
}