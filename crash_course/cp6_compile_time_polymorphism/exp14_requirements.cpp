//
// Created by wbai on 11/13/2021.
//

/*
 * Requirements are ad hoc constraints on template parameters. Each concept can specify any number of requirements on
 * its template parameters. Requirements are encoded into requires expressions denoted by the "requires" keyword
 * followed by function arguments and a body.
 *
 * A sequence of syntactic requirements comprises the requirement expression's body. Each syntactic requirement puts
 * a constraint on the template parameters. Together, requires expressions have the following form:
 *
 * requires (arg-1, arg-2, ...) {
 *      {expression1} -> return-type1;
 *      {expression2} -> return-type2;
 *      --snip--
 * }
 *
 * T, U are types
 * requires (T t, U u) {
 *      { t == u } -> bool; // syntactic requirement 1
 *      { u == t } -> bool; // syntactic requirement 2
 *      { t != u } -> bool; // syntactic requirement 3
 *      { u != t } -> bool; // syntactic requirement 4
 * }
 */
