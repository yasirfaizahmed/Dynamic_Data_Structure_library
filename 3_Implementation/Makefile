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
TEST_NAME = test_dyn_ds_l

ifdef OS
   RM = del
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -f
      FixPath = $1
	  EXEC = out
   endif
endif




# make main files executable
all : $(SRC) $(BUILD)
		$(CC) $(SRC) $(INC) -o $(call FixPath, $(PROJECT_NAME).$(EXEC))

# make test files executable
test : $(BUILD)
		$(CC) $(TEST_SRC) $(TEST_INC) -o $(call FixPath, $(TEST_NAME).$(EXEC))
		./$(TEST_NAME).$(EXEC)

# run main executable	
run :
		$(call FixPath, $(PROJECT_NAME).$(EXEC))

<<<<<<< HEAD
# cpp check
cppcheck:
	cppcheck --enable=all $(SRC) main.c 
		
		
=======
# run test executable
run_test :
		$(TEST_OUTPUT)
>>>>>>> 9c7970ac1842402bf0a458d70a3539a6e8f00822

# clean all exectables
clean : 
		$(RM) *.$(EXEC)
