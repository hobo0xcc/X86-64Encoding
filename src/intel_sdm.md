# Intel SDMのよみかた

---

*Intel® 64 and IA-32 Architectures Software Developer Manuals* (以下，Intel SDMと呼ぶ) という，Intelによる**Intel 64**の公式マニュアルみたいなものがあります。この記事では，そのIntel SDMの読み方について書いていきます。

## ダウンロード

[https://software.intel.com/en-us/articles/intel-sdm](https://software.intel.com/en-us/articles/intel-sdm) からダウンロードできます。Intel SDMには4つの章があり，一つ目がIntel 64アーキテクチャの概要的な紹介，二つ目が命令セットの詳しい情報，三つ目がIntel 64上でOSを開発する際に必要となる情報，四つ目がMSR (model-specific registers) に関する情報，というような具合に書かれています。

この記事では主にIntel SDMの二つ目の章の読み方について書きます。

## 命令表の読み方

Intel SDMのVolume 2: Instruction Set Referenceの 3.2, 4.3, 5.2 にそれぞれ，AからL，MからU，VからZの命令の表が書かれています。

それらの命令表には，以下のような情報が書かれています。

| Opcode            | Instruction      | Op/En | 64-Bit Mode | Compat/Leg Mode | Description          |
|:----------------- | ---------------- | ----- | ----------- |:--------------- | -------------------- |
| 88 /r             | MOV r/m8,r8      | MR    | Valid       | Valid           | Move r8 to r/m8.     |
| REX.W + B8+ rd io | MOV r64, imm64   | OI    | Valid       | N.E.            | Move imm8 to r8      |
| C7 /0 id          | MOV r/m32, imm32 | MI    | Valid       | Valid           | Move imm32 to r/m32. |

上記の表はMov命令の表の抜粋です。

### Opcodeの記号

Opcodeの記号とその説明を以下に書きます。

- REX.W
  
  64ビットのレジスタを使用する。

- /0-7
  
  ModR/Mのregフィールドをオペコードの拡張に使用する。r/mフィールドのみをオペランドに使用する。

- /r
  
  ModR/Mのr/mフィールドとregフィールドの両方を使用する。

- cb, cw, cd, cp, co, ct
  
  オペコードの後に，1バイト (cb), 2バイト (cw), 4バイト (cd), 6バイト (cp), 8バイト (co), 10バイト (ct) が続く。

- ib, iw, id, io
  
  オペコード，ModR/M，SIBのいずれかの後に，1バイト (ib), 2バイト (iw), 4バイト (id) or 8バイト (io) が続く。これらは即値として使用される。

- +rb, +rw, +rd, +ro
  
  オペコードに加算される0から7までのレジスタコード。

(書きかけ)


