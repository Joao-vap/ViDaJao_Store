#include <stdio.h>  /* printf */
#include <stdlib.h>
#include <string.h>

/* funcao auxiliar para printar a logo da loja */
void Header(void) {
printf("                     =================================================================================================================================================================\n");
printf("                     =================================================================================================================================================================\n");
printf("                     =########  ######## ##     ##         ##     ## #### ##    ## ########   #######        ###     #######     ##       ######## #### ##          ###     #######  =\n");
printf("                     =##     ## ##       ###   ###         ##     ##  ##  ###   ## ##     ## ##     ##      ## ##   ##     ##    ##       ##        ##  ##         ## ##   ##     ## =\n");
printf("                     =##     ## ##       #### ####         ##     ##  ##  ####  ## ##     ## ##     ##     ##   ##  ##     ##    ##       ##        ##  ##        ##   ##  ##     ## =\n");
printf("                     =########  ######   ## ### ## ####### ##     ##  ##  ## ## ## ##     ## ##     ##    ##     ## ##     ##    ##       ######    ##  ##       ##     ## ##     ## =\n");
printf("                     =##     ## ##       ##     ##          ##   ##   ##  ##  #### ##     ## ##     ##    ######### ##     ##    ##       ##        ##  ##       ######### ##     ## =\n");
printf("                     =##     ## ##       ##     ##           ## ##    ##  ##   ### ##     ## ##     ##    ##     ## ##     ##    ##       ##        ##  ##       ##     ## ##     ## =\n");
printf("                     =########  ######## ##     ##            ###    #### ##    ## ########   #######     ##     ##  #######     ######## ######## #### ######## ##     ##  #######  =\n");
printf("                     =================================================================================================================================================================\n");
printf("                     =            VVVVVVVV           VVVVVVVV  iiii  DDDDDDDDDDDDD                                    JJJJJJJJJJJ                                                    =\n");
printf("                     =            V::::::V           V::::::V i::::i D::::::::::::DDD                                 J:::::::::J                                                    =\n");
printf("                     =            V::::::V           V::::::V  iiii  D:::::::::::::::DD                               J:::::::::J                                                    =\n");
printf("                     =            V::::::V           V::::::V        DDD:::::DDDDD:::::D                              JJ:::::::JJ                                                    =\n");
printf("                     =             V:::::V           V:::::V iiiiiii   D:::::D    D:::::D   aaaaaaaaaaaaa               J:::::J    aaaaaaaaaaaaa      ooooooooooo                    =\n");
printf("                     =              V:::::V         V:::::V  i:::::i   D:::::D     D:::::D  a::::::::::::a              J:::::J    a::::::::::::a   oo:::::::::::oo                  =\n");
printf("                     =               V:::::V       V:::::V    i::::i   D:::::D     D:::::D  aaaaaaaaa:::::a             J:::::J    aaaaaaaaa:::::a o:::::::::::::::o                 =\n");
printf("                     =                V:::::V     V:::::V     i::::i   D:::::D     D:::::D           a::::a             J:::::j             a::::a o:::::ooooo:::::o                 =\n");
printf("                     =                 V:::::V   V:::::V      i::::i   D:::::D     D:::::D    aaaaaaa:::::a             J:::::J      aaaaaaa:::::a o::::o     o::::o                 =\n");
printf("                     =                  V:::::V V:::::V       i::::i   D:::::D     D:::::D  aa::::::::::::a JJJJJJJ     J:::::J    aa::::::::::::a o::::o     o::::o                 =\n");
printf("                     =                   V:::::V:::::V        i::::i   D:::::D     D:::::D a::::aaaa::::::a J:::::J     J:::::J   a::::aaaa::::::a o::::o     o::::o                 =\n");
printf("                     =                    V:::::::::V         i::::i   D:::::D    D:::::D a::::a    a:::::a J::::::J   J::::::J  a::::a    a:::::a o::::o     o::::o                 =\n");
printf("                     =                     V:::::::V         i::::::iDDD:::::DDDDD:::::D  a::::a    a:::::a J:::::::JJJ:::::::J  a::::a    a:::::a o:::::ooooo:::::o                 =\n");
printf("                     =                      V:::::V          i::::::iD:::::::::::::::DD   a:::::aaaa::::::a  JJ:::::::::::::JJ   a:::::aaaa::::::a o:::::::::::::::o                 =\n");
printf("                     =                       V:::V           i::::::iD::::::::::::DDD      a::::::::::aa:::a   JJ:::::::::JJ      a::::::::::aa:::a oo:::::::::::oo                  =\n");
printf("                     =                        VVV            iiiiiiiiDDDDDDDDDDDDD          aaaaaaaaaa  aaaa     JJJJJJJJJ         aaaaaaaaaa  aaaa   ooooooooooo                    =\n");
printf("                     =================================================================================================================================================================\n");
printf("                     =              `7MMM.     ,MMF'                                          `7MM                 .g8''8q.                                                          =\n");
printf("                     =                MMMb    dPMM                                              MM               .dP'    `YM.                                                        =\n");
printf("                     =                M YM   ,M MM   .gPYa    `7MMpMMMb. `7MM  `7MM       ,M'''bMM   .gPYa       dM'      `MM  `7MMpdMAo.  ,p6bo   ,pWWq.    .gPYa   ,pPYbd          =\n");
printf("                     =                M  Mb  M' MM  ,M'   Yb   MM    MM    MM    MM      ,AP    MM  ,M'   Yb     MM        MM   MM   `Wb 6M'  OO  6W'   `Wb ,M'  Yb  8I   ''         =\n");
printf("                     =                M  YM.P'  MM  8M''''''   MM    MM    MM    MM      8MI    MM  8M''''''     MM.      ,MP   MM    M8 8M       8M     M8 8M'''' ` YMMMa.          =\n");
printf("                     =                M  `YM'   MM  YM.    ,   MM    MM    MM    MM      `Mb    MM  YM.    ,     `Mb.    ,dP'   MM   ,AP YM.    , YA.   ,A9 YM.    , L.   I8         =\n");
printf("                     =              .JML. `'  .JMML. `Mbmmd' .JMML  JMML.  `Mbod'YML.     `Wbmd'MML. `Mbmmd'       `'bmmd'      MMbmmd'   YMbmd'   `Ybmd9'   `Mbmmd' M9mmmP'         =\n");
printf("                     =                                                                                                          MM                                                   =\n");
printf("                     =                                                                                                        .JMML.                                                 =\n");
}

