//
// Created by wbai on 12/21/2021.
//

int mani(){
    int *p = nullptr;
    *p = 10; //this won't work as there is no memory backing up this pointer
    p = new int;
    *p = 10;
}