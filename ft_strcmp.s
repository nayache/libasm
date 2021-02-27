# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcmp.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nayache <nayache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 14:34:07 by nayache           #+#    #+#              #
#    Updated: 2021/02/25 14:34:09 by nayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global ft_strcmp

section .text

ft_strcmp:
		movzx rcx, byte [rdi]
		movzx rbx, byte [rsi]
		cmp rcx, rbx
		jne return_value
		cmp rcx, 0
		je return_value
		cmp rbx, 0
		je return_value
		inc rdi
		inc rsi
		jmp ft_strcmp

return_value:
		sub rcx, rbx
		mov rax, rcx
		ret

