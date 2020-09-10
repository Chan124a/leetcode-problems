#include <stack>
#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include <unordered_map>
#include <time.h>
using namespace std;
//struct fraction {
//	int num;
//	int denum;
//};
//struct student {
//	char* name;
//	char suid[8];
//	int numUnits;
//};
void* isearch(void* key, void* base, int n, int elemsize, int (*cmpfn)(void*, void*)) {
	for (int i = 0; i < n; i++)
	{
		void* elemaddr = (char*)base + i * elemsize;
		if (cmpfn(key, elemaddr) == 0)return elemaddr;
	}
	return NULL;
}
int intcmp(void* elem1, void* elem2) {
	int* ip1 = (int *)elem1;
	int* ip2 = (int*)elem2;
	return *ip1 = *ip2;
}
int StrCmp(void* vp1, void* vp2) {
	char* s1 = *(char**)vp1;
	char* s2 = *(char**)vp2;
	return strcmp(s1, s2);
}
int main() {
	//第2课代码

	//int i = 5;  //00000000 0000000 00000000 00000101
	//float f = i;  //5=1.25*2^2, 0 10000001 01000000000000000000000 ,这里指数10000001为2+127=129，0.25=2^-2
	//cout << f << endl; //输出结果为5

	//int i = 37;   //00000000 00000000 00000000 00100101
	//float f = *(float*)&i; //&i对应的地址（指针）类型为 int *，（float *）将int * 转换为 float *类型，*表示读取该地址的数据.此时的结果将会把i对应的二进制数值解释为float类型
	//cout << f << endl;  //输出结果为 (1+2^-21+2^-23)*2^-127 

	//f = 7.0;
	//short s = *(short*)&f;  //假设 f对应的二进制位为 1******* 2******* 3******* 4*******,并且是在大端机器上运行，那么这里会将 1******* 2*******复制给s
	//int arr[5];

	//第3课代码

	//fraction pi;
	//pi.num = 22;
	//pi.denum = 7;
	//((fraction*)&(pi.denum))->num = 12;
	//((fraction*)&(pi.denum))->denum = 33;
	//cout << sizeof(fraction) << endl;
	//cout << sizeof(fraction*) << endl;

	//int arr[5];
	//arr[3] = 128;
	//cout << sizeof(short) << endl;
	//cout << sizeof(short*) << endl;
	////cout << sizeof(char*) << endl;
	////cout << sizeof(char) << endl;
	//cout << arr + 3 << endl;
	//((short*)arr)[6] = 2;
	//((short*)arr)[5] = 3;
	//cout << arr[3] << endl;
	//((short*)(((char*)(&arr[1])) + 8))[3] = 100;

	//student pupils[4];
	//pupils[0].numUnits = 21;
	//pupils[2].name = strdup("Adam");
	//pupils[3].name = pupils[0].suid + 6;
	//strcpy(pupils[1].suid, "40415xx");
	//strcpy(pupils[3].name, "123456");
	//cout << pupils[3].name << endl;
	
	
	/*char* str[] = { "hello","c++","world" };
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", str[i]);
	}*/

	//第5课
	//int arr[] = { 4,2,3,7,11,6 };
	//int size = 6;
	//int number = 7;
	//int *found = (int*)isearch(&number, arr, 6, sizeof(int), intcmp);
	char* notes[] = { "Ab","F#","B","Gb","D" };
	char notes2[] = "AAAAA BBBB CCCC   ";
	char* favoretenote = "Eb";
	char** found = (char **)isearch(&favoretenote, notes, 5, sizeof(char*), StrCmp);
}