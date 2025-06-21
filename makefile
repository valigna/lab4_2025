# Compiler
CC=g++
# Compiler flags
CFLAGS=-c -Wall -I./include -g
# Linker
LD=g++
# Linker flags
LDFLAGS=
# Source directory
SRCDIR=src
# Object directory
OBJDIR=obj
# Executable file
EXECUTABLE=main
PRINCIPAL=main

# Source files
SOURCES=$(wildcard $(SRCDIR)/**/*.cpp $(SRCDIR)/*.cpp)
# Object files
OBJECTS=$(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Include directories
INCDIRS=$(shell find include -type d)
INCFLAGS=$(addprefix -I,$(INCDIRS))

# Default rule to build executable
all: $(EXECUTABLE)

# Rule to build executable
$(EXECUTABLE): $(OBJECTS)
	@printf '\nCompilando y enlazando $(@) \nObjetos a enlazar: $(?) \n\n'; \
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@printf 'Compilando $(<) \n'; \
	$(CC) $(CFLAGS) $(INCFLAGS) $< -o $@

# Clean rule to remove object files and executable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) 

valgrind:
	valgrind --leak-check=full ./$(EXECUTABLE)

entrega:
	zip -r 98_lab4.zip Makefile src include
