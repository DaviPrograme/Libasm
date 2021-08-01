bits 64

global ft_strcpy

section .text:
		ft_strcpy:
			xor rcx, rcx
			.while:
				mov dl, byte[rsi+rcx]
				mov [rdi+rcx], dl
				cmp dl, byte 0
				je .return
				inc rcx
				jmp .while
			.return:
				mov [rdi + rcx], byte 0
				mov rax, rdi
				ret
