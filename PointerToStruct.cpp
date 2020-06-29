/*5. Realice un programa que le permita al usuario: a) imprimir la información
del empleado (id de empleado, nombre y RFC), b) sus pagos quincenales y
mensuales, o c) el promedio anual de ingresos de todos los empleados. (2
puntos)
Notas:
1. La información de los empleados debe almacenarse en un arreglo de estructuras.
2. Las búsquedas se tienen que hacer recorriendo el arreglo con un apuntador usando el
id de empleado.
3. Debe haber funciones y, en todas ellas, usarse parámetros por valor y por referencia.*/
#include <stdlib.h> 
#include <stdio.h>

typedef struct {
	int id;
	float salario;
	char nombre[50];
	char rfc[50];
}empleado;

void introducir(empleado *data, float n);
void buscar(empleado *data, int id, float n);
void pagos(empleado *data, int id, float n);
void pago_quincenal(float salario);
void pago_mensual(float salario);
void promedio_anual(empleado *data, float n);

int main(){
	empleado *p;
	int i,j,m,l,opcion,id, auxmateria,mayor, auxid;
	float n;
	printf("Cuantos empleados ingresaras: ");
	scanf("%f",&n);
	p = (empleado *)malloc(n*sizeof(empleado));
	introducir(p,n);
	
	
	do{
		printf("\n1.-Informacion del Empleado\n 2.-Pagos Quincenales y Mensuales\n 3.-Promedio anual de Ingresos de todos los empleados\n 4.-Salir\n");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				printf("1.-Informacion del Empleado");
				printf("Empleado a Buscar conforme a su ID: ");
				scanf("%i", &id);
				buscar(p,id,n);
				break;
			case 2:
				printf("2.-Pagos Quincenales y Mensuales\n");
				printf("Empleado a Buscar conforme a su ID: ");
				scanf("%i", &id);
				pagos(p,id,n);
				break;
			case 3:
				printf("3.-Promedio anual de Ingresos de todos los empleados\n");
				promedio_anual(p,n);
				break;
		}
	}while(opcion!=5);
 
	return 0;
}

void introducir(empleado *data, float n){
	int i,j;
	for(i=0;i<n;i++){
		data[i].id=i;
		printf("Nombre del empleado: ");
		scanf(" %[^\n]",&data[i].nombre);
	
		
		printf("Cual es tu salario: ");
		scanf("%f",&data[i].salario);
			
		printf("Cual es tu rfc: ");
		scanf(" %[^\n]",&data[i].rfc);
	}
}

void buscar(empleado *data, int id, float n){
	printf("Datos:\n");
	for(int i=0;i<n;i++,data++){
		if(id==data->id){
			printf("ID del empleado: %i\n",data->id);		
			printf("Nombre del empleado: %s\n",data->nombre);
			printf("RFC del empleado: %s\n",data->rfc);
			printf("Salario del empleado: %.2f\n",data->salario);
		}
	}
}

void pagos(empleado *data, int id, float n){
	for(int i=0;i<n;i++,data++){
		if(id==data->id){
			printf("ID del empleado: %i\n",data->id);		
			printf("Nombre del empleado: %s\n",data->nombre);
			printf("Salario del empleado: \n");
			pago_quincenal(data->salario);
			pago_mensual(data->salario);
		}
	}
}

void pago_quincenal(float salario){
	float salarioq = salario * 15;
	printf("Salario Quincenal: %.2f \n", salarioq);
}

void pago_mensual(float salario){
	float salariom = salario * 30;
	printf("Salario Mensual: %.2f \n", salariom);
}

void promedio_anual(empleado *data, float n){
	float aux, aux1, aux2;
	printf("Promedio de Salarios: \n");
	for(int i=0;i<n;i++){
		
		aux=aux + data[i].salario;
	}
	
	aux1 = aux*365;
	aux2=  aux1/n;
	printf("Promedio: %f", aux2);
}
