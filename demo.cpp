#include "tictoc.hpp"
#include <stdlib.h>
int main() {

    const int TRY_TIMES = 1000000;
    const int MEMORY_LENGTH = 1024;

    TIC // #1
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TOC // #2    time: #2 - #1
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TOC // #3    time: #3 - #1
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TOC // #4    time: #4 - #1
    TICTOC // #5    time: #5 - #1
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TICTOC_NODISPLAY // no display below
    TICTOC // #6    time: #6 - #5, will not output
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TICTOC_DISPLAY // display below
    TICTOC // #7    time: #7 - #6
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TICTOC // #8    time: #8 - #7
}
