#include "7zip\LzmaDec.h"
#include "7zip\Alloc.h"

#define LZMA_PROPS_SIZE 5

extern "C"
{
	__declspec(dllexport) int LzmaUncompress(Byte* src, SizeT srcLen, Byte* dest, SizeT destLen)
	{
		ELzmaStatus status;
		return LzmaDecode(dest, &destLen, src + LZMA_PROPS_SIZE + 8, &srcLen, src, LZMA_PROPS_SIZE, LZMA_FINISH_ANY, &status, &g_Alloc);
	}
}