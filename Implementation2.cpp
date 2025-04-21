#include <iostream>

using namespace std;

/**
 * Definition for a linked list node representing a room clue.
 */
struct Room {
    int clue;
    Room* next;
    
    Room(int val) : clue(val), next(nullptr) {}
};

/**
 * Finds the duplicate clue causing the haunted house loop.
 * @param head - The head of the linked list.
 * @return The duplicate clue value.
 */
int findDuplicateClue(Room* head) {
    Room* slow = head;
    Room* fast = head;

    // Phase 1: Detect cycle
    do {
        if (!fast || !fast->next) return -1; // safety check
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // Phase 2: Find the start of the cycle (duplicate clue)
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->clue;
}

int main() {
    int n;
    cout << "Enter number of rooms (n + 1 clues): ";
    cin >> n;

    Room* head = nullptr;
    Room* tail = nullptr;

    cout << "Enter clues:\n";
    for (int i = 0; i < n; i++) {
        int clue;
        cin >> clue;
        Room* newRoom = new Room(clue);

        if (!head) {
            head = tail = newRoom;
        } else {
            tail->next = newRoom;
            tail = newRoom;
        }
    }

    // Manually create a cycle by linking the tail to a node with the same clue
    Room* cycleStart = nullptr;
    Room* curr = head;
    while (curr) {
        if (curr != tail && curr->clue == tail->clue) {
            cycleStart = curr;
            break;
        }
        curr = curr->next;
    }

    if (cycleStart) {
        tail->next = cycleStart; // create the loop
    } else {
        cout << "No duplicate clue found to form a cycle.\n";
        return 0;
    }

    int duplicate = findDuplicateClue(head);
    cout << "Duplicate clue is: " << duplicate << endl;

    return 0;
}