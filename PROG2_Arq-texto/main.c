#include <stdio.h>
#include <string.h>

int escreverArquivo(char nome[50],int idade){
    char idadeString[10];
    char texto[50] = "";
    sprintf(idadeString,"%d",idade); //TRANFORMA A IDADE EM STRING

    //CONCATENA AS INFORMACOES EM UM TEXTO
    strcat(texto,nome);
    strcat(texto,", ");
    strcat(texto,idadeString);

    //SALVA NO ARQUIVO AS INFORMACOES
    FILE *arquivo;
    arquivo = fopen("./teste.txt", "a+") ;
    if ( arquivo == NULL ) {
        return 0;
    } else {
        if ( strlen(texto) > 0 ) {
            fputs(texto, arquivo) ;
            fputs("\n", arquivo) ;
        }
        fclose(arquivo) ;
        return 1;
    }

}

void lerArquivo(){
    FILE *arquivo ;
    char textoLido[200];
    arquivo = fopen("teste.txt", "r") ;
    if ( arquivo == NULL ) {
        printf( "Nao foi possivel abrir arquivo." ) ;
    } else {
        while( fgets(textoLido, 200, arquivo ) != NULL ) {
            printf( "%s " , textoLido ) ;
        }
        fclose(arquivo) ;
    }

}

void lerLinhaEspecifica(int linha){

    int contaLinha =0;
    char linhaNome[50];
    char linhaIdade[50];
    FILE *arquivo ;
    arquivo = fopen("teste.txt", "r") ;
    if ( arquivo == NULL ) {
        printf( "Nao foi possivel abrir arquivo." ) ;
    } else {
        if(linha > 1){
            while(contaLinha!=(linha*2)-1){
                fscanf(arquivo, "%s", linhaNome); //lê uma linha
                contaLinha++;
            }
            while(contaLinha!=linha*2){
                fscanf(arquivo, "%s", linhaIdade); //lê uma linha
                contaLinha++;
            }
        }else{
            while(contaLinha!=linha){
                fscanf(arquivo, "%s", linhaNome); //lê uma linha
                contaLinha++;
            }
            while(contaLinha!=linha+1){
                fscanf(arquivo, "%s", linhaIdade); //lê uma linha
                contaLinha++;
            }
        }
        linhaNome[strlen(linhaNome)-1] = '\0';
        printf("Nome %s\n",linhaNome);
        printf("Idade: %s\n",linhaIdade);
        fclose(arquivo) ;
    }

}

int main() {
    int linha;
    int resp;
    char nome[50] = "";
    int idade;
    printf("BEM-VINDO...\n");
    do {
        printf("1 - Apresentar todo conteudo do arquivo\n");
        printf("2 - Apresentar conteudo de um registro\n");
        printf("3 - Cadastrar um registro\n");
        printf("4 - Fechar o programa\n");
        printf("SELECIONE A OPCAO QUE DESEJA:\n");
        scanf("%d",&resp);
        getchar();
        switch (resp) {
            case 1:
                printf("MOSTRAR REGISTROS:\n\n");
                lerArquivo();
                break;
            case 2:
                printf("SELECIONAR REGISTRO:\n\n");
                printf("Informe a linha que deseja ler:\n");
                scanf("%d",&linha);
                getchar();
                lerLinhaEspecifica(linha);
                break;
            case 3:
                printf("CADASTRO DE REGISTROS:\n\n");

                printf("Informe o nome da pessoa:\n");
                fgets(nome,50,stdin);
                nome[strlen(nome)-1] = '\0';

                printf("Informe a idade da pessoa:\n");
                scanf("%d",&idade);
                getchar();

                int confirmacao = escreverArquivo(nome,idade);
                if(confirmacao == 1){
                    printf("CADASTRADO COM SUCESSO\n");
                }else{
                    printf("ERRO NO CADASTRO! TENTE NOVAMENTE\n");
                }
                break;
            case 4:
                printf("FECHAR PROGRAMA\n");
                break;
            default:
                printf("ENTRADA INVALIDA\n");
                break;
        }
        printf("\n");
        printf("----------------------------------------------------\n");
    }while(resp != 4);
}
