PROGRAM1 := CalcularPosicion
PROGRAM2 := OrdenarInsercionYMezcla
COMP := g++
FLAGS := -o

compilar: $(PROGRAM1) $(PROGRAM2)

$(PROGRAM1): $(PROGRAM1).cpp
	$(COMP) $(PROGRAM1).cpp $(FLAGS) $(PROGRAM1)

$(PROGRAM2): $(PROGRAM2).cpp
	$(COMP) $(PROGRAM2).cpp $(FLAGS) $(PROGRAM2)

run1: 
	./$(PROGRAM1)

run2: 
	./$(PROGRAM2)

clean:
	rm -f $(PROGRAM1) $(PROGRAM2)