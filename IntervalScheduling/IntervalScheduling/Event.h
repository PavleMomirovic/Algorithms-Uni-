#pragma once
class Event
{
private:
    int Start;
    int End;
public:
    Event(int start, int end)
    {
        this->Start = start;
        this->End = end;
    }
    int GetStart()
    {
        return this->Start;
    }
    int GetEnd()
    {
        return this->End;
    }
};

