	.arch msp430g2553
	.p2align 1,0		        ; set memory boundary of 2 bytes with padding of zeroes

	.text
	.align 2
	.global drawMc
	.extern drawPixel
	.extern fillRectangle

drawMc:
	mov #10, r12
	mov #150, r13
	mov 0x0000, r14
	call #drawPixel
 	pop r0
