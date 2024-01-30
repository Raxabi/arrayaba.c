# local directories variables
OUT_DIR   = ./out
LIB_DIR   = ./lib
BUILD_DIR = ./build

# compiler
CC     = gcc
CFLAGS = -g

# informational variables
VERSION = 1.0.0

# dependecies for the final build
DEPS     = main.c arrayaba/arrayaba.c
LIB_NAME = arrayaba.so.$(VERSION)

# Change the value of this var to change the final location of the shared library
STANDARD_LOCATION_LIB = /usr/lib/$(LIB_NAME)

### RULES TO BUILD NECCESARY FILES (library files, object files, etc) ###

# builds the object files into ./out dir
# each object file required by other rule
# that should be located at ./out/[object_file_name].o
# will trigger this rule
$(OUT_DIR)/%.o: arrayaba/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Same as above rule, but for source files that are located at root of the project
$(OUT_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# builds the shared library
$(LIB_DIR)/$(LIB_NAME): out/arrayaba.o
	$(CC) $< -shared -fPIC -o $@

# builds the executable program
$(BUILD_DIR)/test.out: out/main.o
	$(CC) $< -o $@ -l:$(LIB_NAME)

### RULES THAT RUN THE 'RULE BUILDERS' (above rules that produce's the necessary files) ###

# build only the objects files
objects: out/main.o out/arrayaba.o

# builds the library and the object files
library: $(LIB_DIR)/$(LIB_NAME)

# build the executable file "test.out" within the corresponding object files and shared library
assemble: $(BUILD_DIR)/test.out


### POST-CODE TREATMENT ###

copylib:
	cp $(LIB_DIR)/$(LIB_NAME) $(STANDARD_LOCATION_LIB)

# clean the standard (std) locations where the linker search for libraries
stdclean:
	rm -v $(STANDARD_LOCATION_LIB)/$(LIB_NAME)

# clean the local workspace of gcc produced files
clean:
	rm -rv $(OUT_DIR)/* $(BUILD_DIR)/* $(LIB_DIR)/*

# produces a library and 'install' it
install: library copylib

# removes the files produces by the compiler in the local project and $(STANDARD_LOCATION_LIB)
uninstall: clean stdclean

# produces a shared library, copying it into /usr/lib/ directory
# and producing an executable file
all: library install assemble

# run the executable file, result of run the `assemble` or `all` rules
test: assemble
	./build/test.out
