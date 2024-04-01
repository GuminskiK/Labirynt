all: preprocessor analyzer

preprocessor: main.o mazePreanalyzer.o fileReader.o mazeAnalyzer.o define.h graphCreator.o fileWriter.o
	gcc $(CFLAGS) -o $@ $^

analyzer: main2.o graphReader.o node.h solveMaze.o solutionWriter.o
	gcc $(CFLAGS) -o $@ $^

%.o: %.c $(INC_DIR)/*.h
	$(CC) $(CFLAGS) -I include -c -o $@ $<

clean:
	rm -f preprocessor analyzer *.o

run_1: preprocessor 
	time ./preprocessor $(src)
run_2: analyzer run_1
	time ./analyzer out
