//
// Created by wbai on 11/22/2021.
//

/*
 * You can bind an object's scope to an if statement by adding an init-statement to if and else if declarations
 */

#include <cstdio>


struct TextFile {
    bool success;
    const char *data;
    size_t n_bytes;
};


TextFile read_text_file(const char *path) {
    const static char contents[]{"Sometimes the goat is your."};
    return TextFile{
            true,
            contents,
            sizeof(contents)
    };
}

int main() {
    if (const auto[success, txt, len] = read_text_file("README.txt"); success) {
        printf("Read %d bytes: %s\n", len, txt);
    } else {
        printf("Failed to open README.txt.");
    }
}