NAME := cub3d

CC := cc
CFLAGS := -Wall -Wextra -Werror -I.

RESET = \033[0m
GREEN = \033[32m
BLUE = \033[34m

SRC_DIR := render parsing gnl
LIBFT_DIR := libft
MLX_DIR := minilibx-linux
GNL := gnl/get_next_line.c gnl/get_next_line_utils.c

SRCS := render/cub3d.c parsing/copy_map.c parsing/manage_map.c parsing/parsing_map.c parsing/utils_parsing.c \
	render/checker.c render/drawer.c render/fryer.c render/initialisation.c \
	render/manager.c render/mlx_utils.c render/movement.c render/render_ray.c  render/render.c\
	render/sprites_manager.c render/sprites.c render/texture.c render/utils.c crosshair/crosshair.c \
	parsing/parsing_bonus.c
OBJS := $(SRCS:.c=.o)
LIBRARY = -L/usr/X11R6/lib -lX11 -lXext -lXrandr -lXi -lXfixes

LIBFT := $(LIBFT_DIR)/libft.a
MLX := $(MLX_DIR)/libmlx.a
GNL_OBJ := $(GNL:.c=.o)
all: banner $(NAME)

banner:
	@echo "$(BLUE)Compiling cub3d by tgerardi and a little bit of romlambe...$(RESET)"

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(GNL_OBJ)
	@echo "$(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(GNL_OBJ) -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lm $(LIBRARY)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@ rm -rf $(OBJS) $(GNL_OBJ)
	@echo "$(BLUE)Cleaned up!$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(BLUE)Full cleaned up!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
