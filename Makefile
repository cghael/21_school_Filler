# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghael <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 12:00:54 by cghael            #+#    #+#              #
#    Updated: 2020/07/24 12:00:57 by cghael           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker
NAME_VS = visual

CC = gcc
FLAGS = -Wall -Werror -Wextra

LIBRARIES_PS = -lftprintf -L$(LIBFTPRINTF_DIR) -lft -L$(LIBFT_DIR)
INCLUDES_PS = -I$(HEADERS_DIR) -I$(LIBFTPRINTF_HEADERS) -I$(LIBFT_HEADERS)
LIBRARIES_MLX = -lmlx -L$(MINILIBX_DIRECTORY) \
				-framework OpenGL -framework AppKit
INCLUDES_MLX = -I$(MINILIBX_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./ft_printf/libft/
LIBFT_HEADERS = $(LIBFT_DIR)inc/

LIBFTPRINTF = $(LIBFTPRINTF_DIR)libftprintf.a
LIBFTPRINTF_DIR = ./ft_printf/
LIBFTPRINTF_HEADERS = $(LIBFTPRINTF_DIR)includes/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADERS_LIST = push_swap.h \
				visual.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = src/
SRC_LIST = ft_check_n_write_args.c \
			ft_one_agr.c \
			ft_multi_arg.c \
			ft_new_elem_add.c \
			ft_free_stack.c \
			ft_sort_stacks.c \
			ft_check_stack_sorted.c \
			ft_print_operations.c \
			ft_new_order_add.c \
			ft_free_cmd_stack.c \
			ft_free_push_swap_mem.c \
			ft_pa_pb.c \
			ft_print_stack_step.c \
			ft_ra_rb.c \
			ft_rra_rrb.c \
			ft_sa_sb.c \
			ft_create_t_st_elem.c \
			ft_sort_two_three_elem.c \
			ft_start_sorting.c \
			ft_get_stack_back.c \
			ft_choose_optimal_step.c \
			ft_count_steps.c \
			ft_rr_rrr.c \
			ft_count_ra_rb.c \
			ft_count_rra_rrb.c \
			ft_presort_stack.c \
			ft_min_steps_count.c \
			ft_run_cmd.c \
			ft_create_cmd.c \
			ft_get_push_swap.c \
			ft_max_min_int.c
SRC_LIST_PS = push_swap.c
SRC_LIST_CH = checker.c
SRC_LIST_VS = visual.c \
			ft_get_vis.c \
			ft_draw.c \
			ft_draw_stacks.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
SRC_PS = $(addprefix $(SRC_DIR), $(SRC_LIST_PS))
SRC_CH = $(addprefix $(SRC_DIR), $(SRC_LIST_CH))
SRC_VS = $(addprefix $(SRC_DIR), $(SRC_LIST_VS))

OBJ_DIR = objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ_LIST_PS = $(patsubst %.c, %.o, $(SRC_LIST_PS))
OBJ_LIST_CH = $(patsubst %.c, %.o, $(SRC_LIST_CH))
OBJ_LIST_VS = $(patsubst %.c, %.o, $(SRC_LIST_VS))

OBJ	= $(addprefix $(OBJ_DIR), $(OBJ_LIST))
OBJ_PS	= $(addprefix $(OBJ_DIR), $(OBJ_LIST_PS))
OBJ_CH	= $(addprefix $(OBJ_DIR), $(OBJ_LIST_CH))
OBJ_VS	= $(addprefix $(OBJ_DIR), $(OBJ_LIST_VS))

# COLORS

GRN = \033[0;32m
RED = \033[0;31m
YEL = \033[1;33m
END = \033[0m

.PHONY: all clean fclean re

all: $(NAME_PS) $(NAME_CH) $(NAME_VS)

$(NAME_PS): $(LIBFTPRINTF) $(OBJ_DIR) $(OBJ) $(OBJ_PS)
	@$(CC) $(FLAGS) $(LIBRARIES_PS) $(INCLUDES_PS) \
												$(OBJ) $(OBJ_PS) -o $(NAME_PS)
	@echo "\n$(NAME_PS): $(GRN)$(NAME_PS) object files were created$(RESET)"
	@echo "$(NAME_PS): $(GRN)$(NAME_PS) was created$(RESET)"

$(NAME_CH): $(LIBFTPRINTF) $(OBJ_DIR) $(OBJ) $(OBJ_CH)
	@$(CC) $(FLAGS) $(LIBRARIES_PS) $(INCLUDES_PS) \
												$(OBJ) $(OBJ_CH) -o $(NAME_CH)
	@echo "\n$(NAME_CH): $(GRN)$(NAME_CH) object files were created$(RESET)"
	@echo "$(NAME_CH): $(GRN)$(NAME_CH) was created$(RESET)"

$(NAME_VS): $(LIBFTPRINTF) $(MINILIBX) $(OBJ_DIR) $(OBJ) $(OBJ_VS)
	@$(CC) $(FLAGS) $(LIBRARIES_PS) $(LIBRARIES_MLX) \
				$(INCLUDES_PS) $(INCLUDES_MLX) $(OBJ) $(OBJ_VS) -o $(NAME_VS)
	@echo "\n$(NAME_VS): $(GRN)$(NAME_VS) object files were created$(RESET)"
	@echo "$(NAME_VS): $(GRN)$(NAME_VS) was created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME_PS): $(GRN)$(OBJ_DIR) created$(END)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES_PS) $< -o $@
	@echo "$(GRN).$(END)\c"

$(LIBFTPRINTF):
	@echo "$(NAME_PS): $(GRN)Creating $(LIBFTPRINTF)...$(END)"
	@$(MAKE) -C $(LIBFTPRINTF_DIR)

$(MINILIBX):
	@echo "$(NAME_PS): $(GREEN)Creating $(MINILIBX)...$(RESET)"
	@$(MAKE) -C $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBFTPRINTF_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME_PS): $(RED)$(OBJ_DIR) deleted$(END)"
	@echo "$(NAME_PS): $(RED)*.o files deleted$(END)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(LIBFTPRINTF_DIR) fclean
	@rm -f $(NAME_PS)
	@echo "$(NAME_PS): $(RED)$(NAME_PS) deleted$(END)"
	@rm -f $(NAME_CH)
	@echo "$(NAME_CH): $(RED)$(NAME_CH) deleted$(END)"
	@rm -f $(NAME_VS)
	@echo "$(NAME_VS): $(RED)$(NAME_VS) deleted$(END)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
