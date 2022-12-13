//
// Created by wbai on 11/13/2021.
//

/*
 * A concept is a template. It's a constant expression involving template arguments, evaluated at compile time. Think
 * of a concept as one bit predicate: a function that evaluates to true or false.
 *
 * If a set of template parameters meets the criteria for a given concept, that concept evaluates to true when
 * instantiated with those parameters; otherwise, it will evaluate to false. When a concept evaluates to false,
 * template instantiation fails.
 *
 * You declare concepts using the keyword concept on an otherwise familiar template function definition
 */

//template<typename T1, typename T2, ...>
//concept bool ConceptName() {
//    // --snip--
//};