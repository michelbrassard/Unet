# First build

- mkdir -p build && cd build
- cmake ..
- cmake --build .

## Second builds without changes in CMakeLists.txt

- cd build
- cmake --build . (build)
- ./Unet (run)

## Second builds with changes in CMakeLists.txt

- cd build
- cmake ..
- cmake --build .

### Reminders

use launch.json command when debugger is needed
otherwise use tasks.json
