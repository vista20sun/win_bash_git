// windownbashgit.cpp: 定义控制台应用程序的入口点。
// 64位系统使用x64编译

#include "stdafx.h"



int main(int argc, char** argv)
{
	string x = "bash.exe -c \"git";
	regex reg("[A-Z]:(\\\\.+)+\\\\?"); //parten of windows path
	smatch match;
	for (int i = 1; i < argc; i++)
	{
		string str(argv[i]);
		x.append(" ");
		string::size_type idx;
		idx = str.find(" ");
		if (idx != string::npos)
			x.append("'");
		if (regex_match(str, match, reg))
		{
			transform(str.begin(), str.end(), str.begin(), tolower);
			regex split("\\\\");
			str = regex_replace(str, split, "/");
			regex remove(":");
			str = regex_replace(str, remove, "");
			x.append("/mnt/");
		}
		x.append(str);
		if (idx != string::npos)
			x.append("'");

	}
	x.append("\"");
	system(x.c_str());
	return 0;
}