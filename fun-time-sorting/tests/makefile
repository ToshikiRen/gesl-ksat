CXX = g++
CXXFLAGS = -g -Wall
EXECUTABLE = tests
SHARED-LIB = sorting
BUILD_FOLDER_PATH = ../build/
LIB_PATH = ../src/libs/
TEST_LIB_PATH = ./libs
BASE_FILES = main.cpp test-utils.cpp

build:
	$(CXX) $(CXXFLAGS) *.cpp -l$(SHARED-LIB) -I$(LIB_PATH) -I$(TEST_LIB_PATH) -L../build -o $(BUILD_FOLDER_PATH)$(EXECUTABLE)

build-c1:
	$(CXX) $(CXXFLAGS) task1.cpp $(BASE_FILES) -l$(SHARED-LIB) -I$(LIB_PATH) -I$(TEST_LIB_PATH) -L../build -o $(BUILD_FOLDER_PATH)$(EXECUTABLE)

test-c1: build-c1
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(BUILD_FOLDER_PATH) &&\
	$(BUILD_FOLDER_PATH)$(EXECUTABLE)

test: build
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(BUILD_FOLDER_PATH) &&\
	$(BUILD_FOLDER_PATH)$(EXECUTABLE)
