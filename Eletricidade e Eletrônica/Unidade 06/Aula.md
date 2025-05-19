# Corrente Contínua x Corrente Alternada

## Corrente Contínua

* Flui sempre por um sentido apenas.

* Corrente e tensão não são necessariamente constantes.

* Dispositivos de armazenamento de energia sempre são em corrente contínua.

* Ou seja, os polos da fonte de alimentação serão sempre os mesmos, e a fonte fluirá de um terminal para o outro.

## Corrente Alternada

* A corrente muda de sentido constantemente.

* Só é possível com alternância dos polos da tensão.

* Se os picos forem de tensão positiva -> corrente em sentido horário.

* Se os picos forem de tensão negativa -> corrente em sentido anti-horário.

* A tensão alternada utilizada como padrão possui um formato senoidal(ondas) em que o pico positvo e o pico negativo definem as variações na direção da corrente.

## Tensão Eficaz

* A tensão eficaz é obtida por meio da formaula Vrms = Vpico / raiz de 2

* Essa tensão converte o pico de uma rede de tensão alternada em tensão contínua, como se calculasse a "média"

## Retificadores

* A conversão AC pra DC ocorre pois os dispositivos só conseguem armazenar corrente contínua, ou seja, ela circula alternada mas para armazenamento ela é contínua.

* Essa conversão é feita justamente por meio dos calculos de tensão eficaz que converte a corrente alternada para continua.

* O componente utilizado é justamente o diodo retificador, que força a corrente a circula por apenas um sentido.

## Retificador de Meia Onda

* Apenas um diodo, ele fica em série com a fonte de tensão senoidal tendo sua saída em um resistor.

* A corrente vai no sentido horário, com o diodo estando polarizado no mesmo sentido logo quando ela oscila pra baixo(anti-horário) não passa pelo diodo, e quando oscila pra cima(horáro) passa.

* Essa retificação permite apenas a parte positiva da onda passar.

* A frequência da saída é igual a da entrada.

* A tensão de pico na saída é a tensão de entrada menos 0,7V.

* A tensão média da saída(DC) = 0,318 * a tensão de pico na saída.

## Retificador de Onda Completa(Ponte Retificadora)

* Aproveita toda a onda.

* São utilizados 4 diodos, de modo que a corrente vai percorrer dois diodos diretamente polarizados e os demais serão reversamente.

* A tensão de saída será a de entrada menos 1,4V, uma vez que a tensão cairá duas vezes.

* **Lembrando: a tensão de entrada é alternada**, ou seja, seus terminais se invertem promovendo a passagem da corrente em ambos os sentidos e, seguindo a arquitetura do circuito, conseguindo armazenar tanto o pico negativo(quando os terminais estão invertidos) tanto o pico positivo(quando o terminal está normal).

* A tensão média na saída será = 0,636 * a tensão de pico na saída

* A frequência na saída é o dobro da na entrada.

### Derivação Central

* Também é um retificador de onda completa, mas com uma característica diferente: ele utiliza apenas dois diodos.

* Ele funciona pegando um transformador com um fio enrolando, em que vai ser pego o meio exato desse fio para que os lados esquerdo e direito fique com os mesmos valores(simetricos) e com polaridades opostas.

* Cada fio vai conduzir a corrente por diodos diretamente polarizados e ambas correntes vão se encontrar no resistor de saída.

* Com isso, a corrente volta para o o fio central que vai funcionar como terminal hibrido para as duas polaridades(uma vez que vai ter cargas positivas e negativas).
