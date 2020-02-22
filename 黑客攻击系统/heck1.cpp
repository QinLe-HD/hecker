#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include "hacker.h"
#define COLS 60
#define LINES 20

	using namespace std;
	void printitle (string title);//函数声明

	void cinPwd(char pwd[],int pwd1){//输入密码且不回显
		char ch;
		int i=0;
		while(1){
			ch= getch();
			if(ch=='\r'){
				pwd[i]=0;
				break;
			}

			pwd[i]=ch;
			i++;
			cout << "*";
		}
			
	}

	void ingo(){//函数登陆模块

		//重复验证
		while(1){
			system("cls");

			string id = "heke78";
			//string wpd = "123456";
			char pwd[32];

			cout << "请输入账号: " ;
			cin >> id;

			cout << "请输入密码: " ;
			//cin >> wpd;
			cinPwd(pwd,sizeof(pwd));

			if(id=="heke78"&&!strcmp(pwd,"123456")){	
				break;
			}else{
				cout << "用户名或者密码错误" << endl;
				system("pause");
		}
	}
		
}

void menu(){//打印菜单	
	system("cls");
	string Str[]={
		"1.网站404 攻击",
		"2.网站篡改攻击",
		"3.网站恢复攻击",
		"4.网站攻击记录",
		"5.退出"
	};
	printitle ("---黑客攻击系统---");

	//计算行数
	int colsSize= sizeof(Str)/sizeof(Str[0]);
	int max=0;

	for(int i=0;i<colsSize;i++){
		if(max < Str[i].length() ){
			max = Str[i].length();
		}
	}


	int spaceSize= (COLS-max)/2;

	for(int i=0;i<colsSize;i++){
		for(int j=0;j<spaceSize;j++){
			cout << " " ;
		}
		cout <<  Str[i] << endl;
	}
		
}

void printitle (string title){//打印标题
	int titleSize= title.length();
	int prinSize=( COLS- titleSize)/2;//计算空格长度

	for(int i=0;i<prinSize;i++){
		cout << " ";
	}

	cout << title << endl;
}

int menuShow (void){//输入菜单选择
	cout << " " << endl;
	cout << "                  请选择攻击功能对应的序号: ";
	 int n;
	while(1){		
		 cin >> n;
		 if(cin.fail()){
			cin.clear();
			cin.sync();
			cout << "输入无效请输入有效数字;";
		}else{
			break;
		}
	}

	return n;
}


void attk_404(){//404攻击
	system("cls");

	char id[64];
	char response[4096];
	cout <<"请输入要攻击网站的id: ";
	scanf_s("%s",id,sizeof(id));

	cout<< "正在执行网站404攻击......" <<endl;
	hk_404(id, response) ;//发起攻击
	string retStr = UTF8ToGBK(response); 

	cout<< retStr << endl;//打印攻击结果
	system("pause");

}


void attk_chuanGai(){//网站篡改攻击
	system("cls");
	char id[64];
	char response[4096];
	string attackText;
	string Str;

		cout << "请输入你要攻击网站的id: ";
		scanf_s("%s",id,sizeof(id));

		cout << "请输入要篡改的内容: ";
		cin>> attackText;

		cout <<"网站篡改攻击执行中......" << endl;
		GBKToUTF8(attackText);
		hk_tamper(id, (char*)attackText.c_str(), response);

		string retStr = UTF8ToGBK(response); 
		cout << retStr << endl;

		system("pause");
}


void attk_HuiFu(){//网站恢复攻击
	system("cls");
	char id[64];
	char response[4096];
	string setStr;
	cout << "请输入要恢复的网站id: ";
	scanf_s("%s",id,sizeof(id));
	cout << "网站恢复中......" <<endl;

	 hk_restore(id, response);
	 setStr = UTF8ToGBK(response);
	 cout << setStr << endl;
	 system("pause");

}


void attk_Jilu(){//网站攻击记录
	system("cls");
	char id[64];
	char response[4096];
	string setStr;
	cout << "请输入要查询网站的id: ";
	scanf_s("%s",id,sizeof(id));
	cout << "网站攻击查询中......"<< endl;

	hk_record(id,response);
	setStr = UTF8ToGBK(response);
	cout << setStr << endl;
	
	system("pause");
}


void WindoSize (void){//初始化终端大小
	char cmd[128];
	sprintf(cmd,"mode con: cols=%d lines=%d",COLS,LINES);
	system(cmd);
}

int main(void){
	WindoSize ();
	ingo();

	while(1){
		 menu ();

	     int n = menuShow();
			//黑客攻击系统攻击模块	
			switch(n){
			case 1:
				attk_404();
				break;
			case 2:
				attk_chuanGai();
				break;
			case 3:
				attk_HuiFu();
				break;
			case 4:
				attk_Jilu();
				break;
			case 5:			  
				return 0;
			default:
			cout << "无效输入,请输入有效数字" << endl;
			}		 

	}
}

