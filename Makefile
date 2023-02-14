# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 18:49:05 by yoel-idr          #+#    #+#              #
#    Updated: 2023/02/14 23:37:38 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := gc_memory.a

FLAGS := -Wall -Wextra -Werror

SRCS  := srcs/
INC   := include
FILES := $(addprefix $(SRCS), gc_memory.c)
OBJS  := $(FILES:.c=.o)

OBJ_COLOR   		:= \033[0;36m
OK_COLOR    		:= \033[0;32m
NO_COLOR    		:= \033[m
OK_STRING    		:= "[OK]"

all : $(NAME)
		@printf "%b               %b\n" "$(OBJ_COLOR)GC_MEMORY$(NO_COLOR)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)"

$(NAME) : $(OBJS)
	@ar -rc $@ $^
	
.c.o : 
		@cc $(FLAGS) -c $< -o $@ -I $(INC)

clean : 
		@printf "%b        %b\n" "$(OBJ_COLOR)Deleting objects$(NO_COLOR)" "$(OK_COLOR)$(OK_STRING)$(RESET)"
		@rm -rf $(OBJS)
fclean : clean
		@printf "%b     %b\n" "$(OBJ_COLOR)Deleting everything$(NO_COLOR)" "$(OK_COLOR)$(OK_STRING)$(RESET)"
		@rm -drf $(NAME)

re : fclean all