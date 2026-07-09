#include <stdlib.h>

// Simple hash table structure
typedef struct {
    int key;
    int value;
} HashItem;

#define SIZE 10007  // prime number for hashing

int hash(int key) {
    return abs(key) % SIZE;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashItem* table = (HashItem*)malloc(SIZE * sizeof(HashItem));

    // Initialize hash table
    for (int i = 0; i < SIZE; i++) {
        table[i].key = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int h = hash(complement);

        // Search for complement
        while (table[h].key != INT_MIN) {
            if (table[h].key == complement) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = table[h].value;
                result[1] = i;
                *returnSize = 2;
                free(table);
                return result;
            }
            h = (h + 1) % SIZE;
        }

        // Insert current number
        h = hash(nums[i]);
        while (table[h].key != INT_MIN) {
            h = (h + 1) % SIZE;
        }
        table[h].key = nums[i];
        table[h].value = i;
    }

    *returnSize = 0;
    free(table);
    return NULL;
}