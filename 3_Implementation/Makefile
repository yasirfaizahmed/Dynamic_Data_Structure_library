
# our compiler collection name
CC = gcc

# project name
PROJECT_NAME = dyn_ds_l

# source files
SRC = main.c src/binary_search_tree.c src/queue.c src/singly_linked_list.c
TEST_SRC = test/test_dyn_ds_l.c src/binary_search_tree.c src/queue.c src/singly_linked_list.c unity/unity.c

# include files
INC = -I inc
TEST_INC = -I inc\
-I unity 

# temporary build folder for .exe or .out
BUILD = build

# project output name
PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out
TEST_OUTPUT = $(BUILD)/test_$(PROJECT_NAME).out


main : $(SRC) $(BUILD)
		$(CC) $(SRC) $(INC) -o $(PROJECT_OUTPUT)

test : $(BUILD)
		$(CC) $(TEST_SRC) $(TEST_INC) -o $(TEST_OUTPUT)

clean : 
		rm -rf $(BUILD)

$(BUILD) : 
		mkdir build