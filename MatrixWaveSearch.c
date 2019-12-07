#include <stdio.h>
#include <stdlib.h>
# include <time.h>

int **mas;
int **rab;
int i;
int j;
int n;
int m;
int d = 0;
int aloc;
int cloc;
int a;
int b;
int iter = 0;
int iterk;
int min;
int x;
int y;
int x1;
int y1;

int main() {

    scanf("%d", &n);

    mas = (int**)calloc(n, sizeof(int*));
    for (i = 0; i < n; i++){
        mas[i] = (int*)calloc(n, sizeof(int));
    }

    srand((unsigned int)clock());

    m = n * n + 1;
    a = m + 1;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            mas[i][j] = rand() % 2;
            mas[i][j] += m;
        }
    }

    rab = (int**)calloc(n, sizeof(int*));
    for(i = 0; i < n; i++){
        rab[i] = (int*)calloc(n, sizeof(int));
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            rab[i][j] = mas[i][j];
        }
    }
    
    iterk = m - 1;
    min = m + 1;



    printf("\n Massiv:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%5d", mas[i][j] - m);
        }
        printf("\n");
    }
    printf("\n---— END —---\n");



    printf("шарик из какой клетки хотите переместить?\n");
    scanf("%d %d", &a, &b);

    printf("Куда переместить?\n");
    scanf("%d%d", &aloc, &cloc);

    a -= 1;
    b -= 1;
    aloc -= 1;
    cloc -= 1;

    if (mas[a][b] != min){
        printf("В этой клетке нет шарика\n");
        return 0;
    } else {
        if (mas[aloc][cloc] != m){
            printf("В этой ячейке уже есть шарик\n");
            return 0;
        } else {
            mas[a][b] = rab[a][b] = iterk;
            mas[aloc][cloc] = rab[aloc][cloc] = 0;
        }
    }

	x = a;
	y = b;

	while (iter < iterk){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (rab[i][j] == iter){
					if (i+1 < n && j+1 < n){
						if (rab[i+1][j+1] == m) {
							rab[i+1][j+1] = iter + 1;
						} else {
							if (rab[i+1][j+1] == m-1) {
								d = iter;
								iter = iterk * 2;
							}
						} 
					}

					if (i-1 > 0 && j-1 > 0){
						if (rab[i-1][j-1] == m) {
							rab[i-1][j-1] = iter + 1;
						} else {
							if (rab[i-1][j-1] == m-1) {
								d = iter;
								iter = iterk * 2;
							}
						} 
					}

					if (i+1 < n && j-1 > 0){
						if (rab[i+1][j-1] == m) {
							rab[i+1][j-1] = iter + 1;
						} else {
							if (rab[i+1][j-1] == m-1) {
								d = iter;
								iter = iterk * 2;
							}
						}
					}

					if (i-1 > 0 && j+1 < n){
						if (rab[i-1][j+1] == m) {
							rab[i-1][j+1] = iter + 1;
						} else {
							if (rab[i-1][j+1] == m-1) {
								d = iter;
								iter = iterk * 2;
							}
						}
					}
				}
			}
		}
		iter++;
	}
	printf("%d iter\n", iter);
	printf("\n MassivRAB:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%5d",rab[i][j]);
		}
		printf("\n");
	}
	printf("\n---— END —---\n");

	/*if (iter != iterk){
	printf("нет пути\n");
	return 0;
	}*/
	
	/*
	while (1){

	if (x+1 < n && y+1 < n){
	if (rab[x+1][y+1]<min){
		min = rab[x+1][y+1];
		x1 = x + 1;
		y1 = y + 1;
	}   
	}

	
	if (x-1 > 0 && y-1 > 0){
	if (rab[x-1][y-1]<min){
		min = rab[x-1][y-1];
		x1 = x - 1;
		y1 = y - 1;
	}    
	}
	
	if (x+1 < n && y-1 > 0){
	if (rab[x+1][y-1]<min){
		min = rab[x+1][y-1];
		x1 = x + 1;
		y1 = y - 1;
	}    
	}
	
	if (x-1 > 0 && y+1 < n){
	if (rab[x-1][y+1]<min){
		min = rab[x-1][y+1];
		x1 = x - 1;
		y1 = y + 1;
	}    
	}
	

	if (rab[x1][y1] == 0) {
	break;
	}

	mas[x1][y1] = -1;

	}
	*/

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (rab[i][j] == m - 1){
				x = i;
				y = j;
			}
		}
	}

	min = m - 1;
	i = 0;
	j = 0;
	while ( i == 0){
		if (x+1 < n && y+1 < n){
			if (rab[x+1][y+1]<min){
				min = rab[x+1][y+1];
    			x1 = x + 1;
				y1 = y + 1;
			}
		}


		if (x-1 > 0 && y-1 > 0){
			if (rab[x-1][y-1] < min){
				min = rab[x-1][y-1];
				x1 = x - 1;
				y1 = y - 1;
			}
		}

		if (x+1 < n && y-1 > 0){
			if (rab[x+1][y-1] < min){
				min = rab[x+1][y-1];
				x1 = x + 1;
				y1 = y - 1;
			}
		}

		if (x-1 > 0 && y+1 < n){
			if (rab[x-1][y+1] < min){
				min = rab[x-1][y+1];
				x1 = x - 1;
				y1 = y + 1;
			}
		}
		j++;
		printf("%d %d\n", rab[x1][y1], j );

		x = x1;
		y = y1;

		if (rab[x1][y1] == 0) {
			break;
		}

		mas[x1][y1] = -1;
	}




	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (rab[i][j] == m ){
				mas[i][j] = 0;
			} else {
				if (rab[i][j] == m + 1){
					mas [i][j] = 1;
				} else {
					if (rab[i][j] == 0){
						mas[i][j] = 222;
					} else {
						if (rab[i][j] == m - 1){
							mas[i][j] = 111;
						}
					}
				}
			}
		}
	}





 
	printf("\n Massiv:\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("%5d",mas[i][j]);
		}
		printf("\n");
	}
	printf("\n---— END —---\n");










	for (i = 0; i < n; i++)
		free(mas[i]);
	free(mas);

	for (i = 0; i < n; i++)
		free(rab[i]);
	free(rab);


	return 0;
}