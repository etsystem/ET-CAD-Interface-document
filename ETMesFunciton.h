// mgGLFile.h: interface for the mgGLFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ET_MES_FUNCTION_H__C6A03DCE_0A14_4775_8948_7A34461F061E__INCLUDED_)
#define AFX_ET_MES_FUNCTION_H__C6A03DCE_0A14_4775_8948_7A34461F061E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//���ص���������
struct TASK_DATA
{
	int id;			//����ID
	int process;	//�������
	int pod;		//pod���
	int taskState;	//����״̬��0δ���䣬1�ѷ��䣬2�����
	int modelFile;	//�������Ŀ¼���Ƿ�����ʽ�ļ�,0��ʾû��
	CString error;	//������Ϣ
	CString name;	//������
	CString model;	//��ʽ��
	CString json;	//��ض������浥���ݣ��Ŷ�Ϊ��
	CString jsonArray;	//��ض������浥�������飬�Ŷ�Ϊ��
	CStringArray order;	//���ϵĶ����̰󶨣���Ҫ�����������̵�����
//	CString path;	//����·����
};

//���ص���ʽ��Ϣ
struct MODEL_DATA
{
	int styleID;	//��ʽID
	int modelID;	//��ʽID
	int save;		//�洢ģʽ: 0��ʾ����ģʽ,1��ʾ������ģʽ,-1��ʾ����ģʽ
	CString style;	//��ʽ��
	CString uri;	//·������·����ʽ�磬BuyiStyle\201803\����
	CString LastTime;	//�ÿ�ʽ������޸�ʱ��
	CString error;	//������Ϣ
};

struct PDM_FILE
{
	int		m_action;	//0�½�,1�������ļ�,2ˢ�°浥
//	CString m_uUrl;		//�ϴ��ĵ�ַ
//	CString m_dUrl;		//���صĵ�ַ
	CString	m_projectName;	//����
	CString m_projectID;	//�����Ķ���ID
	CString m_saveURL;		//�����ļ���ַ
	CString m_filename;		//���ص�����֮����ļ�ȫ·��������Ҳ���ж��Ƿ����ļ����ݵ�����
};

//��������
enum ERP_TYPE
{
	erp_error = 0,		//�������ʧ��
	erp_model = 1,		//�浥
	erp_order = 2,		//����������
	erp_td = 3,			//�Ŷ�����
	erp_gd = 4,			//��������
	erp_task = 5,		//����ϵͳ����
	erp_bom = 6,		//��������
};

typedef CString (CALLBACK *PDMSAVEFILE)(void* pDoc, LPCTSTR style, LPCTSTR projectID, LPCTSTR fileID, LPCTSTR fileName);

//�������ϵͳ����
//thisUrl�Ǻ�����ļ���صİ浥(������)��ҳ���ַ
//json���ڷ��ع���ϵͳ�Ķ������߰浥��Ϣ
//locetePath�Ǽ��������ļ��Ļ��ı���Ŀ¼, file�����ص��ļ���ص���Ϣ, ����m_filename�ж��Ƿ����ļ�������
//ע����ļ���projectID��json�е�id��һ��һ��
//����ֵ��ʵ����������
//����erp_error��ʾʧ�ܻ�ȡ��
_declspec(dllexport) ERP_TYPE mesPdmLogin(ERP_TYPE type, LPCTSTR thisUrl, LPCTSTR locetePath, CString& json, PDM_FILE* file);

//mesPdmLogin�ļ򻯰汾
//����ֵ��ʵ����������
//����erp_error��ʾʧ�ܻ�ȡ��
_declspec(dllexport) ERP_TYPE mesPdmNoFile(ERP_TYPE type, CString& json);

//�ɰ汾: �ύ�����棩�ļ���ҳ������
_declspec(dllexport) bool mesPdmSave(LPCTSTR url, PDMSAVEFILE pFun, void* pDoc);

