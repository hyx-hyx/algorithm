;filename 8254.asm
.486
CODE SEGMENT USE16
    ASSUME CS:CODE
BEG: 
    MOV AL,00110110B  ;控制字:选择0号计数器;写入时先写低8位，再写高8位；技数器工作在方式3；数制为二进制。
    MOV DX,213H  ;控制字写入地址为213H
    OUT DX,AL   ;向213H写入控制字
    MOV AL,10H   
    MOV DX,210H  ;0号计数器地址为210H
    OUT DX,AL
    MOV AL,27H
    OUT DX,AL    ;写入的数字大小为2710H，即10000D，外部输入时钟为100k，所以0号计数器工作在10Hz。

    MOV AL,01110110B   ;控制字:选择1号计数器;写入时先写低8位，再写高8位；技数器工作在方式3；数制为二进制。
    MOV DX,213H         ;控制字写入地址为213H
    OUT DX,AL           ;向213H写入控制字
    MOV AL,0D0H
    MOV DX,211H         ;1号计数器地址为211H
    MOV AL,07H
    OUT DX,AL     ;写入的数字大小为7D0H，即2000D，外部输入时钟为10k，所以1号计数器工作在5Hz。

    MOV AL,10110110B    ;控制字:选择2号计数器;写入时先写低8位，再写高8位；技数器工作在方式3；数制为二进制。
    MOV DX,213H       ;控制字写入地址为213H
    OUT DX,AL         ;向213H写入控制字
    MOV AL,0E8H
    MOV DX,212H       ;2号计数器地址为212H
    MOV AL,03H
    OUT DX,AL          ;写入的数字大小为3E8H，即1000D，外部输入时钟为1k，所以2号计数器工作在1Hz。
CIRCLE: 
    JMP CIRCLE          ;进入死循环。
    MOV AL,4CH
    INT 21H
CODE ENDS
END BEG 