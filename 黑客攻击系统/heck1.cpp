#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include "hacker.h"
#define COLS 60
#define LINES 20

	using namespace std;
	void printitle (string title);//��������

	void cinPwd(char pwd[],int pwd1){//���������Ҳ�����
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

	void ingo(){//������½ģ��

		//�ظ���֤
		while(1){
			system("cls");

			string id = "heke78";
			//string wpd = "123456";
			char pwd[32];

			cout << "�������˺�: " ;
			cin >> id;

			cout << "����������: " ;
			//cin >> wpd;
			cinPwd(pwd,sizeof(pwd));

			if(id=="heke78"&&!strcmp(pwd,"123456")){	
				break;
			}else{
				cout << "�û��������������" << endl;
				system("pause");
		}
	}
		
}

void menu(){//��ӡ�˵�	
	system("cls");
	string Str[]={
		"1.��վ404 ����",
		"2.��վ�۸Ĺ���",
		"3.��վ�ָ�����",
		"4.��վ������¼",
		"5.�˳�"
	};
	printitle ("---�ڿ͹���ϵͳ---");

	//��������
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

void printitle (string title){//��ӡ����
	int titleSize= title.length();
	int prinSize=( COLS- titleSize)/2;//����ո񳤶�

	for(int i=0;i<prinSize;i++){
		cout << " ";
	}

	cout << title << endl;
}

int menuShow (void){//����˵�ѡ��
	cout << " " << endl;
	cout << "                  ��ѡ�񹥻����ܶ�Ӧ�����: ";
	 int n;
	while(1){		
		 cin >> n;
		 if(cin.fail()){
			cin.clear();
			cin.sync();
			cout << "������Ч��������Ч����;";
		}else{
			break;
		}
	}

	return n;
}


void attk_404(){//404����
	system("cls");

	char id[64];
	char response[4096];
	cout <<"������Ҫ������վ��id: ";
	scanf_s("%s",id,sizeof(id));

	cout<< "����ִ����վ404����......" <<endl;
	hk_404(id, response) ;//���𹥻�
	string retStr = UTF8ToGBK(response); 

	cout<< retStr << endl;//��ӡ�������
	system("pause");

}


void attk_chuanGai(){//��վ�۸Ĺ���
	system("cls");
	char id[64];
	char response[4096];
	string attackText;
	string Str;

		cout << "��������Ҫ������վ��id: ";
		scanf_s("%s",id,sizeof(id));

		cout << "������Ҫ�۸ĵ�����: ";
		cin>> attackText;

		cout <<"��վ�۸Ĺ���ִ����......" << endl;
		GBKToUTF8(attackText);
		hk_tamper(id, (char*)attackText.c_str(), response);

		string retStr = UTF8ToGBK(response); 
		cout << retStr << endl;

		system("pause");
}


void attk_HuiFu(){//��վ�ָ�����
	system("cls");
	char id[64];
	char response[4096];
	string setStr;
	cout << "������Ҫ�ָ�����վid: ";
	scanf_s("%s",id,sizeof(id));
	cout << "��վ�ָ���......" <<endl;

	 hk_restore(id, response);
	 setStr = UTF8ToGBK(response);
	 cout << setStr << endl;
	 system("pause");

}


void attk_Jilu(){//��վ������¼
	system("cls");
	char id[64];
	char response[4096];
	string setStr;
	cout << "������Ҫ��ѯ��վ��id: ";
	scanf_s("%s",id,sizeof(id));
	cout << "��վ������ѯ��......"<< endl;

	hk_record(id,response);
	setStr = UTF8ToGBK(response);
	cout << setStr << endl;
	
	system("pause");
}


void WindoSize (void){//��ʼ���ն˴�С
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
			//�ڿ͹���ϵͳ����ģ��	
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
			cout << "��Ч����,��������Ч����" << endl;
			}		 

	}
}

