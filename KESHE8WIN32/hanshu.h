#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

/*求某个数值任意幂的函数
一、参数信息
1.x：代表任意底数，double类型
2.i：用作循环变量，int类型
3.n：代表指数，int类型
4.p：用于存储计算结果，double类型
二、函数的功能
用于计算x的n次幂，n必须为整数*/
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

/*求阶乘函数
一、参数信息
1.x：被计算的数值
二、函数的功能
通过递归计算x的阶乘，且x必须为整数
*/
double Factorial(int x)
{
	if(x==1)
		return 1;
	else
		return Factorial(x-1)*x;
}

/*浮点型数据栈的类
功能:
1.取栈顶元素
2.栈顶元素出栈
3.元素入栈
4.判断栈是否为空（空返回1否则返回0）
栈中存储的元素类型必须是浮点型*/
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

//中缀变换成后缀是临时存储字符的字符栈
/*功能:
1.取栈顶元素
2.栈顶元素出栈
3.元素入栈
4.判断栈是否为空（空返回1否则返回0）
栈中存储的元素类型必须是字符型*/
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

//对表达式进行处理的类
class Expression
{
private:
	char InArr[1024];						//中缀表达式
	DStack dsta;                            //浮点型数据栈
	CStack csta;                            //字符栈
	char arr[20];                           //临时数组，存放多位浮点数
public:	
	char AfterArr[1024];                    //后缀表达式
	Expression(){}							//构造函数
    void get(char preArr[]){strcpy(InArr,preArr);}//将字符串preArr中的内容拷贝到InArr中
	int CaseDetermine();                          //情况判定
	void InfixToSuffix();						  //将中缀表达式转化成后缀表达式，数字，运算符两两之间加空格
	double SuffixExpressionEvaluation ();         //后缀表达式求值
	double TrigonometricFunction();               //三角函数求值
	~Expression(){}                               //析构函数
};
//情况判定
int Expression::CaseDetermine ()
{
	if(InArr[0]=='\0')return 0;         //如果输入为空则返回0
	else if(isupper(InArr[0])) return 1;//如果是大写字母，即代表是三角函数运算，返回1
	else if(islower(InArr[0])) return 2;//如果是小写字母，即代表字母表达式的运算，返回2
	else return 3;                      //返回3，代表正常数值表达式的计算
}
//三角函数的计算
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
//将中缀表达式转化成后缀表达式
void Expression::InfixToSuffix()
{	
	int j,k;
	char c,x,ch;
	j=k=0;
	x=InArr[k];
	while(x!='\0')            
	{
		while( isdigit(x)!=0 || x=='.' || islower(x)!=0 ||x=='$')//$表示数学公式中的pai；isalpha判断是否为字母（包括大小写）
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
		else if(x=='*' || x=='/' || x=='@')//@代表取余运算												
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
			if(csta.IsEmpty())//如果栈为空，可以直接将加减号入栈
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
			MessageBox(NULL,"存在不合法输入！程序已略去不合法字符。\n如需重新计算，请先清除然后重新输入","出错提示",MB_OK | MB_ICONHAND);
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
//后缀表达式求值
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
			arr[j]='\0';//不能省
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
		case '^'://代表求x的n次幂
				b=dsta.Pop();
				a=dsta.Pop();
				dsta.Push(Power(a,b));
				break;
			case '!'://代表求阶乘
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
			case '@'://代表取余运算
				b=dsta.Pop();
				a=dsta.Pop();
				if(b==0)
				{
					MessageBox(NULL,"取余运算的除数不能为零！请先清除然后重新输入","出错提示",MB_OK | MB_ICONHAND);
				}
				else dsta.Push((int)a%(int)b);
				break;
			case '/':
				b=dsta.Pop();
				a=dsta.Pop();
				if(b==0)
				{
					MessageBox(NULL,"除数不能为零！请先清除然后重新输入","出错提示",MB_OK | MB_ICONHAND);
				}
				else dsta.Push(a/b);
				break;
			case '%'://用作百分号
				a=dsta.Pop()/100;
				dsta.Push(a);
				break;
		}
		i++;
	}
	a=dsta.Pop();
	return a;
}