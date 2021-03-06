#include <stdio.h>
#include <math.h>

int ascensor = 1; // Pon a "0" si prefieres no considerarlo como PAU
int plantas = 0;
int viviendas = 0;
char tipopares = 'a';
float acometidasstdp = 0;
int regletassalida = 0;
int regletasentrada = 0;

int main(void) {
	// Introduccion de datos
	printf("\nIntroduce numero de plantas EXCLUYENDO bajo: ");
	scanf("%i", &plantas);
	printf("\nIntroduce numero total de viviendas (generalmente multiplica plantas · viviendas/planta): ");
	scanf("%i", &viviendas);
	printf("\n¿La distancia entre RITI/RITU y PAU más lejano MENOS de 100 metros (s/n)? ");
	scanf(" %c", &tipopares);
	
	printf("\n\n- Numero de PAUs = %i", viviendas);
	printf(" + 1 (obligatorio prever ascensor) = %i PAUs", viviendas+ascensor);
	if( (plantas+ascensor<4) && viviendas+ascensor <= 16 )  printf("\n- Se permite recinto unico, RITU.");
		else printf("\n- Se requiere RITI+RITS.");
		
	// Pares o pares trenzados
	if (tipopares == 's') // pares trenzados
		{
			acometidasstdp = (int)ceil((viviendas+ascensor)*1.2);			
			printf("\n- STDP con pares trenzados cat6 o superior. Se necesitan %i cables (contando reserva de planta).", (int)acometidasstdp);
			
			regletassalida = (int)acometidasstdp;
			printf("\n  Patch panel de salida: %i tomas RJ-45.", regletassalida);
			if (viviendas+ascensor > 10) regletasentrada = (int)ceil(regletassalida*1.5);
			if (viviendas+ascensor <= 10) regletasentrada = (int)(regletassalida*2);
			printf("\n  Patch panel de entrada: %i tomas RJ-45.", regletasentrada);
		}
	if (tipopares == 'n') // pares 
		{
			printf("\n- STDP con pares en topologia ");
			if ((viviendas+ascensor)*2 <= 30 ) printf("estrella.");
			if ((viviendas+ascensor)*2 > 30 ) printf("manguera multipar.");
			acometidasstdp = (int)ceil((viviendas+ascensor)*2*1.2);
			printf(" Se necesitan %i pares (contando reserva de planta).", (int)acometidasstdp);
			
			regletassalida = (int)ceil(acometidasstdp/10);
			printf("\n  Regletas de salida: %i regletas krone de 10 pares.", regletassalida);		
			if (viviendas+ascensor > 10) regletasentrada = ceil(acometidasstdp*1.5/10);
			if (viviendas+ascensor <= 10) regletasentrada = ceil(acometidasstdp*2/10);
			printf("\n  Regletas de entrada: %i regletas krone de 10 pares.", regletasentrada);
		}	
		
	// TBA (banda ancha coaxial)	
	if (viviendas+ascensor <= 20) printf("\n- TBA coaxial en topologia estrella. Se necesitan %i cables.", viviendas+ascensor);
	if (viviendas+ascensor > 20) printf("\n- TBA coaxial en topologia arbol-rama. Se necesitan %i cables.", viviendas+ascensor);	
		
	// Fibra optica
	if (viviendas+ascensor <= 20) printf("\n- Fibra optica en topologia estrella. Se necesitan %i fibras.", (int)ceil((viviendas+ascensor)*2*1.2));
	if (viviendas+ascensor > 20) printf("\n- Fibra optica en topologia segregacion. Se necesitan %i fibras.", (int)ceil((viviendas+ascensor)*2*1.2));	
			
	return 0;
}
