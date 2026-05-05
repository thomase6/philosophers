# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/29 08:46:26 by texenber          #+#    #+#              #
#    Updated: 2026/05/05 09:46:34 by texenber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

#ingredients

SRC 		=	main.c		\
				utils.c		\
				parse.c		\
				init.c		\
				time.c		\
				cleanup.c	
SRCS		=	$(addprefix $(PRE), $(SRC))
PRE			=	./src/
HEAD		=	./inc/
CC			=	cc
WARN		=	-Wall -Werror -Wextra 
TFLAGS		=	-pthread
ifeq ($(NOWARN), 1)
	WARN	=
endif
CFLAGS		=	$(WARN) $(TFLAGS)
DFLAGS		=	-g
ODIR		=	obj/
OBJS		=	$(SRCS:$(PRE)%.c=$(ODIR)%.o)

#utensils
RM			=	rm -f
MAKEFLAGS	+=	--no-print-directory
DIR_DUP		=	mkdir -p $(@D)

#recipe
all:		$(NAME)

$(ODIR)%.o:	$(PRE)%.c
			@$(DIR_DUP)
			@$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $@

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -I $(HEAD) $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS)
			@rm -rf $(ODIR)
			
fclean:		clean
			@$(RM) $(NAME)

debug:		
			@$(MAKE) CFLAGS="$(CFLAGS) $(DFLAGS)" re

re:			fclean all clean

.PHONY:		all clean fclean debug re