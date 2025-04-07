//grthgiurtghiperhgiuerhtgiurethgiurhtgiuhrtiguht

#include <stdlib.h>
#include <stdio.h>

// struct FILE;  // No definition necessary.

int main() {
    FILE *f = fopen("02-opaque-pointers.c", "r");  // "constructor", (1) resources are allocated by the library.

    // Never try to access `FILE`'s fields directly.
    char buf[20];  // (2) memory is provided by the caller.
    fscanf(f, "%20s", buf);  // "method". FIXME: why UB here?
    printf("buf=|%s|\n", buf);

    fclose(f);  // "destructor"
}
