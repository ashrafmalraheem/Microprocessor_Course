	.file	"main.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	__vector_13
	.type	__vector_13, @function
__vector_13:
	push r1
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
/* prologue: Signal */
/* frame size = 0 */
/* stack size = 3 */
.L__stack_usage = 3
	sbi 0x3,5
/* epilogue start */
	pop r0
	out __SREG__,r0
	pop r0
	pop r1
	reti
	.size	__vector_13, .-__vector_13
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	lds r24,i
	subi r24,lo8(-(1))
	sts i,r24
	sbi 0x4,5
	ldi r30,lo8(-127)
	ldi r31,0
	ld r24,Z
	ori r24,lo8(2)
	st Z,r24
	ld r24,Z
	ori r24,lo8(1)
	st Z,r24
	ldi r30,lo8(111)
	ldi r31,0
	ld r24,Z
	ori r24,lo8(1)
	st Z,r24
/* #APP */
 ;  45 "main.c" 1
	sei
 ;  0 "" 2
/* #NOAPP */
.L3:
	rjmp .L3
	.size	main, .-main
	.comm	i,1,1
	.ident	"GCC: (AVR_8_bit_GNU_Toolchain_3.5.1_1671) 4.9.2"
.global __do_clear_bss
