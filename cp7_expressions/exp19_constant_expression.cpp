//
// Created by andy- on 2021-11-20.
//

/*
 * Constant expressions are expressions that can be evaluated at compiler time. For performance and safety reasons,
 * whenever a computation can be done at compile time rather than runtime, you should do it. Simple mathematical
 * operations involving literals are an obvious example of expressions that can be evaluated at compile time.
 *
 * You can extend the reach of the compiler by using the expression constexpr. Whenever all the information required to
 * compute an expression is present at compile time, the compiler is compelled to do so if that expression is marked
 * constexpr. This simple commitment can enable a surprisingly large impact on code readability and runtime performance.
 *
 * Both const and constexpr are closely related. Whereas constexpr enforces that an expression is compile-time
 * evaluable, const enforces that a variable cannot change within some scope (ar runtime). All constexpr expressions are
 * const because they're always fixed at runtime.
 *
 * All constexpr expressions begin with one or more fundamental types (int, float, wchar_t, and so on). You can build
 * on top of these types by using operators and constexpr functions. Constant expressions are used mainly to replace
 * manually computed values in your code. This generally produces code that is more robust and easier to understand,
 * because you can eliminate so-called magic values -- manually calculated constants copy and pasted directly source
 * code.
 */
#include <cstdint>
#include <cstdio>
struct Color {
    float H, S, V;
};

constexpr uint8_t max(uint8_t a, uint8_t b) {
    return a > b ? a : b;
}

constexpr uint8_t max(uint8_t a, uint8_t b, uint8_t c) {
    return max(max(a, b), max(a, c));
}

constexpr uint8_t min(uint8_t a, uint8_t b) {
    return a < b ? a : b;
}

constexpr uint8_t min(uint8_t a, uint8_t b, uint8_t c){
    return min(min(a, b), min(a, c));
}

constexpr float modulo(float dividend, float divisor) {
    const auto quotient = dividend / divisor;
    return divisor * (quotient - static_cast<uint8_t>(quotient));
}

/*
 * Each function is marked constexpr, which tells the compiler that the function must be evaluable at compile time.
 */

constexpr Color rgb_to_hsv(uint8_t r, uint8_t g, uint8_t b) {
    Color c{};
    const auto c_max = max(r, g, b);
    c.V = c_max / 255.0f;

    const auto c_min = min(r, g, b);
    const auto delta = c.V - c_min / 255.0f;
    c.S = c_max == 0 ? 0 : delta / c.V;

    if (c_max == c_min) {
        c.H = 0;
        return c;
    }
    if (c_max == r) {
        c.H = (g / 255.0f - b / 255.0f) / delta;
    } else if (c_max == g) {
        c.H = (b / 255.0f - r / 255.0f) / delta + 2.0f;
    } else if (c_max == b) {
        c.H = (r / 255.0f - g / 255.0f) / delta + 4.0f;
    }
    c.H * 60.0f;
    c.H >= 0.0f ? c.H : c.H + 360.0f;
    c.H = modulo(c.H, 360.0f);
    return c;
}

int main() {
    auto black = rgb_to_hsv(0, 0, 0);
    auto white = rgb_to_hsv(255, 255, 255);
    auto red = rgb_to_hsv(255, 0, 0);
    auto green = rgb_to_hsv(0, 255, 0);
    auto blue = rgb_to_hsv(0, 0, 255);
    printf("black: (%f, %f, %f)\n", black.H, black.S, black.V);
    printf("white: (%f, %f, %f)\n", white.H, white.S, white.V);
    printf("red: (%f, %f, %f)\n", red.H, red.S, red.V);
    printf("green: (%f, %f, %f)\n", green.H, green.S, green.V);
    printf("blue: (%f, %f, %f)\n", blue.H, blue.S, blue.V);
}

/*
 * There are some restrictions on what sorts of functions can be "constexpr", but these restrictions have been relaxed
 * with each new C++ version.
 *
 * In certain context, like embedded development, constexpr is indispensable. In general, if an expression can be
 * declared constexpr, you should strongly consider doing so. Using constexpr rather than manually calculated literals
 * can make your code more expressive. Often, it can also seriously boost performance and safety at runtime.
 */