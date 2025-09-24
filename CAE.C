#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings 

int registro() //Função responsável por cadastrar os usuários no sistema

{
	//Início da criação de variáveis/strings
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Final da criação de variáveis/strings
	
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
		FILE *file; // Cria o arquivo
		file = fopen(arquivo, "w"); // Cria o arquivo
		fprintf(file,cpf); // Salva o valor da variável
		fclose(file); // Fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen(arquivo, "a"); 
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
		
		file = fopen(arquivo, "a");
 		fprintf(file,cargo);
		fclose(file);
		
		system ("pause");
	
	
	}

int consulta()

{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	 printf("digite o cpf a ser consultado: ");
	 scanf("%s",cpf);
	 
	 FILE *file;
	 file = fopen(cpf,"r");
	 
	 if(file == NULL)
	 {
	 	printf("Não foi possível abrir o arquivo / Arquivo não localizado!.\n");
	 }
	 
	 while (fgets(conteudo, 200, file) != NULL)
	 {
	 	printf("\nEssas são as informações do usuário: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");
	 
}

int deletar()

{
	char cpf[40];
	
	printf("Digite o cpf do usuário a ser inexistido: "); //Ignorar a parte de "inexistido" é referência a gostos de RPG do programador :)
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuário Inexistido / Usuário Inexistente!.\n");
		system("pause");
	}
	
}


int main ()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");
	
	setlocale(LC_ALL, "portuguese"); //Definindo linguagem
	
	printf("### Bem-vinde a CAE: Central de Alunos da EBAC ###\n\n"); // Início do menu
	printf("Escolha a opção desejada abaixo: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("opção: ");//Fim do menu
	
	scanf("%d", &opcao); //Armazenando escolha do usuário
	
	system("cls"); //Responsável por limpar a tela
	
	
	switch(opcao) //Início da seleção de menu
	{
	    case 1: //Chamada de funções
        registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		 
	    default:
		printf("Essa opção não está disponível!\n");
		system("pause");
		break;
	}	// Fim da seleção
	
}
}
