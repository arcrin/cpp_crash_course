//
// Created by andy- on 2021-11-11.
//

/*
 * To declare an interface, declare a pure virtual class. To implement an interface, derive from it. Because the
 * interface is pure virtual, an implementation must implement all the interface's methods.
 *
 * It's good a practice to mark these methods with the override keyword. This communicates that you intend to override
 * a virtual function, allowing the compiler to save you form simple mistakes
 */

/*
 * Using interfaces
 *
 * As a consumer, you can only deal in references or pointers to interfaces. The compiler cannot know ahead of time
 * how much memory to allocate for the underlying type: if the compiler could know the underlying type, you would be
 * better off using templates.
 *
 * There are two options for how to set the member:
 */

/*
 * Constructor injection
 * With constructor injection, you use a method to set a pointer member. This allows you to change the object to which
 * the member points.
 */

/*
 * Property injection
 * With property injection, you use a method to set a pointer member. This allows you to change the object to which the
 * member points.
 */

/*
 * You can combine these approaches by accepting an interface pointer in a constructor while also providing a method
 * to set the point to something else.
 *
 * Typically, you will use constructor injection when the injected field won't change throughout the lifetime of the
 * object. If you need the flexibility of modifying the filed, you will provide methods to perform property injection.
 */