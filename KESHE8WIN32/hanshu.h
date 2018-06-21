#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

/*��ĳ����ֵ�����ݵĺ���
һ��������Ϣ
1.x���������������double����
2.i������ѭ��������int����
3.n������ָ����int����
4.p�����ڴ洢��������double����
���������Ĺ���
���ڼ���x��n���ݣ�n����Ϊ����*/
double Power(double x,int n)
{
	int i;
	double p=1.0;
	for(i=1;i<=n;i++)
	{
		p*=x;
	}
	return p;
}

/*��׳˺���
һ��������Ϣ
1.x�����������ֵ
���������Ĺ���
ͨ���ݹ����x�Ľ׳ˣ���x����Ϊ����
*/
double Factorial(int x)
{
	if(x==1)
		return 1;
	else
		return Factorial(x-1)*x;
}

/*����������ջ����
����:
1.ȡջ��Ԫ��
2.ջ��Ԫ�س�ջ
3.Ԫ����ջ
4.�ж�ջ�Ƿ�Ϊ�գ��շ���1���򷵻�0��
ջ�д洢��Ԫ�����ͱ����Ǹ�����*/
class DStack                                
{
private:
	double datasta[100];
	int top;
public:
	DStack(){top=-1;}
	double Pop(){return datasta[top--];}
	double Get(){return datasta[top];}
	void Push(double x){datasta[++top]=x;}
	int IsEmpty(){if(top==-1)return 1;else return 0;}
};

//��׺�任�ɺ�׺����ʱ�洢�ַ����ַ�ջ
/*����:
1.ȡջ��Ԫ��
2.ջ��Ԫ�س�ջ
3.Ԫ����ջ
4.�ж�ջ�Ƿ�Ϊ�գ��շ���1���򷵻�0��
ջ�д洢��Ԫ�����ͱ������ַ���*/
class CStack      
{
private:
	char datasta[100];
	int top;
public:
	CStack(){top=-1;}
	char Pop(){return datasta[top--];}
	char Get(){return datasta[top];}
	void Push(char x){datasta[++top]=x;}
	int IsEmpty(){if(top==-1)return 1;else return 0;}
};

