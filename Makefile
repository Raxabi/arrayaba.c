# local directories variables
OUT_DIR   = ./out
LIB_DIR   = ./lib
BUILD_DIR = ./build

# compiler
CC     = /sbin/gcc
CFLAGS = -g

# informational variables
VERSION = 1.0.0

# dependecies for the final build
DEPS     = main.c arrayaba/arrayaba.c
objects  = out/main.o out/arrayaba.o
LIB_NAME = arrayaba.so.$(VERSION)

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
	$(CC) $< -shared -fPIC -o $(LIB_DIR)/$(LIB_NAME)

# builds the executable program
$(BUILD_DIR)/test.out: out/main.o
	$(CC) $< -o $@ -l:$(LIB_NAME)

### RULES THAT RUN THE 'RULE BUILDERS' (above rules that produce's the necessary files) ###
# build the executable file "test.out" within the corresponding object files and shared library
assemble: $(BUILD_DIR)/test.out

# build only the objects files
object: out/main.o out/arrayaba.o

# builds the library and the object files
library: $(LIB_DIR)/$(LIB_NAME)

### POST-CODE TREATMENT ###

# clean the standard (std) locations where the linker search for libraries
stdclean:
	rm -v /usr/lib/$(LIB_NAME)

# clean the local workspace of gcc produced files
clean:
	rm -rv $(OUT_DIR)/* $(BUILD_DIR)/* $(LIB_DIR)/*

# run all the rules to get an executable program
install:
	cp $(LIB_DIR)/$(LIB_NAME) $(STANDARD_LOCATION_LIB)

uninstall: stdclean clean

# produces a shared library, copying it into /usr/lib/ directory
# and producing an executable file
all: library install assemble

# run the executable file, result of run the `assemble` or `all` rules
run:
	./build/test.out

