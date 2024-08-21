# Nome do executável
EXEC = bin/autocompletar

# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I./include

# Diretório de origem
SRCDIR = src
INCDIR = include
BINDIR = bin

# Arquivos fonte
SRCS = $(wildcard $(SRCDIR)/*.cpp)
# Arquivos objeto
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)

# Regra principal
all: $(EXEC)

# Como compilar o executável
$(EXEC): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Como compilar arquivos objeto
$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos gerados
clean:
	rm -f $(BINDIR)/*.o $(EXEC)

.PHONY: all clean
