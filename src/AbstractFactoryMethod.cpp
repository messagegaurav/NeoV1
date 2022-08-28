/*
 * Created on Sun Dec 26 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include "AbstractFactoryMethod.h"

using namespace std;

unique_ptr<cNode> cNodeFactory::GetNode(cNodeFactory::eNodeType type)
{
    if (type == eNodeType::NODE_MCN)
        return make_unique<cMCNNode>();
    if (type == eNodeType::NODE_FCN)
        return make_unique<cFCNNode>();
}

void cMCNNode::DoSomething()
{
    cout << "MCN Node: doing my stuff"
         << "\n\n";
}

void cFCNNode::DoSomething()
{
    cout << "FCN Node: doing my stuff"
         << "\n\n";
}

cMCNNode::cMCNNode()
{
    cout << "MCN: I am alive now"
         << "\n\n";
}

cFCNNode::cFCNNode()
{
    cout << "FCN: I am alive now"
         << "\n\n";
}

cMCNNode::~cMCNNode()
{
    cout << "MCN: dead"
         << "\n\n";
}

cFCNNode::~cFCNNode()
{
    cout << "FCN: dead"
         << "\n\n";
}

void PlayingWithFactories()
{
    // unique_ptr<cNode> pNode.reset(cNodeFactory::GetNode(eNodeType::NODE_MCN));
    // pNode->DoSomething();
    auto pNode1 = cNodeFactory::GetNode(cNodeFactory::eNodeType::NODE_FCN);
    cout << pNode1.get() << "\n\n";
    pNode1 = (cNodeFactory::GetNode(cNodeFactory::eNodeType::NODE_MCN));
    pNode1->DoSomething();
    cout << pNode1.get() << "\n\n";
}