
.cpu cortex-m0
.data
buffer: .skip 10*10 //https://www.cs.emory.edu/~cheung/Courses/255/Syllabus/7-ARM/array-define.html
.text
.align 2
.global lz_decompressor

lz_decompressor:
	push { r4-r7,lr }
	ldr r4, =lz_compressor

loop:
	ldrb r5, [r4]
	cmp r5, #0
	beq done

	cmp r5, #'@'
	bne addCharParameter

	add r4, r4, #1
	ldrb r6, [r4] //offset (no migos)
	add r4, r4, #1
	ldrb r7, [r4] //length
	sub r6, r6, #'0'
	sub r7, r7, #'0'
	ldr r5, =buffer

addMatch:
	ldrb r0, [r5, r6]
	bl createBuffer
	sub r7, r7, #1
	cmp r7, #0
	bne addMatch
	add r4, r4, #1
	b loop

addCharParameter:
	mov r0, r5
	bl createBuffer
	add r4, r4, #1
	b loop

createBuffer:
	ldr r1, =buffer
	mov r2, #100

addChar:
	sub r2, r2, #1
	sub r2, r2, #1
	ldrb r3, [r1, r2]
	add r2, r2, #1
	strb r3, [r1, r2]
	cmp r2, #0
	bgt addChar
	strb r0, [r1, #0]
	b uart_put_char

done:
	mov pc, lr
	pop {r4-r7, pc}