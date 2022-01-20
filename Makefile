SRC = main.c pushto.c rotate.c swapa.c sort.c libft.a
B_SRC = checker_bonus.c pushto_bonus.c rotate_bonus.c swap_bonus.c \
get_next_line/get_next_line.c get_next_line/get_next_line_utils_bonus.c libft.a
BM_OBJ =  main.o pushto.o rotate.o swapa.o sort.o checker_bonus.o \
libft.a get_next_line/get_next_line.o get_next_line/get_next_line_utils_bonus.o
CC = cc
NAME = push_swap
B_NAME = checker

all :
	cd Libft && make && make bonus && cd .. && mv Libft/libft.a .
	$(CC) $(SRC) -o $(NAME)
clean :
	cd Libft && make clean && cd .. && rm -f $(BM_OBJ)
fclean : clean
	rm $(NAME) $(B_NAME)
re : fclean all bonus
bonus :
	$(CC) $(B_SRC) -o $(B_NAME)