/* funcao auxiliar para printar o menu versao maior */
void HeaderMenuGrande(void){
printf("                     =================================================================================================================================================================\n");
printf("                     =                                                                   1) Cadastrar um Produto                                                                     =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                  2) Listar Produtos e Lances                                                                  =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                        3) Dar um Lance                                                                        =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                   4) Sugestao de Produtos                                                                     =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                    5) Remover um produto                                                                      =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                 6) Ver Lances de um Produto                                                                   =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                      7) Encerrar Leilao                                                                       =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
}

/* funcao auxiliar para receber o input de opcao do menu */
int ReceberEscolha(void){
    int opcao;
printf("                     =                                                  Por favor, insira abaixo o numero correspondente a sua escolha:                                              =\n");
printf("                                                                                                  R:");
    scanf("%d", &opcao);
    if (opcao != 1 || opcao != 2 || opcao != 3 || opcao != 4 || opcao != 5 || opcao != 6 || opcao != 7){
        opcao = opcao;
    }
    else {
        opcao = 100;
    }
printf("                     =================================================================================================================================================================\n");   
    return opcao;
}

/* funcao auxiliar para printar o menu versao menor */
void MiniMenu(void){
printf("                     =================================================================================================================================================================\n");
printf("                     =                                                                   1) Cadastrar um Produto                                                                     =\n");
printf("                     =                                                                  2) Listar Produtos e Lances                                                                  =\n");
printf("                     =                                                                        3) Dar um Lance                                                                        =\n");
printf("                     =                                                                   4) Sugestao de Produtos                                                                     =\n");
printf("                     =                                                                    5) Remover um produto                                                                      =\n");
printf("                     =                                                                 6) Ver Lances de um Produto                                                                   =\n");
printf("                     =                                                                      7) Encerrar Leilao                                                                       =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n"); 
}

/* funcao auxiliar para print de resposta de cadastro de produto */
void PrintarProdCadastrado(void){
printf("                     =                                                                  ==> Produto cadastrado!                                                                      =\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
}

void PrintarProdJaCadastrado(void){
printf("                     =                                                                ==> Produto ja cadastrado!                                                                     =\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
}

/* funcao auxiliar para printar linha de divisa de menus */
void PrintarLinhaDupla(void){
printf("                     =================================================================================================================================================================\n");
}

/* funcao auxiliar para print de resposta de produto nao cadastrado */
void PrintarProdInexistente(void){
printf("                     =                                                                 ==> Produto nao existente!                                                                    =\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
}

/* funcao auxiliar para print de resposta de produto removido */
void PrintarProdRemovido(void){
printf("                     =                                                             ==> Produto removido com sucesso!                                                                 =\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
}

/* funcao auxiliar para printar qual opcao foi escolhida */
void PrintarOpcaoSelecionada(int opcao){
    switch (opcao)
    {
    case 1:
printf("                     =                                                        >>> Opcao Selecionada: Cadastrar um Produto                                                            =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
        break;
    case 2:
printf("                     =                                                     >>> Opcao Selecionada: Listar Produtos e Lances                                                           =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
        break;
    case 3:
printf("                     =                                                           >>> Opcao Selecionada: Dar um Lance                                                                 =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
        break;
    case 4:
printf("                     =                                                       >>> Opcao Selecionada: Sugestao de Produtos                                                             =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
        break;
    case 5:
printf("                     =                                                        >>> Opcao Selecionada: Remover um Produto                                                              =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
        break;
    case 6:
printf("                     =                                                     >>> Opcao Selecionada: Ver Lances de um Produto                                                           =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
        break;
    case 7:
printf("                     =                                                          >>> Opcao Selecionada: Encerrar Leilao                                                               =\n");
printf("                     =---------------------------------------------------------------------------------------------------------------------------------------------------------------=\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                   ==> Leilao Encerrado!                                                                       =\n");
        break;
    default:
printf("                     =                                                                    ==> Opcao invalida!                                                                        =\n");
        break;
    }
}

/* funcao auxilar para printar o encerramento da loja */
void PrintarGoodBye(void){
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                        A equipe ViDaJao espera lhe rever em breve!                                                            =\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =================================================================================================================================================================\n");
}

/* funcao auxiliar para print de resposta de produto nao cadastrado */
void PrintarNenhumProd(void){
printf("                     =                                                                  Nenhum produto cadastrado!                                                                   =\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
}

/* funcao auxiliar para print de resposta de lance */
void PrintarLanceEfetuado(void){
printf("                                                                                          ==> Lance efetuado!                                                                        =\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");

}

/* funcao auxiliar para print de resposta de lance */
void PrintarLanceAbaixoAtual(void){
printf("                     =                                                        ==> Valor de lance abaixo do lance atual!                                                              =\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
}

/* funcao auxiliar para print de resposta de lance */
void PrintarLanceAbaixoMinimo(void){
printf("                     =                                                           ==> Valor de lance abaixo do minimo!                                                                =\n");
printf("                     =                                                                                                                                                               =\n");
printf("                     =                                                                                                                                                               =\n");
}
/* funcao auxiliar para printar linha de espacamento */
void PulaLinha(void){
printf("                     =                                                                                                                                                               =\n");
}

/* funcao auxiliar para print de resposta des lances de um produto */
void PrintaAindaNaoHaLance(void){
printf("                                                                                ----> Ainda nao ha lances nesse produto!                                                             =\n");
PulaLinha();
}

char* ToString(char* palavra_in){
    char *palavra_out = (char*)malloc(50*sizeof(char));
    strcpy(palavra_out, palavra_in);
    return palavra_out;
}