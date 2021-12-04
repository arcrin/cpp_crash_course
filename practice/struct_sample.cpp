//
// Created by wbai on 12/3/2021.
//
#include <cstdio>

typedef struct {
    int value;
}Foo, *pFoo;

void print_foo(Foo& temp){
    printf("%d\n", temp.value);
}

void print_pFoo(pFoo temp){
    printf("%d\n", temp->value);
}

void change_foo(Foo temp) {
    temp.value += 1; // this will not change the value of foo1, this is a local copy of the Foo object passed by
                     // reference
    printf("%d\n", temp.value);
}

void change_pFoo(pFoo temp){
    (*temp).value += 1; // if I want to change the actual content of foo, I need to use pointer to access the content
}

int main(){

    Foo *p_foo;
//    (*foo).value = 2;
    Foo foo{2};
    p_foo = &foo;
    Foo foo1{1};
    print_foo(foo1);
    change_foo(foo1);
    print_foo(foo1);

    print_pFoo(p_foo);
    change_pFoo(p_foo);
    print_pFoo(p_foo);
}
