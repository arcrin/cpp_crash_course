//
// Created by wbai on 11/13/2021.
//

/*
 * Concepts constrain template parameters, allowing for parameter checking at the point of instantiation rather than the
 * point of first use. By catching usage issues at the point of instantiation, the compiler can give you a friendly,
 * informative error code - for example, "You tried to instantiate this template with a char*, but this template
 * requires a type that supports multiplication."
 *
 * Concepts allow you to express requirements on template parameters directly in the language.
 *
 * Concepts are not yet officially part of the C++ standard.
 */