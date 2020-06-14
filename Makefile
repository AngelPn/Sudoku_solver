OBJS= sudoku_solver.o
CFLAGS = -g -Wall -I.
PROGRAM= solve_sudoku

$(PROGRAM): clean $(OBJS)
	g++ -g $(OBJS) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM) $(OBJS)