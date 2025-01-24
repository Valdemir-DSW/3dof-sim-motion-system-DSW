# 3dof-sim-motion-system-DSW
Sistema de plataforma de movimento código aberto para você fazer em casa ou para venda!
![image](https://github.com/user-attachments/assets/10f311fb-ba1b-4f9f-82e0-c729a0fb9a9b)

![image](https://github.com/user-attachments/assets/5d32f8da-6533-44f5-b6b3-fbb43652b2d2)
imagem ilustrativa()

---

deixei um código de exemplo para utilizar 3 drivers BTS7960 E motores DC( mas lembre-se você pode colocar qualquer motorização que pode funcionar com Arduino)
![image](https://github.com/user-attachments/assets/69628939-06d1-4377-b341-140221213b7f)

sistema planejado para ter noção de posição baseada em potenciômetro deve ser com a letra B de 5 a 20K 
![image](https://github.com/user-attachments/assets/ecbc064f-797f-448b-8248-45b3e7560d73)
caso o giro de algum deles fique invertido basta inverter no potenciômetro o pino A e C
e é claro que você precisa calibrar..
No código defina  ![image](https://github.com/user-attachments/assets/cf19438f-d158-454e-95eb-ec07ba72a8db) = 1 
abra o monitor serial com Arduino conectado


![image](https://github.com/user-attachments/assets/6332ddad-86cd-4c6e-9eb1-d1e4952a9b6c)


observe o menor valor que os eixos alcançam no input e defina ![image](https://github.com/user-attachments/assets/bb70486a-d8ce-48ab-87c8-86c662d34718)
como esse valor faça a mesma coisa com valor máximo definindo ![image](https://github.com/user-attachments/assets/e4da68bb-c374-479c-9c48-1570e9d3b502)

importante que todos os potenciômetro se movimentem para o mesmo lado caso estiverem movimentando para lados opostos você perceberá que os valores irão oscilar caso algum você perceber que está invertido você se lembra inverter os pinos no potenciometro A e C  o potenciômetro denominado x deve diminuir o valor ao movimentar a plataforma à esquerda o Y para trás e o Z ao empurrar para baixo

![image](https://github.com/user-attachments/assets/128fb2e9-1168-4310-ad3c-2be1268ed823)

eu também deixei previsto que você coloque um botão on off nesta posição ele deve estar ligado para o sistema atuar.
https://youtu.be/VhdpO9qy3Cs?si=xbZMnfJMTS--O50O
aqui um vídeo para você retirar de inspiração e lembrando você não precisa utilizar todos os eixos você pode fazer um sistema apenas com eixo z para fazer uma cadeira que sobe desce!
Esse vídeo não é meu e eu nem fiz parceria eu apenas coloquei porque achei legal e é o mesmo estilo de funcionamento que nós utilizamos aqui e você pode utilizar o nosso programa para fazer esse sistema mostrado no vídeo.


