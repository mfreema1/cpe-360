class Node {
    public:
        int val;
        int row;
        int col;
        Node* next;

        Node(int val, int row, int col) {
            this.val = val
            this.row = row
            this.col = col;
            next = NULL;
        }

        bool isSameRowCol(Node* node) {
            return this.row == node.row && this.col == node.col;
        }

        bool isGreaterRowCol(Node* node) {
            if(this.row < node.row)
                return false;
            else if(this.col <= node.col)
                return false;
            return true;
        }
}

class SparseMatrix {
    public:
        Node* head;
        
        SparseMatrix() {
            head = NULL;
        }

    void addNodeToEnd(int val, int row, int col) {
        //keep in mind that temp is not the name of the object,
        //but rather the pointer that finds it for us
        Node* temp = new Node(val, row, col);
        if(head == NULL)
            head = temp;
        else {
            //the list isn't empty, traverse to the end of the list
            Node* trav = head;
            while(trav->next != NULL) {
                trav = temp->next;
            }
            //trav is now at the last element of the list
            //throw in our new element
            trav->next = temp;
        }
    }
}