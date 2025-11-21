#include <stdio.h>
#define TABLE_SIZE 10
int hashTable[TABLE_SIZE];
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1; 
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    hashTable[index] = key;
}

int search(int key) {
    int index = hash(key);

    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index; 
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return -1;
}


void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    initHashTable();

    int numValues;
    printf("Enter the number of values to insert: ");
    scanf("%d", &numValues);

    printf("Enter %d values to insert:\n", numValues);
    for (int i = 0; i < numValues; i++) {
        int value;
        scanf("%d", &value);
        insert(value);
    }

    printf("Enter a value to search: ");
    int searchValue;
    scanf("%d", &searchValue);

    int index = search(searchValue);
    if (index != -1) {
        printf("Value %d found at index %d\n", searchValue, index);
    } else {
        printf("Value %d not found\n", searchValue);
    }

    display();

    return 0;
}
