
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void parallel_sort_bridge(unsigned int* arr,size_t size); //CPP sort algo

int main() {
    unsigned int *arr = malloc(1000000000*sizeof(unsigned int));
    size_t num_elements = 1000000000;
    uint64_t state = 0x1234567890ABCDEF;

    if (arr==NULL) {
        printf("PC out of memory, Malloc failed!\n");
        return 1;
    }

    for (size_t i = 0; i < num_elements; i++){
        state ^= state << 13;
        state ^= state >> 7;
        state ^= state << 17;
        arr[i] = (unsigned int)state;
    }

    parallel_sort_bridge(arr, 1000000000); //here last

    printf("Array sorted, first is %u, last is %u\n",arr[0],arr[num_elements-1]);

    free(arr);
    return 0;
}
