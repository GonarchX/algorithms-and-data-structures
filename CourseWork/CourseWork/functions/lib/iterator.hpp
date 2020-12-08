#pragma once

class Iterator
{
public:
    virtual std::string getCurrent() = 0;
    virtual void next() = 0;
	virtual bool has_next() = 0;
};