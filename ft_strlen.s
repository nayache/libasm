# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nayache <nayache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 14:33:51 by nayache           #+#    #+#              #
#    Updated: 2021/02/27 06:36:13 by nayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text

global ft_strlen

ft_strlen:
		mov rcx, 0
		
_loop:
		cmp byte [rdi], 0
		je return_value
		inc rcx
		inc rdi
		jmp _loop

return_value:
		mov rax, rcx
		ret
