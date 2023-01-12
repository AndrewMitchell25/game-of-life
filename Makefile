CMP = gcc
MAIN = playlife
FUNC = lifefunc
EXEC = playlife

$(EXEC): $(FUNC).o $(MAIN).o 
	$(CMP) $(FUNC).o $(MAIN).o -lm -o $(EXEC)

$(FUNC).o: $(FUNC).c $(FUNC).h 
	$(CMP) -c $(FUNC).c -o $(FUNC).o -std=c11 -D_XOPEN_SOURCE=600 -D_POSIX_C_SOURCE=200112L

$(MAIN).o: $(MAIN).c $(FUNC).h
	$(CMP) -c $(MAIN).c -o $(MAIN).o -std=c11

clean:
	rm *.o
	rm $(EXEC)