# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 14:59:23 by msierra-          #+#    #+#              #
#    Updated: 2022/01/25 14:57:23 by msierra-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	philosopher

SRCS		=	./includes/ft_atoi.c	\
		  		./sources/cleaner.c		\
		  		./sources/parse.c		\
		  		./sources/philomanage.c	\
		  		./sources/philosopher.c	\
		  		./sources/state.c		\
		  		./sources/utils.c		\
		  		./sources/error.c		\

PINK = \033[1;35m
GREEN = \033[1;32m
BLUE = \033[1;36m
RESET = \033[0m

OBJS	= ${SRCS:.c=.o}

CC		= gcc

RM		= rm -rf

AR		= ar rcs

CFLAGS 	= -Wall -Werror -Wextra

all	:		$(NAME)

$(NAME)	:	start $(OBJS)
			@$(CC) $(OBJS) -o $(NAME) -fsanitize=address
			@echo "$(RESET)Done"
			@echo "$(GREEN)==========WELLDONE==========$(RESET)"
			@echo "Success creating $(NAME) file"

start:
			@echo "$(BLUE)==========CREATING: $(GREEN)$(NAME)$(BLUE)==========$(PINK)"

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:	
			$(RM) ${OBJS}

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
