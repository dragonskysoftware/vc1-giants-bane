/*
 * SymbolList.h
 * Defines a typedef that renames the std::list<Symbol> type to the SymbolList type
 * Created by Andrew Davis
 * Created on 3/20/2017
 * Open source (GPL license)
 */

//disallow reinclusion
#ifndef SYM_LIST_H
#define SYM_LIST_H

//include std::list
#include <list>

//forward declaration of class Symbol
class Symbol;

//typedef definition
typedef std::list<Symbol> SymbolList;

#endif
