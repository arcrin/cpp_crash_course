//
// Created by andy- on 2021-11-06.
//

/*
 * The call stack is a runtime structure that stores information about active functions. When a piece of code
 * (the caller) invokes a function (the callee), the machine keeps track of who called whom by pushing information
 * onto the call stack. This allows programs to have many function calls nested within each other. The callee could
 * then, in turn, become the caller by invoking another function.
 */

/*
 * A stack is a flexible data container that can hold a dynamic number of elements. There are two essential
 * operations that all stacks support: pushing elements onto the top of the stack and popping those elements
 * off. It is a last-in, first-out data structure.
 *
 * Each time a function is invoked, information about the function invocation is arranged into a stack frame
 * and pushed onto the call stack. Because a new stack frame is pushed onto the stack for every function call,
 * a callee is free to call other functions, forming arbitrarily deep call chains. Whenever a function returns,
 * its stack frame is popped off the top of the call stack, and execution control resumes as indicated by the
 * previous stack frame.
 */

/*
 * The runtime seeks the closet exception handler to a thrown exception. If there is a matching exception handler
 * in the current stack frame, it will handle the exception. If no matching handler is found, the runtime will
 * unwind the call stack until it finds a suitable handler. Any objects whose lifetimes end are destroyed in the
 * usual way.
 */

int main() {

}