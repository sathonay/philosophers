SRC_FOLDER	= ./
SRC=	\
	life.c \
	philo.c \
	atol.c \
	time.c \
	init.c \
	print.c \
	mutex.c \
	util_function.c \

OBJ_FOLDER=objects/
OBJ		=$(addprefix $(OBJ_FOLDER), $(SRC:.c=.o))


CC = cc
FLAGS=-Wall -Wextra -Werror # -g -fsanitize=thread #-fno-sanitize=thread

NAME = philo

SHELL = bash

RESET	= \x1b[1;0m
BLACK	= \x1b[1;30m
RED		= \x1b[1;31m
GREEN	= \x1b[1;32m
YELLOW	= \x1b[1;33m
BLUE	= \x1b[1;34m
PURPLE	= \x1b[1;35m
CYAN	= \x1b[1;36m
WHITE	= \x1b[1;37m

BORDER_C = $(PURPLE)

OVERLAP = 3

CAT_C = $(PURPLE)
CATE_C = $(RED)

define box
	@tput civis
	$(if $(filter $(3), 0), ,@tput cuu $(3))
	@printf "$(BORDER_C)%s%s%s%16s\n" "╘╪" "─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─" "╪╛" ""
	@printf "%-20s $(1)%-29s$(RESET)$(BORDER_C)%s%16s\n" "╞╫" "$(2)" "╫╡" ""
	@printf "%s%s%s$(RESET)%16s\n" "╒╪" "─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─═─" "╪╕" ""
	@tput cnorm	
endef

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.c | cat
	$(call box, $(YELLOW), $<, 0)
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(FLAGS) -c $< -o $@
	$(call box, $(GREEN), $<, $(OVERLAP))

$(NAME): $(OBJ) | cat
	$(call box, $(YELLOW), BUILDING EXECUTABLE..., 0)
	@$(CC) $(FLAGS) -o $@ $(OBJ)
	$(call box, $(GREEN), BUILDING EXECUTABLE, $(OVERLAP))


$(LIBFT_LIB): | cat
	$(call box, $(YELLOW), BUILDING LIBFT..., 0)
	@make --silent -C $(LIBFT_DIR)
	$(call box, $(GREEN), LIBFT BUILD SUCCESS, $(OVERLAP))

cat: 
	@echo -e "$(CAT_C)⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀ "
	@echo -e "$(CAT_C)⠀⠀⠀⠀⢀⡴⣆⠀⠀⠀⠀⠀⣠⡀⠀⠀⠀⠀⠀⠀⣼⣿⡗⠀⠀⠀⠀"
	@echo -e "$(CAT_C)⠀⠀⠀⣠⠟⠀⠘⠷⠶⠶⠶⠾⠉⢳⡄⠀⠀⠀⠀⠀⣧⣿⠀⠀⠀⠀⠀"
	@echo -e "$(CAT_C)⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣤⣤⣤⣤⣤⣿⢿⣄⠀⠀⠀⠀"
	@echo -e "$(CAT_C)⠀⠀⡇⠀$(CATE_C)x⠀⠀⠀⠀⠀x$(CAT_C)⠀⠀⠀⠀⣧⠀⠀⠀⠀⠀⠀⠙⣷⡴⠶⣦"
	@echo -e "$(CAT_C)⠀⠀⢱⡀⠀ ⠉⠉⠀⠀⠀  ⠀⢠⡟⠂⠀⠀⢀⣀⣠⣤⠿⠞⠛⠋"
	@echo -e "$(CAT_C)⣠⠾⠋⠙⣶⣤⣤⣤⣤⣤⣀⣠⣤⣾⣿⠴⠶⠚⠋⠉⠁⠀⠀⠀⠀⠀⠀"
	@echo -e "$(CAT_C)⠛⠒⠛⠉⠉⠀⠀⠀⣴⠟⣣⡴⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo -e "$(CAT_C)⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"

all: $(NAME)

re: cat clean all

clean: cat 
	$(call box, $(RED), CLEANING, 0)
	@rm -fr $(OBJ_FOLDER)
	$(call box, $(GREEN), CLEANING, $(OVERLAP))

fclean: cat clean
	$(call box, $(RED), CLEANING LIBS, 0)
	@rm -fr $(NAME)
	$(call box, $(GREEN), CLEANING LIBS, $(OVERLAP))

.PHONY: all re clean fclean cat
