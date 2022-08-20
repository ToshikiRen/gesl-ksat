CC = gcc
CFLAGS = -g -Wall
FLAGS = -g -Wall -o
EXECUTABLE = program
BUILD_FOLDER_PATH = ./build/

build: build-dir
	cd ./src &&\
	make build-lib

test: build
	cd ./tests &&\
	make test


build-dir: clean
	mkdir $(BUILD_FOLDER_PATH)

single-run: build-dir
	cd ./src &&\
	make run

test-c1: build
	cd ./tests &&\
	make test-c1

clean:
	rm -rf $(BUILD_FOLDER_PATH)
