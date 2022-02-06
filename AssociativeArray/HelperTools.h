#pragma once
#include<String>
#include"Dictionary.h"


void interaction()
{
	const size_t lenDic = 100;
	Dictionary<string, string, LEN_DIC> dic;
	dic.pushBack("Слово", "Слово - это слово");
	dic.pushBack("Алфавит", "Список всех букв языка");
	//cout << dic.isExistKey("Алфавит") << endl;
	//cout << dic.findKeyData("Слово") << endl;
	//dic.UpdateDataOnKey("Слово", "Слово - это СЛОВО");
	//dic.showDic();
	//cout << dic["Слово"] << endl;
	Dictionary<string, string, LEN_DIC> dic2;
	dic2 = dic;
	dic2.showDic();
}