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
    int controlador = 0;
    int controlaSplit = 0;
    FILE *arquivo ;
    char textoLido[200];
    char linhaArquivo[50];
    char linhaNome[50];
    char linhaIdade[10];
    int j = 0;
    arquivo = fopen("teste.txt", "r") ;
    if ( arquivo == NULL ) {
        printf( "Nao foi possivel abrir arquivo." ) ;
    } else {
        while( fgets(textoLido, 200, arquivo ) != NULL ) {
            contaLinha++;
            if(contaLinha == linha){
                strcpy(linhaArquivo,textoLido);
                controlador = 1;
            }
        }
        fclose(arquivo) ;
    }
    if(controlador == 1){
        for (int i = 0; i < strlen(linhaArquivo); ++i) {
            if(linhaArquivo[i] == ','){
                controlaSplit = 1;
            }else{
                if(controlaSplit == 0){
                    linhaNome[i] = linhaArquivo[i];
                }else{
                    linhaIdade[j] = linhaArquivo[i];
                    j++;
                }
            }
        }
        printf("Nome: %s\n",linhaNome);
        printf("Idade: %s\n",linhaIdade);
    }else{
        printf( "Linha nao encontrada" ) ;
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
