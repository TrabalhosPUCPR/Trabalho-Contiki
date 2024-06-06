#include "contiki.h"
#include "random.h"
#include <stdio.h>

int generate_random_int(int min, int max);

// definimos os processos e avisamos para iniciar eles automaticamente
PROCESS(bat_cardiaco, "Batimento cardiaco");
PROCESS(sat_oxigenio, "Saturacao oxigenio");
PROCESS(temperatura, "Temperatura");
PROCESS(aviso, "Processo aviso");
AUTOSTART_PROCESSES(&bat_cardiaco, &sat_oxigenio, &temperatura, &aviso);

/*
 * Funcao de utilidade para gerar um numero inteiro aleatorio entre min e max
*/ 
int generate_random_int(int min, int max)
{
  return (random_rand() % (max - min + 1)) + min;
}

/*
 * Criamos o processo do batimento cardiaco
 */ 
PROCESS_THREAD(bat_cardiaco, ev, data)
{
  static struct etimer timer;
  PROCESS_BEGIN();
 	
  etimer_set(&timer, CLOCK_SECOND*3);
  while(true) {
    int batimento = generate_random_int(20, 140); // gera um numero aleatorio
    process_post(&aviso, PROCESS_EVENT_MSG, NULL); // envia o evento dizendo que mudou o batimento
    // passa por todos esses ifs para ver qual o estado do novo batimento cardiaco e printa
    if(batimento < 50)
    {
      printf("BATICAMENTO CARDIACO (BAIXO) = %d\n", batimento);
    }
    else if(batimento > 90)
    {
      printf("BATIMENTO CARDIACO (ALTO) = %d\n", batimento);
    }
    else
    {
      printf("BATIMENTO CARDIACO (NORMAL) = %d\n", batimento);
    }
    // espera 3 segundos para reiniciar o loop
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
    etimer_reset(&timer);
  }

  PROCESS_END();
}

PROCESS_THREAD(temperatura, ev, data)
{
  static struct etimer timer;
  PROCESS_BEGIN();

  etimer_set(&timer, CLOCK_SECOND*3);
  while(true)
  {
    // eu nao sei a forma normal pra gerar um double aleatorio
    // da forma certa, entao a gente faz gambiarra
    double temp = generate_random_int(340, 410)/10.0;
    // o resto e igual ao processo de cima, porem mudando os ifs 
    process_post(&aviso, PROCESS_EVENT_MSG, NULL);
    if(temp > 37.5)
    {
      printf("TEMPERATURA (FEBRE) = %.1f\n", temp);
    }
    else if(temp < 35.0)
    {
      printf("TEMPERATURA (HIPOTERMIA) = %.1f\n", temp);
    }
    else
    {
      printf("TEMPERATURA (NORMAL) = %.1f\n", temp);
    }
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
    etimer_reset(&timer);
  }

  PROCESS_END();
}

PROCESS_THREAD(sat_oxigenio, ev, data)
{
  static struct etimer timer;
  PROCESS_BEGIN();

  etimer_set(&timer, CLOCK_SECOND*3);
  while(true)
  {
    int saturacao = generate_random_int(80, 100);
    // igual ao processo de cima, so mudando os ifs
    process_post(&aviso, PROCESS_EVENT_MSG, NULL);
    if(saturacao < 90)
    {
      printf("SATURACAO (BAIXA) = %d\n", saturacao);
    }
    else
    {
      printf("SATURACAO (NORMAL) = %d\n", saturacao);
    }
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&timer));
    etimer_reset(&timer);
  }

  PROCESS_END();
}

PROCESS_THREAD(aviso, ev, data)
{
  // contador para avisar apenas quando os 3 dados vitais e atualizado
  static int n = 0;
  PROCESS_BEGIN();
  while(true)
  {
    // esperamos receber um evento
    PROCESS_WAIT_EVENT();
    // caso ja tiver recebido 3 eventos, manda o alerta e reinicia
    if(n >= 2)
    {
      n = 0;
      printf("Dados vitais modificado!\n\n");
    }
    else
    {
      // caso contrario, incrementa o contador
      n++;
    }
  }
  PROCESS_END();
}



