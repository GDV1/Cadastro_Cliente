/** Autor: Gabriel Dias **/

/**
*	Este algoritmo simula um sistema de cadastro de clientes em um arquivo. Neste algoritmo
*	� usado o conceito de recursividade, para facilitar a leitura e modularizar o c�digo.
**/

// Bibliotecas padr�o
#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
#include <string.h>

// Fun��o para inclus�o de registros
int incluir(){
	
	// Configura o idioma de acordo com a localiza��o
    setlocale(LC_ALL, "portuguese");

	// Vari�veis
	char nome[50], sexo, cidade[50], setor[50];

	printf("Digite o nome do cliente: ");
	scanf(" %[^\n]s", nome);
	setbuf(stdin, NULL); // Limpa o buffer do teclado

	printf("Digite a cidade do cliente: ");
	scanf(" %[^\n]s", cidade);
	setbuf(stdin, NULL);

	printf("Digite o setor do cliente: ");
	scanf(" %[^\n]s", setor);
	setbuf(stdin, NULL);

	printf("Digite o sexo do cliente (M ou F): ");
	scanf(" %c", &sexo);
	setbuf(stdin, NULL);

	if(sexo == 'M' || sexo == 'F' || sexo == 'm' || sexo == 'f'){

	}else{
		printf("Dado inv�lido!");
	}

	// Manipula o arquivo bdClientes.txt abrindo-o, inserindo dados e fechando-o
	FILE *arqDisc;
	arqDisc = fopen("bdClientes.txt", "a");
	fprintf(arqDisc, "%s, %s, %s, %c\n", nome, cidade, setor, sexo);
	fclose(arqDisc);

}

// Fun��o para listagem dos clientes cadastrados
int listar(){

	// Configura o idioma de acordo com a localiza��o
    setlocale(LC_ALL, "portuguese");

	// Vari�veis
    char Linha [150];
    char *linha;

	// Manipula o arquivo bdClientes.txt abrindo-o, listando dados e fechando-o. Esse trecho de c�digo
	// ainda verifica se o arquivo existe.
    FILE *arqCadastro;
    arqCadastro = fopen("bdClientes.txt", "r");
    if(arqCadastro == NULL){
        printf("N�o foi poss�vel abrir o arquivo.\n");
        system("pause");
    }else{
        while(!feof(arqCadastro)){
            linha = fgets(Linha, 150, arqCadastro);
            printf(" %s", linha);
        }

     fclose(arqCadastro);
    }
}

// Fun��o para pesquisar clientes cadastrados
int pesquisa(){
	
	// Configura o idioma de acordo com a localiza��o
    setlocale(LC_ALL, "portuguese");
	
	// Vari�veis
    char linha[120], buscar[60];
    int n;

	// Permite a busca por um dado cliente a partir do primeiro nome
    printf("Digite o nome do cliente: ");
    scanf("%s", buscar);
	fflush(stdin);
	n = strlen(buscar);

	// Manipula o arquivo abrindo-o, pesquisando o par�metro informado
	FILE *arqCadastro;
    arqCadastro = fopen("bdClientes.txt", "r");
    fgets(linha, 120, arqCadastro);
    while(!feof(arqCadastro)){
        if(strncmp(linha, buscar, n) == 0){
            printf("Cliente encontrado: %s\n", linha);
        }
        fgets(linha, 120, arqCadastro);
        fflush(stdin);
    }
	fclose(arqCadastro);
}

// Fun��o para excluir cliente
int excluircliente(){
	
	// Configura o idioma de acordo com a localiza��o
    setlocale(LC_ALL, "portuguese");

	// Vari�veis
    char linha[120], buscar[60];
    int n;

	// Par�metro para exclus�o
	
	/*
	*	O algoritmo pede um par�metro (nome) para fazer a busca no arquivo e excluir o dado.
	*/
	
    printf("Digite o nome do cliente (apenas primeiro nome) para a busca: ");
    scanf("%s", buscar);

    fflush(stdin);

    n=strlen(buscar);

    FILE *arqCadastro, *arq_alterado;
    arqCadastro=fopen("bdClientes.txt", "r");
    arq_alterado= fopen("alterado.txt", "w");

    fgets(linha, 120, arqCadastro);

    while(!feof(arqCadastro)){
        if(strncmp(linha, buscar, n)==0){
            printf("Encontrado: %s\n", linha);
        }else{
            fprintf(arq_alterado, "%s\n", linha);
        }
    fgets(linha, 120, arqCadastro);
    fflush(stdin);

    }

    fclose(arqCadastro);
    fclose(arq_alterado);
    unlink("bdClientes.txt");
    rename("alterado.txt", "bdClientes.txt" );
}

// Fun��o principal
int main(){
	
	// Configura o idioma de acordo com a localiza��o
    setlocale(LC_ALL, "portuguese");
    
    // Vari�veis
    int opcao;
	
	// Processamento
    printf("Escolha a op��o desejada: \n");
    printf("1 - Cadastrar Clientes\n\n");
    printf("2 - Listar Clientes\n\n");
    printf("3 - Pesquisar Clientes\n\n");
    printf("4 - Excluir Cliente\n\n");
    printf("5 - Sair\n\n");
    scanf(" %d", &opcao);

    do{
        switch (opcao){
        case 1:
            incluir(opcao);
            break;

        case 2:
        	listar(opcao);
        	break;
		case 3:
			pesquisa(opcao);
			break;

        case 4:
            excluircliente(opcao);
            break;
        }
	
	printf("\n");
	printf("Escolha a op��o desejada: \n");
    printf("1 - Cadastrar Clientes\n\n");
    printf("2 - Listar Clientes\n\n");
    printf("3 - Pesquisar Clientes\n\n");
    printf("4 - Excluir Cliente\n\n");
    printf("5 - Sair\n\n");
    scanf(" %d", &opcao);

    }while(opcao != 5);

    printf("\nVoc� saiu do programa!\n");
    system("pause");
}
