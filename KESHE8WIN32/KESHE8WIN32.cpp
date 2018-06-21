// KESHE8WIN32.cpp : Defines the entry point for the application.

#include "stdafx.h"//windows.hͷ�ļ�
#include "resource.h"//��Դ�ļ�������ͼ��Ͱ�ť��
#include "hanshu.h"//�㷨ʵ�ֵ�ͷ�ļ�

/*�Ի������Ϣ�ص�����
һ��������Ϣ��
1. hwndDlg��handle to dialog box ��ʱ�����ı��Ի���ľ�����˾�������޸ĶԻ���ı������֡��ƶ����ڡ��رնԻ���
2.uMsg��message  WPARAM wParam, ��Ϣ�����ࣨ�����ť���������֡�����ݼ�����ͬ�������Ϣ�в�ͬ�ı�ţ�UINT������
3.wParam��first message parameter   wParam�����ͱ���һ�����ĸ��ֽڣ�wParam��Ϊ�����ָ������ֽں͵������ֽڡ�
	����Ϣ����Ϊ���¿�ݼ�ʱ�ڸ���λ�ֽ��ϼ�¼1������Ϣ����Ϊ�����ť��˵�ѡ��ʱ�ڸ���λ�ֽڣ�HIWORD���ϼ�¼0��
	����λ�ֽڣ�LOWORD���洢��Ϣ��ID��ţ�1����CANCEL��2����OK
4.lParam��second message parameter �����Ϣ�������ǵ����ť���򱻵����ť�ľ����¼��lParam�У������������ϢlParam�м�¼NULL
���������Ĺ���
�������Ի������Ϣ�ص���������Ϣ��������������Ϣ�Ƚ��нػ�Ȼ����ú������д���
��Ϣ=��Ϣ���루uMsg��+�������ݣ�wParam��lParam��
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
				lstrcat(szBuffer, "@");//ȡ��
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
			case IDC_BUTTON_FACTORIAL://�׳�
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
			case IDC_BUTTON_RESULT://��������ڵȺ��д���
				GetDlgItemText(hwndDlg,IDC_EDITSHOW1,preArr,sizeof(preArr));//��ñ༭���еı��ʽ
				memset(szBuffer,'\0',sizeof(szBuffer));//���
				//���ʽ����
				ex.get(preArr);
				if(ex.CaseDetermine()==1)//���Ǻ�������
				{
					fResult=ex.TrigonometricFunction();
					sprintf(cResult,"%f",fResult );
					SetDlgItemText(hwndDlg,IDC_EDITSHOW_RESULT,cResult);
					SetDlgItemText(hwndDlg,IDC_EDIT_SHOW2,string);
				}
				else if(ex.CaseDetermine()==2)//��ĸ���ʽ������
				{
					ex.InfixToSuffix();
					sprintf(string,"%s",ex.AfterArr);
					SetDlgItemText(hwndDlg,IDC_EDIT_SHOW2,string);
					SetDlgItemText(hwndDlg,IDC_EDITSHOW_RESULT,cResult);
				}
				else if(ex.CaseDetermine()==3)//��ֵ���ʽ�ļ���
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
			case IDCLEAR://���
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
//������
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	DialogBox(hInstance,(LPCTSTR)IDD_DIALOG1,NULL,DialogProc);
	return 0;
}



