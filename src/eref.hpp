#ifndef ENUM_REFLECTION
#define ENUM_REFLECTION

#include <string>

/// @brief Hidden implementation details
namespace {
template <typename T, T N>
const char* get_enum_name_static() {
    return __PRETTY_FUNCTION__;
}

template<int Beg, int End, typename F>
void static_for(F const& func) {
    if constexpr (Beg == End) {
        return;
    }
    else {
        func(std::integral_constant<int, Beg>());
        static_for<Beg + 1, End>(func);
    }
}
}

namespace eref {
template<typename T, T Beg, T End>
std::string get_enum_name(T n) {
    std::string s;
    static_for<Beg, End>([&] (auto ic) {
        constexpr auto i = ic.value;
        if (n == static_cast<T>(i)) {
            s = get_enum_name_static<T, static_cast<T>(i)>();
        }
    });
    auto pos1 = s.find("N = ");
    pos1 += 4;
    auto pos2 = s.find_first_of("];", pos1);
    return std::move(s.substr(pos1, pos2 - pos1));
}

template<typename T>
std::string get_enum_name(T n) {
    return get_enum_name<T, static_cast<T>(0), static_cast<T>(256)>(n);
}

template<typename T, T Beg, T End>
T enum_from_name(const std::string_view& s) {
    for (int i = static_cast<int>(Beg); i != static_cast<int>(End); i++) {
        if (s == get_enum_name(static_cast<T>(i))) {
            return static_cast<T>(i);
        }
    }
    throw std::runtime_error("Not found enum type");
}

template<typename T>
T enum_from_name(const std::string_view& s) {
    return enum_from_name<T, static_cast<T>(0), static_cast<T>(256)>(s);
}
}

#endif
