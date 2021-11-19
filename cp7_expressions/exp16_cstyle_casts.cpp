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
 * it's not clear
 */