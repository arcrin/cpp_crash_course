//
// Created by wbai on 11/18/2021.
//

/*
 * Recall from chapter 6 that the named conversion functions allow you to perform dangerous casts that braced
 * initialization won't permit. You can also perform C-style casts, but this is done mainly to maintain some
 * compatibility between the languages.
 *
 * (desired-type)object-to-cast
 *
 * For each C-style cast, there exists some incantation of static_casts, const_casts, and reinterpret_casts that would
 * achieve the desired type conversion. C-style casts are far more dangerous than the named casts (and this is saying
 * quite a bit).
 *
 * The syntax of the C++ explicit casts is intentionally ugly and verbose. This calls attention to a point in the code
 * where the rigid rules of the type system are being bent or broken. The C-style cast doesn't do this. In addition,
 * it's not clear from the cast what kind of conversion the programmer is intending. When you ue instruments like the
 * named casts, the compiler can at least enforce some constraints. For example, it's all too easy to forget const
 * correctness when using a C-style cast when you only intended a reinterpret_cast.
 *
 * Suppose you wanted to treat a const char* array as unsigned within the body of a function. It would be too easy to
 * write following code.
 */

#include <cstdio>

void trainwreck(const char *read_only) {
    auto as_unsigned = reinterpret_cast<unsigned char*> (read_only);
    *as_unsigned = 'b'; // Crashes on Windows 10 x64
}

int main() {
    auto ezra = "Ezra";
    printf("Before trainwreck: %s\n", ezra);
    trainwreck(ezra);
    printf("After trainwreck: %s\n", ezra);
}
