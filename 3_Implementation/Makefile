
# our compiler collection name
CC = gcc

# project name
PROJECT_NAME = dyn_ds_l

# source files
SRC = main.c\
src/binary_search_tree.c\
src/queue.c\
src/singly_linked_list.c
TEST_SRC = test/test_dyn_ds_l.c\
src/binary_search_tree.c\
src/queue.c\
src/singly_linked_list.c\
unity/unity.c

# include files
INC = -I inc
TEST_INC = -I inc\
-I unity 

# temporary build folder for .exe or .out
BUILD = build

$(BUILD) : 
		mkdir build

# project output 
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out
TEST_OUTPUT = $(BUILD)/test_$(PROJECT_NAME).out

# make main files executable
all : $(SRC) $(BUILD)
		$(CC) $(SRC) $(INC) -o $(PROJECT_OUTPUT)

# make test files executable
test : $(BUILD)
		$(CC) $(TEST_SRC) $(TEST_INC) -o $(TEST_OUTPUT)

# run main executable	
run_all :
		$(PROJECT_OUTPUT)

# run test executable
run_test :
		$(TEST_OUTPUT)

# clean all exectables
clean : 
		rm -rf $(BUILD)
