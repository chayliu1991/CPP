#pragma once
#include <streambuf>
#include <locale>
#include <cstdio>

class outbuf : public std::streambuf
{
protected:
	virtual int_type overflow(int_type c)
	{
		if (c != EOF)
		{
			c = std::toupper(c, getloc());
			if (std::putchar(c) == EOF)
				return EOF;
		}
		return c;
	}
};