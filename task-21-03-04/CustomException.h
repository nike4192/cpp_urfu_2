#pragma once

#include <exception>
#include <string>

/* ����� ���������� ���������� ����, ���������������� �� std::exception */
class CustomException : public std::exception
{
public:

	CustomException(const std::string _message) : std::exception(_message.c_str()) {};
};

