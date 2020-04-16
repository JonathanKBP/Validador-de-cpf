#include<stdio.h>
#include<stdbool.h>
#include<string.h>
bool ehdigito(char c){
	return (c >='0' && c <= '9');
}
int convertenumerico(char c){
	return c - '0';	
}
void converteentrada(char entrada[], int cpf[]){
	int i = strlen(entrada)-1,j = 10;
	while (i >=0){
		if(ehdigito(entrada[i])){
			cpf[j] = convertenumerico(entrada[i]);
			j--; 
		}
		i--;		
	}
	while (j>=0){
		cpf[j]=0;
		j--;
	}
}
bool verificadigito(int cpf[], int mult[],int n){
	int i ,soma=0;
	for(i=0;i<n;i++)
		soma = soma +cpf[i]*mult[i];
	int resto = ((soma*10)%11)%10;
	return resto == cpf[n];
}
int main (){
	int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	int i,j;
	char entrada[50];
	printf("Entre com os 11 digitos do CPF:\n");
	gets (entrada);
	converteentrada(entrada,cpf);
	if(verificadigito(cpf,m1,9)&& verificadigito(cpf,m2,10)){
		printf("cpf valido\n");
		if(cpf[8]==0){
			printf("rio grande do sul\n");
		}
		else if (cpf[8]==1){
			printf("distrito federal, goias,mato grosso,Mato Grosso do Sul e Tocantins\n");
		}
		else if(cpf[8]==2){
			printf("Amazonas, Pará, Roraima, Amapá, Acre e Rondônia\n");
		}
		else if(cpf[8]==3){
			printf("Ceará, Maranhão e Piauí\n");
		}
		else if(cpf[8]==4){
			printf("paraiba,pernambuco,alagoas,rio grande do norte\n");
		}	
		else if(cpf[8]==5){
			printf("bh,sergipe\n");
		}
		else if (cpf[8]==6){
			printf("mg\n");
		}
		else if(cpf[8]==7){
			printf("rj,espirito santo\n");
		}
		else if(cpf[8]==8){
			printf("sp\n");
		}
		else{
			printf("parana,santa catarina\n");
		}
	}	
	else printf("cpf invalido\n");		
	
	return 0;
}
