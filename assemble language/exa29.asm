.486
DATA SEGMENT USE16
BUF DB 'BCDEBCDEAG'
LL EQU $-BUF  ;得到字符串的长度
SUM DB 0
DATA ENDS
CODE SEGMENT USE16
    ASSUME CS:CODE,DS:DATA
BEG:
    MOV AX,DATA
    MOV DS,AX
    CALL COMPARE  ;调用COMPARE子程序对符合条件的字符计数
    CALL BINARY   ;调用BINARY子程序将得到的十进制数转化为二进制并显示
FINISH:  
    MOV AH,4CH
    INT 21H

COMPARE PROC
    MOV BX,OFFSET BUF
    MOV CX,LL             ;循环次数就是字符串的长度
LESS:
    CMP BYTE PTR [BX],42H ;跟42H比较，小于跳转下一个字符
    JC NEXT
GREATER:
    CMP BYTE PTR [BX],46H ;跟45H比较，大于跳转下一个字符
    JNC NEXT
    INC SUM
NEXT:
    INC BX      ;BX寄存器值加一，为下一位字符的比较做准备
    LOOP LESS
    RET
COMPARE ENDP

BINARY PROC
    MOV CX,8    ;显示位数为8位二进制位
    MOV BL,SUM
TESTBIT:
    RCL BL,1    ;循环左移,C标志==1输出'1'，==0输出'0'
    JC ONE      
    MOV AH,02H  ;调用DOS 02号功能
    MOV DL,30H  ;将'0'写入DL寄存器
    INT 21H     ;产生中断，调用DOS执行02号功能
    LOOP TESTBIT
    RET
ONE:
    MOV AH,02H
    MOV DL,31H
    INT 21H 
    LOOP TESTBIT  
    RET
BINARY ENDP
CODE ENDS
    END BEG