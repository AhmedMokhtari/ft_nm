NAME = ft_nm

SRC_O = main.o 

CFLAGS = -Wall -Wextra -Werror  -fsanitize=leak -g

all : $(NAME)

$(NAME) : $(SRC_O)
	gcc $(CFLAGS) $(SRC_O) -o $(NAME)

%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

clean : 
	rm -rf $(SRC_O)

fclean : clean
	rm -rf $(NAME)

re : fclean all
