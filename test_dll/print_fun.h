#ifdef TEST_DLL_EXPORTS
#define DLL_DECLSPEC  __declspec(dllexport)
#else
#define DLL_DECLSPEC  __declspec(dllimport)
#endif

extern "C"
{
    DLL_DECLSPEC void MyPrint(int i);
    DLL_DECLSPEC void MyPrint2();
}




class  Test {
public:
    DLL_DECLSPEC static void print();
    DLL_DECLSPEC static int i;
};
