#include<iostream>
void sizeofPointer(){
	char szNum[] = "0123";
	char *pszNum = "0123";
	char mszBuff[40];
	char *p;

	p = mszBuff;
	memset(mszBuff,0,sizeof(mszBuff));
	memcpy(mszBuff,szNum,4);
	mszBuff[4] += sizeof(p) + sizeof(pszNum) + sizeof(szNum) + sizeof(mszBuff);
	/*cout<<mszBuff<<endl;*/
	printf(mszBuff);
}
//int main(){
//	t();
//	return 0;
//}