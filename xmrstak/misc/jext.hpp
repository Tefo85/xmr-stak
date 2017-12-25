#pragma once

#ifdef __GNUC__
#	pragma GCC diagnostic push
#	pragma GCC diagnostic ignored "-Wuseless-cast"
#	pragma GCC diagnostic ignored "-Wsign-conversion"
#endif

#include "xmrstak/rapidjson/document.h"
#include "xmrstak/rapidjson/error/en.h"

#ifdef __GNUC__
# pragma GCC diagnostic pop
#endif

using namespace rapidjson;

/* This macro brings rapidjson more in line with other libs */
inline const Value* GetObjectMember(const Value& obj, const char* key)
{
	Value::ConstMemberIterator itr = obj.FindMember(key);
	if (itr != obj.MemberEnd())
		return &itr->value;
	else
		return nullptr;
}
