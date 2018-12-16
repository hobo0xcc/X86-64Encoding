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

## Legacy prefix
各命令には、最大4つのプリフィックスをつけることができます。
4つのグループがあり、1つのグループにつき1つ使うことができます。

使えるプリフィックスを以下に示します。

- Prefix group 1
    - 0xF0
    - 0xF2
    - 0xF3
- Prefix group 2
    - 0x2E
    - 0x36
    - 0x3E
    - 0x26
    - 0x64
    - 0x65
    - 0x2E
    - 0x3E
- Prefix group 3
    - 0x66
- Prefix group 4
    - 0x67

それぞれに意味がありますが、よく使うのは0x66と0x67くらいです。

# REX prefix
REX prefixは、64bitのオペランドか、拡張レジスタを使用する場合などにつけられます。

REX prefixは、最初の4bitが`0100`で始まり、残りの1bit * 4(4bit)でプリフィックスを表現します。最後の4bitは1bitずつ左からW, R, X, Bと呼ばれます。

WRXBにはそれぞれ次のような意味があります。

| Field | Length |                                                  Description                                                  |
| :---: | :----: | :-----------------------------------------------------------------------------------------------------------: |
|   W   |  1bit  | この値が1の場合は64bitのオペランドサイズが使用されます。0の場合はデフォルトのオペランドサイズが使用されます。 |
|   R   |  1bit  |                拡張レジスタを使用する場合は1にします。0の場合は通常のレジスタが使用されます。                 |
|   X   |  1bit  |        SIBのbaseフィールドの拡張に使われます。1の場合はbaseで拡張レジスタを使用しての指定ができます。         |
|   B   |  1bit  |        ModR/Mのr/mフィールドの拡張に使われます。1の場合はr/mで拡張レジスタの使用しての指定ができます。        |

# Opcode
Opcodeは、命令を識別します。

[Intelのマニュアル](https://software.intel.com/en-us/articles/intel-sdm)に命令ごとのOpcodeの一覧が載っているので、これを参考にするか、あるいはndisasmやobjdumpなどの逆アセンブラを参考にするのが良いでしょう。