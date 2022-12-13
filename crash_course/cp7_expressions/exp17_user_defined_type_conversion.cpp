//
// Created by andy- on 2021-11-20.
//


/*
 * In user-defined types, you can provide use-defined conversion functions. These functions tell the compiler how your
 * user-defined types behave during implicit and explicit conversion. You can declare these conversion functions using
 * the following usage pattern.
 *
 */

//struct MyType{
//    operator destination-type() const{
//        // return a destination-type from here.
//    }
//};

struct ReadOnlyInt {
    ReadOnlyInt(int val) : val{val}{}
    operator int() const {
        return val;
    }
private:
    const int val;
};

int main() {
    ReadOnlyInt the_answer{42};
    auto ten_answers = the_answer * 10; // int with value 420
}