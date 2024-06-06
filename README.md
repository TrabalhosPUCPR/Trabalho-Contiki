# Trabalho-Contiki
atividade simples no contiki


Contexto: Para auxiliar no combate da Pandemia do Covid-19, o centro pesquisa de equipamentos médicos está convidando você para participar do desenvolvimento de um novo projeto. O projeto consiste em monitor de dados vitais em um smartwatch. O monitor deve registrar os batimentos cardíacos do paciente (considerar entre 20 e 140 batimentos cardíacos - abaixo de 50 mensagem de batimento cardíaco baixo, acima de 90 apresentar mensagem batimento cardíaco alto), nível saturação do oxigênio (considerar oxigenação entre 80% e 100% - abaixo de 90% mensagem de saturação baixa) no sangue e temperatura (considerar temperatura de 34° a 41° - abaixo de 35° apresentar mensagem de hipotermia, acima de 37° mensagem de febre). 

A. Implementar um programa no Contiki destinado a monitorar os dados vitais de uma pessoa (deve medir os batimentos cardíacos, saturação de oxigênio e febre);

B. Deverá ser criado três funções thread de processos, uma para monitorar cada um dos dados vitais;

C. Para simular os dados vitais deverão ser utilizadas funções randômicas;

D.	Os dados vitais (aleatórios) devem ser gerados dentro de cada uma das funções thread de processo;

E.	Imprimir os dados vitais em cada uma das funções;

F.	Utilizar a função PROCESS_WAIT_EVENT_UNTIL() configurando um tempo de três segundos para cada função thread de processo.

G.	Todas as funções thread de processos devem definir sua exclusão explicita utilizando a macro PROCESS_END();

H.	Deverá ser criado uma quarta função thread de processo que deve aguardar por um evento;

I.	Gerar um evento sempre que os dados vitais estiverem alterados (considerar os valores normais de cada um dos dados vitais);

J.	O evento deve gerar uma mensagem de alerta para o usuário;   

K.	O código deve ser documentado, utilizar os comentários em toda a extensão do programa.
