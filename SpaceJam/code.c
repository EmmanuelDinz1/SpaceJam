/*
    Space Jam
*/
#include <allegro.h>
#include <string.h>

void init(); // Inicializa as funções do allegro;
void deinit(); // Finaliza as funções do allegro;
void fMovimento(); // Função que Movimenta a nave pelo timer;
int fMenu(BITMAP *buffer); // Função do Menu;
int fFase1(BITMAP *buffer); // Função da 1ª fase;
int fFase2(BITMAP *buffer); // Função da 2ª fase;
void fTesta_Colisao(); // Função que testa as colisões, é utilizada pelo timer;
void fScrool_Background();
void fGame_Over();

//  ########## - Variaveis Globais - ################
float nave_y = 418; // Posição Y da Nave;
float nave_x = 20; // Posição x da nave;
int pouso_x = 440; // Posição x do BITMAP "Pouso1";
int pouso_y = 200; // Posição y do BITMAP "Pouso1";
float fundo_y = 0; // Começa na posição 0 o fundo;
float fundo_y2 = -767; // 767 pq é o tamanho da imagem de altura;
float velocidade_fundo = 0.6; // Velocidade que movimenta o fundo;
int vFase = 1; // Testa em qual fase está;
float vVelocidade = 1.2; // Velocidade de Movimentação da nave;
float vGravidade = 1.6;
bool movendo = false; // Teste se a nave está se movendo ou não;
bool vColisao = false; // Testa as colisões;
BITMAP *nave1_parada; // BITMAP da nave parada;
BITMAP *nave1_movendo; // BITMAP da nave em movimento;
BITMAP *pouso1;
BITMAP *fundo; // BITMAP do fundo do jogo;
BITMAP *barra_vertical;
char game_over[40]; // Variavel para a mensagem de game_over;
//  ################################################# 

int main() 
{
	init();
	set_window_title("SPACEJAM");  // Titulo da janela;

    strcpy(game_over, "Game Over"); // Mensagem que aparece quando o jogador perde;
	BITMAP *buffer = create_bitmap(640,480); // Cria o BITMAP buffer
  
    nave1_parada = load_bitmap("Naves\\Nave1_Parada.bmp", NULL); // Carrega um bitmap para a nave parada;
    nave1_movendo = load_bitmap("Naves\\Nave1_Movimento.bmp", NULL); // Carrega um bitmap para a nave em movimento;
    fundo = load_bitmap("Tiles\\fundo.bmp", NULL); // Carrega um bitmap para o fundo;
    pouso1 = load_bitmap("Tiles\\pouso1.bmp", NULL);
    barra_vertical = load_bitmap("Tiles\\barra_vertical.bmp", NULL);
    
    if ( fMenu(buffer) == 1 )
    {
        if ( fFase1(buffer) == 1 )
        {
            vFase = 2;
            fFase2(buffer);
        }
    
    }
    
    deinit();
	return 0;
}
END_OF_MAIN();

void init() 
{
	allegro_init();
	set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);

	install_timer();
	install_keyboard();
	install_mouse();
}

void deinit() 
{
	clear_keybuf();
}

