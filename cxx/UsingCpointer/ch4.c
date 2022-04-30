int main(){
	int iivector[5];
	int vector[] = {1,2,3,4,5};
	len  = sizeof(vector)/sizeof(int);
	int matrix[2][3] = {{1,2,3},{1,2,3}};
	int *pv = vector;
	int value = 3;
	int i = 0;
	for (i = 0; i < 5; i++){
		*pv++ *= value;	
	}

	int *pv = (int *) malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++){
		pv[i] = value;			
	}

}
