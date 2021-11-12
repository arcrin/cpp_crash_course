//
// Created by andy- on 2021-11-11.
//

/*
 * You declare templates with a template prefix, which consists of the keyword template followed by angle brackets <>.
 * Within the angle brackets, you place the declarations of one or more parameters. You can declare template parameters
 * using either the typename or class keywords followed by identifiers.
 */

template <typename X, typename Y, typename Z>
struct MyTemplateClass {
    X foo(Y &);
private:
    Z *member;
};

/*
 * You can also specify template functions
 */
template<typename X, typename Y, typename Z>
X my_template_function(Y &arg1, const Z *arg2) {
    // --snip--
}

/*
 * Instantiating Templates
 *
 * template class:
 * tc_name<t_param1, t_param2, ...> my_concrete_class{...};
 *
 * template function:
 * auto result = tf_name<t_param1, t_param2, ...>(f_param1, f_param2, ...);
 */