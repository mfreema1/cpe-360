#include<iostream>
#include<vector>
using namespace std;

//we don't need any methods from the disks, just a group of data
struct disk {
        int altitude;
        int last_pos;
        int curr_pos;
    };

int program_counter = 0;
int number_of_disks;

/*
*@params
*column_from - the vector of the column to move the disk from
*column_to - the vector to put the disk on
*column_to_pos - integer representing the position of the column.  May be 1, 2, or 3
*We don't need to know the column_from_pos because we may take it from the curr_pos
*property of the disk structure.  Pass in vectors via pointers.
*/
void moveDisk(vector<disk> column_from, vector<disk> column_to, int column_to_pos) {
    int last_index = column_from.size() - 1;
    disk disk_to_add = column_from[last_index];
    disk_to_add.last_pos = disk_to_add.curr_pos;
    disk_to_add.curr_pos = column_to_pos;
    column_from.pop_back();
    column_to.push_back(disk_to_add);
    program_counter++;
}

//returns true if the vector has the smallest disk, false if it does not
bool hasSmallestDisk(vector<disk> column_to_search) {
    //smallest disk will always be on top due to rule of the game
    int last_index = column_to_search.size() - 1;
    if(column_to_search[last_index].altitude == number_of_disks)
        return true;
    return false;
}

int main() {
    cout << "Enter number of disks: " << endl;
    cin >> number_of_disks;

    //keep it local, we'll pass it to our `moveDisk` function by reference
    vector<disk> column_1, column_2, column_3;

    //we need to access this by index, so array that
    vector<disk> board [3] = column_1, column_2, column_3;

    //fill the first column with the number of disks the user entered
    //the rest will start empty
    for(int i = 1; i <= number_of_disks; i++) {
        disk disk_to_add;
        disk_to_add.altitude = number_of_disks;
        disk_to_add.curr_pos = 1;
        //will need to move curr_pos to last after a move, won't assign
        //last_pos here
        column_1.push_back(disk_to_add);
    }

    //create pointers to all of the columns, assign them addresses
    vector<disk> *friend_column_1 = &column_1;
    vector<disk> *friend_column_2 = &column_2;
    vector<disk> *friend_column_3 = &column_3;

    vector<disk> *friends [3] = {friend_column_1, friend_column_2, friend_column_3};

    //if N is even, move first disk to column 2, else move it to column 3
    //also sets program counter to 1
    if(number_of_disks % 2 == 0)
        moveDisk(*friend_column_1, *friend_column_2, 2); 
    else
        moveDisk(*friend_column_1, *friend_column_3, 3);

    //main loop of the program, the rest has been setup
    while(column_3.size() < number_of_disks) {

        //skip phase 1 of the loop the first time through
        if(program_counter != 1) {
            //hardcode 3 to avoid friends.size()
            for(int i = 0; i < 3; i++) {
                //we know the index, can get a reference to the top disk
                if(hasSmallestDisk(*friends[i])) {
                    int last_index = board[i].size() - 1;
                    disk disk_to_move = board[i][last_index];
                    //math hack to determine location of move.  This works because we have 3 columns and
                    //this disk must go to not current position and not last position.
                    int destination_column = 6 - disk_to_move.curr_pos - disk_to_move.last_pos;
                    //we subtract one to line up the destination column and the index of friends
                    moveDisk(*friends[i], *friends[destination_column - 1], destination_column);
                }
            }
        }
        //begin phase 2
    }
    return 1;
}