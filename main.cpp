#include <allegro.h>
#include <iostream>
#include <ctime>
#include "cenario.h"
#include "jogador.h"
#include "bolas.h"

/*
BDJBALL 2.0 - www.bdjogos.com
Autor: Adriano Waltrick

Jogo no estilo Arkanoid
Use para estudar organização de códigos 
e programação em C++

O arquivo main controla o jogo e é o primeiro a ser executado.


Data de Criação
16/01/2008

Data última modificação
20/02/2008
*/

///#####################################
// PASSO 1 - INICIE A LEITURA POR AQUI
///#####################################


// variáveis globais 
// ver em http://bdjogos.com/adrw/c/variaveis.htm
int fps = 0;

int fps_antigo 	= 0;
int fps_speed 	= 0;

// ver http://bdjogos.com/adrw/c/funcoes.htm
// prototipo do contador de frames
void frame_rate();

// prototipo do contador de velocidade
void incrementa_speed();

int main()
{
	///////////////////
	// Inicia Allegro
	// ver em http://www.bdjogos.com/biblioteca_conteudo.php?id=2
  allegro_init();
  set_color_depth(16);
  install_keyboard();
	install_mouse();
			
	// seta tamanho da tela		
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	
	// timer para o fps
	install_timer();	
  install_int( frame_rate, 1000 );
  install_int_ex( incrementa_speed, BPS_TO_TIMER(60) );
	
	
	// FIM Inicia Allegro
	///////////////////
	
    
    
  ///////////////////
	// Double Buffer
  // ver em http://www.bdjogos.com/conteudo.php?link=capitulo_25.php      
  BITMAP *buffer = NULL;         
  buffer = create_bitmap(640,480);    
    
	// FIM Double Buffer
  ///////////////////
    
    
    
    
  ///////////////////
	// Menu - Imagens e variáveis 
	
  // imagens do menu
  // ver em http://www.bdjogos.com/biblioteca_conteudo.php?id=7
  BITMAP * fundo_menu		= load_bitmap( "img/textura_menu.bmp", NULL);
  BITMAP * menu_play1		= load_bitmap( "img/play1.bmp", NULL );   
  BITMAP * menu_play2		= load_bitmap( "img/play2.bmp", NULL );
  BITMAP * menu_quit1		= load_bitmap( "img/quit1.bmp", NULL );
  BITMAP * menu_quit2		= load_bitmap( "img/quit2.bmp", NULL );

	// variáveis do menu
	int pos_menu1x = 430;
	int pos_menu1y = 330;
  int pos_menu2x = 425;
	int pos_menu2y = 370;
	int pos_menu   = 0;
	
	// FIM Menu - Imagens e variáveis 
  ///////////////////
  
  
  //////////////////////
  // Img Jogo
  
  BITMAP * img_jogo	= load_bitmap( "img/menu_jogo.bmp", NULL );
  BITMAP * fcenario   = create_bitmap(640,480);  
  
  // Img Jogo
  ////////////////////

	
	
	
	//////////////////
	// Variáveis Gerais

	int i = 0; 
	int c = 0;
	
	// indica aonde o jogador está no jogo
  int sessao_jogo = 0; 
  
  // saida do jogo
  bool sair = false;
  
  int key_buffer = 0;
    
	// FIM Variáveis Gerais
  ///////////////////


  ///#####################################
  // PASSO 1 - FIM
  ///#####################################







	///#####################################
  // PASSO 2 
  ///#####################################
  
 	///////////////////
	// Variáveis principais
  Cenario cenario;
  Jogador jogador;
  
  ///#####################################
  // Abra o arquivo cenario.h
  ///#####################################
  
  
  ///#####################################
  // PASSO 6 - INICIO
  ///#####################################

  // Aqui executamos as funções para criar o cenario..
  // essas funçoes leem arquivos txt, só que elas foram criadas apenas
  // no final da programação do jogo
  
           
  // inicia objetos do jogo
  cenario.iniciar( 300, 450 );       
  
  // le primeira fase
  if ( cenario.le_fases() != true )
	{    
    	cenario.teste();
	}
	else
	{
		cenario.cria_fase();
	}
	
	///#####################################
  // abra o arquivo cenario.cpp e leia a partir do passo 6
  ///#####################################
  
  
  ///#####################################
  // PASSO 7 - iniciar
  ///#####################################
	
	// inicia o jogador
	jogador.iniciar( 10, cenario.tamanho_y - 20, 10, cenario.tamanho_x );
                
    
    
	// FIM Variáveis principais
	///////////////////
	
	
	
	
	
  // Laço principal
  while( sair == false )
  {
    while ( ::fps_speed > 0 )
    {
    
      clear( buffer );
      
      // está no menu
      if ( sessao_jogo == 0 )
      {
  			blit( fundo_menu, buffer, 0, 0, 0, 0, 640, 480 );
  			
  			blit( menu_play1, buffer, 0, 0, pos_menu1x, pos_menu1y, 100, 39 );
  			blit( menu_quit1, buffer, 0, 0, pos_menu2x, pos_menu2y, 100, 39 );
  				
  			if ( pos_menu == 1 )
  			{
  				blit( menu_play2, buffer, 0, 0, pos_menu1x, pos_menu1y, 100, 39 );				
  			}
  			
  			if ( pos_menu == 2 )
  			{					
  				blit( menu_quit2, buffer, 0, 0, pos_menu2x, pos_menu2y, 100, 39 );
  			}

	
          //textprintf_ex( buffer, font, 10, 10, makecol(255,0,0), -1, "Precione Enter para iniciar" );
      }
        
      // jogo iniciado
      if ( sessao_jogo == 1 )
      {
        // imprime fundo e peças    
  			blit( img_jogo, buffer, 0, 0, 350, 0, 308, 480 );          
  			
  			fcenario = cenario.mostrar();
        blit( fcenario, buffer, 0, 0, 0, 0, cenario.tamanho_x, cenario.tamanho_y );             
          
        // imprime o jogador
        jogador.mostrar( buffer );
	
	      // aqui nós passamos o endereço da variavel jogador
        cenario.colisao_bola( buffer, &jogador );        
      }  
      // jogo iniciado
	
	
        
      // reinicia jogo e volta para menu
      if ( sessao_jogo == 2 )
      {
  			jogador.destrutor();
  			cenario.destrutor();
  			
  			sessao_jogo = 0;
      }
      // reinicia jogo e volta para menu
    
        
      if ( sessao_jogo == 3 )
      {
        jogador.destrutor();
        cenario.destrutor();

        cenario.iniciar( 300, 450 );  
        cenario.le_fases();
        cenario.cria_fase();     
        jogador.iniciar( 10, cenario.tamanho_y - 20, 10, cenario.tamanho_x );
        
        sessao_jogo = 0;
      }
  
    	
  	  // sai do jogo ou volta para o menu
  	  if ( key[KEY_ESC] && key_buffer == 0 )
  	  {
    		if ( sessao_jogo == 0 )
    		{
    			sair = true;	
    		}	
    		
    		if ( sessao_jogo == 1 )
    		{
    			sessao_jogo = 2;
    		}
    		
    		key_buffer = 30;
    	}

  		if ( key_buffer > 0 )
  		{
  			key_buffer--;
  		}
      // sai do jogo ou volta para o menu
        
        
        
      // inicia jogo
      if ( key[KEY_ENTER] )
      {
          if ( sessao_jogo == 0 )
          {
          	sessao_jogo = 1;
          }
      }  
      // inicia jogo
        
        
        
      // verifica posição do mouse menu
      pos_menu = 0;
      
		  if (
   		( mouse_x >= pos_menu1x && mouse_x <= pos_menu1x+100 )
   		)      	
  		{
  			if ( ( mouse_y >= pos_menu1y && mouse_y <= pos_menu1y+40 ) )
  			{
  				pos_menu = 1; 
  				
  				if (mouse_b & 1)
  				{    				
  					sessao_jogo = 1;
  				}
			  }
		
  			if ( ( mouse_y >= pos_menu2y && mouse_y <= pos_menu2y+40 ) )
  			{
  				pos_menu = 2; 
  				
  				if (mouse_b & 1)
  				{
  					sair = true;
  				}
  			}		
        		
  			
  		}			
      // verifica posição do mouse
      
        
      jogador.refresh();
                  
      
  		if ( cenario.verifica_pecas() == false )
      {
        if ( cenario.cria_fase() == false )
        {
          sessao_jogo = 3;  

        }
        else
        {
          jogador.iniciar( 10, cenario.tamanho_y - 20, 10, cenario.tamanho_x );
        }
      }
      else
      {
        
        if ( cenario.verifica_vidas() == false )
        {
	        sessao_jogo = 2;
        }
    	
      }
      
      
      
      ::fps_speed--;
      ::fps++;
    }
    
    
    
    
    blit( buffer, screen, 0,0,0,0, SCREEN_W, SCREEN_H);

    //show_mouse(screen);
    vsync();
  
  }

  cenario.destrutor();
  
  destroy_bitmap( buffer );
  destroy_bitmap( fundo_menu );
  destroy_bitmap( menu_play1 );
  destroy_bitmap( menu_play2 );
  destroy_bitmap( menu_quit1 );
  destroy_bitmap( menu_quit2 );
  destroy_bitmap( img_jogo );
  


  allegro_exit();
  return 0;
}
END_OF_MAIN();



void frame_rate()
{
    ::fps_antigo = ::fps;
    ::fps = 0;
}

void incrementa_speed()
{
    ::fps_speed++;
} 
