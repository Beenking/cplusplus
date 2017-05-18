
namespace Mcsf
{
	class A
	{
	public:
		typedef std::shared_ptr<A> Ptr;
		int m_a;
	};
	typedef std::shared_ptr<A> ptrA;


	namespace AppPlugin
	{
		class B
		{
		public:
			int m_b;
		};
	}
}