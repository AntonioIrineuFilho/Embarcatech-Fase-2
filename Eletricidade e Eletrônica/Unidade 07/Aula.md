# Transistores Bipolares de Junção

* Transistores são formados por três camadas de semicondutores dopados(tipo P ou tipo N), podendo ser PNP ou NPN.

* As extremidades serão os terminais emissor e coletor, e o centro é a base, que realiza o controle do transistor.

* Esse controle da base basicamente consiste em abrir e fechar a chave, conforme passagem de uma corrente pequena de controle.

* Se a chave abre, permite a passagem de corrente, se não, não permite.

* Na simbologia, a diferença entre o PNP e o NPN é a seta que, se apontar do emissor para a base, significa que **a corrente do emissor é penetrante o transistor é PNP**.

* Se a seta sai da base apontando para o emissor, **a corrente é não penetrante e o transistor é NPN**.

* **Em um transistor NPN, a corrente do emissor é igual à corrente do coletor + a corrente da base**.

* **Nos transistores PNP a mesma fórmula é válida, no entanto, com as correntes em sentido oposto, com o coletor sendo a saída e o emissor a entrada**.

* **Ie = Ic + Ib (Equação 1)**

* A quantidade de vezes que a corrente do coletor é maior que a corrente da base é chamado de **ganho de corrente**.

* **β = Ic / Ib (Equação 2)**

* Como a corrente no emissor é a soma do coletor e da base, e a base é praticamente insignificante, então a corrente no emissor é praticamente igual à corrente no coletor.

## Diferença de Potencial nos Transistores

* A tensão nos transistores podem ser base-emissor, coletor-emissor, coletor-base.

### Base-Emissor

* A tensão funciona como em um diodo, ou seja, se no NPN o potencial elétrico for maior na base que no emissor, então haverá condução de corrente(Vbe). No caso, do PNP, o potencial elétrico deve ser maior no emissor para conduzir(Veb).

* A queda de tensão é de aproximadamente 0,7V em condução, em corte pode assumir outros valores.

### Coletor-Emissor

* Tanto Vce quanto Vec não vai possuir queda de tensão fixa.

### Coletor-Base

* DDP entra o coletor e a base(Vcb e Vbc), menos importante que os anteriores nas análises de tensão.

## Modos de Operação

* Os transistores tem basicamente três estados de operação: **corte**, **saturação** e **ativo**.

* O estado de corte precisa que a tensão base-emissor(Vbe) esteja reversamente polarizada. Ou seja, se a ddp da junção base-emissor não estiver próximo a 0,7V, o estado é de corte.

* Se o transistor estiver conduzindo, significa que está ativo ou em satuação.

* A melhor forma é medir se está ativo ou em satuação é a tensão coletor-emissor(Vce).

* O modo de saturação ocorre quando o transistor apresenta valores muito baixos de Vce. Se a tensão Vce for inferior a Vbe, ou seja, 0,7 volts. O transistor está em modo de saturação. O modo de saturação ocorre tipicamente com a Vce inferior a 0,2 volts.

* Para valores de Vce maiores que 0,7 volts, o transistor já está em modo ativo.

* Mas, na prática, a região próxima a 0,7 volts é muito instável. Por isso, nas aplicações reais é comum encontrar valores de Vce próximos a zero volts, quando o transistor está em modo de saturação e bem superiores a 0,7 volts quando o transistor está em modo ativo.

## Aplicações

* Amplificação de sinais e chaveamento.

* Amplificação é feita no modo de operação ativo.

* Chaveamento é feito alternando entre saturação e corte.

### Chaveamento

* O controle da base pode ser feito por PWN, um controlador que passa uma pequena corrente na base quando o nível lógico está alto.

### Amplificação

* Na amplificação, é recebido um sinal de entrada AC geralmente, esse sinal deve passar por um capacitor que acopla a parte AC do sinal, bloqueando a parte DC da entrada. Esse AC se soma ao DC da fonte de alimentação(que pode ser uma bateria, pilha, etc) para que base do capacitor(que só trabalha com tensão DC) deixe passar.

## Transistores e portas lógicas

* Internamente, as próprias portas lógicas são arranjos de transistores trabalhando em modo chaveamento.

* Para a chave entrar em estado de saturação(ligar) a queda de tensão Vbe deve ser próxima a 0,7V e a queda de tensão Vce deve ser próxima a 0V.

* As entradas da porta lógica é a corrente de passagem do nível lógico para a base enquanto a saída 0 pode ser o aterramento.

## Transistores de efeito de campo(FETs)

* Possuem a mesma função que um TBJ, no entanto, não são controlados por corrente, mas sim por tensão.

* Basicamente o pino de controle não passa corrente, mas sim é aplicado ums tensão que gera um campo elétrico que permite a passagem de corrente entre os outros dois terminais.

* O principal tipo de FET é o **MOSFET**.

### MOSFET

* Os MOSFETs podem ser NPN ou PNP, conduzindo corrente em apenas um sentido tal qual os TBJ.

* **Gate** -> O terminal de controle, onde não passa corrente.

* **Fonte(Source)** e **Drain(Dreno)** -> Outros terminais por onde a corrente passa, semelhante ao emissor e coletor.

* No MOSFET do tipo n(NPN), a seta aponta para o gate , enquanto no MOSFET do tipo p(PNP) aponta para fora do gate.
