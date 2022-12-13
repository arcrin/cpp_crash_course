//
// Created by andy- on 2021-11-06.
//

/*
 * In your programs, you must handle errors; errors are unavoidable. When you use exceptions correctly and no errors
 * occur, your code is faster than manually error-checked code. If an error does occur, exception handling can sometimes
 * be slower, but you make huge gains in robustness and maintainability over the alternative.
 *
 * "use of exception handling leads to programs that are faster when they execute normally, and better behaved when they
 * fail."
 *
 * When a C++ program executes normally (without exceptions being thrown), there is no runtime overhead associated with
 * checking exceptions. It's only when an exception is thrown that you pay overhead.
 *
 *
 * Sometimes, unfortunately, you won't be able to use exceptions. One example is embedded development where real-time
 * guarantees are required. Tools simply don't (yet) exist in this setting. Another example is with some legacy code.
 * Exceptions are elegant because of how they fit in with RAII objects. When destructors are responsible for cleaning up
 * resources, stack unwinding is direct and effective way to guarantee against resource leakages. In legacy code,
 * you might find manual resource management and error handling instead of RAII objects. This makes using exceptions
 * very dangerous, because stack unwinding is safe only with RAII objects. Without them, you could easily leak
 * resources.
 */