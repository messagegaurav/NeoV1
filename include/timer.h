/*
 * Created on Tue Jun 08 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

// Hiding, now all data members for Implementation are hidden from this header file
class Timer
{
public:
    explicit Timer(double);
    ~Timer();
    Timer(const Timer &);
    Timer &operator=(const Timer &);

private:
    class Implementation;
    Implementation *mpImpl;
};

void callingTimer();