#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()//Função responsavel por cadastrar os usuários no sistema
{
	//Inicio da criação de variavéis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	////Final da criação de variavéis/strings
	
	printf("Digite o CPF a ser cadastrado:");//Coletando Informação do usuário
	scanf("%s", cpf);//%s refere-se a string (Toda vez que precisar salvar uma string)
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");// abre um arquivo ja criado e o "a" significa exatamente abrir o arquivo ja criado
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//Lê um arquivo ja criado o "r" lê um arquivo ja criado 
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
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
	
	printf("Digite o CPF dp usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usuário não se encontra no sistema!\n");
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
        		
    	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
        printf("---------- Cartório da EBAC ----------\n\n"); //Inicio do menu
        printf("Escolha a opção desejada do menu\n\n");
	    printf("\t1 Registrar nomes\n");
	    printf("\t2 Consultar nomes\n");
	    printf("\t3 Deletar nomes\n\n");
	    printf("Opção: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazendando a escolha do usuário
	
	    system("cls");//Responsável por limpar a tela
	    	    
	    switch(opcao)
	    {
	    	case 1:
	    	registro();	//chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponivel!\n\n");	
	    	system("pause");
			break;	
		}
    }
}




