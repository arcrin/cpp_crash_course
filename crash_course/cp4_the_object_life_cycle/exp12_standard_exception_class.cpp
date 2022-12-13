//
// Created by wbai on 11/4/2021.
//

/*
 * Logic Errors:
 * Logic errors derive from the logic_error class. Generally, you could avoid these exceptions through more careful
 * programming. A primary example is when a logical precondition of a class isn't satisfied, such as when a class
 * invariant cannot be established.
 *
 * Since a class invariant is something that the programmer defines, neither the compiler nor the runtime environment
 * can enforce it without help. You can use a class constructor to check for various conditions, and if you cannot
 * establish a class invariant, you can throw an exception. If the failure is the result of, say, passing an incorrect
 * parameter to the constructor, a logic_error is an appropriate exception to throw.
 *
 * The logic_error has several subclasses:
 *
 * - domain_error reports errors related to valid input range, especially for math functions. The square root,
 * for example, only supports non-negative numbers (in the real case). If a negative argument is passed,
 * a square root function could throw a domain_error
 *
 * - invalid_argument exception reports generally unexpected arguments
 *
 * -length_error exception reports that some action would violate a maximum size constraint.
 *
 * - out_of_range exception reports that some value isn't in an expected range. The canonical example is
 * bounds-check indexing into a data structure
 */

/*
 * Runtime Errors:
 * Runtime errors derive from the runtime_error class. These exceptions help you report error that are outside the
 * program's scope.
 *
 * runtime_error has the following subclasses:
 * - The system_error reports that the operating system encountered some error. You can get a lot of mileage out of
 * this kind of exception. Inside the <system_error> header, there's a large number of error codes and error conditions.
 * When a system_error is constructed, information about the error is packed in, so you can determine the nature of the
 * error. The .code() method returns an enum class of type std::errc that has a large number of values, such as
 * - bad_file_descriptor, timed_out, and permission_denied
 * overflow_error and underflow_error report arithmetic overflow and underflow, respectively.
 *
 * Other errors inherit directly from exception. A common one is the bad_alloc exception, which reports that new failed
 * to allocate the required memory for dynamic storage.
 */

/*
 * Language Support Errors:
 * You won't use language support errors directly. They exist to indicate that some core language feature at runtime.
 */