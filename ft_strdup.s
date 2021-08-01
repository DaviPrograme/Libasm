bits 64

global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc
extern __errno_location

section .text

ft_strdup:
	call ft_strlen ;como o rdi da strdup ja é a string eu chamo a strlen
	push rdi       ;como eu vou precisar chamar outra função eu guardo o valor do rdi (string)
	mov rdi, rax   ;eu passo para o rdi a quantidade de caracteres da string
	inc rdi
	call malloc
	cmp rax, 0
	je .error
	mov rdi, rax
	pop rsi
	call ft_strcpy
	ret
	.error:
		ret
		
