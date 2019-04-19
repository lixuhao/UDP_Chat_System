#include "data.h"

data::data()
{
}

void data::serialize(std::string &out_string)
{
	Json::Value root;
	root["nick_name"] = nick_name;
	root["school"] = school;
	root["message"] = message;
	root["type"] = type;

#ifdef FAST
	Json::FastWriter w;
#else
	Json::StyledWriter w;
#endif
	out_string = w.write(root);
}

void data::unserialize(std::string &in_string)
{
	Json::Value root;
	Json::Reader r;
	r.parse(in_string, root, false);

	nick_name = root["nick_name"].asString();
	school = root["school"].asString();
	message = root["message"].asString();
	type = root["type"].asString();
}

data::~data()
{
}

//int main()
//{
//	data d;
//	d.nick_name = "最美的夕阳";
//	d.school = "临潼养老院";
//	d.message = "hello";
//	d.type = "None";
//
//	std::string out_string;
//	d.serialize(out_string);
//
//	std::cout << out_string << std::endl;
//}

