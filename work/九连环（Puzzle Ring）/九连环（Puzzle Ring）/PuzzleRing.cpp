#include <iostream>
#include "Puzzle Ring.h"
using namespace std;
/*****前num个环退下*****/
void LoopDown ( int num )
{
	if ( num == 2 ) 
	{
		CircleDown ( 2 );
		CircleDown ( 1 ) ;
		return ;
	}
	if ( num == 1 ) 
	{
		CircleDown ( 1 ) ;
		return ;
	}
	LoopDown ( num - 2 ) ;
	CircleDown ( num ) ;
	LoopUp ( num - 2 ) ;
	LoopDown ( num - 1 ) ;
}
/*****第num个环退下*****/
void CircleDown ( int num )
{
	cout << num << " ↓ " ;
	count ++ ;
	if ( ! ( count % 15 ) ) cout << "\n" << endl;
}
/*****前num个环装上*****/
void LoopUp ( int num )
{
	if ( num == 2 ) 
	{
		CircleUp ( 1 ) ;
		CircleUp ( 2 ) ;
		return ;
	}
	if ( num == 1 ) 
	{
		CircleUp ( 1 ) ;
		return ;
	}
	LoopUp ( num - 1 ) ;
	LoopDown ( num - 2 ) ;
	CircleUp ( num ) ;
	LoopUp ( num - 2 ) ;
}
/*****第num个环装上*****/
void CircleUp ( int num ) 
{
	cout << num << " ↑ " ;
	count ++ ;
	if ( ! ( count % 15 ) ) cout << "\n" << endl;
}
void main () 
{
	cout << "这是类九连环游戏解法简单演示程序" << endl ;
	while ( 1 ) 
	{
		cout << "请输入游戏中圆环的个数：" << endl ;
		float num ;
		while ( 1 ) 
		{
			cin >> num ;
			num = num / 1 ;
			if ( num > 0 ) break ;
			cout << "输入数据有误，圆环数必须是大于零的整数！" << endl ;
		}
		count = 0;
		cout << "本解法将圆环编号，有手柄末端起始编号为1，\n手柄手持端最近圆环为最大编号。" << endl ;
		cout << "下面展示类九连环游戏" << num << "个圆环时的解法步骤：" << endl ;
		cout << " 选择九连环解开或安装（y解开，n安装）：" << endl ;
		char state = 'y';
		cin >> state ;
		if ( state == 'y' ) LoopDown ( num ) ;
		else LoopUp ( num ) ;
		cout << "\n共" << count << "步。" << endl ;
		cout << " 退出请输入0。任意数字重新开始。 " << endl ;
		num = 0 ;
		cin >> num ;
		if ( !num ) break;
	}
}