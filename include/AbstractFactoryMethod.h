/*
 * Created on Sun Dec 26 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#ifndef ABSTRACT_FACTORY_METHOD_
#define ABSTRACT_FACTORY_METHOD_

#include <iostream>
#include <memory>
#include <vector>

using namespace std;
// base class for node
class cNode
{
public:
    virtual ~cNode() {}
    virtual void DoSomething() = 0;
};

class cMCNNode : public cNode
{
public:
    cMCNNode();
    virtual ~cMCNNode();
    virtual void DoSomething();
};

class cFCNNode : public cNode
{
public:
    cFCNNode();
    virtual ~cFCNNode();
    virtual void DoSomething();
};

// abstract factory class
class cNodeFactory
{
public:
    enum class eNodeType
    {
        NODE_MCN,
        NODE_FCN
    };
    static unique_ptr<cNode> GetNode(eNodeType type);
};

void PlayingWithFactories();

#endif
