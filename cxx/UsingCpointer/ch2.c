#include <stdlib.h> // for malloc,realloc
#include <string.h> // for strcpy
#include <stdio.h> // for printf
#define RAII_VARIABLE(vartype,varname,initval,dtor) \
    void _dtor_ ## varname (vartype * v) { dtor(*v); } \
    vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)

void print(const char *str,const char* name){
	printf("String %s Value: %p [%s]\n",name,str,str);
}

void raiiEaxmple(){
	RAII_VARIABLE(char* ,name, (char *)malloc(32), free);
	strcpy(name,"RAII Eaxmple!");
	printf("%s\n",name);
}

int main(){
	
	raiiEaxmple();
//	char *string1;
//	char *string2;
//	char *string3;
//	string1 = (char*) malloc(16); // malloc 16 byte
//	strcpy(string1,"0123456789AB"); // only using 13 byte
//	string2 = realloc(string1,8);
//	string3 = realloc(string1,64);
//	print(string1,"1");
//	print(string2,"2");
//	print(string3,"3");
	
	return 0;
}

