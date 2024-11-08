NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rc

SRCS	= ft_printf.c ft_printf_funcs.c ft_printf_funcs2.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(B_OBJS)
	$(AR) $(NAME) $(B_OBJS)

clean:
	$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	$(RM) $(NAME) $(OBJS) $(B_OBJS)

re: fclean all

.PHONY: all re clean fclean bonus