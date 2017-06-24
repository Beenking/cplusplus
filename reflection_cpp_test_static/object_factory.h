#ifndef OBJECT_CREATOR
#define OBJECT_CREATOR(BaseClass, ConcreteClass)				\
class ConcreteClass##ObjectCreator								\
{																\
public:															\
	ConcreteClass##ObjectCreator(const std::string & strID)		\	
	{															\
		;														\
	}															\
};																
#endif // !OBJECT_CREATOR


#ifndef ClassNameToString
#define ClassNameToString(className) #className
#endif


#ifndef REGISTER_CLASS
#define REGISTER_CLASS(BASETYPE, CONCRTETYPE)			\
	OBJECT_CREATOR(BASETYPE, CONCRTETYPE)				\
	static CONCRTETYPE##ObjectCreator					\
	 CONCRETETYPE##objCreator(ClassNameToString(CONCRETETYPE));
#endif // !REGISTER_CLASS