# dssolve_c

*A simple linear complex sparse solver based on [Eigen's SparseLU](https://eigen.tuxfamily.org/dox/classEigen_1_1SparseLU.html).*

This library aims to provide a permissive-licensed and _Rust-friendly_ solver for linear `Ax=b` systems, where `A` is sparse with complex coefficients, and `x` and `b` are dense vectors with complex coefficients.

## Usage

```C++
// main.cpp
#include "dssolve.h"

int main ()
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
  
  // Solve the system Ax = b and salve the result in b.
  solve(values, rows, cols, n_value, b, size);

  // Print the solution.
  for (unsigned int i = 0; i < size; i++)
  {
    std::cout << "x[" << i << "] = "
              << b[i].real << " + j(" << b[i].imag << ")" << std::endl;
  }

    return 0;
}
```

## How to Build

_You can also see [`build.py`](.github\workflows\build.py) as an example of the build process._

### 0. Clone the repository
```shell
git clone --recursive https://github.com/BTdss/dssolve_c.git
```
### 1. Create the build configuration

#### For the release type
```shell
cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
```

#### For the debug type
```shell
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build
```

### 2. Build the library

A folder named `dssolve_c` will be created in this process, there you can find the library.

#### For Linux and macOS
```shell
cmake --build build
```
#### For Windows
```shell
cmake --build build --config Release
```

## Tests

Tests are created during the build process and can be found on the folder `dssolve_c` created.

Execute the binary test to run the tests:
```shell
exec dssolve_c/lib/test_dssolve 
```

The tests use [GoogleTest](https://github.com/google/googletest) a C++ test framework. 

## License
`dssolve_c` is licensed under both of:

- Apache License, Version 2.0 ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
- MIT license ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)


_**`dssolve_c` also depends on Eigen v3.4.0 which is licensed under [MPL v2.0](https://www.mozilla.org/en-US/MPL/2.0/). The source code of Eigen can be found on [Eigen's Home Page](https://eigen.tuxfamily.org/).**_