int fMenu(BITMAP *buffer)
{
    install_int(fScrool_Background,10);
    BITMAP *logo = load_bitmap("Tiles\\logo.bmp", NULL);
    int opcao_menu = 1;
    
	while (!key[KEY_ESC] ) 
    {
        clear_bitmap(buffer);
        draw_sprite(buffer, fundo, 0, fundo_y);
        draw_sprite(buffer, fundo, 0, fundo_y2);
		draw_sprite(buffer, logo, 60, 80);

        if ( key[KEY_UP] )
        {
            rest(140);
            if ( opcao_menu == 1 )
            {
                 opcao_menu = 3;
            }
            else
            if ( opcao_menu == 2 )
            {
                 opcao_menu = 1;
            }
            else
            if ( opcao_menu == 3 )
            {
                 opcao_menu = 2;
            }
        }
        else 
        if ( key[KEY_DOWN] ) // Move a nave para a esquerda;
        {
            rest(140);
            if ( opcao_menu == 1 )
            {
                 opcao_menu = 2;
            }
            else
            if ( opcao_menu == 2 )
            {
                 opcao_menu = 3;
            }
            else
            if ( opcao_menu == 3 )
            {
                 opcao_menu = 1;
            }
        }
        
        if ( key[KEY_ENTER] ) // Move a nave para a esquerda;
        {
            if ( opcao_menu == 1 )
            {
                 return 1;
            }
            else
            if ( opcao_menu == 2 )
            {
                 allegro_message("Space Jam\n\n Criado e Desenvolvido por Emmanuel D. Cheroto\n Versao: 0.1\n\n Para Jogar: Pressione as setas para direita,\npara a esquerda e para cima.\nObjetivo: Pousar no lugar certo, sem bater em nada.");
            }
            else
            if ( opcao_menu == 3 )
            {
                 return -1;
            }
            rest(200);
        }
        	
		if ( opcao_menu == 1 )
        {
            rotate_sprite_v_flip(buffer, nave1_movendo, 450, 194, itofix(64));
		    rotate_sprite(buffer, nave1_movendo, 156, 194, itofix(64));
        }
		else
        if ( opcao_menu == 2 )
        {
            rotate_sprite_v_flip(buffer, nave1_movendo, 390, 286, itofix(64));
		    rotate_sprite(buffer, nave1_movendo, 224, 286, itofix(64));
        }	
		else
        if ( opcao_menu == 3 )
        {
            rotate_sprite_v_flip(buffer, nave1_movendo, 386, 370, itofix(64));
		    rotate_sprite(buffer, nave1_movendo, 228, 370, itofix(64));
        }			
        
        draw_sprite(screen, buffer, 0, 0); // Manda o buffer para a tela;
    }
}

void fMovimento()
{
     if (!key[KEY_UP]) // Se não estiver pressionando barra de espaço para a nave subir, ela desce;
     { 
         if ( nave_y < 418 ) // Se não estiver no final da tela;
             nave_y += vGravidade;
     }
}

void fScrool_Background() // Função que movimenta o fundo da tela;
{
    fundo_y += velocidade_fundo;
    fundo_y2 += velocidade_fundo;
    
    if ( fundo_y > 767 ) // Se chegar no final do tamanho da imagem ela sobe para cima;
        fundo_y = -767;
    if ( fundo_y2 > 767 ) // Se chegar no final do tamanho da imagem ela sobe para cima;
        fundo_y2 = -767;
}

int fFase1(BITMAP *buffer) // Fase 1 do jogo;
{
    install_int(fMovimento,20); // Função ativada pelo timer para a nave descer sozinha;
    install_int(fTesta_Colisao,10);
    install_int(fScrool_Background,10);

	while (!key[KEY_ESC] ) 
    {
        clear_bitmap(buffer);
        draw_sprite(buffer, fundo, 0, fundo_y);
        draw_sprite(buffer, fundo, 0, fundo_y2);
		draw_sprite(buffer, pouso1, pouso_x, pouso_y);
		draw_sprite(buffer, barra_vertical, 340, 100);
		
        if ( key[KEY_UP] && nave_y > 4 )
        {
             nave_y -= vVelocidade; // Sobe a nave se espaço for pressionado;
             movendo = true; // Mostra que está movendo; 
        }
        if ( key[KEY_LEFT] && nave_y < 400 ) // Move a nave para a esquerda;
        {
             if ( nave_x  > 8 )
                 nave_x -= vVelocidade-0.4;
             rotate_sprite_v_flip(buffer, nave1_movendo, nave_x, nave_y, itofix(96));
        }
        else if ( key[KEY_RIGHT] && nave_y < 400 ) // Move a nave para a direita;
        {
             if ( nave_x < 596 )
                 nave_x += vVelocidade-0.4;
             rotate_sprite(buffer, nave1_movendo, nave_x, nave_y, itofix(32));
        }		
		
		if ( !key[KEY_RIGHT] && !key[KEY_LEFT] || nave_y > 400 )
		{
    		if ( movendo == true ) // Testa se a nave está se movendo ou nao para mostrar a imagem correta;
    		    draw_sprite(buffer, nave1_movendo, nave_x, nave_y);
            else
                draw_sprite(buffer, nave1_parada, nave_x, nave_y);
        }
            
        draw_sprite(screen, buffer, 0, 0); // Manda o buffer para a tela;
        
        movendo = false; // Da false na movimentação, para trocar a imagem da nave;
        
        if ( nave_x >= 430 && nave_x <= 490 && nave_y >= 150 && nave_y <= 152 )
        {
            remove_int(fMovimento);
            allegro_message("Parabens!!!\n Voce passou para a fase %d!",vFase+1);
            return 1;
        }       
        if ( vColisao == true )
        {
             return 0;
        }
        
    }
    
    return -1;
}