//�ύ�����棩�ļ���ҳ������
_declspec(dllexport) bool mesPdmSave(LPCTSTR url, PDMSAVEFILE pFun, void* pDoc, const CString& json);

//�����ݷ���������ϵͳ,json��Ҫ����������
_declspec(dllexport) bool mesPdmFeedback(ERP_TYPE type, const CString& json);

//��Ӳ���ļ�,�ϴ�������ϵͳ
_declspec(dllexport) bool mesPdmFile(const CStringArray& order, LPCTSTR orderType, LPCTSTR name, LPCTSTR type,
									 LPCTSTR filename, CString& error);

//�����������ϴ�������ϵͳ
_declspec(dllexport) bool mesPdmPost(const char utf8[], int nByte, CString& error);
_declspec(dllexport) bool mesPdmPost(const CString& cr, CString& error);

//ʹ��google������ں�
_declspec(dllexport) void mesPdmUseChrome();

//ʹ��IE������ں�
_declspec(dllexport) void mesPdmUseIE();

//��ȡ��ַ�趨�ļ�
_declspec(dllexport) void mesPdmReadSetting(LPCTSTR filename);
_declspec(dllexport) void mesPdmReadSetting(LPCTSTR filename, int appType);

//�༭�����е�������Ϣ
_declspec(dllexport) int mesEditFabric(ERP_TYPE type, bool bEdit, CStringArray& mName, CString& json);

_declspec(dllexport) bool mesPostWebApi(LPCTSTR uri, const char utf8[], int nByte, CString& error);
_declspec(dllexport) bool mesPostWebApi(LPCTSTR uri, const CString& post, CString& error);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//job_number�ǹ���
_declspec(dllexport) HANDLE mesLogin();

//job_number�ǹ���
_declspec(dllexport) HANDLE mesLogin(LPCTSTR ip, int job_number);

//���ڵ��ԣ�����XML����
_declspec(dllexport) HANDLE mesLoginDebug(LPCTSTR ip, int job_number, CString& xml);

//�ͷŵ�½��Ϣ
_declspec(dllexport) void mesClose(HANDLE mesHandle);

//д��־
_declspec(dllexport) void mesWriteLog(HANDLE mesHandle, LPCTSTR text);

//�ͻ���Ȩʹ���Թ����������ٹ���
_declspec(dllexport) bool tgcOauth(UINT lockNumber);

//�ϴ��Թ������ݣ������ض�ά����Ϣ
_declspec(dllexport) CString tgcUpload(HANDLE tgcHandle, UINT lockNumber, const char* json);


/*********************************��Щ���������ӷ�����*****************************************/

//ɾ���ļ���
_declspec(dllexport) bool mesDeleteFolder(LPCTSTR src);

//�����ļ��У��ļ��д��ڵĻ�������ɾ��
_declspec(dllexport) bool mesCreateFolder(LPCTSTR src);

//������һ�ε��ã��������˵ķ����ַ��������ڵ��ԣ�ֻ��mesLoginDebug��ʼ�� mesHandle������Ч
_declspec(dllexport) void mesGetReturnString(HANDLE mesHandle, CString& string);


/*********************************��Щ�������ı������*************************************/

//����ʽ���Ƿ��Ѵ��ڣ� 0��ʾ�����ڣ�1��ʾ���ڣ�2��ʾ���ӷ�����ʧ��
_declspec(dllexport) int mesCheckStyleName(HANDLE mesHandle, LPCTSTR style_name);

//�����ʽ���Ƿ��Ѵ���
_declspec(dllexport) int mesCheckModelName(HANDLE mesHandle, LPCTSTR model_name);

//�����ʽ���Ƿ��Ѵ���
_declspec(dllexport) int mesCheckOrderName(HANDLE mesHandle, LPCTSTR order_name);


