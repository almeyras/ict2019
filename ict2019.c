#include <stdio.h>
#include <math.h>

int plantas = 0;
int vivplanta = 0;
char tipopares = 'a';

int main(void) {
	// Introduccion de datos
	printf("\nIntroduce numero de plantas: ");
	scanf("%i", &plantas);
	printf("\nIntroduce numero de viviendas/planta: ");
	scanf("%i", &vivplanta);
	printf("\n¿La distancia entre RITI/RITU y PAU más lejano es inferior a 100 metros (s/n)?");
	scanf(" %c", &tipopares);
	
	printf("\n\n- Numero de PAUs = %i", plantas*vivplanta);
	printf(" + 1 (obligatorio prever ascensor) = %i PAUs", plantas*vivplanta+1);
	if( (plantas+1<4) && plantas*vivplanta+1 <= 16 )  printf("\n- Se permite recinto unico, RITU.");
		else printf("\n- Se requiere RITI+RITS.");
		
	// Pares o pares trenzados
	if (tipopares == 's') printf("\n- Pares trenzados cat6 o superior. Se necesitan %i cables (contando reserva de planta).\n", (int)ceil((plantas*vivplanta+1)*1.2));
	if (tipopares == 'n') 
		{
			printf("\n- Pares en topología ");
			if ((plantas*vivplanta+1)*2 <= 30 ) printf("estrella.");
			if ((plantas*vivplanta+1)*2 > 30 ) printf("manguera multipar.");
			printf(" Se necesitan %i pares (contando reserva de planta).\n",(int)ceil((plantas*vivplanta+1)*2*1.2));
		}	
		
	// TBA (banda ancha coaxial)	
	if (plantas*vivplanta+1 <= 20) printf("- TBA coaxial en topologia estrella. Se necesitan %i cables.", plantas*vivplanta+1);
	if (plantas*vivplanta+1 > 20) printf("- TBA coaxial en topologia arbol-rama. Se necesitan %i cables.", plantas*vivplanta+1);	
		
	// Fibra optica
	if (plantas*vivplanta+1 <= 20) printf("\n- Fibra optica en topologia estrella. Se necesitan %i fibras.", (int)ceil((plantas*vivplanta+1)*2*1.2));
	if (plantas*vivplanta+1 > 20) printf("\n- Fibra optica en topologia segregacion. Se necesitan %i fibras.", (int)ceil((plantas*vivplanta+1)*2*1.2));	
		
	
	return 0;
}
