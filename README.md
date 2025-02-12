# Controle de Servomotor e LED RGB com Raspberry Pi Pico W

## Descrição
Este projeto demonstra o controle de um **servomotor** e de um **LED RGB** usando o **Raspberry Pi Pico W** e o **WOKWI**.  
A simulação foi realizada no **Wokwi**, e o código reproduz o movimento de um braço de servomotor controlado por PWM. Posteriormente, o mesmo comportamento foi reproduzido no LED RGB, simulando as posições do servo através do controle de brilho.

## Funcionamento
### Controle do Servomotor (GPIO 22)
- Frequência de PWM: 50 Hz (período de 20 ms)  
- Ciclos ativos utilizados para controle do servo:
  - **500 µs → Posição 0°**
  - **1470 µs → Posição 90°**
  - **2400 µs → Posição 180°**

**O mesmo código vale para o controle do led, trocando apenas o valor da variável SERVO_PIN de 22 para 12 e ao testar na placa Pi Pico W, o LED apresentará o mesmo comportamento que o servo do wokwi, colocando um brilho maximo, minimo alternando entre eles**

## Instruções de uso

Ao clonar o repositório e abrir no VSCode. Só simular o arquivo diagram.json e o programa mostrará o controle do servo motor automaticamente do jeito que foi explicado. Primeiro na posição de 180º, depois na posição de 90º, depois na posição de 0º e depois decrementando
e incrementando automaticamente, sozinho.
Ao trocar a variável e testar na placa, o led irá realizar o mesmo comportamento, começando com um brilho alto, depois um médio e um brilho baixo, e depois alternando suavemente entre eles. 

https://drive.google.com/file/d/1jDVZdcoQxTpe0orMnU3Mns96P29foUrT/view?usp=sharing -- Vídeo 1 com a explicação do código e o Wokwi do servo
https://drive.google.com/file/d/1Eifzn7_JNkZVbG0LKt_a1KO9Fogwo-ZL/view?usp=sharing -- Vídeo 2 com o teste no led
