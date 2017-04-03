#ifndef _KAIN_XPLATFORM_TYPES_

#ifdef _WIN32
#include <d3d.h>
#include <d3dtypes.h>
#include <Windows.h>
#else
#include <stdint.h>
#include "WINTYPES.h"
#endif


#ifndef _SCOPETABLE_
struct _SCOPETABLE_ENTRY {
	int EnclosingLevel;
	void *FilterFunc;
	void *HandlerFunc;
};

typedef struct _SCOPETABLE_ENTRY *PSCOPETABLE_ENTRY;
#endif

#ifndef _EH3EXC_
struct _EH3_EXCEPTION_REGISTRATION {
	struct _EH3_EXCEPTION_REGISTRATION *Next;
	void *ExceptionHandler;
	PSCOPETABLE_ENTRY ScopeTable;
	DWORD TryLevel;
};

typedef struct _EH3_EXCEPTION_REGISTRATION EH3_EXCEPTION_REGISTRATION;
typedef struct _EH3_EXCEPTION_REGISTRATION *PEH3_EXCEPTION_REGISTRATION;
#endif

#ifndef _CPPEH_
struct CPPEH_RECORD {
	DWORD old_esp;
	EXCEPTION_POINTERS *exc_ptr;
	DWORD TryLevel;
};
#endif

#ifndef _INT_VARIATIONS_
typedef double _ix64;
struct _LARGE_INTEGER_INTERNAL {
	DWORD LowPart;
	LONG HighPart;
};
union _LARGE_INTEGER {
	struct {
		DWORD LowPart;
		LONG HighPart;
	};
	_LARGE_INTEGER_INTERNAL u;
	LONGLONG QuadPart;
};
#endif

#ifndef __m_types__
union __declspec(align(8)) __m64 {
	unsigned __int64 m64_u64;
	float m64_f32[2];
	__int8 m64_i8[8];
};
#endif


#endif // !_KAIN_XPLATFORM_TYPES_
