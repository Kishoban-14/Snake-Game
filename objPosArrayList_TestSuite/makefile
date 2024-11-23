CC = g++
CFLAGS = -I. -lm -g
DEPS = $(wildcard *.h)
OBJ = objPos.o objPosArrayList.o Player.o Project.o GameMechs.o

# Rule for compiling .cpp files into .o files
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rule for building the final executable
ALTester: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Placeholder for testing executable (customize as needed)
test: ALTester
	./ALTester

.PHONY: clean

# Rule for cleaning up generated files
clean:
	del /Q *.o ALTester.exe
