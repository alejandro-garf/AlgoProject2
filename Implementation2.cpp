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

    // First phase: Find the meeting point
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    // Second phase: Find the start of the loop
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

    cout << "Duplicate clue is: " << findDuplicateClue(head) << endl;

    return 0;
}
