//using a string of pointers in the heap is like having a string of beads.
//if the string gets cut, then the beads slide away

#include<iostream>
using namespace std;

//conceptually structure data
class chromeTab{
    public:
        //attributes
        int length;
        int width;
        chromeTab* next;

        //constructor
        chromeTab() {
            length = 100;
            width = 50;
            next = NULL;
        }
};

int main() {
    chromeTab* head;

    //ACT 1: let's add a bunch of chunks and create this string of beads
    //<Pointer> = new <type-of-structure>
    head = new chromeTab;//head--->tab1
    
    //let's try to create head--->tab1--->tab2
    head->next = new chromeTab;
    
    //another tab, head-->tab1-->tab2-->tab3
    head->next->next = new chromeTab;
    
    //another one
    head->next->next->next = new chromeTab;

    //yet another
    head->next->next->next->next = new chromeTab;


    //change third tab's length to 30 and width to 10
    head->next->next->width = 10;
    head->next->next->length = 30;

    //last chunk, change length to 200, width to 60
    head->next->next->next->next->width = 60;
    head->next->next->next->next->length = 200;

    //==========================
    //DELETE one of these objects
    //==========================

    //if you plan on deleting something, you must knit the chunk before
    //to the chunk following the chunk to be deleted.  This must be done
    //before the chunk is deleeted

    //target is to delete the SECOND chunk
    //to do that, we must have a 'temp' pointer at the chunk BEFORE (first)
    chromeTab *temp, *target;

    //get temp to point to the first chunk
    temp = head;
    target = head->next;
    //the next pointer of the first one, and point to the third chunk
    temp->next = temp->next->next;

    delete target; //delete does not get rid of target, it gets rid of the chunk whose address target has

    //delete the new third chunk
    temp = head->next;
    target = head->next->next;
    temp->next = temp->next->next;
    delete target;


    return 1;
}