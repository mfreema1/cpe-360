#include<iostream>
using namespace std;

class Brick {
    public:
        int length;
        int width;

        Brick() {
            length = 10;
            width = 5;
        }
};

int main() {
    //NOT going to do
    //Brick var;

    //STEP1: You need a pointer to go into the heap
    Brick* ptr;

    //STEP2: Using pointer, request for a new 'brick' from the heap
    ptr = new Brick;

    //STEP3: Access that newly created brick in the heap
    ptr->length = 30;
    ptr->width = 40;

    //STEP4: Let go of the chunk when you're done
    delete ptr;
    //grabbing something from the heap is like taking a book from the library,
    //you need to give it back when you're done so someone else can have it

    //when you say delete ptr, ptr is still alive, but it does erase the thing ptr
    //is pointing to
    return 1;
}