#include <iostream>
#include <string>
#include <complex>
#include <vector>

class MyString {
public:
	MyString(const char* c = nullptr){
		if (nullptr == c)
		{
			m_data = new char('\0');
		}
		else
		{
			int size = strlen(c) + 1;
			m_data = new char[size];
			strcpy_s(m_data, size, c);
		}
	}

	MyString(const MyString& str)
	{
		int size = strlen(str.m_data) + 1;
		m_data = new char[size];
		strcpy_s(m_data, size, str.m_data);
	}

	MyString(MyString&& str)
	{
		m_data = str.m_data;
		str.m_data = nullptr;
	}

	MyString& operator= (const MyString& str)
	{
		MyString temp(str);
		this->swap(temp);

		return *this;
	}

	MyString& operator= (MyString&& str)
	{
		this->swap(str);

		return *this;
	}

	~MyString()
	{
		std::cout << "dctor" << std::endl;
		if (m_data != nullptr)
		{
			delete[] m_data;
			m_data = nullptr;
		}
	}
	
public:
	void swap(MyString &rhs)
	{
		std::swap(m_data, rhs.m_data);		
	}

private:
	char* m_data;
};

int main()
{
	MyString str1("abc");
	MyString str2(str1);

	MyString str3("www");

	str2 = std::move( str3 );
	MyString str4(std::move(str1));

	std::complex<double> cp(0,0);
	std::complex<double> cp2(std::move(cp));

	std::string s;
	return 0;
}