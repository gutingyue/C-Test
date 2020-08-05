#include "Base64.h"

//编码
string Base64::Encode(const string& strData){
	string strEncode;
	//编码表
	string EncodeTable("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");
	unsigned char temp[3];

	int x = 0;
	//3个一组
	for (size_t i = 0; i < strData.size() / 3; ++i){
		temp[0] = strData[x++];
		temp[1] = strData[x++];
		temp[2] = strData[x++];

		//第一个字节的高2位
		strEncode += EncodeTable[temp[0] >> 2];
		//第一个字节的低2位+第二个字节的高4位
		strEncode += EncodeTable[((temp[0] << 4) | (temp[1] >> 4)) & 0x3F];
		//第二个字节低4位+第三个字节高2位
		strEncode += EncodeTable[((temp[1] << 2) | (temp[2] >> 6)) & 0x3F];
		//第三个字节低6位
		strEncode += EncodeTable[temp[2] & 0x3F];
	}

	//模完后余两个字节
	if (strData.size() % 3 == 2){
		temp[0] = strData[x++];
		temp[1] = strData[x++];

		strEncode += EncodeTable[temp[0] >> 2];

		strEncode += EncodeTable[((temp[0] << 4) | (temp[1] >> 4)) & 0x3F];

		//最后4位，放在最后一个字节的低6位中的高4位
		strEncode += EncodeTable[(temp[1] << 2)  & 0x3F];
		strEncode += '=';

	}
	//模完后余一个字节
	else if (strData.size() % 3 == 1){
		temp[0] = strData[x++];

		strEncode += EncodeTable[temp[0] >> 2];

		//剩下2位放在最后一个字节低6位的高2位
		strEncode += EncodeTable[(temp[0] << 4) & 0x3F];

		strEncode += '=';
		strEncode += '=';
	}

	return strEncode;
}

//解码
string Base64::Decode(const string& strData){
	string strDecode;


	return strDecode;
}