# Componentes Elementares

* Os componentes fundamentais em um circuito elétrico são: **transistores**, **capacitores**, **indutores** e **geradores**.

## Resistores

* Os resistores são componentes com a capacidade de se opor a uma corrente elétrica, ou seja, gerar **resistência** a ela.

* A importância de um resistor é limitar a corrente, evitando um fluxo infinito, ou seja, um curto-circuito.
 
### Isolantes x Resistores

* Um material isolante possui uma resistência elétrica extremamente alta, uma vez que não vai possuir eletrons livres para favorecer a passagem da corrente.
 
* No entanto, um resistor é feito de material condutor, mas com uma resistência controlada e esppecífica para o objetivo proposto.

### Tipos de Resistores

* Carvão e filme metálico -> Muito usados na eletrônica.

* Fio metálico -> Usados como resistores de potência.

* Silício -> Usados em circuitos integrados.

### Código de Cores

* Os resistores de carvão/filme metálico são os mais utilizados, com sua resistência identificada pelas faixas de cores.

* Na maioria das vezes, esses resistores vão possuir de 4 a 5 faixas, sendo o todo faixas de resistência e uma de tolerância.

* Em caso de não haver uma faixa de tolerãncia(resistores de 3 faixas), a tolerância é de 20%.

* As principais cores que indicam as faixas de tolerância é o dourado(+-5%) e o prateado(+-10%).

* As faixas de resistência são lidas da esquerda para a direita.

* A última faixa de resistência indica ordem de grandeza, ou seja, multiplicação.

* As faixas anteriores terão seus valores concatenados, com base nas cores.

* **Por exemplo: Se eu tiver um resistor com quatro faixas, sendo a de tolerância(extremidade direita) cinza e as de resistência, respectivamente verde, azul e amarelo(começando da extremidade esquerda), qual será o total da resistência?**

* A verde e a azul será concatenada(56) e multiplicada pela ordem de grandeza da amarela(x10 kOHMS), resultando em 560 kOHMS, com 10% de tolerância, ou seja, 504-616 kOHMS.

## Capacitores

* O capacitor é um componente cuja finalidade é armazenar energia elétrica em um campo elétrico.

* Ele é composto por duas placas condutoras que ficam nas extreminadades, chamadas de **armaduras** e por um isolante chamada dielétrico, que fica entre os condutores.

### Capacitância

* É deonimanda **capacitância** a capacidade de armazenamento de cargas elétricas de um capacitor nas suas armaduras, dependendo de fatores como a área da armadura. a distância entre as armaduras e tipo de isolante que as separa.

* Os capacitores normalmente não possuem polaridade, mas os eletroliticos possuem, logo é importante não inverter a polaridade.

* C = p * A / d

* C -> Capacitância

* p -> Permissividade elétrica do dielétrico

* A -> Área das armaduras(diretamente proporcional à capacitância)

* d -> Distância entre as armaduras(inversamente proporcional à capacitância)

## Indutores

* Diferente dos capacitores, tem a finalidade de armanezar energia em **campos magnéticos**.

* São feitos de fios condutores enrolados em espiras, formando uma bobina. Esses fios são esmaltados, ou seja, isolados uns dos outros para evitar curto quando entram em contato.

* O núcleo da bobina pode ser feito de ar, ferro ou ferrite.

* O objetivo é gerar um campo magnético.

* Possuem alta impedância/resistência em corrente alternada e baixa impedância/resistência em corrente contínua.

* O campo magnético é gerado em sentido oposto à variação da corrente.

### Indutância

* A indutância é a capacidade de armazenar uma maior ou menor quantidade de cargas elétricas no campo magnético do indutor.

* A indutância depende da área das espiras, do número de espiras da bobina, do comprimento da bobina e do material que constitui o núcleo da bobina.

* L = u * N² * A / I

* L -> Indutância

* N -> Número de espiras

* A -> Área das espiras

* u -> Constante do material que constitui o núcleo da bobina(permeabilidade magnética)

* I -> Comprimento da bobina

## Geradores Elétricos

* Dispositivos que convertem outros tipos de energia em energia elétrica.

* Ele gera um polo positivo e um polo negativo, o que possibilita uma diferença de potencial entre os terminais.

* Em um gerador real existem perdas, uma vez que parte da energia é dissipada em forma de calor em função da sua resistência interna.

* A eficiência/rendimento de um gerador é determinado pela razão da potência que entra pela potência que sai do gerador.
