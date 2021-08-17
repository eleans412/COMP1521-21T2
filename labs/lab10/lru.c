// Simulate LRU replacement of page frames

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


// represent an entry in a simple inverted page table

typedef struct ipt_entry {
    int virtual_page;        // == -1 if physical page free
    int last_access_time;
} ipt_entry_t;


void lru(int n_physical_pages, int n_virtual_pages);
void access_page(int virtual_page, int access_time, int n_physical_pages, struct ipt_entry *ipt);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <n-physical-pages> <n-virtual-pages>\n", argv[0]);
        return 1;
    }
    lru(atoi(argv[1]), atoi(argv[2]));
    return 0;
}


void lru(int n_physical_pages, int n_virtual_pages) {
    printf("Simulating %d pages of physical memory, %d pages of virtual memory\n",
          n_physical_pages, n_virtual_pages);
    struct ipt_entry *ipt = malloc(n_physical_pages * sizeof *ipt);
    assert(ipt);

    for (int i = 0; i < n_physical_pages; i++) {
        ipt[i].virtual_page = -1;
        ipt[i].last_access_time = -1;
    }

    int virtual_page;
    for (int access_time = 0; scanf("%d", &virtual_page) == 1; access_time++) {
        assert(virtual_page >= 0 && virtual_page < n_virtual_pages);
        access_page(virtual_page, access_time, n_physical_pages, ipt);
    }
}


// if virtual_page is not in ipt, the first free page is used
// if there is no free page, the least-recently-used page is evicted
//
// a single line of output describing the page access is always printed
// the last_access_time in ipt is always updated

void access_page(int virtual_page, int access_time, int n_physical_pages, struct ipt_entry *ipt) {

    int i = 0;
    int physical_page = 0;
    int is_free = 0;
    int free_location = 0;
    // Loop to find where there is a match the virtual page
    while (i < n_physical_pages) {
        // 1) The virtual page is already in a physical page
        if (ipt[i].virtual_page == virtual_page) {
            ipt[i].last_access_time = access_time;
            printf("Time %d: virtual page %d -> physical page %d\n", access_time, virtual_page, physical_page);
            return;
        }       
        physical_page++;
        i++;
    }
    i = 0;
    physical_page = 0;
    // Flag if there are free pages 
    while (i < n_physical_pages) {
        if (ipt[i].virtual_page == -1) {
            is_free = 1;
            free_location = physical_page;
            break;
        }
        i++;
        physical_page++;
    }
    
    // 2) The virtual page is not in a physical page,
    //    and there is free physical page
    //
    if (is_free) {
        // Set the location
        ipt[free_location].virtual_page = virtual_page;
        // Update time accessed
        ipt[free_location].last_access_time = access_time;
        printf("Time %d: virtual page %d loaded to physical page %d\n", access_time, virtual_page, free_location);
        return;
    }
    // 3) The virtual page is not in a physical page,
    //    and there is no free physical page
    
    else {
        int original_virtual_page = 0;
        physical_page = 0;
        i = 0;
        int least_location = 0;
        int least_recent = ipt[i].last_access_time;
        // Loop to check for the least recently used page
        while (i < n_physical_pages) {
            // If the last time accessed is less than or equal to the least_recent update
            // Search for the least recently used
            if (ipt[i].last_access_time <= least_recent) {
                least_recent = ipt[i].last_access_time;
                original_virtual_page = ipt[i].virtual_page;
                least_location = i;
            }

            i++;
        }
        // Do the replacing here
        ipt[least_location].virtual_page = virtual_page;
        ipt[least_location].last_access_time = access_time;
        printf("Time %d: virtual page %d  - virtual page %d evicted - loaded to physical page %d\n", access_time, virtual_page, original_virtual_page, least_location);
    }
    

    // don't forget to update the last_access_time of the virtual_page

    //printf("Time %d: virtual page %d accessed\n", access_time, virtual_page);
}
