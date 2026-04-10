
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>

void parallel_sort_bridge(unsigned int* arr,size_t size); //CPP sort algo

int main() {
    uint32_t *arr = mmap(NULL,1000000000*sizeof(unsigned int), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_POPULATE, -1, 0);
    madvise(arr, 1000000000*sizeof(unsigned int), MADV_SEQUENTIAL | MADV_WILLNEED);

    size_t num_elements = 1000000000;
    uint64_t state = 0x1234567890ABCDEF;

    if (arr==MAP_FAILED) {
        printf("PC out of memory, Mmap failed!\n");
        return 1;
        exit(1);
    }

    for (size_t i = 0; i < num_elements; i +=2){
        state ^= state << 13;
        state ^= state >> 7;
        state ^= state << 17;
        arr[i] = (unsigned int)state;
        arr[i+1] = (uint32_t)(state>>32);
    }

    parallel_sort_bridge(arr, 1000000000); //here last

    printf("Array sorted, first is %u, last is %u\n",arr[0],arr[num_elements-1]);

    munmap(arr,1000000000*sizeof(unsigned int));
    return 0;

    
}

