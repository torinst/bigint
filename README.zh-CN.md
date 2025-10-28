<p align="center">
  <img src="logo.png" alt="bigint logo" width="300"/>
</p>
<h3 align="center">C++ 任意精度整数类</h3>

中文简体 | [English](README.md)

一个轻量级、仅头文件的 C++ 库，提供 **任意精度整数运算**，支持与内置整数类型相似的操作与接口。

### 功能特性
- ✅ 任意精度整数（不受机器字长限制）
- ✅ 支持正数与负数
- ✅ 算术运算符：+ - * / % ++ -- += -= *= /= %=
- ✅ 比较运算符：== != < > <= >=
- ✅ 支持流式输入输出（std::cout, std::cin）
- ✅ 支持从 std::string, int64_t 等类型构造
- ✅ 异常安全，内存管理高效
- ✅ 无第三方依赖，仅使用标准 C++

### 快速开始
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

#### 输出结果：
```cpp
a + b = 1111111110111111111011111111100
a * b = 121932631137021795226185032733622923332237463801111263526900
b - a = 864197532086419753208641975320
a = 4294967296
c = 4294967296
a == c
```

### 使用方式
```bash
# 克隆代码到本地
git clone https://github.com/torinst/bigint.git
```

#### 方式一：直接包含头文件
```bash
# 将 bigint 文件复制到您的源文件目录中
cp bigint/bigint /path/to/your/source/directory/
```

然后在您的代码中引入
```cpp
#include "bigint"
```

#### 方式二：安装后引入使用
```bash
# 克隆代码后进入目录运行 install.sh 安装脚本
cd bigint
./install.sh

# bigint 文件将被安装在 /usr/local/include 目录中
```

然后在您的代码中引入
```cpp
#include <bigint>
```

**Note：** 若需卸载，运行 install.sh 脚本并使用 uninstall 参数即可
```bash
./install.sh uninstall
```

#### 其他使用方式
如使用 CMake 集成等，请自行研究

### API 概览
#### 1、运算符概览
| 运算符 | 类型 | 功能说明 |
|:----------|:----------|:----------|
| `+` | 算术运算 | 加法 |
| `-` | 算术运算 | 减法 |
| `*` | 算术运算 | 乘法 |
| `/` | 算术运算 | 整除 |
| `%` | 算术运算 | 取模 |
| `+=`, `-=`, `*=`, `/=`, `%=` | 算术运算 | 复合赋值运算 |
| `<`, `<=`, `>`, `>=`, `==`, `!=` | 比较运算 | 标准比较操作 |
| `++` | 算术运算 | 将操作数加 1（前置/后置） |
| `--` | 算术运算 | 将操作数减 1（前置/后置） |
| `operator bool()` | 类型转换 | 将对象转换为 bool |
| `operator-()` | 一元算术运算 | 对单个操作数取负值 |
| `operator=`[^1] | 赋值运算 | 给对象赋值 |

[^1]: 可以接受 `内置整数类型`、`std::string`、`const char*` 或另一个 `bigint`

#### 2、输入输出与类型转换
```cpp
std::string to_string() const;

friend std::istream& operator>>(std::istream&, bigint&);
friend std::ostream& operator<<(std::ostream&, const bigint&);
```

#### 3、其他API
```cpp
bigint abs() const;  // 返回当前操作数的绝对值
int sign() const;    // 返回当前操作数的符号
```

### 测试
```bash
# 运行提供的单元测试
# 安装 libgtest-dev 及 CMake
apt install libgtest-dev cmake build-essential
cd tests/
# 运行测试构建脚本
./build.sh
./build/bigint_out

# 也可构建后立即运行测试代码
# 使用 --run 或 -r 参数即可
./build.sh -r
```

### 许可证
本项目基于 MIT License 许可协议发布。详情请参阅仓库中的 [LICENSE](LICENSE) 文件。

### 贡献指南
欢迎对本项目提出改进建议或提交代码！

如果你发现问题或希望新增功能，可以通过以下方式参与贡献：
```bash
# 1、Fork 本仓库

# 2、在本地创建新分支
git checkout -b feat/your-feature-name

# 3、修改代码

# 4、提交修改
git commit -m "描述你的修改内容"
# 或对提交签名
git commit -S -m "描述你的修改内容"

# 5、将修改推送到你的仓库
git push origin feat/your-feature-name

# 6、发起 Pull Request（PR）到主分支
```
您的贡献将被认真审阅并合并，感谢支持！
