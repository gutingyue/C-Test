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

	//�����
	const char DecodeTable[] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		62, // '+'
		0, 0, 0,
		63, // '/'
		52, 53, 54, 55, 56, 57, 58, 59, 60, 61, // '0'-'9'
		0, 0, 0, 0, 0, 0, 0,
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // 'A'-'Z'
		0, 0, 0, 0, 0, 0,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, // 'a'-'z'
	};

	size_t value;
	for(int i = 0; i < strData.size();){
		if (strData[i] != '\r'&&strData[i + 1] != '\n'){
			//һ��û������

			//�����һ������
			value = DecodeTable[strData[i++]]<<18;

			//����ڶ�������
			value += DecodeTable[strData[i++]] << 12;
			strDecode += ((value >> 16) & 0xFF);

			if (strData[i] != '='){
				//�������������
				value += DecodeTable[strData[i++]] << 6;
				strDecode += ((value >> 8) & 0xFF);

				if (strData[i] != '='){
					//������ĸ�����
					value += DecodeTable[strData[i++]];
					strDecode += (value & 0xFF);
				}
			}
			else{
				break;
			}


		}
		else{
			//���뵽��ĩβ������"\r\n"
			i += 2;
		}
	}


	return strDecode;
}