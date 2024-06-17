##
## EPITECH PROJECT, 2024
## Github
## File description:
## Makefile
##

CC = g++
AR = rcs

TARGET = program
TARGET_DEBUG = $(TARGET)_debug
CFLAGS_INCLUDES = -I$(INCLUDE_DIR)\
    $(foreach dep,$(DEPENDENCIES_PATH),-I$(dep)/includes)
CFLAGS = $(CFLAGS_INCLUDES) -W -Wextra
CFLAGS_DEBUG = -g

INCLUDE_DIR = includes
SRC_DIR = src
OBJ_DIR = obj
DEPENDENCIES_PATH =

SRC = $(shell find $(SRC_DIR) -name '*.cpp')
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: build_dependencies $(TARGET)

build_dependencies:
    @$(foreach dep, $(DEPENDENCIES_PATH), make -C $(dep);)

$(TARGET): $(OBJ)
    $(CC) $(CFLAGS) $(SRC)\
    $(foreach dep,$(DEPENDENCIES_PATH),-L$(dep) -l$(dep)) -o $(TARGET)
    @echo "project '$(TARGET)' successfully build"

$(TARGET_DEBUG): $(OBJ)
    @echo "project '$(TARGET_DEBUG)' successfully build"
    $(CC) $(CFLAGS) $(CFLAGS_DEBUG) $(SRC)\
    $(foreach dep,$(DEPENDENCIES_PATH),-L$(dep) -l$(dep)) -o $(TARGET_DEBUG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
    @mkdir -p $(dir $@)
    $(CC) $(CFLAGS) -cpp $< -o $@

$(OBJ_DIR):
    @mkdir -p $(OBJ_DIR)
    @echo "making directory '$(OBJ_DIR)' since it doesn't exist"

debug: build_dependencies $(TARGET_DEBUG)

clean:
    @$(foreach dep, $(DEPENDENCIES_PATH), make -C $(dep) clean;)
    @rm -rf $(OBJ_DIR)

fclean: clean
    @$(foreach dep, $(DEPENDENCIES_PATH), make -C $(dep) fclean;)
    @rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re build_dependencies