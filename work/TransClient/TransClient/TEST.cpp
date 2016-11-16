# include"TransClient.h"

void main()
{
	TransClient t(TransClient::File);
	
	t.init("192.168.1.134",12308);
	t.fileTrans("3.e","bobo");
	
	/*char * a = new char[6000000];
	int l = t.PicTrans( a, 6000000 );*/
	

}