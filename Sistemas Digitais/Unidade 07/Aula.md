# Circuitos Aritméticos e Plexers

## Circuitos Aritméticos

### Meio Somador

* **A expressão canônica da soma é um XOR(não do carry) em ambos circuitos**.

* Circuito derivado da tabela verdade da soma de dois bits, possuindo duas entradas(bits da soma) e duas saídas(soma e resto).

* Útil apenas para soma entre os bits menos significativos, pois não lida com o "vai 1" para os bits mais significativos, tornando a soma incompleta.

### Somador Completo

* Três bits de entrada, os dois da soma + um "vem 1", considerando a soma completa a partir das sobras da parte menos significativa.

* Mesma saída do outro circuito.

### Meio Subtrator

* Praticamente igual ao meio somador, duas entradas que serão os bits a serem subtraídos e duas saídas: subtração e vai 1.

* **A expressão canônica da saída referente à subtração também é um XOR**.

### Subtrator Completo

* Assim como o somador completo, subtrai os dois bits e o vem 1 da casa anterior, saídas serão a subtração e o vai 1.

## Plexers

* Mux e Demux são circuitos que entregam saídas com base em bits de seleção.

### Mux

* Várias entradas e uma saída.

* A quantidade de bits de seleção define a quantidade máxima de entradas aceitáveis.

* Ex: Se eu tiver três bits de seleção, significa que eu consigo selecionar um todo de oito entradas possíveis.

### Demux

* Oposto do mux, basicamente uma saída e várias entradas, em que os bits de seleção mapeiam a saída que deve receber o valor da entrada.