//���ĳ����ʽ��(��ʽ)·��,����0��ʾ�ɹ�
_declspec(dllexport) int mesGetModelInfo(HANDLE mesHandle, LPCTSTR model_name, MODEL_DATA& info);


//���ĳ�����̵�����,����0��ʾ�ɹ�
//id������id, process�ǹ����,�����ж�����������
_declspec(dllexport) int mesGetTaskName(HANDLE mesHandle, int id, int process, CString& name);


/*************************************��Щ�����ı������***********************************/
//��ʱ��ѯ�Ƿ��к��Լ���ص�������Ҫ�������� pMainWnd �ķ��� ������ϢtaskID��fileID
_declspec(dllexport) void mesWatcher(HANDLE mesHandle, int appType, CWnd* pMainWnd, int taskID, int fileID);

//����0��ʾ�ɹ�
//appType��ʾ��������,1��ʾ�����ϳ���,2��ʾ�ǲô����ȳ���,0��ʾ���������������
_declspec(dllexport) int mesApplyTask(HANDLE mesHandle, int appType, TASK_DATA& rtn);

_declspec(dllexport) int mesApplyTaskByProcess(HANDLE mesHandle, int process, TASK_DATA& rtn);

//���������Ϣ,id��mesApplyTask���صĵ�rtn.id
//�˺���������mesApplyTask����֮������ʧ���ˣ��������ػ���ˢ������
//��������������ʺϹ���35,35Ӧ���� mesGetTaskName
_declspec(dllexport) int mesGetTaskInfo(HANDLE mesHandle, int appType, int id, TASK_DATA& rtn);

//�˻ص�ǰһ������, ����0��ʾ�ɹ�������ʱ�ڲ������Ի�����ʾ��ʾ��Ϣ
_declspec(dllexport) int mesGoBack(HANDLE mesHandle, int id, int process);

//�жϴ�����, ����0��ʾ�ɹ�������ʱ�ڲ������Ի�����ʾ��ʾ��Ϣ
_declspec(dllexport) int mesStop(HANDLE mesHandle, int id, int process);


/*************************************���������ļ��ϴ�***********************************/


//����ĳ�����̵�ĳ������, ����0��ʾ�ɹ�������ʱ�ڲ������Ի�����ʾ��ʾ��Ϣ
//pstrLocalRoot��pstrFileName��pstrDirName�ĺ�����mesUpload��ͬ,������ֵ��������NULL
_declspec(dllexport) int mesFinishTask(HANDLE mesHandle, int id, int process, 
									   LPCTSTR pstrLocalRoot = NULL, LPCTSTR pstrFileName = NULL, LPCTSTR pstrFileName2 = NULL, LPCTSTR pstrDirName = NULL);

_declspec(dllexport) int mesFinishTask2(HANDLE mesHandle, int id, int process, LPCTSTR markJson,
									   LPCTSTR pstrLocalRoot = NULL, LPCTSTR pstrFileName = NULL, LPCTSTR pstrFileName2 = NULL, LPCTSTR pstrDirName = NULL);

//ר��Ϊ���POD����, taskName,pstrLocalRoot,pstrFileName����ΪNULL���ű�ʾ��pod�ļ����޸���
_declspec(dllexport) int mesFinishPod(HANDLE mesHandle, int id, int pod, LPCTSTR taskName,  LPCTSTR pstrLocalRoot, LPCTSTR pstrFileName);

//����һ��������, ���һ������process��ʵ�����Ѿ����
//pstrLocalRoot��pstrFileName��pstrDirName�ĺ�����mesUpload��ͬ
_declspec(dllexport) int mesCreate(HANDLE mesHandle, LPCTSTR taskName, int process, 
								   LPCTSTR pstrLocalRoot, LPCTSTR pstrFileName, LPCTSTR pstrFileName2, LPCTSTR pstrDirName);

/*************************************�ļ��ϴ������غ���***********************************/

//��������·�������⣺

