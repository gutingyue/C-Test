#include "Base64.h"

//����
string Base64::Encode(const string& strData){
	string strEncode;
	//�����
	string EncodeTable("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
	unsigned char temp[3];

	int x = 0;
	//3��һ��
	for (size_t i = 0; i < strData.size() / 3; ++i){
		temp[0] = strData[x++];
		temp[1] = strData[x++];
		temp[2] = strData[x++];

		//��һ���ֽڵĸ�2λ
		strEncode += EncodeTable[temp[0] >> 2];
		//��һ���ֽڵĵ�2λ+�ڶ����ֽڵĸ�4λ
		strEncode += EncodeTable[((temp[0] << 4) | (temp[1] >> 4)) & 0x3F];
		//�ڶ����ֽڵ�4λ+�������ֽڸ�2λ
		strEncode += EncodeTable[((temp[1] << 2) | (temp[2] >> 6)) & 0x3F];
		//�������ֽڵ�6λ
		strEncode += EncodeTable[temp[2] & 0x3F];
	}

	//ģ����������ֽ�
	if (strData.size() % 3 == 2){
		temp[0] = strData[x++];
		temp[1] = strData[x++];

		strEncode += EncodeTable[temp[0] >> 2];

		strEncode += EncodeTable[((temp[0] << 4) | (temp[1] >> 4)) & 0x3F];

		//���4λ���������һ���ֽڵĵ�6λ�еĸ�4λ
		strEncode += EncodeTable[(temp[1] << 2)  & 0x3F];
		strEncode += '=';

	}
	//ģ�����һ���ֽ�
	else if (strData.size() % 3 == 1){
		temp[0] = strData[x++];

		strEncode += EncodeTable[temp[0] >> 2];

		//ʣ��2λ�������һ���ֽڵ�6λ�ĸ�2λ
		strEncode += EncodeTable[(temp[0] << 4) & 0x3F];

		strEncode += '=';
		strEncode += '=';
	}

	return strEncode;
}

//����
string Base64::Decode(const string& strData){
	string strDecode;


	return strDecode;
}