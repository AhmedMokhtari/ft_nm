NAME = ft_nm

SRC_O = main.o 

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC_O)
	cc $(CFLAGS) $(SRC_O) -o $(NAME)

%.o : %.c
	cc -c $(CFLAGS) $< -o $@

clean : 
	rm -rf $(SRC_O)

fclean : clean
	rm -rf $(NAME)

re : fclean all
