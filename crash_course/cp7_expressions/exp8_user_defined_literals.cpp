//
// Created by wbai on 11/17/2021.
//

/*
 * Chapter 2 covered how to declare literals, constant values that you use directly in your programs. These help
 * compiler to turn embedded values into the desired types. Each fundamental type has its own syntax for literals.
 * For example, a char literal is declared in single quotes like 'J', whereas a wchar_t is declared with an L prefix
 * like L'J'. You can specify the precision of floating-point numbers using either the F or L suffix.
 *
 * FOr convenience, you can also make your own user-defined literals. As with the baked-in literals, these provide you
 * with some syntactical support for giving type information to the compiler. Although you'd rarely ever need to declare
 * a user defined literal, it's worth mentioning because you might find them in libraries. The stdlib <chrono> header
 * uses literals extensively to give programmers a clean syntax for using time types - for example, 700ms demotes
 * 700 milliseconds. Because user-defined literals are fairly rare, I won't cover them in any more detail here.
 */
