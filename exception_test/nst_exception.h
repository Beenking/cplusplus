#pragma once
#include <exception>
#include <iostream>
#include <string>

namespace NST
{
    class Exception : public std::exception
    {
    public:
        Exception(std::string sFile, std::string sFunc, long lLine, std::string sDes);

        virtual char const* what() const;

        ~Exception();

    private:
        std::string m_sFileName;
        std::string m_sFuncName;
        long m_lLine;
        std::string m_sDes;
        std::string m_FullDescription;
    };


    Exception::Exception(std::string sFile, std::string sFunc, long lLine, std::string sDes) :
        m_sFileName(sFile), m_sFuncName(sFunc), m_lLine(lLine), m_sDes(sDes)
    {
        m_FullDescription = std::string(
            "Exception File Name: " + m_sFileName + "\n" +
            "Exception Func Name: " + m_sFuncName + "\n" +
            "Exception Line No.:  " + std::to_string(m_lLine) + "\n" +
            "Exception Description: " + m_sDes );
    }

    Exception::~Exception()
    {
    }

    char const * Exception::what() const
    {
        return m_FullDescription.c_str();
    }
}

#define NST_THROW_EXCEPTION(sDes) throw NST::Exception(__FILE__, __FUNCTION__, __LINE__, sDes)