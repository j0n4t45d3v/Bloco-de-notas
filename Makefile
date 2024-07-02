
CXX=g++
CXX_FLAGS=

DB_DIR=./database
VIEW_DIR=./views
APP_DIR=./app
BIN_DIR=./bin

DB_FILES=$(DB_DIR)/**.cpp
VIEWS_FILES=$(VIEW_DIR)/**.cpp
APP_FILES=$(APP_DIR)/**.cpp
OUT_BIN=$(BIN_DIR)/main

LIBS = -lsqlite3

all: run

create_out_folder:
	@if [ ! -d $(BIN_DIR) ]; then mkdir -p $(BIN_DIR); fi

build: create_out_folder
	$(CXX) ./main.cpp $(VIEWS_FILES) $(DB_FILES) $(APP_FILES) -o $(OUT_BIN) $(LIBS)

run: build
	$(OUT_BIN)