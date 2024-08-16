# Makefile para compilar o projeto

# Nome do executável
EXEC = programa

# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Arquivos fonte
SRCS = main.cpp Termo.cpp autocomplete.cpp

# Arquivos objetos
OBJS = $(SRCS:.cpp=.o)

# Regra principal
all: $(EXEC)

# Como compilar o executável
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Como compilar arquivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -f $(EXEC) $(OBJS)