//�Ա��ʽ���д������
class Expression
{
private:
	char InArr[1024];						//��׺���ʽ
	DStack dsta;                            //����������ջ
	CStack csta;                            //�ַ�ջ
	char arr[20];                           //��ʱ���飬��Ŷ�λ������
public:	
	char AfterArr[1024];                    //��׺���ʽ
	Expression(){}							//���캯��
    void get(char preArr[]){strcpy(InArr,preArr);}//���ַ���preArr�е����ݿ�����InArr��
	int CaseDetermine();                          //����ж�
	void InfixToSuffix();						  //����׺���ʽת���ɺ�׺���ʽ�����֣����������֮��ӿո�
	double SuffixExpressionEvaluation ();         //��׺���ʽ��ֵ
	double TrigonometricFunction();               //���Ǻ�����ֵ
	~Expression(){}                               //��������
};
//����ж�
int Expression::CaseDetermine ()
{
	if(InArr[0]=='\0')return 0;         //�������Ϊ���򷵻�0
	else if(isupper(InArr[0])) return 1;//����Ǵ�д��ĸ�������������Ǻ������㣬����1
	else if(islower(InArr[0])) return 2;//�����Сд��ĸ����������ĸ���ʽ�����㣬����2
	else return 3;                      //����3������������ֵ���ʽ�ļ���
}
//���Ǻ����ļ���
double Expression::TrigonometricFunction ()
{
	int i,j;
	double a;
	for(i=1,j=0;InArr[i]!='\0';i++,j++)
	{
		arr[j]=InArr[i];
	}
	arr[j]='\0';
	a=atof(arr);
	if(InArr[0]=='S') a=sin(a);
	else if(InArr[0]=='C')a=cos(a);
	else a=tan(a);
	return a;
}
//����׺���ʽת���ɺ�׺���ʽ
void Expression::InfixToSuffix()
{	
	int j,k;
	char c,x,ch;
	j=k=0;
	x=InArr[k];
	while(x!='\0')            
	{
		while( isdigit(x)!=0 || x=='.' || islower(x)!=0 ||x=='$')//$��ʾ��ѧ��ʽ�е�pai��isalpha�ж��Ƿ�Ϊ��ĸ��������Сд��
		{
			if(x=='$')
			{
				AfterArr[j++]='3';
				AfterArr[j]='\0';
				AfterArr[j++]='.';
				AfterArr[j]='\0';
				AfterArr[j++]='1';
				AfterArr[j]='\0';
				AfterArr[j++]='4';
				AfterArr[j]='\0';
				AfterArr[j++]=' ';
				AfterArr[j]='\0';
				k++;x=InArr[k];
				if(x=='=')break;
			}
			else
			{
				AfterArr[j++]=x;
				AfterArr[j]='\0';
				k++;x=InArr[k];
				if(isdigit(x)==0 && x!='.')
				{
					AfterArr[j++]=' ';
					AfterArr[j]='\0';
				}
			}
		}
		if(x=='(')                  
		{
			csta.Push(x);
		}
		else if(x==')')
		{
			c=csta.Pop();
			while(c!='(')
			{
				AfterArr[j++]=c;
				AfterArr[j]='\0';
				AfterArr[j++]=' ';
				AfterArr[j]='\0';
				c=csta.Pop();
			}
		}
		else if(x=='!'||x=='%') 
		{
			AfterArr[j++]=x;
			AfterArr[j]='\0';
			AfterArr[j++]=' ';
			AfterArr[j]='\0';
		}
		else if(x=='^')
		{
			csta.Push(x);
		}
		else if(x=='*' || x=='/' || x=='@')//@����ȡ������												
		{				
					c=csta.Get();
					if(c=='^')
					{
						ch=csta.Pop();
						AfterArr[j++]=ch;
						AfterArr[j]='\0';

					}	
				 else	while(csta.IsEmpty()!=1 && c!='(' && (c=='*' || c=='/'||c=='@'))
							{
								ch=csta.Pop();
								AfterArr[j++]=ch;
								AfterArr[j]='\0';
							}
					csta.Push(x);
		}
		else if(x=='+' || x=='-')
		{
			if(csta.IsEmpty())//���ջΪ�գ�����ֱ�ӽ��Ӽ�����ջ
			{
				csta.Push(x);
			}
			else 
			{
				c=csta.Get();
				if(c=='^')
				{
					ch=csta.Pop();
					AfterArr[j++]=ch;
					AfterArr[j]='\0';
				}
				else
				{
						do
						{
							c=csta.Pop();
							if(c=='(')
								csta.Push(c);
							else
							{
								AfterArr[j++]=c;
								AfterArr[j]='\0';
								AfterArr[j++]=' ';
								AfterArr[j]='\0';
							}
						}while(c!='('&&csta.IsEmpty()!=1);
				}
				csta.Push(x);
			}
		}
		else if(x=='\0')break;
		else 
		{
			MessageBox(NULL,"���ڲ��Ϸ����룡��������ȥ���Ϸ��ַ���\n�������¼��㣬�������Ȼ����������","������ʾ",MB_OK | MB_ICONHAND);
		}
		k++;x=InArr[k];
	}
	while(csta.IsEmpty()!=1)
	{
		c=csta.Pop();
		AfterArr[j++]=c;
		AfterArr[j]='\0';
		AfterArr[j++]=' ';
		AfterArr[j]='\0';
	}	
}
//��׺���ʽ��ֵ
double Expression::SuffixExpressionEvaluation()
{
	int i,j;
	double a,b;
	j=0;
	i=0;
	while(AfterArr[i]!='\0')
	{
		while(isdigit(AfterArr[i])!=0 || AfterArr[i]=='.')
		{
			arr[j++]=AfterArr[i];
			arr[j]='\0';//����ʡ
			i++;
			if(AfterArr[i]==' ')
			{
				a=atof(arr);
				dsta.Push(a);
				j=0;
				break;
			}
		}
		switch (AfterArr[i])
		{
		case '^'://������x��n����
				b=dsta.Pop();
				a=dsta.Pop();
				dsta.Push(Power(a,b));
				break;
			case '!'://������׳�
				a=dsta.Pop();
				b=Factorial(a);
				dsta.Push(b);
				break;
			case '+':
				b=dsta.Pop();
				a=dsta.Pop();
				dsta.Push(a+b);
				break;
			case '-':
				b=dsta.Pop();
				a=dsta.Pop();
				dsta.Push(a-b);
				break;
			case '*':
				b=dsta.Pop();
				a=dsta.Pop();
				dsta.Push(a*b);
				break;
			case '@'://����ȡ������
				b=dsta.Pop();
				a=dsta.Pop();
				if(b==0)
				{
					MessageBox(NULL,"ȡ������ĳ�������Ϊ�㣡�������Ȼ����������","������ʾ",MB_OK | MB_ICONHAND);
				}
				else dsta.Push((int)a%(int)b);
				break;
			case '/':
				b=dsta.Pop();
				a=dsta.Pop();
				if(b==0)
				{
					MessageBox(NULL,"��������Ϊ�㣡�������Ȼ����������","������ʾ",MB_OK | MB_ICONHAND);
				}
				else dsta.Push(a/b);
				break;
			case '%'://�����ٷֺ�
				a=dsta.Pop()/100;
				dsta.Push(a);
				break;
		}
		i++;
	}
	a=dsta.Pop();
	return a;
}