#include "global.h"

//// �㽭С��
//// ���Ա��ļ�
//const string attrFilePath = "";	
//// ������ģ��·��
//const string modelPath = "H:\\tga\\";
//// ����ģ�ͣ�������������Ĳ��֣�·��
//const string envPath = "H:\\fbxTest\\";
//// x����ʱ��λ������
//const string XdispFilePath = "F:\\wy\\0510NewBeiChuan\\disp\\0608_chichi.bin";
//// y����ʱ��λ������
//const string YdispFilePath = "F:\\wy\\0510NewBeiChuan\\disp\\0608_chichi.bin";
//// ����״̬����
//const string damageStatePath = "F:\\wy\\zjxz\\_new\\Result_125gal\\";


// ���ǹ㳡�������������������
const string attrFilePath = "G:\\osg_test\\SingleVR-bc0304\\_data\\JiaXingGuangChang\\attr\\BC_911_attr.txt";	
const string modelPath = "G:\\osg_test\\SingleVR-bc0304\\_data\\Beichuan\\";
const string envPath = "G:\\osg_test\\SingleVR-bc0304\\_data\\Beichuan\\env\\";
//const string XdispFilePath = "G:\\osg_test\\SingleVR2\\_data\\JiaXingGuangChang\\disp\\x_Disp.bin";
//const string YdispFilePath = "G:\\osg_test\\SingleVR2\\_data\\JiaXingGuangChang\\disp\\y_Disp.bin";
//const string XdispFilePath = "G:\\osg_test\\SingleVR-bc\\_data\\JiaXingGuangChang\\bc0115\\wc2bc_ew_02.bin";
//const string YdispFilePath = "G:\\osg_test\\SingleVR-bc\\_data\\JiaXingGuangChang\\bc0115\\wc2bc_ns_02.bin";
const string XdispFilePath = "G:\\osg_test\\SingleVR-bc0304\\_data\\JiaXingGuangChang\\bc0115\\Disp_ew.bin";
const string YdispFilePath = "G:\\osg_test\\SingleVR-bc0304\\_data\\JiaXingGuangChang\\bc0115\\Disp_ns.bin";
//const string XdispFilePath = "G:\\osg_test\\SingleVR2\\_data\\JiaXingGuangChang\\201015\\3ew_Disp.bin";
//const string YdispFilePath = "G:\\osg_test\\SingleVR2\\_data\\JiaXingGuangChang\\201015\\3ns_Disp.bin";
const string damageStatePath = "G:\\osg_test\\SingleVR-bc0304\\_data\\_new\\Result_125gal\\";
const string smokeDataPath = "G:\\osg_test\\SingleVR-bc0304\\_data\\";

const string modelFileType = ".fbx";
const string envFileType = ".fbx";

int nBuildings;
int* idMap;
map<int, string> models;
vector<string> envs;
vector<vector<string>> attrArray;
vector<vector<vector<double>>> XdispArray;
vector<vector<vector<double>>> YdispArray;

vector<vector<float>> VerticeXcoordsArray;
vector<vector<float>> VerticeYcoordsArray;
vector<vector<float>> VerticeZcoordsArray;

vector<int> damageState;
vector<int> damageStateOrigin;
vector<int> damageType;
vector<int> collapseStorey;
vector<int> inModelList;
float rotateAxis[2][3];
int rotateDirctn[3];
float smokeCoordsArray[1000][2];
int smokeTime[1000][2];
int smokeStartTime[6];
int smokeEndTime[6];

float globalDispScale = 50.0;
int nTimePoint = 8000;     //��Ӧ0504\\0\\ew_Disp.bin
//const int nTimePoint = 4000;
float collapsSpeed = 0.954993;

int objIDIndex=0;
int storeyIndex=4;

bool isFrameSkip = false;		//�Ƿ�������֡
int frameSkip = 10;
int idleFrame = 3000;

bool setDamage = true;
bool useVBO = false;
bool useDamageSnapshot = false;

bool isPause = false;

int verticeLabel = 0;

float PI_F = 3.14159265358979f;