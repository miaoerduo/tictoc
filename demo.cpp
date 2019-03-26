#include "tictoc.hpp"
#include <stdlib.h>
int main() {

    TIC
    for (int i = 0; i < 100000; ++ i) {
        void *x = malloc(10);
        free(x);
    }
    TOC
    for (int i = 0; i < 100000; ++ i) {
        void *x = malloc(10);
        free(x);
    }
    TOC
    for (int i = 0; i < 100000; ++ i) {
        void *x = malloc(10);
        free(x);
    }
    TOC
    TICTOC
    for (int i = 0; i < 100000; ++ i) {
        void *x = malloc(10);
        free(x);
    }
    TICTOC
    for (int i = 0; i < 100000; ++ i) {
        void *x = malloc(10);
        free(x);
    }
    TICTOC
    for (int i = 0; i < 100000; ++ i) {
        void *x = malloc(10);
        free(x);
    }
    TICTOC

}