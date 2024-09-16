#pragma once

#ifdef AP_DLL
	#define APOLLO_API __declspec(dllexport)	
#else
	#define APOLLO_API __declspec(dllimport)
#endif