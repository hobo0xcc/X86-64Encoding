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

# ModR/M
ModR/MはMode register / memoryの略で、レジスタとメモリの形式を指定します。

レジスタとメモリの形式というのは、例えば:

```nasm
mov  [eax+1], 10
```

このコードは、eaxに1を足したアドレスに10をムーブします。

```nasm
mov eax, 10
```

このコードはeaxに10をムーブします。

これらのような2つのコードのレジスタやメモリアドレスの形式を指定するのがModR/Mの役割です。

ModR/Mには3つのフィールドがあります。
以下にその3つのフィールドとその説明を示します。

| Field | Length |                                              Description                                              |
| ----- | ------ | ----------------------------------------------------------------------------------------------------- |
| Mod   | 2bit   | メモリアドレスの形式を指定します。                                                                    |
| Reg   | 3bit   | 2つのオペランドがどちらも直接、または間接的にレジスタを使用している場合に右側のレジスタを指定します。 |
| RM    | 3bit   | レジスタオペランドを指定します。これはメモリアドレスの形式に影響します。                              |

ModR/Mで指定できるメモリアドレスの形式を以下に示します。

<table>
<tr align="center">
    <th colspan=1>addr</th>
    <th>(REX.B).RM
</tr>
<tr align="center">
    <th colspan=1>Mod</th>
    <th>0.000<br>AX</th>
    <th>0.001<br>CX</th>
    <th>0.010<br>DX</th>
    <th>0.011<br>BX</th>
    <th>0.100<br>SP</th>
    <th>0.101<br>BP</th>
    <th>0.110<br>SI</th>
    <th>0.111<br>DI</th>
    <th>1.000<br>R8</th>
    <th>1.001<br>R9</th>
    <th>1.010<br>R10</th>
    <th>1.011<br>R11</th>
    <th>1.100<br>R12</th>
    <th>1.101<br>R13</th>
    <th>1.110<br>R14</th>
    <th>1.111<br>R15</th>
</tr>
<tr align="center">
    <th colspan=1>00</th>
    <td colspan=4>[R/M]</td>
    <td colspan=1>[SIB]</td>
    <td colspan=1>[RIP/EIP+disp32]</td>
    <td colspan=6>[R/M]</td>
    <td colspan=1>[SIB]</td>
    <td colspan=1>[RIP/EIP+disp32]</td>
    <td colspan=2>[R/M]</td>
</tr>
<tr align="center">
    <th colspan=1>01</th>
    <td colspan=4>[R/M+disp8]</td>
    <td colspan=1>[SIB+disp8]</td>
    <td colspan=7>[R/M+disp8]</td>
    <td colspan=1>[SIB+disp8]</td>
    <td colspan=3>[R/M+disp8]</td>
<tr align="center">
    <th colspan=1>10</th>
    <td colspan=4>[R/M+disp32]</td>
    <td colspan=1>[SIB+disp32]</td>
    <td colspan=7>[R/M+disp32]</td>
    <td colspan=1>[SIB+disp32]</td>
    <td colspan=3>[R/M+disp32]</td>
</tr>
<tr align="center">
    <th colspan=1>11</th>
    <td colspan=16>R/</td>
</tr>
</table>