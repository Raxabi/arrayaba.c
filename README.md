# arrayaba.c

Library for integer array's hadling / manipulation written in C, ported from Java

## Dependencies

- gcc or another C compiler (like clang, etc)
- nothing else xd

## How to build?

- Clone this repository:
  - > git clone <https://github.com/Raxabi/arrayaba.c.git>

- Once the repository was cloned:
  - > sudo make all
    - This will do the next steps:
      - Compile all the source files to object files, storing them at ./out
      - Creates a shared library from these object files
      - Copy the produced library at /usr/lib (a standard location) (you need use sudo permissons)
      - nothing else again xd
  - To test the 'test' that comes with the repo:
    - > make test

- How to uninstall the installed library?
  - > sudo make uninstall
    - This will remove the `/usr/lib/arrayaba.so.[major.minor.patch]`
    - `make uninstall` will too remove:
      - all contents inside ./build, ./lib and ./out
