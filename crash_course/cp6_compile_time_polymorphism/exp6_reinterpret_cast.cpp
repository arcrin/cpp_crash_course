//
// Created by wbai on 11/12/2021.
//

/*
 * Sometimes in low-level programming, you must perform type conversion that are not well-defined. In system programming
 * and especially in embedded environments, you often need complete control over how to interpret memory. The
 * reinterpret_cast gives you such control, but ensuring correctness of these conversions is entirely your
 * responsibility.
 *
 * Suppose your embedded device keeps an unsigned long timer at memory address 0x1000. You could see reinterpret_cast
 * to read from the timer.
 */

#include <cstdio>

int main() {
    auto timer = reinterpret_cast<const unsigned long *>(0x1000);
    printf("Timer is %lu.", *timer);
}

/*
 * Of course, the compiler has no idea whether the memory at address 0x1000 contains an unsigned long. It's entirely
 * up to you to ensure correctness. Because you are taking full responsibility for this very dangerous construction,
 * the compiler forces you to employ reinterpret_cast. You couldn't replace the initialization of timer with the
 * following line:
 */

//int main() {
//    const unsigned long *timer{0x1000}; // Compiler will grumble about converting an int to a pointer.
//}