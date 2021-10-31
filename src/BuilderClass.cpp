/*
 * Created on Sun Oct 31 2021
 *
 * Copyright (c) 2021 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include "BuilderClass.h"

using namespace std;

void Pizza::setDough(const string &dough)
{
    m_dough = dough;
}

void Pizza::setSauce(const string &sauce)
{
    m_sauce = sauce;
}

void Pizza::setToppings(const string &toppings)
{
    m_toppings = toppings;
}

void Pizza::open() const
{
    cout << "\n\n The pizza have "
         << m_dough << " dough, "
         << m_sauce << " sauce, "
         << m_toppings << " toppings. "
         << "\n\n";
}

void Cook::createPizza(PizzaBuilder *pPizzaBuilder)
{
    mp_PizzaBuilder = pPizzaBuilder;
    mp_PizzaBuilder->createNewPizza();
    mp_PizzaBuilder->buildDough();
    mp_PizzaBuilder->buildSauce();
    mp_PizzaBuilder->buildToppings();
}

void Cook::openPizza() const
{
    /* Only if you're using unique_ptr.get() coz unique_ptr.release() returns raw ptr which has to be deleted explicity
    instead of .get() which doesn't disassociate with assigned object thus compiler deletes the assigned object as part of smart pointer */

    // mp_PizzaBuilder->getPizza()->open();
    const_cast<Cook *>(this)->mp_Pizza = mp_PizzaBuilder->getPizza();
    mp_Pizza->open();
}

void callBuilderClass()
{
    Cook newCook;
    HawaiianPizzaBuilder hawaiianPizza;
    newCook.createPizza(&hawaiianPizza);
    newCook.openPizza();
    newCook.releasePtr();

    IndianaPizzaBuilder indianaPizza;
    newCook.createPizza(&indianaPizza);
    newCook.openPizza();
    newCook.releasePtr();
}