#include<16f877.h>
#use delay(clock=4000000)
#fuses NOWDT, XT, PUT, NOPROTECT, NOBROWNOUT, NOLVP, NOCPD, NOWRT

//mascara para simbolos numericos para display de sete segmentos
   int Disp7Seg[10]={
                     0b11111100, //posicao 0 --> 0 no dip
                     0b01100000, //posicao 1 --> 1 no dip
                     0b11011010, //posicao 2 --> 2 no dip
                     0b11110010, //posicao 3 --> 3 no dip
                     0b01100110, //posicao 4 --> 4 no dip
                     0b10110110, //posicao 5 --> 5 no dip
                     0b10111110, //posicao 6 --> 6 no dip
                     0b11100000, //posicao 7 --> 7 no dip
                     0b11111110, //posicao 8 --> 8 no dip
                     0b11110110, //posicao 9 --> 9 no dip
   };
void EscreveDisplay(int ValorDisplay)//funcao para escrita no display
{
   output_d(Disp7Seg[ValorDisplay]);
}

void main()
{
   int ContadorDisplay=0;     //variavel que sera mostrada no display
   set_tris_d(0);             //configurar todas PORTD como saida
   set_tris_b(0b00100100);    //configura RB2 e RB5 como entada
   EscreveDisplay(0);         //mostra no display o valor zero
   
   while(1)
   {
      //testa a tecla de decremento
      if(input(PIN_B2)==0)    //verifica se deve decrementar
      {
         if(ContadorDisplay > 0 )//nao premite que a variavel seja negativa
            ContadorDisplay--;  //se ainda for maior que 0 decrementa
            EscreveDisplay(ContadorDisplay);//mostra no display o valor da variavel
            while(input(PIN_B2)==0); // fica aqui ate soltar a tecla
      }
      
      //testa a tecla de incremento
      if(input(PIN_B5)==0)    //verifica se deve incrementar
      {
         if(ContadorDisplay < 9 )//nao premite que a variavel seja maior que 9
            ContadorDisplay++;  //se ainda for maior que 0 decrementa
            EscreveDisplay(ContadorDisplay);//mostra no display o valor da variavel
            while(input(PIN_B5)==0); // fica aqui ate soltar a tecla
      }
   }
}
