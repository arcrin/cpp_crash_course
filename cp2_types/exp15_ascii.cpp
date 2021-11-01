//
// Created by andy- on 2021-10-31.
//

#include <cstdio>

int main(){
    char alphabet[27];
    for (int i=0; i<26; i++){
        alphabet[i] = i + 97;
    }
    alphabet[26] = 0;
    printf("%s\n", alphabet);
    for (int i=0; i<26; i++){
        alphabet[i] = i + 65;
    }
    printf("%s", alphabet);
}