<p align="center">
  <img src="logo.png" alt="bigint logo" width="300"/>
</p>
<h3 align="center">Arbitrary Precision Integer for C++</h3>

English | [中文简体](README.zh-CN.md)

A lightweight, header-only C++ library that provides **arbitrary precision integer arithmetic**, supporting operations and interfaces similar to built-in integer types.

### Features
- ✅ Arbitrary precision integers (no bit-width limit)
- ✅ Supports both positive and negative numbers
- ✅ Arithmetic operators: `+ - * / % ++ -- += -= *= /= %=`
- ✅ Comparison operators: `== != < > <= >=`
- ✅ Stream I/O support (`std::cout`, `std::cin`)
- ✅ Supports construction from types such as `std::string`, `int64_t`, etc.
- ✅ Exception-safe, efficient memory management
- ✅ No third-party dependencies — standard C++ only

### Quick Start
```cpp
#include "bigint"
#include <iostream>

int main()
{
    bigint a = "123456789012345678901234567890";
    bigint b("987654321098765432109876543210");

    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "b - a = " << (b - a) << std::endl;

    a = 0x100000000;  // 2 ^ 32
    std::cout << "a = " << a << std::endl;
    bigint c("100000000", 16);  // hexadecimal, value is 2 ^ 32
    std::cout << "c = " << c << std::endl;

    if (a == c)
        std::cout << "a == c\n";
    else
        std::cout << "a != c\n";

    return 0;
}
```

#### Output:
```cpp
a + b = 1111111110111111111011111111100
a * b = 121932631137021795226185032733622923332237463801111263526900
b - a = 864197532086419753208641975320
a = 4294967296
c = 4294967296
a == c
```

### Usage
```bash
# Clone the code to your local machine
git clone https://github.com/torinst/bigint.git
```

#### Option 1: Direct include
```bash
# Copy the bigint file to your source directory
cp bigint/bigint /path/to/your/source/directory/
```

Then include it in your code
```cpp
#include "bigint"
```

#### Option 2：After installation, include and use it
```bash
# After cloning the code, navigate to the directory and run the install.sh script
cd bigint
./install.sh

# The bigint file will be installed in the /usr/local/include directory
```

Then include it in your code
```cpp
#include <bigint>
```

**Note：** To uninstall, run the install.sh script with the uninstall argument
```bash
./install.sh uninstall
```

#### Other Usage
Such as integration with CMake, please explore on your own.

### API Overview
#### 1. Operator Overview
| Operator | Type | Description |
|:----------|:----------|:----------|
| `+` | Arithmetic Operator | Addition |
| `-` | Arithmetic Operator | Subtraction |
| `*` | Arithmetic Operator | Multiplication |
| `/` | Arithmetic Operator | Integer division |
| `%` | Arithmetic Operator | Modulo |
| `+=`, `-=`, `*=`, `/=`, `%=` | Arithmetic Operator | Compound assignments |
| `<`, `<=`, `>`, `>=`, `==`, `!=` | Comparison Operator | All standard comparisons |
| `++` | Arithmetic Operator | Increment the operand by 1 (prefix/postfix) |
| `--` | Arithmetic Operator | Decrement the operand by 1 (prefix/postfix) |
| `operator bool()` | Type Conversion Operator | Convert the object to bool |
| `operator-()` | Unary Arithmetic Operator | Negate a single operand |
| `operator=`[^1] | Assignment Operator | Assign a value to the object |

[^1]: Can take `built-in integer types`, `std::string`, `const char*`, or another `bigint`

#### 2. I/O and Conversion
```cpp
std::string to_string() const;

friend std::istream& operator>>(std::istream&, bigint&);
friend std::ostream& operator<<(std::ostream&, const bigint&);
```

#### 3. Other API
```cpp
bigint abs() const;  // Return the absolute value of the current operand
int sign() const;    // Return the sign of the current operand
```

### Testing
```bash
# Run provided unit tests
# install libgtest-dev and CMake
apt install libgtest-dev cmake build-essential
cd tests/
# Run the test build script
./build.sh
./build/bigint_out

# Can also run the test code immediately after building
# Simply use the --run or -r option
./build.sh -r
```

### License
This project is licensed under the MIT License — see [LICENSE](LICENSE) for details.

### Contributing Guide
We welcome suggestions and code contributions to improve this project!

If you find any issues or would like to add new features, you can contribute by following these steps:
```bash
# 1. Fork this repository

# 2. Create a new branch locally
git checkout -b feat/your-feature-name

# 3. Modify the code

# 4. Commit your changes
git commit -m "Describe your changes"
# or sign your commit
git commit -S -m "Describe your changes"

# 5. Push your changes to your repository
git push origin feat/your-feature-name

# 6. Create a Pull Request (PR) to the main branch
```
Your contribution will be carefully reviewed and merged — thank you for your support!