void fTesta_Colisao()
{    
    if ( vFase == 1 )
    {
        if (nave_x >= 420 && nave_x <= 500 && nave_y >= 200 && nave_y <= 220 ) // Testa se bateu no pouso1;
        {
            fGame_Over();
        } 
        else
        if ( nave_y <= 4 || nave_x >= 596 || nave_x <= 8 ) // Testa se bateu nas laterais da tela;
        {
            fGame_Over();
        }
        else
        if ( nave_y >= 100 && nave_y <= 170 && nave_x >= 320 && nave_x <= 340 ) // Testa se bateu na barra vertical;
        {
            fGame_Over();
        }        
    }
    else
    if ( vFase == 2 )
    {
        if ( nave_x >= 420 && nave_x <= 500 && nave_y >= 200 && nave_y <= 220 ) // Testa se bateu no pouso1;
        {
            fGame_Over();
        }
        if ( nave_y <= 4 || nave_x >= 596 || nave_x <= 8 ) // Testa se bateu nas laterais da tela;
        {
            fGame_Over();
        }
        else
        if ( nave_x >= 80 && nave_x <= 100 && nave_y >= 100 && nave_y <= 170 ) // Testa se bateu na Barra 1;
        {
            fGame_Over();
        }  
        else
        if ( nave_x >= 240 && nave_x <= 260 && nave_y >= 300 && nave_y <= 370 )// Testa se bateu na Barra 2;
        {
            fGame_Over();
        }  
        else
        if ( nave_x >= 280 && nave_x <= 300 && nave_y >= 120 && nave_y <= 190 )// Testa se bateu na Barra 3;
        {
            fGame_Over();
        }  
    }
}

void fGame_Over()
{
    remove_int(fMovimento);
    remove_int(fTesta_Colisao);
    remove_int(fScrool_Background);
    allegro_message(game_over);
    vColisao = true;
}

int fFase2(BITMAP *buffer) // Fase 1 do jogo;
{
    nave_y = 418; // Posição Y da Nave;
    nave_x = 20; // Posição x da nave;
    
    install_int(fMovimento,20); // Função ativada pelo timer para a nave descer sozinha;
    install_int(fTesta_Colisao,10);
    install_int(fScrool_Background,10);
    
	while (!key[KEY_ESC] ) 
    {
        clear_bitmap(buffer);
        draw_sprite(buffer, fundo, 0, fundo_y);
        draw_sprite(buffer, fundo, 0, fundo_y2);
		draw_sprite(buffer, pouso1, pouso_x, pouso_y);
		draw_sprite(buffer, barra_vertical, 100, 100);
		draw_sprite(buffer, barra_vertical, 260, 300);
		draw_sprite(buffer, barra_vertical, 300, 120);

        if ( key[KEY_UP] && nave_y > 4 )
        {
             nave_y -= vVelocidade; // Sobe a nave se espaço for pressionado;
             movendo = true; // Mostra que está movendo; 
        }
        if ( key[KEY_LEFT] && nave_y < 400 ) // Move a nave para a esquerda;
        {
             if ( nave_x  > 8 )
                 nave_x -= vVelocidade-0.4;
             rotate_sprite_v_flip(buffer, nave1_movendo, nave_x, nave_y, itofix(96));
        }
        else if ( key[KEY_RIGHT] && nave_y < 400 ) // Move a nave para a direita;
        {
             if ( nave_x < 596 )
                 nave_x += vVelocidade-0.4;
             rotate_sprite(buffer, nave1_movendo, nave_x, nave_y, itofix(32));
        }		
		
		if ( !key[KEY_RIGHT] && !key[KEY_LEFT] || nave_y > 400 )
		{
    		if ( movendo == true ) // Testa se a nave está se movendo ou nao para mostrar a imagem correta;
    		    draw_sprite(buffer, nave1_movendo, nave_x, nave_y);
            else
                draw_sprite(buffer, nave1_parada, nave_x, nave_y);
        }
            
        draw_sprite(screen, buffer, 0, 0); // Manda o buffer para a tela;
        
        movendo = false; // Da false na movimentação, para trocar a imagem da nave;
        
        if ( nave_x >= 430 && nave_x <= 490 && nave_y >= 150 && nave_y <= 152 )
        {
            remove_int(fMovimento);
            allegro_message("Parabens!\n Voce Concluiu o jogo!\n\n :)");
            return 1;
        }       
        if ( vColisao == true )
        {
             return 0;
        }
        
    }
    
    return -1;
}
