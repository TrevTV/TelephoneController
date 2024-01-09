#pragma once

class Page
{
public:
    virtual ~Page() {}
    virtual void start() = 0;
    virtual void loop() = 0;
};