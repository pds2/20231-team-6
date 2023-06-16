CXX = g++
SRC_DIR = src
OBJ_DIR = build
PROJ_NAME = main
CXXFLAGS = -c        \
           -Wall     \
           -Wextra   \
           -I include

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJ_FILES)
	$(CXX) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | obj
	$(CXX) $(CXXFLAGS) $< -o $@

obj:
	mkdir $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(PROJ_NAME)

.PHONY: all clean