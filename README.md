# Readme - Projeto de Medição de Consumo de Energia com Arduino

Este é um projeto de medição de consumo de energia utilizando um Arduino Uno, uma protoboard, três LEDs, três resistores, um potenciômetro e dois multímetros. O objetivo deste projeto é simular a medição dos gastos de energia dos LEDs e, a partir dos multímetros, calcular a potência em watts (volts x amperes) consumida por cada LED.
Materiais Necessários

   - Arduino Uno
   - Protoboard
   - 3 LEDs (diferentes cores para fácil identificação)
   - 3 Resistores (para limitar a corrente nos LEDs)
   - Potenciômetro (para ajustar a corrente)
   - 2 Multímetros (um para medir a tensão e outro para medir a corrente)
   - Cabos jumper
     
##  Montagem do Circuito
 - Conecte os LEDs à protoboard, observando a polaridade (o terminal mais longo é o ânodo e o terminal mais curto é o cátodo).
 - Conecte um resistor de valor adequado em série com cada LED para limitar a corrente (consulte a especificação do LED para determinar a resistência necessária).
 - Conecte os outros terminais dos LEDs e resistores à protoboard.

 > Conexão do Potenciômetro:
 -   Conecte o potenciômetro à protoboard.
 -  Conecte o terminal central do potenciômetro (cursor) a uma porta analógica do Arduino (por exemplo, A0).
 -  Conecte os outros dois terminais do potenciômetro a VCC e GND da protoboard.

 >   Conexão dos Multímetros:
 -  Conecte o multímetro configurado para medir a tensão entre a saída do LED e o terra.
 -  Conecte o segundo multímetro configurado para medir a corrente em série com o LED (entre o resistor e o LED).

 >  Conexão do Arduino:
 -  Conecte o Arduino à protoboard usando cabos jumper.
 -  Certifique-se de conectar o terra do Arduino à terra da protoboard para referência comum.
 -  Uso do Projeto

   Ligue o Arduino no computador.
   Insira o Codigo 
   Ajuste o potenciômetro para variar a tensão.
   Os valores de tensão, corrente e potência serão exibidos no Monitor Serial da IDE do Arduino.




## Como o IOT pode ajudar no projeto
   A Internet das Coisas (IoT) pode ser integrada ao projeto para monitorar e controlar o consumo de energia de forma remota. Um exemplo de plataforma IoT que pode ser usada é o Tago.io. Você pode configurar o Arduino para enviar dados de consumo de energia para o Tago.io usando uma conexão Wi-Fi. Aqui estão alguns benefícios da integração da IoT:

- Monitoramento Remoto: Com o Tago.io, você pode acompanhar o consumo de energia dos LEDs em tempo real de qualquer lugar do mundo através de uma interface web ou aplicativo móvel.

- Alertas de Consumo Excessivo: Você pode configurar o Tago.io para enviar notificações por e-mail quando o consumo de energia dos LEDs estiver acima do valor recomendado, permitindo uma resposta rápida a situações de alto consumo.

- Armazenamento de Dados: A plataforma IoT permite armazenar e visualizar históricos de consumo de energia, facilitando a análise de tendências e o planejamento de eficiência energética.

Para integrar o Arduino ao Tago.io, você precisará seguir as instruções fornecidas pela plataforma IoT e adaptar o código do Arduino para enviar os dados de medição para a nuvem. Certifique-se de configurar o Tago.io para que ele envie alertas de e-mail quando os níveis de consumo excederem os limites definidos.
   



## Considerações Finais

Este projeto permite simular a medição dos gastos de energia dos LEDs e calcular a potência consumida por cada um. Lembre-se de que os valores de resistência dos resistores devem ser escolhidos corretamente para limitar a corrente através dos LEDs e garantir medições precisas. Além disso, esteja ciente de medidas de segurança ao lidar com eletricidade.


## integrantes 
João Pedro de Albuquerque Oliveira         RM:551579
Maurício Santos Rodrigues                  RM: 551076
Vitor Reyes Souza                          RM:550766
Luis Serafin Bezagio Mendieta              RM:551588
Pedro Augusto Carneiro Barone Bomfim       RM:99781
