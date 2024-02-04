.cpu cortex-m0
.text
.align 2
.global application

text:
    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"

application:
    ldr r0, =text
    bl print_asciz

    