//
// Created by andy- on 2021-11-06.
//

/*
 * Copy Guidelines:
 *
 * When you implement copy behavior, think about the following criteria:
 *
 * Correctness: You must ensure that class invariants are maintained. The SimpleString class demonstrated that
 * the default copy constructor can violate invariants.
 *
 * Independence: After copy assignment or copy construction, the original object and the copy shouldn't change each
 * other's state during modification. Had you simply copied buffer from one SimpleString to another, writing to one
 * buffer could overwrite the data from the other.
 *
 * Equivalence: The original and the copy should be the same. The semantics of sameness depend on context. But generally,
 * an operation applied to the original should yield the same result when applied to the copy.
 */

int main() {

}