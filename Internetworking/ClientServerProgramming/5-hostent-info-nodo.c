#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>	/* in_addr_t */
#include <netdb.h>		/* gethostbyname() hostent */


int main(int argc, char *argv[])
{
	int i;

	/* Indirizzo nella forma alfanumerica */
	char *ind_alphanum = "www.google.com";

	/* I sistemi operativi che utilizzano lo standard POSIX conservano gli
	 * indirizzi in una variabile di tipo in_addr_t */
	in_addr_t ind;

	/* La funzione gethostbyname() restituisce un puntatore alla struttura
	 * hostent, contenente svariate informazioni relative all'host, nel caso
	 * specifico le informazioni riguardano l'host ind_alphanum  */
	struct hostent *host_info;
	host_info = gethostbyname(ind_alphanum);

	if (host_info == NULL) {
		perror("gethostbyname");
		return -1;
	}

	/* Si estrae il primo indirizzo numerico mediante un cast */
	ind = *((in_addr_t*) (host_info->h_addr_list[0]));
	
	/* Si stampano tutte le informazioni circa il nodo ind_alphanum */
	printf("h_name       - nome ufficiale: ");
	for (i=0; host_info->h_name[i] != 0; i++)
		printf("%c", host_info->h_name[i]);
	/*
	printf("\nh_aliases    - lista degli alias: ");
	for (i=0; host_info->h_aliases[i] != NULL; i++) {
		char alias = *(char *)host_info->h_aliases[i];
		printf("%c", alias );
	}
	*/

	printf("\nh_addrtype   - tipo di indirizzo: %d\n", host_info->h_addrtype);
	printf("h_length     - dimensioni indirizzo: %d byte\n", host_info->h_length);
	printf("h_addr_list  - lista degli indirizzi (IP 32bit): %u\n", ind);



	

	return(EXIT_SUCCESS);
}
