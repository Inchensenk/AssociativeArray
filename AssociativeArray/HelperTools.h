#pragma once
#include<String>
#include"Dictionary.h"


void interaction()
{
	const size_t lenDic = 100;
	Dictionary<string, string, LEN_DIC> dic;
	dic.pushBack("�����", "����� - ��� �����");
	dic.pushBack("�������", "������ ���� ���� �����");
	//cout << dic.isExistKey("�������") << endl;
	//cout << dic.findKeyData("�����") << endl;
	//dic.UpdateDataOnKey("�����", "����� - ��� �����");
	//dic.showDic();
	//cout << dic["�����"] << endl;
	Dictionary<string, string, LEN_DIC> dic2;
	dic2 = dic;
	dic2.showDic();
}