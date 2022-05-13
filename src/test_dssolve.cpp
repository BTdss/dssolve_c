#include <gtest/gtest.h>
#include "dssolve.h"

// Demonstrate some basic assertions.
TEST(Basic, BasicAssertions)
{
  cmplx values[] = {{1, 1}, {1, 1}};
  unsigned int rows[] = {0, 1};
  unsigned int cols[] = {0, 1};
  unsigned int n_value = 2;
  cmplx b[] = {{1, 0}, {0, 1}};
  unsigned int size = 2;

  cmplx expected[] = {{0.5, -0.5}, {0.5, 0.5}};

  solve(values, rows, cols, n_value, b, size);

  for (unsigned int i = 0; i < size; i++)
  {
    EXPECT_NEAR(expected[i].real, b[i].real, 1e-6);
    EXPECT_NEAR(expected[i].imag, b[i].imag, 1e-6);
  }

  for (unsigned int i = 0; i < size; i++)
  {
    std::cerr << "x[" << i << "] = "
              << b[i].real << " + j(" << b[i].imag << ")" << std::endl;
  }
}