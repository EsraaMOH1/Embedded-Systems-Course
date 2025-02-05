.synatax unified
.equ GPIO_BASE,0x40022000
.equ GPIO_DOE, GPIO_BASE+0XD0
.equ GPIO_DOUT31_0,GPIO_BASE+0XB0

.equ ioc,0x40081000
.equ ioc_13,ioc+0x34

.global lab_4

lab_4:

ldr r0,=GPIO_DOE
ldr r1,[r0]
mov r2,#1
lsl r2,#6
orr r1, r1,r2
str r1,[r0]


ldr r0,=ioc_13
ldr r1,[r0]

mov r2,#1
lsl r2,#13
and r1,r1,r2
str r1,[r0]

cmp [r0],#0
myloop:


stop: B stop

