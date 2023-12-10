#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "1.2decla.h"
int main() {
	int sel;
	for (;;) {
		printf("Enter selection: ");
		scanf("%d", &sel);
		switch (sel) {

		case 1: {
			insert();
			break;
		}
		case 2: {
			search();
			break;
		}
		case 3: {
			update();
			break;
		}

		case 4: {
			display();
			break;
		}
		case 5: {
			printf("\nBye!");
			return 0;
		}
		default: {
			printf("\nError! Not in the options\n");
			break;
		}
		}
	}

	return 0;
}
/*
  ___ ____      _ _ ____  ____ ____   ___  _ _____ __
 |_ _|  _ \ _  / / |___ \| ___| ___| / _ \/ |___  / /_
  | || | | (_) | | | __) |___ \___ \| | | | |  / / '_ \
  | || |_| |_  | | |/ __/ ___) |__) | |_| | | / /| (_) |
 |___|____/(_) |_|_|_____|____/____/ \___/|_|/_/  \___/

*/

 
