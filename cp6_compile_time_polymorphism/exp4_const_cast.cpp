//
// Created by wbai on 11/12/2021.
//

/*
 * The const_cast function shucks away the const modifier, allowing the modification of const values. The object-to-cast
 * is of some const type, and the desired-type is that type minus the const qualifier.
 */

void carbon_thaw(const int& encased_solo) {
    //encased_solo++ // Compiler error; modifying const
    auto &hibernation_sick_solo = const_cast <int &>(encased_solo);
    hibernation_sick_solo++;
    //encased_solo++; // Still compiler error; const_cast does not affect object-to-cast
}

/*
 * Only use const_cast to obtain write access to const objects. Any other type conversion will result in a compiler
 * error.
 */