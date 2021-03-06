//Mark Freeman, tower of hanoi, no recursion allowed -- February 2018
#include<iostream>
#include<vector>
using namespace std;

//altitude is the height of the disk off the ground.  Bottom disk is 1, top is number of input disks
struct disk {
    int altitude;
    int last_pos;
    int curr_pos;
    disk(int alt, int last, int curr) {
        altitude = alt;
        last_pos = last;
        curr_pos = curr;
    }
};

int program_counter = 0;
int number_of_disks;

// column_from[last_index] is the disk of interest, column_to_pos is 1, 2, or 3
void moveDisk(vector<disk> &column_from, vector<disk> &column_to, int column_to_pos) { //need to do this by reference (indicated by &)
    int last_index = column_from.size() - 1;
    column_from[last_index].last_pos = column_from[last_index].curr_pos;
    column_from[last_index].curr_pos = column_to_pos;
    column_to.push_back(column_from[last_index]);
    program_counter++;
    cout << "Program counter: " << program_counter << endl;
    cout << "Move disk from column " << column_from[last_index].last_pos << " to column " << column_to_pos << endl;
    column_from.pop_back(); //needs to be done last to avoid index errors
}

//this function acts much like the following function, perhaps could be consolidated, solution isn't very dry right now
//disk to inspect is (*(columns_to_search[i]))[last_index]
int getColumnWithSmallestDisk(vector<disk> *columns_to_search[3]) {
    for (int i = 0; i < 3; i++) {
        int last_index = columns_to_search[i]->size() - 1;
        if (last_index != -1 && (*(columns_to_search[i]))[last_index].altitude == number_of_disks)
            return i; // I want the column as a number 0 to 2
    }
}

//disk to inspect is (*(columns_to_search[i]))[last_index]
int getColumnWithNextSmallestDisk(vector<disk> *columns_to_search[3]) {
    int result; //don't need to initialize, we will hit a disk guaranteed
    int max_altitude = 0;
    for (int i = 0; i < 3; i++) {
        int last_index = (columns_to_search[i])->size() - 1;
        //I only want the next smallest disk, so we need to block the altitude of the number
        //of disks
        if (last_index != -1 && (*(columns_to_search[i]))[last_index].altitude > max_altitude && (*(columns_to_search[i]))[last_index].altitude != number_of_disks) {
            max_altitude = (*(columns_to_search[i]))[last_index].altitude;
            result = i; //I want the column as a number 0 to 2
        }
    }
    return result;
}

int main() {
    cout << "Enter number of disks: " << endl;
    cin >> number_of_disks;

    vector<disk> column_1, column_2, column_3;

    //fill the first column with the number of disks the user entered
    //the rest will start empty
    for (int i = 1; i <= number_of_disks; i++) {
        disk * disk_to_add  = new disk(i, -1, 1);
        column_1.push_back(*disk_to_add);
    }

    //create pointers to all of the columns, assign them addresses, for loop probably isn't shorter
    vector<disk> *friend_column_1 = &column_1;
    vector<disk> *friend_column_2 = &column_2;
    vector<disk> *friend_column_3 = &column_3;
    vector<disk> *friends[3] = { friend_column_1, friend_column_2, friend_column_3 }; //array of pointers to vectors of disks

    int position_of_smallest_disk;
    //if N is even, move first disk to column 2, else move it to column 3, also sets program counter to 1
    if (number_of_disks % 2 == 0) {
        moveDisk(*friend_column_1, *friend_column_2, 2);
        position_of_smallest_disk = 2;
    }
    else {
        moveDisk(*friend_column_1, *friend_column_3, 3);
        position_of_smallest_disk = 3;
    }

    while (column_3.size() < number_of_disks) {
        //skip phase 1 of the loop the first time through.  Get the smalleset disk and move it to the position it was not last at
        //disk to move is (*(friends[column_of_interest]))[last_index]
        if (program_counter != 1 && program_counter % 2 == 0) {
            int column_of_interest = getColumnWithSmallestDisk(friends);
            int last_index = (friends[column_of_interest]->size()) - 1;
            //math hack to determine location of move.  This works because we have 3 columns and
            //this disk must go to not current position and not last position.
            int destination_column = 6 - (*(friends[column_of_interest]))[last_index].curr_pos - (*(friends[column_of_interest]))[last_index].last_pos;
            position_of_smallest_disk = destination_column; //keep track of the small disk
            //we subtract one to line up the destination column and the index of friends
            moveDisk(*friends[column_of_interest], *friends[destination_column - 1], destination_column);
        }
        //begin phase 2, program counter is odd, find next highest column, move it onto the pillar without the N altitude block
        //disk to move is (*(friends[column_of_interest]))[last_index]
        else {
            int column_of_interest = getColumnWithNextSmallestDisk(friends);
            int last_index = (friends[column_of_interest]->size()) - 1;
            //same math hack as above
            int destination_column = 6 - position_of_smallest_disk - (*(friends[column_of_interest]))[last_index].curr_pos;
            moveDisk(*friends[column_of_interest], *friends[destination_column - 1], destination_column);
        }
    }
    cout << "Moves taken: " << program_counter << endl;
    return 1;
}
