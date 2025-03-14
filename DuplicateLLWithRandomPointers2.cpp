class Solution {
public:
    Node* copyList(Node* head) {
        if (head == NULL) return NULL;

        // Step 1: Create new nodes interleaved with original nodes
        Node* temp = head;
        while (temp != NULL) {
            Node* next = temp->next;
            Node* newnode = new Node(temp->data);
            temp->next = newnode;
            newnode->next = next;
            temp = next;
        }

        // Step 2: Set random pointers for the new nodes
        temp = head;
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Step 3: Separate the interleaved original and copied nodes
        Node* anshead = head->next;
        Node* copy = anshead;
        temp = head;
        while (temp != NULL) {
            temp->next = temp->next->next;
            if (copy->next != NULL) {
                copy->next = copy->next->next;
            }
            temp = temp->next;
            copy = copy->next;
        }

        return anshead;
    }
};