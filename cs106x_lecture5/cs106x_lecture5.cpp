// cs106x_lecture5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

void Swap(void * vp1,void *vp2,int size){
	void* tmp = malloc(size);
	memcpy(tmp,vp1,size);	
	memcpy(vp1,vp2,size);
	memcpy(vp2,tmp,size);
}

int xcomp(void* vp1,void*vp2){
	if (memcmp(vp1,vp2,1) ){
		cout << "found match! Final char is"<< (char*)vp1 << endl;
		return 1;
	}
	return 0;
}
void* lsearch(
	void* key,
	void* base , 
	int elemcount,
	int elemsize, 
	int (*xcomp)(void* vp1,void* vp2)){
		for(int i=0;i<elemcount;i++){
			void *elemAddress = (char*)base + i * elemsize;
			if (xcomp(key,elemAddress)){
				return key;
			}
		}

	return NULL;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a=10;
	int b=4;
/*	cout << &a << "=" << a << endl << &b << "=" << b << endl;
	Swap(&a,&b,sizeof(int));
	cout << &a << "=" << a << endl << &b << "=" << b;

	*/
	//=====================================

	char* nodes[]={"A-","E#","Bb","D"};
	char* myfavnode = "E#";
	
	char* result = (char*)lsearch(nodes,myfavnode,4,sizeof(char*),xcomp);

	cout << result << endl;	
	system("pause");
	return 0;
}


