# Introdução a Computação Gráfica
## Primeiro Trabalho (2018.1)
![Hexagrama](https://github.com/Skalnark/ICG/blob/master/images/Hexagrama2.png)

#### Put Pixel
A primeira função a ser implementada é a PutPixel, uma função simples que apenas altera os valores de um ponteiro no collor buffer. O código desta função está disponível na definição do trabalho, então julguei desnecessário apresentação do mesmo.
Como orientado, foram utilizadas classes para manipular os vetores e as cores.
#### Draw Line
![DrawLine](https://github.com/Skalnark/ICG/blob/master/images/DrawLine.png)
A função mais difícil de ser implementada. É a aplicação do algoritmo de Bresenham Algor adaptada para os oito octantes. 
Primeiro são checadas algumas condições para determinar a qual octante a linha pertence, depois é aplicada uma regra sobre o x e o y para fazer com que o pixel pintado na tela seja correspondente ao octante correto, mesmo utilizando a mesma função para todos os pontos.
#### Draw Triangle
![DrawTriangle](https://github.com/Skalnark/ICG/blob/master/images/DrawTriangle.png)
Esta apenas faz uso da função Drawline, foi a função mais simples de ser implementada. Ela simplesmente desenha três linhas, ligando as três coordenadas fornecidas.
#### Interpolação de cores
![Interpolation](https://github.com/Skalnark/ICG/blob/master/images/Interpolation.png)
Embora não tenha sido pedido na descrição do trabalho, vi isso sendo implementado em outros trabalhos e achei interessante fazer. O algoritmo de interpolação funciona da diferença nos valores das cores a serem interpoladas, dividida pela quantidade de pixels a serem pintados na linha. Esse valor é iterado antes de cada pixel ser desenhado.
#### Conclusão
Graças as imagens e blogs disponíveis, não foi difícil definir as regras para cada octante, tornando o trabalho bastante simples, ainda que a função DrawLine tenha me levado uma madrugada inteira. Um dos problemas encontrados foi durante a interpolação das cores, onde não obtive resultados horríveis a princípio, quando os valores de RGBA eram guardados em inteiros, mas um colega me disse pra alterar o tipo para float e tudo funcionou.
