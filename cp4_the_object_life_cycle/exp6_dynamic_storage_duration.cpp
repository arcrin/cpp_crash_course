//
// Created by wbai on 11/3/2021.
//

/*
 * Objects with dynamic storage duration are allocated and deallocated on request.
 * You have manual control over when a dynamic object's life begins and when it ends.
 * Dynamic objects are also called allocated objects for this reason.
 *
 * The primary way to allocate a dynamic object is with a new expression. A new expression begins
 * with the new keyword followed by the desired type of the dynamic object. New expression create
 * objects of a given type and then return a pointer to the newly minted object.
 */
int main (){
    int *my_int_ptr = new int;

    int *my_other_int_ptr = new int{42};

    delete my_int_ptr;

    delete my_other_int_ptr;
}