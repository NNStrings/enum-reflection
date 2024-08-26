# enum-reflection

本仓库基于 C++17 实现了一个编译期枚举类型反射功能，目前支持 gcc, clang, msvc 编译器

## 接口

**将枚举类型转换成字符串类型：**

```cpp
template<typename T, T Beg, T End>
std::string get_enum_name(T n)
template<typename T>
std::string get_enum_name(T n)
```

**将字符串类型转换成枚举类型：**

```cpp
template<typename T, T Beg, T End>
T enum_from_name(const std::string_view& s);
template<typename T>
T enum_from_name(const std::string_view& s);
```

