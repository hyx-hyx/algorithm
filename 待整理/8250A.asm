;filename 8250A.asm
.486
DATA SEGMENT USE16
INPUTBUF DB 125
         DB ?
         DB 125 DUP(?)
DATA ENDS
CODE SEGMENT USE16
    ASSUME CS:CODE,DS:DATA
BEG: MOV AX,DATA
MOV DS,AX

CALL READ
CALL I8250
MOV DL,0DH
MOV AH,02H
INT 21H
MOV DL,0AH
MOV AH,02H          ;调用DOS02号功能，显示0x0D,0x0A字符，即换行。
INT 21H
CALL SEND

MOV AX,4CH
INT 21H


READ PROC
MOV DX,OFFSET INPUTBUF
MOV AH,0AH
INT 21H
RET
READ ENDP

I8250 PROC
MOV DX,3FBH
MOV AL,80H
OUT DX,AL      ;设置寻址位为1，访问除数寄存器

MOV DX,3F9H
MOV AL,00H
OUT DX,AL
MOV DX,3F8H
MOV AL,0CH
OUT DX,AL      ;设置通信速率为9600波特，除数寄存器为000CH

MOV DX,3FBH
MOV AL,03H
OUT DX,AL       ;规定一帧数据的格式

MOV DX,3F9H
MOV AL,0
OUT DX,AL       ;采用查询方式，设置中断允许控制字为全0

MOV DX,3FCH
MOV AL,10H
OUT DX,AL       ;设置MODEM寄存器，工作方式为内环自检
RET
I8250 ENDP


SEND PROC
MOV BX,OFFSET INPUTBUF
MOV CH,0
MOV CL,[BX+1]
ADD CL,1
SCAN:
    MOV DX,3FDH
    IN AL,DX
    TEST AL,00011110B ;获取通信线状态字寄存器的值
    JNZ PROCEND       ;如果D1~D4为1，说明通信线出现错误，子程序终止
    CMP CX,0
    JZ PROCEND        ;如果cx为0,说明字符已发送完，子程序终止
SENDCHAR:
    MOV DX,3FDH       
    IN AL,DX
    TEST AL,20H       ;查询通信线状态字寄存器，如果D5位为1，代表发送保持寄存器空闲
    JZ SENDCHAR       ;如果D5位不为1,则重复查询过程以等待发送完成。
    MOV DX,3F8H         
    MOV AL,[BX+2]     
    OUT DX,AL
    INC BX
    SUB CX,1
RECV:    
    MOV DX,3FDH
    IN AL,DX
    TEST AL,01H        ;查询通信线状态字寄存器，如果D5位为1，代表发送保持寄存器空闲
    JZ RECV            ;如果D5位不为1,则重复查询过程以等待发送完成。 
    MOV DX,3F8H        
    IN  AL,DX
    MOV DL,AL
    MOV AH,02H         ;调用DOS02号功能，显示字符。
    INT 21H
    JMP SCAN         
PROCEND:
    RET

SEND ENDP

CODE ENDS
    END BEG
