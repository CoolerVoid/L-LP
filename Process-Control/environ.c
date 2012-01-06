#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h> 

/*
 Un processo lavora all'interno di un sistema operativo, o meglio, e' eseguito
 nell'ambiente ben definito del sistema operativo stesso, per cui vi devono
 essere delle specifiche informazioni che consentano di lavorare all'interno 
 dell'ambiente stesso.
 
 Nei sistemi operativi UNIX vi sono diverse variabili d'ambiente, esse sono 
 caratterizzate dal formato <name = value> (es. HOME = user).
 
 L'indirizzo della lista delle variabili di ambiente e' ottenibile attraverso la
 variabile globale <environ>, un puntatore ad un array di stringhe, all'interno
 della quale ciascuna stringa indica per l'appunto una specifica variabile 
 d'ambiente.
*/

extern char **environ;

int main(int argc, char *argv[], char *envp[])
{
   char **var = environ;

   for( ; *var != NULL; var++)
      printf("%s\n", *var);

   return(EXIT_SUCCESS);
}
