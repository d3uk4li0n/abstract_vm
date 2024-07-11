CC=g++
TARGET=my_abstract_vm
RM=rm -rf

SRC=src
OBJ=obj
CFLAGS+=-Wall -Wextra -g3 -Iinclude 
CPP_FLAGS=-Wpedantic -std=c++17 -Wcast-qual -Wnon-virtual-dtor -Woverloaded-virtual -Wold-style-cast

SRCS=$(wildcard $(SRC)/*.cpp)

OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS) $(CPP_FLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) $(CPP_FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)/*.o

fclean:	clean
	$(RM) $(TARGET)