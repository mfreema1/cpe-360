//so now that we have our string of beads,
//we want to be able to do a few things with this string
//1.  We want to be able to ADD a bead anywhere
//2.  DELETE anything anywhere
//3.  DISPLAY the string of beads

//RULES:
//1.  "Head" points to the first chunk
//2.  The string of beads must be maintained
//3.  The last chunk is always NULL

#include<iostream>
using namespace std;

class legoChunk {
    public:
        int x;
        int y;
        legoChunk* next;
};

int main() {
    legoChunk* head;
    legoChunk *target, *temp;

    //ACT 1: Create five chunks in the heap
    //head-->chunk1-->chunk2-->chunk3-->chunk4-->chunk5-->NULL
    //<POINTER> = new <DataType>
    head = new legoChunk; //head-->chunk1-->NULL
    head->next = new legoChunk; //head-->chunk1-->chunk2-->NULL
    head->next->next = new legoChunk; //head-->chunk1-->chunk2-->chunk3-->NULL
    head->next->next->next = new legoChunk; //head-->chunk1-->chunk2-->chunk3-->chunk4-->NULL

    //ACT 2: Accessing any chunk using "head"
    head->next->y = 50;
    head->next->next->y = 30;
    head->next->next->next->next->y = 100;

    //ACT 3: Delete random chunks
    //1. Set 'target' to the chunk you want to delete
    //2. Set 'temp' to chunk before the chunk you want to delete
    target = head->next->next;
    temp = head->next;
    //get the head-->chunk1-->chunk2-->chunk4-->chunk5-->NULL
    temp->next = temp->next->next;
    //after that, you have 'unhinged' chunk3
    cout << "About to delete chunk3, x: " << target->x << ", y: " << target->y << endl;
    delete target; //does not delete target, deletes the chunk pointed to

    //delete the first chunk
    //head-->chunk1-->chunk2-->...
    //target-->chunk1
    //head-->chunk2-->chunk3-->...
    target = head;
    head = head->next;
    delete target;

    //delete the last chunk
    //1.  target = last chunk
    //2.  temp = second last chunk
    //3.  temp->next is grounded
    target = head->next->next;
    temp = head->next;
    temp->next = NULL;
    delete target;

    //ACT 4: Add anything anywhere
    //scene1: let's add a new chunk between the first and second
    //1. target-->brand new chunk
    //2. take target's pointer and point to the chunk after
    //3. take the chunk before, and point to target
    target = new legoChunk;
    target->next = head->next;
    head->next = target;

    //scene2: add something all the way to the front
    target = new legoChunk;
    target->next = head;
    head = target;

    //scene3: add something all the way to the end
    //target = new chunk
    //temp is set to last chunk
    //knit this new chunk in, all the way to the end
    target = new legoChunk;
    temp = head->next->next->next;
    temp->next = target;

    //ACT 5: Display the chunk
    //the general test is to take a temporary pointer and walk along the chain

    temp = head;
    while(temp != NULL) {
        cout << "X: " << temp->x << endl;
        cout << "Y: " << temp->y << endl;
        temp = temp->next;
    }
    
    //keep in mind that if you do make an error in the code somewhere,
    //since much of this code is determine at runtime, the compiler will
    //not be much help at all

    //to keep this in check, compile often, it's much easier to sift through 20 lines
    //of code rather than 100
    return 1;
}