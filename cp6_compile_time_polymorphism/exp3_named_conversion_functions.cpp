//
// Created by wbai on 11/12/2021.
//

/*
 * Named conversions are language features that explicitly convert one type into another type. You use named conversions
 * sparingly where you cannot use implicit conversion or constructors to get the types you need.
 *
 * All named conversions accept a single object parameter, which is the object you want to cast, object-to-cast; and
 * a single type parameter, which is the type you want to cast to, desired-type
 *
 * named-conversion<desired-type>(object-to-cast)
 */

/*
 * For example, if you need to modify a const object, you would first need to cast away the const qualifier. The named
 * conversion function const_cast allows you to perform this operation. Other named conversions help you to reverse
 * implicit casts (static_cast) or reinterpret memory with a different type (reinterpret_cast)
 */