//mesUpload��mesGetDownloadUrl�����������Ŀ¼(BuyiWork)�ģ�������ǵĲ��� pstrRemoteRoot ��BuyiWork֮�µ�һ����Ŀ¼��ʼ��
//������һ�����̵�������"FD123", ������PodĿ¼��������Ҫ���ļ� FD123[2]#.pod�ϴ������Ŀ¼,
//��pstrRemoteRoot=FD123\A1, pstrFileName=FD123[2]#.pod
//��������Ҫ��Pod��������, ��pstrRemoteRoot = FD123, pstrDirName = Pod


//mesDownload�������ڷ������ϵ��κ��ļ�, ������Ŀ¼��BuyiRoot,
//���mesDownload�Ĳ��� pstrRemoteFileName ���� url ���Ǵ�ĳ��Ԥ�������Ŀ¼��ʼ��
//��ֵֻ���������ĸ�ֵ������֮(BuyiStyle, BuyiHistory, BuyiWork, BuyiCut)


//�ϴ�pstrFileName��pstrDirName֮�µ������ļ�
//pstrFileName��pstrDirName������һ����NULL
//pstrRemoteRoot��ͷ��Ҫ��\, ����ļ��ϴ���Ŀ¼, pstrRemoteRoot�ǿվͿ�����, ����ϴ���2����Ŀ¼��д: ��Ŀ¼\��Ŀ¼
//pstrRemoteRoot��pstrLocalRoot��󶼱��벻��"\"
_declspec(dllexport) int mesUpload(HANDLE mesHandle, LPCTSTR pstrRemoteRoot, LPCTSTR pstrLocalRoot,
													LPCTSTR pstrFileName,  LPCTSTR pstrFileName2, LPCTSTR pstrDirName);


_declspec(dllexport) int mesFtpTest(HANDLE mesHandle, LPCTSTR pstrLocalRoot);

//������������������Ŀ¼���ļ���"����url", url��filename��Ϊ����ֵ����ֱ����ΪmesDownload�Ĳ���
//ʹ�����ĺô�����,����������FTP���Ʊ����������ϵ�Ŀ¼(pstrDirName)
_declspec(dllexport) int mesGetDownloadUrl(HANDLE mesHandle, LPCTSTR pstrRemoteRoot, LPCTSTR pstrLocalRoot,
								   LPCTSTR pstrFileName, LPCTSTR pstrDirName,
								   CStringArray& url, CStringArray& filename);

//����һ���ļ�, һ���ӷ����������µ�
_declspec(dllexport) int mesDownload(HANDLE mesHandle, LPCTSTR pstrRemoteFileName, LPCTSTR pstrLocalFileName);

//���ض���ļ�Ŀ¼, һ���ӷ����������µ�
_declspec(dllexport) int mesDownload(HANDLE mesHandle, CStringArray& url, CStringArray& filename);

//���ض���ļ�Ŀ¼������������ļ��ȴ�ʱ���£��������µ�, time����ʽ��������ʱ��201804281536
_declspec(dllexport) int mesDownload(HANDLE mesHandle, LPCTSTR time, CStringArray& url, CStringArray& filename);

//��ʾ�Ѿ�������Լ������ǻ�δ��ɵ���������û�ѡ������֮һ���򷵻ظ��������Ϣ
//����0��ʾ�û�ѡ����һ������
_declspec(dllexport) int mesSelectTask(HANDLE mesHandle, int appType, int curID, TASK_DATA& rtn);


//��ѯ������Pod�ļ�, workPath�Ǳ�������·���� fiename�����ص�����·�����ļ�ȫ·����
//����0��ʾ�ɹ�
_declspec(dllexport) int mesSelectPod(HANDLE mesHandle, LPCTSTR workPath, TASK_DATA& rtn, CString& fiename);


#endif // !defined(AFX_ET_MES_FUNCTION_H__C6A03DCE_0A14_4775_8948_7A34461F061E__INCLUDED_)

