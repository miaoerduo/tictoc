# tictoc

### Header Only C++ Timer

It's easy to use tictoc timer in your C++ project.

1. include "tictoc.hpp"
2. capture you code with `TIC` and `TOC` (or `TICTOC`, `TICTOC` means `TOC;TIC`)

You can use `TIC` to set a timer start point, and `TOC` to set a end point, the program will output time cost between two points.

Please run the demo first!

compile the demo.cpp and run:

```
g++ demo.cpp -o demo.bin -std=c++11 -DWITH_TICTOP
./demo.bin
```

You will get the output as following:

```
demo.cpp [    8,   13]   elapsed:      0.026 s      26.460 ms       26460 us
demo.cpp [    8,   18]   elapsed:      0.048 s      48.282 ms       48282 us
demo.cpp [    8,   23]   elapsed:      0.071 s      70.769 ms       70769 us
demo.cpp [    8,   24]   elapsed:      0.071 s      70.782 ms       70782 us
demo.cpp [   30,   36]   elapsed:      0.021 s      20.804 ms       20804 us
demo.cpp [   36,   41]   elapsed:      0.021 s      21.212 ms       21212 us
```

The output contains: filename, code lines and elapsed time.

And if you compile demo.cpp without `-DWITH_TICTOP`, the program will work as if tictoc timer never existed!

```
g++ demo.cpp -o demo.bin -std=c++11 # -DWITH_TICTOP
./demo.bin
```

No output!

Macro definition `TICTOC_DISPLAY` and `TICTOC_NODISPLAY` can be used to turn the timer on / off.

All features can be found in `demo.cpp`, Please run the demo first. :P
