#include "AttrDispReader.h"
#include <Windows.h>

using namespace std;

//��ȡ�������ļ�
void ReadResult(){
	ReadAttrFile(attrFilePath);
	ReadDispFile(XdispFilePath, XdispArray, nTimePoint);
	ReadDispFile(YdispFilePath, YdispArray, nTimePoint);
	cout<<"[Time "<<(double) clock()/CLOCKS_PER_SEC<<"]\t"<<"Time history of "<<nBuildings<<" building(s) is loaded."<<endl;
}

//��ȡ���Ա��ļ����ļ������ʽ��Ϊasci��
void ReadAttrFile(string filePath){
	ifstream inFile(filePath);
	string lineStr;
	getline(inFile, lineStr);			//�Թ���ͷ

	while(getline(inFile, lineStr)){
		//cout<< lineStr <<endl;
		string str;
		stringstream ss(lineStr);
		vector<string> lineArray;
		while(getline(ss, str, ',')){
			lineArray.push_back(str);
		}
		attrArray.push_back(lineArray);
	}
	inFile.close();

	//����IDӳ��
	idMap = new int[atoi(attrArray[attrArray.size()-1][objIDIndex].c_str())+1]();
	for(int i=0;i<attrArray.size();i++){
		idMap[atoi(attrArray[i][objIDIndex].c_str())] = i; 
	}
	
	nBuildings = attrArray.size();
	cout<<"[Time "<<(double) clock()/CLOCKS_PER_SEC<<"]\tAttribute is loaded from "<<filePath<<endl;
}

//��ȡdisp.bin�ļ�
void ReadDispFile(string filePath, vector<vector<vector<double>>>& dispArr, int nTimePoint){
	ifstream dispFile(filePath, ios::binary);
	int nBdsInDisp;
	int tempInt;
	double disp = 0.0;
	double tempDouble;
	string tempStr;

	dispFile.read((char*)(&nBdsInDisp), sizeof(nBdsInDisp));
	if(nBdsInDisp != nBuildings){
		cout<<"[Time "<<(double) clock()/CLOCKS_PER_SEC<<"]\t"<<"The nBuildings has discrepancy between disp.bin and attr.txt"<<endl;
		cout<<"[Time "<<(double) clock()/CLOCKS_PER_SEC<<"]\t"<<"nBdsInDisp = "<<nBdsInDisp<<endl;
		return;
	}

	for(int i=0;i<nBuildings;i++){
		dispFile.read((char*)(&tempInt), sizeof(tempInt));
		//cout<<"Object ID: "<<tempInt<<endl;
		int nos = atoi(attrArray[i][storeyIndex].c_str());
		//cout<<"Nubmer of storeies: "<<nos<<endl;
		vector<vector<double>> objDisp;
		for(int j=0;j<=nTimePoint;j++){
			dispFile.read((char*)(&tempDouble),sizeof(tempDouble));
			// cout<<"    Time: "<<tempDouble<<endl;
			vector<double> storeyDisp;
			for(int k=0;k<nos;k++){
				dispFile.read((char*)(&disp),sizeof(disp));
				//cout<<"        Stroey "<<k+1<<": "<<disp<<"\t";
				storeyDisp.push_back(disp);
			}
			//cout<<endl;
			//cout<<storeyDisp.size()<<endl;
			objDisp.push_back(storeyDisp);
			storeyDisp.clear();
		}
		dispArr.push_back(objDisp);
		objDisp.clear();
	}
	dispFile.close();

	cout<<"[Time "<<(double) clock()/CLOCKS_PER_SEC<<"]\tDisp is loaded from "<<filePath<<endl;
}