#ifndef CHECK_MOMORY_LEACKS_H__
#define CHECK_MOMORY_LEACKS_H__

#ifdef _DEBUG
    #include <stdlib.h>
    #include <crtdbg.h>
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG


#endif // !CHECK_MOMORY_LEACKS_H__


