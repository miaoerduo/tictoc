#include "tictoc.hpp"
#include <stdlib.h>
int main() {

    const int TRY_TIMES = 1000000;
    const int MEMORY_LENGTH = 1024;

    TIC
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TOC
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TOC
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TOC
    TICTOC
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TICTOC
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TICTOC
    for (int i = 0; i < TRY_TIMES; ++ i) {
        void *x = malloc(MEMORY_LENGTH);
        free(x);
    }
    TICTOC
}