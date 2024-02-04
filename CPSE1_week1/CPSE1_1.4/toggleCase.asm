.cpu cortex-m0
.text
.align 2
.global toggleCase

toggleCase:
    push { lr }
    cmp r0, #'A'
    bge checkUpper
    b checkLower1
checkUpper:
    cmp r0, #'Z'
    ble makeLower
    b checkLower1
checkLower1:
    cmp r0, #'a'
    bge checkLower2
    b done
checkLower2:
    cmp r0, #'z'
    ble makeUpper
    b done
makeLower:
    add r0, #32
    b done
makeUpper:
    sub r0, #32
    b done
done:
    pop { pc }

    