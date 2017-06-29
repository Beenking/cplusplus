#ifdef TEST_DLL_EXPORTS
#define DLL_DECLSPEC  __declspec(dllexport)
#else
#define DLL_DECLSPEC  __declspec(dllimport)
#endif

DLL_DECLSPEC void MyPrint();

class DLL_DECLSPEC Test {
public:
    static void print();
    static int i;
};
