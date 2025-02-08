# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 00:52:49 by jjhang            #+#    #+#              #
#    Updated: 2024/10/04 14:06:20 by jjhang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
CPP_FLAGS = -std=c++98 -Wall -Wextra -Werror -g -fsanitize=address
NAME = Harl2\.0

SRCS_DIR = ./

OBJ_DIR = obj

SRCS_FILES = main.cpp \
			Harl.cpp

HEADER = ./

SRCS_SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(SRCS_FILES:%.cpp=$(OBJ_DIR)/%.o)


all : $(NAME)

$(NAME) : $(OBJS)
	@$(CPP) $(CPP_FLAGS) -o $(NAME) $^
	@echo ✅[$(NAME)] has been built

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CPP_FLAGS) -c -o $@ $<

$(OBJ_DIR) :
	@mkdir -p $@

clean :
	@rm -f $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re