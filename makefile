all:
	gcc main.c mazePreanalyzer.c mazePreanalyzer.h fileReader.c fileReader.h mazeAnalyzer.c mazeAnalyzer.h define.h graphCreator.c graphCreator.h fileWriter.c fileWriter.h

clean: 
	rm *.gch
dwa:
	gcc main2.c graphReader.c graphReader.h node.h solveMaze.c solveMaze.h solutionWriter.c solutionWriter.h
