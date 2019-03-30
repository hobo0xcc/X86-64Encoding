# 概要
<!--

<table>
<tr align="center">
    <thead>
        <th colspan=1>addr</th>
        <th colspan=16>(REX.B).R/M</th>
    </thead>
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
    <td colspan=16>R/M</td>
</tr>
</table>

-->

<!--
<table>
<tr align="center">
    <thead>
        <th colspan=2></th>
        <th colspan=16>(REX.B).Base</th>
    </thead>
</tr>
<tr align="center">
    <th colspan=1>Mod</th>
    <th colspan=1>(REX.X).Index</th>
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
    <th rowspan=16 colspan=1>00</th>
    <th>0.000<br>AX</th>
    <td rowspan=4 colspan=5>[Base+(Index*Scale)]</td>
    <td rowspan=4 colspan=1>[(Index*Scale)+disp32]
    <td rowspan=4 colspan=7>[Base+(Index*Scale)]</td>
    <td rowspan=4 colspan=1>[(Index*Scale)+disp32]</td>
    <td rowspan=4 colspan=2>[Base+(Index*Scale)]</td>
</tr>
<tr align="center"><th>0.001<br>CX</th></tr>
<tr align="center"><th>0.010<br>DX</th></tr>
<tr align="center"><th>0.011<br>BX</th></tr>
<tr align="center">
    <th>0.100<br>SP</th>
    <td colspan=5>[Base]</td>
    <td colspan=1>[Disp32]</td>
    <td colspan=7>[Base]</td>
    <td>[Disp32]</td>
    <td colspan=2>[Base]</td>
</tr>
<tr align="center">
    <th>0.101<br>BP</th>
    <td rowspan=11 colspan=5>[Base+(Index*Scale)]</td>
    <td rowspan=11 colspan=1>[(Index*Scale) + Disp32]</td>
    <td rowspan=11 colspan=7>[Base+(Index*Scale)]</td>
    <td rowspan=11 colspan=1>[(Index*Scale)+Disp32]</td>
    <td rowspan=11 colspan=2>[Base+(Index*Scale)]</td>
</tr>
<tr align="center"><th>0.110<br>SI</th></tr>
<tr align="center"><th>0.111<br>DI</th></tr>
<tr align="center"><th>1.000<br>R8</th></tr>
<tr align="center"><th>1.001<br>R9</th></tr>
<tr align="center"><th>1.010<br>R10</th></tr>
<tr align="center"><th>1.011<br>R11</th></tr>
<tr align="center"><th>1.100<br>R12</th></tr>
<tr align="center"><th>1.101<br>R13</th></tr>
<tr align="center"><th>1.110<br>R14</th></tr>
<tr align="center"><th>1.111<br>R15</th></tr>

<tr align="center">
    <th rowspan=16 colspan=1>01</th>
    <th>0.000<br>AX</th>
    <td rowspan=4 colspan=16>[Base+(Index*Scale)+Disp8]</td>
</tr>
<tr align="center"><th>0.001<br>CX</th></tr>
<tr align="center"><th>0.010<br>DX</th></tr>
<tr align="center"><th>0.011<br>BX</th></tr>
<tr align="center">
    <th>0.100<br>SP</th>
    <td colspan=16>[Base+Disp8]</th>
</tr>
<tr align="center">
    <th>0.101<br>BP</th>
    <td rowspan=11 colspan=16>[Base+(Index*Scale)+Disp8]</td>
</tr>
<tr align="center"><th>0.110<br>SI</th></tr>
<tr align="center"><th>0.111<br>DI</th></tr>
<tr align="center"><th>1.000<br>R8</th></tr>
<tr align="center"><th>1.001<br>R9</th></tr>
<tr align="center"><th>1.010<br>R10</th></tr>
<tr align="center"><th>1.011<br>R11</th></tr>
<tr align="center"><th>1.100<br>R12</th></tr>
<tr align="center"><th>1.101<br>R13</th></tr>
<tr align="center"><th>1.110<br>R14</th></tr>
<tr align="center"><th>1.111<br>R15</th></tr>

<tr align="center">
    <th rowspan=16 colspan=1>10</th>
    <th>0.000<br>AX</th>
    <td rowspan=4 colspan=16>[Base+(Index*Scale)+Disp32]</td>
</tr>
<tr align="center"><th>0.001<br>CX</th></tr>
<tr align="center"><th>0.010<br>DX</th></tr>
<tr align="center"><th>0.011<br>BX</th></tr>
<tr align="center">
    <th>0.100<br>SP</th>
    <td colspan=16>[Base+Disp32]</td>
</tr>
<tr align="center">
    <th>0.101<br>BP</th>
    <td rowspan=11 colspan=16>[Base+(Index*Scale)+Disp32]</td>
</tr>
<tr align="center"><th>0.110<br>SI</th></tr>
<tr align="center"><th>0.111<br>DI</th></tr>
<tr align="center"><th>1.000<br>R8</th></tr>
<tr align="center"><th>1.001<br>R9</th></tr>
<tr align="center"><th>1.010<br>R10</th></tr>
<tr align="center"><th>1.011<br>R11</th></tr>
<tr align="center"><th>1.100<br>R12</th></tr>
<tr align="center"><th>1.101<br>R13</th></tr>
<tr align="center"><th>1.110<br>R14</th></tr>
<tr align="center"><th>1.111<br>R15</th></tr>
</table>

-->
