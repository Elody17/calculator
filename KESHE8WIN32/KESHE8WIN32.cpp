// KESHE8WIN32.cpp : Defines the entry point for the application.

#include "stdafx.h"//windows.h头文件
#include "resource.h"//资源文件（包括图标和按钮）
#include "hanshu.h"//算法实现的头文件

/*对话框的消息回调函数
一、参数信息：
1. hwndDlg：handle to dialog box 此时弹出的本对话框的句柄，此句柄用于修改对话框的标题文字、移动窗口、关闭对话框
2.uMsg：message  WPARAM wParam, 消息的种类（点击按钮、输入文字、按快捷键）不同种类的消息有不同的编号；UINT是整型
3.wParam：first message parameter   wParam是整型变量一共有四个字节，wParam分为两部分高两个字节和低两个字节。
	当消息类型为按下快捷键时在高两位字节上记录1，当消息类型为点击按钮或菜单选项时在高两位字节（HIWORD）上记录0，
	低两位字节（LOWORD）存储消息的ID编号，1代表CANCEL，2代表OK
4.lParam：second message parameter 如果消息的种类是点击按钮，则被点击按钮的句柄记录在lParam中，其他种类的消息lParam中记录NULL
二、函数的功能
计算器对话框的消息回调函数（消息处理函数），对消息先进行截获，然后调用函数进行处理
消息=消息号码（uMsg）+附带数据（wParam、lParam）
*/
BOOL CALLBACK DialogProc(
  HWND hwndDlg,
  UINT uMsg,
  WPARAM wParam,
  LPARAM lParam) 
{
	static TCHAR szBuffer[1024]={'\0'};
	char preArr[1024]={'\0'};
	char string[1024]={'\0'};
	double fResult;
	char cResult[200]={'\0'};
	Expression ex;
	if(uMsg==WM_COMMAND)
	{
		switch(LOWORD(wParam))
		{
			case IDCANCEL:
				EndDialog(hwndDlg,IDCANCEL);
				return TRUE;
				break;
			case IDC_BUTTON_LEFT:
				lstrcat(szBuffer, "(");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_RIGHT:
				lstrcat(szBuffer, ")");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_POINT:
				lstrcat(szBuffer, ".");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON0:
				lstrcat(szBuffer, "0");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON1:
				lstrcat(szBuffer, "1");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON2:
				lstrcat(szBuffer, "2");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON3:
				lstrcat(szBuffer, "3");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON4:
				lstrcat(szBuffer, "4");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON5:
				lstrcat(szBuffer, "5");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON6:
				lstrcat(szBuffer, "6");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON7:
				lstrcat(szBuffer, "7");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
			case IDC_BUTTON8:
				lstrcat(szBuffer, "8");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON9:
				lstrcat(szBuffer, "9");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PI:
				lstrcat(szBuffer, "$");//pai
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_MOD:
				lstrcat(szBuffer, "@");//取余
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;	
			case IDC_BUTTON_PERSENT:
				lstrcat(szBuffer, "%");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_ADD:
				lstrcat(szBuffer, "+");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_REDUCE:
				lstrcat(szBuffer, "-");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_MULTIPLY:
				lstrcat(szBuffer, "*");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;	
			case IDC_BUTTON_DIVIDE:
				lstrcat(szBuffer, "/");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_XY:
				lstrcat(szBuffer, "^");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_FACTORIAL://阶乘
				lstrcat(szBuffer, "!");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTa:
				lstrcat(szBuffer, "a");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTb:
				lstrcat(szBuffer, "b");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTc:
				lstrcat(szBuffer, "c");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTd:
				lstrcat(szBuffer, "d");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTe:
				lstrcat(szBuffer, "e");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTf:
				lstrcat(szBuffer, "f");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTg:
				lstrcat(szBuffer, "g");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTh:
				lstrcat(szBuffer, "h");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTi:
				lstrcat(szBuffer, "i");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTj:
				lstrcat(szBuffer, "j");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTk:
				lstrcat(szBuffer, "k");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTl:
				lstrcat(szBuffer, "l");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTm:
				lstrcat(szBuffer, "m");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTn:
				lstrcat(szBuffer, "n");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTo:
				lstrcat(szBuffer, "o");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTp:
				lstrcat(szBuffer, "p");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTq:
				lstrcat(szBuffer, "q");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTr:
				lstrcat(szBuffer, "r");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTs:
				lstrcat(szBuffer, "s");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTt:
				lstrcat(szBuffer, "t");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTu:
				lstrcat(szBuffer, "u");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTv:
				lstrcat(szBuffer, "v");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTw:
				lstrcat(szBuffer, "w");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTx:
				lstrcat(szBuffer, "x");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTy:
				lstrcat(szBuffer, "y");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_PERSENTz:
				lstrcat(szBuffer, "z");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_SIN:
				lstrcat(szBuffer, "S");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_COS:
				lstrcat(szBuffer, "C");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_TAN:
				lstrcat(szBuffer, "T");
		 		SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				return TRUE;
				break;
			case IDC_BUTTON_RESULT://运算过程在等号中处理
				GetDlgItemText(hwndDlg,IDC_EDITSHOW1,preArr,sizeof(preArr));//获得编辑框中的表达式
				memset(szBuffer,'\0',sizeof(szBuffer));//清空
				//表达式处理
				ex.get(preArr);
				if(ex.CaseDetermine()==1)//三角函数运算
				{
					fResult=ex.TrigonometricFunction();
					sprintf(cResult,"%f",fResult );
					SetDlgItemText(hwndDlg,IDC_EDITSHOW_RESULT,cResult);
					SetDlgItemText(hwndDlg,IDC_EDIT_SHOW2,string);
				}
				else if(ex.CaseDetermine()==2)//字母表达式的运算
				{
					ex.InfixToSuffix();
					sprintf(string,"%s",ex.AfterArr);
					SetDlgItemText(hwndDlg,IDC_EDIT_SHOW2,string);
					SetDlgItemText(hwndDlg,IDC_EDITSHOW_RESULT,cResult);
				}
				else if(ex.CaseDetermine()==3)//数值表达式的计算
				{
					ex.InfixToSuffix();
					sprintf(string,"%s",ex.AfterArr );
					SetDlgItemText(hwndDlg,IDC_EDIT_SHOW2,string);
					fResult=ex.SuffixExpressionEvaluation ();
					sprintf(cResult,"%f",fResult );
					SetDlgItemText(hwndDlg,IDC_EDITSHOW_RESULT,cResult);
				}
				return TRUE;
				break;
			case IDCLEAR://清除
				memset(szBuffer,'\0',sizeof(szBuffer));
				memset(preArr,'\0',sizeof(preArr));
				memset(string,'\0',sizeof(string));
				memset(cResult,'\0',sizeof(cResult));
				SetDlgItemText(hwndDlg,IDC_EDITSHOW1,szBuffer);
				SetDlgItemText(hwndDlg,IDC_EDIT_SHOW2,string);
				SetDlgItemText(hwndDlg,IDC_EDITSHOW_RESULT,cResult);
				return TRUE;
				break;
		}
		return TRUE;
	}
	return FALSE;
}
//主程序
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	DialogBox(hInstance,(LPCTSTR)IDD_DIALOG1,NULL,DialogProc);
	return 0;
}



