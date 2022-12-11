# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Rules.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/05 14:02:20 by jgo               #+#    #+#              #
#    Updated: 2022/12/11 21:03:22 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL = all

ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -MMD -MP

PIPEX = pipex
NAME = $(PIPEX)

# verbose
Q := $(if $(filter 1,$(V) $(VERBOSE)),,@)

# debug
ifdef DEBUG
	CFLAGS += -g3
endif

# just compile
ifdef JUST
	CFLAGS = -MMD -MP
endif

link_files:: unlink_files
	mkdir -p $(dst_dir);
	$(foreach file,$(files), ln -sf $(src_dir)/$(file) $(dst_dir);)

unlink_files::
	$(foreach file,$(files), $(RM) $(dst_dir)/$(file);)
