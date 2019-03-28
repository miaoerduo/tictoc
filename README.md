# tictoc

### Header Only C++ Timer

It's easy to use tictoc timer in your C++ project.

1. include "tictoc.hpp"
2. capture you code with `TIC` and `TOC` (or `TICTOC`, `TICTOC` means `TOC;TIC`)

You can use `TIC` to set a timer start point, and `TOC` to set a end point, the program will output time cost between two points.

Please run the demo first!

compile the demo.cpp and run:

```
g++ demo.cpp -o demo.bin -DWITH_TICTOP
./demo.bin
```

You will get the output as following:

```
demo.cpp @ main [    8,   13]   elapsed:      0.025 s      24.786 ms       24786 us
demo.cpp @ main [    8,   18]   elapsed:      0.049 s      48.709 ms       48709 us
demo.cpp @ main [    8,   23]   elapsed:      0.072 s      72.211 ms       72211 us
demo.cpp @ main [    8,   24]   elapsed:      0.072 s      72.225 ms       72225 us
demo.cpp @ main [   30,   36]   elapsed:      0.022 s      21.747 ms       21747 us
demo.cpp @ main [   36,   41]   elapsed:      0.021 s      21.463 ms       21463 us
```

The output contains: filename, function, code lines and elapsed time.

And if you compile demo.cpp without `-DWITH_TICTOP`, the program will work as if tictoc timer never existed!

```
g++ demo.cpp -o demo.bin # -DWITH_TICTOP
./demo.bin
```

No output!

Macro definitions `TICTOC_DISPLAY` and `TICTOC_NODISPLAY` can be used to turn the timer on / off.

All features can be found in `demo.cpp`, Please run the demo first. :P
