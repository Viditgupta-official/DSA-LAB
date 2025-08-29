#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX];
int size = 0;

void create() {
    cout << "Enter number of elements: ";
    cin >> size;
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void display() {
    if (size == 0) {
        cout << "Array is empty\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    if (size == MAX) {
        cout << "Array is full, cannot insert.\n";
        return;
    }
    int pos, val;
    cout << "Enter position (1 to " << size + 1 << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;

    if (pos < 1 || pos > size + 1) {
        cout << "Invalid position\n";
        return;
    }

    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    size++;
    cout << "Element inserted.\n";
}

void removeElement() {
    if (size == 0) {
        cout << "Array empty, cannot delete.\n";
        return;
    }
    int pos;
    cout << "Enter position (1 to " << size << "): ";
    cin >> pos;

    if (pos < 1 || pos > size) {
        cout << "Invalid position\n";
        return;
    }

    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted.\n";
}

void linearSearch() {
    if (size == 0) {
        cout << "Array is empty\n";
        return;
    }
    int key, found = 0;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << endl;
            found = 1;
            break;
        }
    }
    if (!found) cout << "Element not found\n";
}

int main() {
    int choice;
    do {
        cout << "\n——MENU——\n";
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: removeElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}
