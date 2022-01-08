/*
 * Created on Sun Oct 31 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

/* Understanding need for Builder Design Pattern */
#ifndef __BUILDER_CLASS__
#define __BUILDER_CLASS__

#include <iostream>
#include <memory>

using namespace std;

void callBuilderClass();

class Pizza
{
public:
    void setDough(const string &dough);

    void setSauce(const string &sauce);

    void setToppings(const string &toppings);

    void open() const;

private:
    string m_dough;
    string m_sauce;
    string m_toppings;
};

// Interface aka builder class
class PizzaBuilder
{
public:
    virtual ~PizzaBuilder() = default;

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildToppings() = 0;

    void GetPizzaInstance()
    {
        m_pizza = make_unique<Pizza>();
    }

    Pizza *DeliverPizza()
    {
        return m_pizza.release();
    }

protected:
    unique_ptr<Pizza> m_pizza;
};

class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
    virtual ~HawaiianPizzaBuilder() override = default;
    void buildDough()
    {
        m_pizza->setDough("Hawaiian");
    }

    void buildSauce()
    {
        m_pizza->setSauce("Hawaiian");
    }

    void buildToppings()
    {
        m_pizza->setToppings("Hawaiian");
    }
};

class IndianaPizzaBuilder : public PizzaBuilder
{
public:
    virtual ~IndianaPizzaBuilder() override = default;
    void buildDough()
    {
        m_pizza->setDough("IndianaPizza");
    }

    void buildSauce()
    {
        m_pizza->setSauce("IndianaPizza");
    }

    void buildToppings()
    {
        m_pizza->setToppings("IndianaPizza");
    }
};

class Cook
{
public:
    void setCook(PizzaBuilder *pPizzaBuilder);

    void createPizza();

private:
    PizzaBuilder *mp_PizzaBuilder;
};

#endif