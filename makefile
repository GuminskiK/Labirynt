all:
	gcc main.c mazePreanalyzer.c mazePreanalyzer.h fileReader.c fileReader.h mazeAnalyzer.c mazeAnalyzer.h define.h edge.h graphCreator.c graphCreator.h

clean: 
	rm *.gch
