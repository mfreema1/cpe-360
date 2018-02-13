#include<iostream>
using namespace std;

class chromeTab {
    public:
        int length;
        int width;
        chromeTab* next; //within the chromeTab is a pointer to the next one

    chromeTab() {
        length = 100;
        width = 50;
        next = NULL;
    }
};

int main() {

    //STEP1: Grab a pointer
    chromeTab* ptr;

    //our first tab in the heap
    ptr = new chromeTab; //nameless object, but it does have an address which ptr holds
    ptr->length = 200;

    //use the first tab, and create a second tab
    //the first tab must point to the second tab
    //<pointer LHS> = new <TYPE>
    ptr->next = new chromeTab;

    //next, let's create a third tab such that the second one points to this
    ptr->next->next = new chromeTab;

    //let's create a fourth tab, such that the third tab points to this one
    ptr->next->next->next = new chromeTab;

    //changing the fourth tab's width to 80
    ptr->next->next->next->width = 80;

    //change the second tab's length to 200
    ptr->next->length = 200;

    //third tab's width to -1
    ptr->next->next->width = -1;

    //note that we've only left one lone pointer in the app space
    return 1;
}