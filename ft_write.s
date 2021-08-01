bits 64

global ft_write
extern __errno_location
section .text

	ft_write:
		mov rax, 1
		syscall
		cmp rax, 0
		jl .error
		ret
		.error:
			neg rax
			push rax
			call __errno_location
			pop r8
			mov [rax], r8
			mov rax, -1
			ret	
