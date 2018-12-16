# 概要
x86-64の命令は、基本的に以下のような並びになります。
命令やオペランドによって値が存在しない(0byte)場合があります。

- Legacy prefix (0 - 4byte)
- REX prefix (0 - 1byte)
- Opcode (1 - 3byte)
- ModR/M (0 - 1byte)
- SIB (0 - 1byte)
- Displacement (0 - 1byte)
- Immediate(0, 1, 2, 4, 8byte)