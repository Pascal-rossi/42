NAME = push_swap.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCFILES = arr_sort.c\
			big_sort.c\
			cost_calculations.c\
			fill_list.c\
			free_memo.c\
			ft_atoi.c\
			ft_split.c\
			input_parsing.c\
			is_digit.c\
			move_nodes.c\
			nodes_utils.c\
			push_swap_rules1.c\
			push_swap_rules2.c\
			push_swap_rules3.c\
			push_swap.c\
			sort_3_4.c\
			sort_5.c\
			sort_utils.c\

OBJFILES = $(SRCFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	@$(AR) $(NAME) $(OBJFILES)

%.o: %.c printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJFILES)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re