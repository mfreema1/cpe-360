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
*property of the disk structure.  Pass in vectors via pointers for reference.
*/
//TODO: print the move to the screen
void moveDisk(vector<disk> column_from, vector<disk> column_to, int column_to_pos) {
    int last_index = column_from.size() - 1;
    disk disk_to_add = column_from[last_index];
    disk_to_add.last_pos = disk_to_add.curr_pos;
    disk_to_add.curr_pos = column_to_pos;
    column_from.pop_back();
    column_to.push_back(disk_to_add);
    program_counter++;
    cout << "Move disk " << disk_to_add.last_pos << " to column " << column_to_pos << endl;
}

//this function acts much like the following function, perhaps could be consolidated,
//solution isn't very dry right now.
int getColumnWithSmallestDisk(vector<disk> columns_to_search[3]) {
    for(int i = 0; i < 3; i++) {
        int last_index = columns_to_search[i].size();
        disk disk_to_inspect = columns_to_search[i][last_index];
        if(disk_to_inspect.altitude == number_of_disks)
            return i; // I want the column as a number 0 to 2
    }
}

int getColumnWithNextSmallestDisk(vector<disk> columns_to_search [3]) {
    int result = 0;
    int max_altitude = 0;
    for(int i = 0; i < 3; i++) {
        int last_index = columns_to_search[i].size();
        disk disk_to_inspect = columns_to_search[i][last_index];
        //I only want the next smallest disk, so we need to block the altitude of the number
        //of disks
        if(disk_to_inspect.altitude > max_altitude && max_altitude != number_of_disks) {
            max_altitude = disk_to_inspect.altitude;
            result = i; //I want the column as a number 0 to 2
        }
    }
    return result;
}

int main() {
    cout << "Enter number of disks: " << endl;
    cin >> number_of_disks;

    //keep it local, we'll pass it to our `moveDisk` function by reference
    vector<disk> column_1, column_2, column_3;

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

    //does this need to be a be a pointer?
    //pointer to an array of 
    vector<disk> *friends [3] = {friend_column_1, friend_column_2, friend_column_3};

    int position_of_smallest_disk;
    //if N is even, move first disk to column 2, else move it to column 3
    //also sets program counter to 1
    if(number_of_disks % 2 == 0) {
        moveDisk(*friend_column_1, *friend_column_2, 2);
        position_of_smallest_disk = 2;
    }
    else {
        moveDisk(*friend_column_1, *friend_column_3, 3);
        position_of_smallest_disk = 3;
    }

    //main loop of the program, the rest has been setup
    while(column_3.size() < number_of_disks) {
        //skip phase 1 of the loop the first time through.  Get the smalleset disk and move it to the position
        //it was not last at
        if(program_counter != 1 && program_counter % 2 == 0) {
            int column_of_interest = getColumnWithSmallestDisk(*friends);
            int last_index = (friends[column_of_interest]->size()) - 1;
            disk disk_to_move = (*(friends[column_of_interest]))[last_index];//need some fancy magic with brackets
            //math hack to determine location of move.  This works because we have 3 columns and
            //this disk must go to not current position and not last position.
            int destination_column = 6 - disk_to_move.curr_pos - disk_to_move.last_pos;
            position_of_smallest_disk = destination_column; //keep track of the small disk
            //we subtract one to line up the destination column and the index of friends
            moveDisk(*friends[column_of_interest], *friends[destination_column - 1], destination_column);
            }
        //begin phase 2, program counter is odd, find next highest column, move it onto the pillar without the
        //N altitude block
        else {
            int column_of_interest = getColumnWithNextSmallestDisk(*friends);
            int last_index = (friends[column_of_interest]->size()) - 1;
            disk disk_to_move = (*(friends[column_of_interest]))[last_index]; //we don't need to instantiate new disks, we just need to access the int on it
            int destination_column = 6 - position_of_smallest_disk - disk_to_move.curr_pos;
            moveDisk(*friends[column_of_interest], *friends[destination_column - 1], destination_column);
        }
    }
    cout << "Moves taken: " << program_counter << endl;
    return 1;
}