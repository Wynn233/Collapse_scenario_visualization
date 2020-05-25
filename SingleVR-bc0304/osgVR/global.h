#ifndef GLOBAL_H
#define GLOBAL_H

#include <osg/NodeVisitor>
#include <osg/Geometry>
#include <osg/Node>
#include <osg/Geode>
#include <osg/Group>
#include <osg/Image>
#include <osg/TexGen>
#include <osg/Texture1D>
#include <osg/TexEnv>
#include <osg/StateSet>
#include <osg/Switch>
#include <osg/Billboard>
#include <osg/PositionAttitudeTransform>
#include <osg/MatrixTransform>
#include <osg/Vec3>
#include <osg/LightModel>
#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgUtil/Optimizer>
#include <osgUtil/Export>
#include <osgUtil/SmoothingVisitor>
#include <osgUtil/Simplifier>
#include <osgUtil/MeshOptimizers>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgDB/Registry>
#include <osgDB/ReaderWriter>

#include <osg\NodeVisitor>
#include <osg\MatrixTransform>
#include <osg\PagedLOD>
#include <osgDB\FileNameUtils>
#include <osg\Geode>
#include <strstream>

#include <osgParticle/ExplosionDebrisEffect>
#include <osgParticle/ExplosionEffect>
#include <osgParticle/SmokeEffect>
#include <osgParticle/FireEffect>
#include <osgParticle/BoxPlacer>
#include <osgParticle/ModularProgram>
#include <osgParticle/AccelOperator>
#include <osgParticle/FluidFrictionOperator>
#include <osgParticle/ParticleSystem>
#include <osgParticle/ParticleSystemUpdater>
#include <osgParticle/MultiSegmentPlacer>
#include <osg/Fog>

#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <math.h>
#include <cstdlib>

using namespace std;

extern const string attrFilePath;		//���Ա��ļ�Ŀ¼
extern const string XdispFilePath;
extern const string YdispFilePath;

extern const string modelPath;			//ģ���ļ�Ŀ¼
extern const string envPath;			//�����ļ�Ŀ¼
extern const string damageStatePath;	//�ƻ�״̬�ļ�Ŀ¼
extern const string smokeDataPath;		//�����ļ�Ŀ¼
extern const string modelFileType;		//ģ�͸�ʽ
extern const string envFileType;		//������ʽ
extern int nTimePoint;			
extern int nBuildings;					//������������
extern float globalDispScale;			//������λ��ϵ����Ĭ��Ϊ1.0

extern int objIDIndex;					//���Ա��ļ���ID�������±�
extern int storeyIndex;					//���Ա��ļ��в����������±�

extern bool isFrameSkip;				//�Ƿ�����֡
extern int frameSkip;					//ÿx֡��ȡһ�Σ�����Ϊ����1��Ч��Ϊ��֡���ţ�
extern float collapsSpeed;
extern bool setDamage;					//�Ƿ���ʾ�����״̬����
extern bool useVBO;						//�Ƿ�ʹ��VBO��ͬʱҲ�����Ķ�����·�ʽ
extern int idleFrame;					//������ʼǰ�ĵȴ�֡��60֡idleһ�룬ͬʱ��������VBOģʽͬ��
extern bool useDamageSnapshot;

extern int verticeLabel;				//��ȡģ�ͼ��ε����

//ArcGIS IDӳ��
//idMap[i] = j
//i: ArcGIS objectID	j: indexInArray
extern int* idMap;			
//ģ���ļ�Ŀ¼
//modesl[i] = str
//i: index    str: ģ���ļ�Ŀ¼(X:\\...\\a.fbx)
extern map<int, string> models;
//����ģ��Ŀ¼
extern vector<string> envs;
//���Ա�����: attrArry[a][b]
//a��objectIndex    b:������Ŀ
//[0]OBJECTID	[1]����		[2]����ʱ��		[3]�������		[4]����; 
//[5]�ṹ����		[6]���		[7]�������		[8]�ṹ����		[9]ռ�����   
extern vector<vector<string>> attrArray;

//ʱ��λ��������dispArray[a][b][c]
//a: objectIndex     b (0~nTimePoint): ��Ӧʱ��λ��    c��0~attrArray[a][4]): ¥��  
extern vector<vector<vector<double>>> XdispArray;
extern vector<vector<vector<double>>> YdispArray;

//ģ������㣺coordsArray[a][b]
//a������ģ�ͱ��	b��ģ�͵�b�����ε������
extern vector<vector<float>> VerticeXcoordsArray;
extern vector<vector<float>> VerticeYcoordsArray;
extern vector<vector<float>> VerticeZcoordsArray;

//�ṹ�ƻ�״̬���飬����������ʱ��
extern vector<int> damageState;
//�ṹ�ƻ�״̬���飬�����𺦽��ȷ���ĵ���������ʱ��
extern vector<int> damageStateOrigin;
//�������ͣ�-1����δ������0������ȫ���������1����ײ�һ�㵹����2����ײ����㵹����3�����м�㵹����4���������㵹
extern vector<int> damageType;
//����¥�㣺-1����ײ������������������м�ĳ�㵹��
extern vector<int> collapseStorey;
//������ȫ�㵹Χ�Ƶ���ת��
extern float rotateAxis[2][3];
//�����㵹�ķ���
//1����������������-1���������Ḻ����0�����㵹
extern int rotateDirctn[3];

//�����������꣺smokeCoordsArray[a][b]
//a���������	b��������������
//[0]X����	[1]Y����
extern float smokeCoordsArray[1000][2];

//����ʱ�䣺smokeTime[a][b]
//a���������	b����������ʱ��
//[0]��ʼʱ��		[1]����ʱ��
extern int smokeTime[1000][2];

//��������ʱ�䣺smokeStartTime[a]
//a���������
//[0]30֡		[1]50֡		[2]60֡		[3]100֡
extern int smokeStartTime[6];

//��������ʱ�䣺smokeEndTime[a]
//a���������
//[0]200֡		[1]150֡		[2]100֡		[3]30֡
extern int smokeEndTime[6];

//�Ƿ��ж�Ӧ�Ľ���fbxģ��
extern vector<int> inModelList;

extern bool isPause;

extern float PI_F;

#endif
